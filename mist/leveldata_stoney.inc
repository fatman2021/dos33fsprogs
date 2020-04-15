
;===============================================
; level data for Stoney Ship
;===============================================

locations:
	.word location0, location1, location2, location3
	.word location4

; STONEY_SHIP_STERN		-- back of the ship
location0:
	.byte	STONEY_SHIP_BOW		; north exit
	.byte	STONEY_SHIP_DOOR_CLOSED	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	ship_entry_n_lzsa	; north bg
	.word	ship_entry_s_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	$ff
;	.byte	DIRECTION_E	; special exit
;	.byte	12,25		; special x
;	.byte	26,46		; special y
;	.word	controls_pressed-1		; special function

; STONY_SHIP_BOW		-- bow of the ship
location1:
	.byte	$ff			; north exit
	.byte	STONEY_SHIP_STERN	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	$ff		; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	ship_bow_go_n_lzsa		; north bg
	.word	ship_bow_s_lzsa			; south bg
	.word	$0000				; east bg
	.word	$0000				; west bg
	.byte	BG_NORTH | BG_SOUTH
	.byte	DIRECTION_N		; special exit
	.byte	9,29		; special x
	.byte	2,46		; special y
	.word	back_to_mist-1	; special function

; STONEY_SHIP_DOOR_CLOSED		-- ship cabin door
location2:
	.byte	STONEY_SHIP_BOW		; north exit
	.byte	STONEY_SHIP_DOOR_OPEN	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	ship_entry_n_lzsa		; north bg
	.word	ship_door_closed_s_lzsa		; south bg
	.word	$0000				; east bg
	.word	$0000				; west bg
	.byte	BG_SOUTH|BG_NORTH
	.byte	$ff		; special exit

; STONEY_SHIP_DOOR_OPEN			-- ship cabin door open
location3:
	.byte	STONEY_SHIP_BOW		; north exit
	.byte	STONEY_SHIP_CHAIR	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	ship_entry_n_lzsa		; north bg
	.word	ship_door_open_s_lzsa		; south bg
	.word	$0000				; east bg
	.word	$0000				; west bg
	.byte	BG_SOUTH|BG_NORTH
	.byte	$ff		; special exit

; STONEY_SHIP_CHAIR			-- chair in the cabin
location4:
	.byte	STONEY_SHIP_STERN	; north exit
;	.byte	STONEY_SHIP_BOOK_CLOSED	; south exit
	.byte	$ff
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	book_chair_n_lzsa		; north bg
	.word	book_chair_s_lzsa		; south bg
	.word	$0000				; east bg
	.word	$0000				; west bg
	.byte	BG_SOUTH|BG_NORTH
	.byte	$ff		; special exit