; draw/move our friend

friend_out:		.byte	0
friend_x:		.byte	0
friend_y:		.byte	0
friend_state:		.byte	0
friend_gait:		.byte	0
friend_direction:	.byte	0
friend_gun:		.byte	0

F_STANDING	= 0
F_WALKING	= 1
F_RUNNING	= 2
F_CROUCHING	= 3
F_TURNING	= 4

	;=======================================
	; Move friend based on current state
	;

move_friend:

	lda	friend_state
	beq	done_move_friend

	lda	friend_state

	cmp	#F_WALKING
	beq	move_friend_walking
	cmp	#F_RUNNING
	beq	move_friend_running

done_move_friend:
	rts

	;======================
	; walking

move_friend_walking:
	inc	friend_gait	; cycle through animation

	lda     friend_gait
	and     #$f
	cmp     #$8			; only walk roughly 1/8 of time
	bne     friend_no_move_walk

	lda	friend_direction
	beq	f_walk_left

	inc	friend_x		; walk right
	rts
f_walk_left:
	dec     friend_x		; walk left
friend_no_move_walk:
	rts

	;======================
	; running
move_friend_running:
	inc	friend_gait	; cycle through animation

	lda     friend_gait
	and     #$3
	cmp     #$2			; only run roughly 1/4 of time
	bne     friend_no_move_run

	lda	friend_direction
	beq	f_run_left

	inc	friend_x		; run right
	rts
f_run_left:
	dec	friend_x		; run left
friend_no_move_run:
	rts

	;======================
	; standing

move_friend_standing:





fstate_table_lo:
	.byte <friend_standing	; 00
	.byte <friend_walking	; 01
	.byte <friend_running	; 02
	.byte <friend_crouching	; 03
	.byte <friend_turning	; 04

fstate_table_hi:
	.byte >friend_standing	; 00
	.byte >friend_walking	; 01
	.byte >friend_running	; 02
	.byte >friend_crouching	; 03
	.byte >friend_turning	; 04

; Urgh, make sure this doesn't end up at $FF or you hit the
;	NMOS 6502 bug

.align 2

fjump:
	.word	$0000

.align 1

;======================================
; draw friend
;======================================

draw_friend:

	lda	friend_out
	beq	no_friend

	lda	friend_state
	tay
	lda	fstate_table_lo,y
	sta	fjump
	lda	fstate_table_hi,y
	sta	fjump+1
	jmp	(fjump)

no_friend:
	rts

;==================================
; STANDING
;==================================

friend_standing:

	lda	#<friend_stand
	sta	INL

	lda	#>friend_stand
	sta	INH

	jmp	finally_draw_friend


;===================================
; CROUCHING
;===================================

friend_crouching:

	; FIXME: we have an animation?

	lda	#<friend_crouch2
	sta	INL

	lda	#>friend_crouch2
	sta	INH

	jmp	finally_draw_friend


;===============================
; Walking
;================================

friend_walking:
	lda	friend_gait
	cmp	#64
	bcc	friend_gait_fine	; blt

	lda	#0
	sta	friend_gait

friend_gait_fine:
	lsr
	lsr
	and	#$fe

	tay

	lda	friend_walk_progression,Y
	sta	INL

	lda	friend_walk_progression+1,Y
	sta	INH

	jmp	finally_draw_friend

;===============================
; Running
;================================

friend_running:
	lda	friend_gait
	cmp	#32
	bcc	friend_run_gait_fine	; blt

	lda	#0
	sta	friend_gait

friend_run_gait_fine:
	lsr
	and	#$fe

	tay

	lda	friend_run_progression,Y
	sta	INL

	lda	friend_run_progression+1,Y
	sta	INH

	jmp	finally_draw_friend

;===============================
; Turning
;================================

friend_turning:

	dec	friend_gait
	bpl	friend_draw_turning

	lda	#0
	sta	friend_gait

	; switch direction
	lda	friend_direction
	eor	#$1
	sta	friend_direction

	lda	#F_WALKING
	sta	friend_state

friend_draw_turning:
	lda	#<friend_turning_sprite
	sta	INL

	lda	#>friend_turning_sprite
	sta	INH

	jmp	finally_draw_friend


;=============================
; Actually Draw Alien
;=============================


finally_draw_friend:
	lda	friend_x
	sta	XPOS

	lda	friend_y
	sta	YPOS

	lda	friend_direction
	bne	friend_facing_right

friend_facing_left:
        jmp	put_sprite_crop

friend_facing_right:
	jmp	put_sprite_flipped_crop
