; Lo-res fire animation, size-optimized

; by deater (Vince Weaver) <vince@deater.net>

; based on code described here http://fabiensanglard.net/doom_fire_psx/

; 611 bytes at first
; 601 bytes -- strip out some unused code
; 592 bytes -- don't init screen
; 443 bytes -- remove more dead code
; 206 bytes -- no need to clear screen
; 193 bytes -- un-cycle exact the random16 code
; 189 bytes -- more optimization of random16 code
; 161 bytes -- move to 8-bit RNG
; 152 bytes -- reduce lookup to top half colors (had to remove brown)
;		also changed maroon to pink
; 149 bytes -- use monitor GR
; 149 bytes -- load into zero page
; 140 bytes -- start using zero-page addressing
; 139 bytes -- rotate instead of mask for low bit
; 138 bytes -- bcs instead of jmp
; 137 bytes -- BIT nop trick to get rid of jump
; 135 bytes -- push/pull instead of saving to zero page
; 134 bytes -- replace half of lookup table with math
; 119 bytes -- replace that half of lookup table with better math
; 134 bytes -- replace other half of lookup table with math
; 132 bytes -- replace stack with zp loads
; 129 bytes -- use Y instead of X
; 125 bytes -- optimize low byte generationw with branch
; 113 bytes -- make get_row a subroutine
; 112 bytes -- regrettable change to the low-byte code
; 109 bytes -- replace BIT/OR in low calc with an ADC

; Zero Page
SEEDL		= $4E
TEMP		= $00
TEMPY		= $01

; 100 = $64

; Soft Switches
SET_GR	= $C050 ; Enable graphics
FULLGR	= $C052	; Full screen, no text
LORES	= $C056	; Enable LORES graphics

; monitor routines
GR	=	$F390

fire_demo:

	; GR part
	jsr	GR							; 3
	bit	FULLGR							; 3
								;==========
								;         6


	; Setup white line on bottom

	lda	#$ff							; 2
	ldy	#39							; 2
white_loop:
	sta	$7d0,Y			; hline 24 (46+47)		; 3
	dey								; 1
	bpl	white_loop						; 2
								;============
								;        10

fire_loop:

	ldx	#22			; 22				; 2

yloop:
	stx	TEMPY	; txa/pha not any better			; 2

	; Self-modify the inner loop so it loads/stores from proper
	; low-res address.  Generate the proper row memory address

	jsr	get_row							; 3
	sty	<smc_sta+1						; 2
	sta	<smc_sta+2						; 2

	inx								; 1

	jsr	get_row							; 3
	sty	<smc_lda+1						; 2
	sta	<smc_lda+2						; 2

	ldy	#39							; 2
xloop:
smc_lda:
	lda	$7d0,Y		; load value at row+1			; 3
	pha			; save on stack				; 1
	and	#$7		; mask off				; 2
	tax								; 1

	;=============================
	; random8
	;=============================
	; 8-bit 6502 Random Number Generator
	; Linear feedback shift register PRNG by White Flame
	; http://codebase64.org/doku.php?id=base:small_fast_8-bit_prng

random8:
	lda	SEEDL							; 2
	beq	doEor							; 2
	asl								; 1
	beq	noEor	; if the input was $80, skip the EOR		; 2
	bcc	noEor							; 2
doEor:	eor	#$1d							; 2
noEor:	sta	SEEDL							; 2

	; end inlined RNG

	ror			; shift into carry			; 1

	pla								; 1

	bcs	no_change						; 2

	.byte	$2c	; BIT trick, nops out next instruction		; 1
no_change:
	lda	<(color_progression),X					; 2

smc_sta:
	sta	$750,Y							; 3
	dey								; 1
	bpl	xloop							; 2

	ldx	TEMPY							; 2

	dex								; 1
	bpl	yloop							; 2

	bmi	fire_loop						; 2


color_progression:
	.byte	$00	; 8->0		; 1000 0101
	.byte	$bb	; 9->11		; 1001 0001
	.byte	$00	; 10->0		; 1010 0000
	.byte	$aa	; 11->10	; 1011 0000
	.byte	$00	; 12->0		; 1100 0000
	.byte	$99	; 13->9		; 1101 1001
	.byte	$00	; 14->0		; 1110 0000
	.byte	$dd	; 15->13	; 1111 1101




	; Take row X and convert to address A:Y
get_row:
	; get low byte

	; 000X X00O
	;	lsr
	; 0000 XX00   O
	;      adc #1
	; 0000 XXOx
	; lsr
	; 0000 0XXO
	; lsr
	; 0000 00XX   O
	; ror

	txa								; 1
	and	#$19							; 2
	lsr								; 1
	adc	#1							; 2
	lsr								; 1
	lsr								; 1
	tay								; 1
	lda	<low_offsets,Y						; 2
	ror								; 1
	tay								; 1
								;===========
								;        13


	; high byte of store address
	txa								; 1
	and	#$7							; 2
	lsr								; 1
	ora	#$4							; 2
								;===========
								;	  6

	rts								; 1


	; 14+6 = 20, as opposed to full lookup table which would be
	; at least 24
	; down to 13+3 at the expense of readability

	; these are shifted left by one due to the algorithm
low_offsets:
	.byte	$00,$50,$a0


