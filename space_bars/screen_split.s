; how quickly can we call this?
; jump table, assuming size to split is in Y?

; Autogenerate?  As we want both HGR/TXT and HGR/GR versions?


; 4  NnNnNnNnNnNnNnNnBBBBbbbbNnNnNnNnNnNnNnNnRrrrrr
; 8  NnNnNnNnNnNnNnBBBBNnNnbbbbNnNnNnNnNnNnNnRrrrrr
; 12 NnNnNnNnNnNnBBBBNnNnNnNnbbbbNnNnNnNnNnNnRrrrrr
; 16 NnNnNnNnNnBBBBNnNnNnNnNnNnbbbbNnNnNnNnNnRrrrrr
; 20 NnNnNnNnBBBBNnNnNnNnNnNnNnNnbbbbNnNnNnNnRrrrrr
; 24 NnNnNnBBBBNnNnNnNnNnNnNnNnNnNnbbbbNnNnNnRrrrrr
; 28 NnNnBBBBNnNnNnNnNnNnNnNnNnNnNnNnbbbbNnNnRrrrrr
; 32 NnBBBBNnNnNnNnNnNnNnNnNnNnNnNnNnNnbbbbNnRrrrrr
; 36 BBBBNnNnNnNnNnNnNnNnNnNnNnNnNnNnNnNnbbbbRrrrrr




split_4:
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	bit	LORES
	bit	HIRES
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	rts

split_8:
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	bit	LORES
	nop
	nop
	bit	HIRES
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	rts



	;       6       4       25+16+8+16  NNNNNNNN
        ;       7       6       25+15+10+15 LNNNNNN
        ;       8       8       25+14+12+14 NNNNNNN
        ;       9       10      25+13+14+13 LNNNNN
        ;       10      12      25+12+16+12
        ;       11      14      25+11+18+11
        ;       12      16      25+10+20+10
        ;       13      18      25+09+22+09
        ;       14      20      25+08+24+08
        ;       15      22      25+07+26+07
        ;       16      24      25+06+28+06
        ;       17      26      25+05+30+05
        ;       18      28      25+04+32+04
        ;       19      30      25+03+34+03
        ;       20      32      25+02+36+02
        ;       21      34      25+01+38+01

