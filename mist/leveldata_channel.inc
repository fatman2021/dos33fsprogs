;===============================================
; level data for Channely Wood
;===============================================

locations:
	.word location0, location1, location2, location3
	.word location4, location5, location6, location7
	.word location8, location9, location10,location11
	.word location12,location13,location14,location15
	.word location16,location17,location18,location19
	.word location20,location21,location22,location23
	.word location24,location25,location26,location27
	.word location28,location29,location30,location31
	.word location32,location33,location34,location35
	.word location36,location37,location38,location39
	.word location40,location41,location42,location43
	.word location44

; CHANNEL_ARRIVAL		-- arrival in channelwood
location0:
	.byte	CHANNEL_PATH2		; north exit
	.byte	$ff			; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	arrival_n_lzsa		; north bg
	.word	arrival_s_lzsa		; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_SOUTH|BG_NORTH
	.byte	$ff

; CHANNEL_PATH2		-- twisty maze of passages all alike
location1:
	.byte	CHANNEL_PATH6		; north exit
	.byte	CHANNEL_ARRIVAL		; south exit
	.byte	CHANNEL_PATH3		; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	DIRECTION_E	; east exit_dir
	.byte	$ff		; west exit_dir
	.word	path2_n_lzsa		; north bg
	.word	path2_s_lzsa		; south bg
	.word	path2_e_lzsa		; east bg
	.word	$0000			; west bg
	.byte	BG_SOUTH|BG_NORTH|BG_EAST
	.byte	DIRECTION_N	; special exit
	.byte	19,24		; special x
	.byte	36,44		; special y
	.word	goto_valve6-1	; special function

; CHANNEL_PATH3		-- twisty maze of passages all alike
location2:
	.byte	CHANNEL_PATH4		; north exit
	.byte	$ff			; south exit
	.byte	CHANNEL_BRIDGE		; east exit
	.byte	CHANNEL_PATH2		; west exit
	.byte	DIRECTION_W	; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	DIRECTION_E	; east exit_dir
	.byte	DIRECTION_S	; west exit_dir
	.word	path3_n_lzsa		; north bg
	.word	$0000			; south bg
	.word	path3_e_lzsa		; east bg
	.word	path3_w_lzsa		; west bg
	.byte	BG_NORTH|BG_WEST|BG_EAST
	.byte	$ff

; CHANNEL_BRIDGE	-- raisable bridge
location3:
	.byte	$ff			; north exit
	.byte	$ff			; south exit
	.byte	$ff			; east exit
	.byte	CHANNEL_PATH3		; west exit
	.byte	$ff		; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	DIRECTION_E	; east exit_dir
	.byte	DIRECTION_W	; west exit_dir
	.word	$0000			; north bg
	.word	$0000			; south bg
	.word	bridge_down_e_lzsa	; east bg
	.word	bridge_w_lzsa		; west bg
	.byte	BG_WEST|BG_EAST
	.byte   DIRECTION_E	; special exit
	.byte	14,20	; special x
	.byte	28,36	; special y
	.word	raise_bridge-1

; CHANNEL_PATH4		-- twisty maze of passages all alike
location4:
	.byte	$ff			; north exit
	.byte	CHANNEL_PATH3		; south exit
	.byte	$ff			; east exit
	.byte	CHANNEL_PATH5		; west exit
	.byte	$ff		; north exit_dir
	.byte	DIRECTION_E	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	DIRECTION_N	; west exit_dir
	.word	$0000			; north bg
	.word	path4_s_lzsa		; south bg
	.word	path4_e_lzsa		; east bg
	.word	path4_w_lzsa		; west bg
	.byte	BG_SOUTH|BG_WEST|BG_EAST
	.byte	DIRECTION_W	; special exit
	.byte	19,24		; special x
	.byte	36,44		; special y
	.word	goto_valve3-1	; special function

; CHANNEL_PATH5		-- twisty maze of passages all alike
location5:
	.byte	CHANNEL_PATH7		; north exit
	.byte	CHANNEL_PATH6		; south exit
	.byte	CHANNEL_PATH4		; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	DIRECTION_E	; east exit_dir
	.byte	$ff		; west exit_dir
	.word	path5_n_lzsa		; north bg
	.word	path5_s_lzsa		; south bg
	.word	path5_e_lzsa		; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH|BG_EAST
	.byte	DIRECTION_S|DIRECTION_N	; special exit
	.byte	16,24		; special x	19,24N  16,20S
	.byte	26,44		; special y	38,44N  26,32S
	.word	goto_path5_valve-1	; special function


; CHANNEL_PATH6		-- twisty maze of passages all alike
location6:
	.byte	CHANNEL_PATH5		; north exit
	.byte	CHANNEL_PATH2		; south exit
	.byte	$ff			; east exit
	.byte	CHANNEL_FORK		; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	DIRECTION_S	; west exit_dir
	.word	path6_n_lzsa		; north bg
	.word	path6_s_lzsa		; south bg
	.word	$0000			; east bg
	.word	path6_w_lzsa		; west bg
	.byte	BG_NORTH|BG_WEST|BG_SOUTH
	.byte	DIRECTION_N|DIRECTION_W|DIRECTION_S	; special exit
	.byte	17,21		; special x	17,21N  17,21S	17,21W
	.byte	26,46		; special y	40,46N  26,32S	26,32W
	.word	goto_path6_valve-1	; special function


; CHANNEL_FORK		-- forked path
location7:
	.byte	CHANNEL_PATH6		; north exit
	.byte	CHANNEL_PIPE_BRIDGE2	; south exit
	.byte	$ff			; east exit
	.byte	CHANNEL_BEFORE_ELEV1	; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_W	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	DIRECTION_W	; west exit_dir
	.word	fork_n_lzsa		; north bg
	.word	fork_s_lzsa		; south bg
	.word	$0000			; east bg
	.word	fork_w_lzsa		; west bg
	.byte	BG_NORTH|BG_WEST|BG_SOUTH
	.byte	DIRECTION_N	; special exit
	.byte	19,25		; special x
	.byte	38,46		; special y
	.word	goto_valve4-1	; special function

; CHANNEL_BEFORE_ELEV1		-- just befor elevator 1
location8:
	.byte	$ff			; north exit
	.byte	$ff			; south exit
	.byte	CHANNEL_FORK		; east exit
	.byte	CHANNEL_ELEV1_OPEN	; west exit
	.byte	$ff		; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	DIRECTION_N	; east exit_dir
	.byte	DIRECTION_W	; west exit_dir
	.word	$0000			; north bg
	.word	$0000			; south bg
	.word	before_elev1_e_lzsa	; east bg
	.word	before_elev1_w_lzsa	; west bg
	.byte	BG_EAST|BG_WEST
	.byte	$ff

; CHANNEL_IN_ELEV1_OPEN		-- inside elevator1, door open
location9:
	.byte	$ff			; north exit
	.byte	$ff			; south exit
	.byte	CHANNEL_BEFORE_ELEV1	; east exit
	.byte	$ff			; west exit
	.byte	$ff		; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	DIRECTION_E	; east exit_dir
	.byte	$ff		; west exit_dir
	.word	$0000			; north bg
	.word	$0000			; south bg
	.word	elevator1_open_lzsa	; east bg
	.word	$0000			; west bg
	.byte	BG_EAST
	.byte	DIRECTION_E	; special exit
	.byte	10,17		; special x
	.byte	6,46		; special y
	.word	elev1_close_door-1	; special function


; CHANNEL_PIPE_BRIDGE2		-- east side of pipe bridge
location10:
	.byte	$ff			; north exit
	.byte	$ff			; south exit
	.byte	CHANNEL_FORK		; east exit
	.byte	$ff			; west exit
	.byte	$ff		; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	DIRECTION_N	; east exit_dir
	.byte	$ff		; west exit_dir
	.word	$0000			; north bg
	.word	$0000			; south bg
	.word	pipe_bridge2_e_lzsa	; east bg
	.word	pipe_bridge2_w_lzsa	; west bg
	.byte	BG_EAST|BG_WEST
	.byte	$ff

; CHANNEL_STEPS_FORK		-- fork going to steps
location11:
	.byte	CHANNEL_WIND_PATH	; north exit
	.byte	CHANNEL_PATH7		; south exit
	.byte	$ff			; east exit
	.byte	CHANNEL_STEPS_PATH	; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	DIRECTION_W	; west exit_dir
	.word	steps_fork_n_lzsa	; north bg
	.word	steps_fork_s_lzsa	; south bg
	.word	$0000			; east bg
	.word	steps_fork_w_lzsa	; west bg
	.byte	BG_NORTH|BG_SOUTH|BG_WEST
	.byte	DIRECTION_N	; special exit
	.byte	18,25		; special x
	.byte	38,46		; special y
	.word	goto_valve1-1	; special function

; CHANNEL_STEPS_PATH		-- path going to steps
location12:
	.byte	$ff			; north exit
	.byte	$ff			; south exit
	.byte	CHANNEL_STEPS_FORK	; east exit
	.byte	CHANNEL_STEPS_DOOR	; west exit
	.byte	$ff		; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	DIRECTION_N	; east exit_dir
	.byte	DIRECTION_W	; west exit_dir
	.word	$0000			; north bg
	.word	$0000			; south bg
	.word	steps_path_e_lzsa	; east bg
	.word	steps_path_w_lzsa	; west bg
	.byte	BG_EAST|BG_WEST
	.byte	$ff

; CHANNEL_STEPS_DOOR		-- door to the steps
location13:
	.byte	$ff			; north exit
	.byte	$ff			; south exit
	.byte	CHANNEL_STEPS_PATH	; east exit
	.byte	$ff			; west exit
	.byte	$ff		; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	DIRECTION_E	; east exit_dir
	.byte	$ff		; west exit_dir
	.word	$0000			; north bg
	.word	$0000			; south bg
	.word	steps_door_e_lzsa	; east bg
	.word	steps_door_w_lzsa	; west bg
	.byte	BG_EAST|BG_WEST
	.byte	DIRECTION_W	; special exit
	.byte	13,27		; special x
	.byte	4,42		; special y
	.word	climb_steps-1		; special function

; CHANNEL_WIND_PATH		-- path to windmill
location14:
	.byte	CHANNEL_WIND_PATH2	; north exit
	.byte	CHANNEL_STEPS_FORK	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	wind_path_n_lzsa	; north bg
	.word	wind_path_s_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	DIRECTION_S	; special exit
	.byte	25,31		; special x
	.byte	24,32		; special y
	.word	goto_valve1-1	; special function


; CHANNEL_WIND_PATH2		-- path to windmill too
location15:
	.byte	CHANNEL_ISLAND1		; north exit
	.byte	CHANNEL_WIND_PATH	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	wind_path2_n_lzsa	; north bg
	.word	wind_path2_s_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	$ff

; CHANNEL_ISLAND1		-- island part1
location16:
	.byte	CHANNEL_ISLAND2		; north exit
	.byte	CHANNEL_WIND_PATH2	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	island1_n_lzsa		; north bg
	.word	island1_s_lzsa		; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	$ff

; CHANNEL_ISLAND2		-- island part2
location17:
	.byte	CHANNEL_ISLAND3		; north exit
	.byte	CHANNEL_ISLAND1		; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	island2_n_lzsa		; north bg
	.word	island2_s_lzsa		; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	$ff

; CHANNEL_ISLAND3		-- island part3
location18:
	.byte	CHANNEL_SHACK		; north exit
	.byte	CHANNEL_ISLAND2		; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	island3_n_lzsa		; north bg
	.word	island3_s_lzsa		; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	$ff

; CHANNEL_SHACK			-- island shack
location19:
	.byte	CHANNEL_TANK		; north exit
	.byte	CHANNEL_ISLAND3		; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	shack_n_lzsa		; north bg
	.word	shack_s_lzsa		; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	$ff

; CHANNEL_TANK			-- inside shack
location20:
	.byte	CHANNEL_WINDMILL	; north exit
	.byte	CHANNEL_SHACK		; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	tank_n_lzsa		; north bg
	.word	tank_s_lzsa		; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	DIRECTION_N	; special exit
	.byte	25,32		; special x
	.byte	40,46		; special y
	.word	look_at_faucet-1		; special function

; CHANNEL_TANK_CLOSE		-- the faucet
location21:
	.byte	CHANNEL_TANK		; north exit
	.byte	$ff			; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	tank_close_lzsa		; north bg
	.word	$0000			; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH
	.byte	DIRECTION_N	; special exit
	.byte	15,25		; special x
	.byte	18,32		; special y
	.word	toggle_faucet-1	; special function

; CHANNEL_WINDMILL		-- windmill machinery
location22:
	.byte	CHANNEL_OUT_BACK	; north exit
	.byte	CHANNEL_TANK		; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	windmill_n_lzsa		; north bg
	.word	windmill_s_lzsa		; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	DIRECTION_N	; special exit
	.byte	10,15		; special x
	.byte	30,38		; special y
	.word	toggle_windmill-1	; special function

; CHANNEL_OUT_BACK		-- back door of windmill
location23:
	.byte	$ff			; north exit
	.byte	CHANNEL_WINDMILL	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	$ff		; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	outback_n_lzsa		; north bg
	.word	outback_s_lzsa		; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	$ff

; CHANNEL_AFTER_BRIDGE1		-- after lift bridge
location24:
	.byte	$ff			; north exit
	.byte	$ff			; south exit
	.byte	CHANNEL_AFTER_BRIDGE2	; east exit
	.byte	CHANNEL_BRIDGE		; west exit
	.byte	$ff		; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	DIRECTION_E	; east exit_dir
	.byte	DIRECTION_W	; west exit_dir
	.word	$0000			; north bg
	.word	$0000			; south bg
	.word	after_bridge1_e_lzsa	; east bg
	.word	after_bridge1_w_lzsa	; west bg
	.byte	BG_EAST|BG_WEST
	.byte	$ff

; CHANNEL_AFTER_BRIDGE2		-- next after lift bridge
location25:
	.byte	$ff			; north exit
	.byte	$ff			; south exit
	.byte	CHANNEL_BOOK_FORK	; east exit
	.byte	CHANNEL_AFTER_BRIDGE1	; west exit
	.byte	$ff		; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	DIRECTION_N	; east exit_dir
	.byte	DIRECTION_W	; west exit_dir
	.word	$0000			; north bg
	.word	$0000			; south bg
	.word	after_bridge2_e_lzsa	; east bg
	.word	after_bridge2_w_lzsa	; west bg
	.byte	BG_EAST|BG_WEST
	.byte	$ff

; CHANNEL_BOOK_FORK		-- fork to book elevator
location26:
	.byte	CHANNEL_BOOK_ELEVATOR	; north exit
	.byte	CHANNEL_PIPE_EXTEND	; south exit
	.byte	$ff			; east exit
	.byte	CHANNEL_AFTER_BRIDGE2	; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	DIRECTION_W	; west exit_dir
	.word	book_fork_n_lzsa	; north bg
	.word	book_fork_s_lzsa	; south bg
	.word	$0000			; east bg
	.word	book_fork_w_lzsa	; west bg
	.byte	BG_NORTH|BG_SOUTH|BG_WEST
	.byte	$ff

; CHANNEL_PIPE_EXTEND		-- pipe extender
location27:
	.byte	CHANNEL_BOOK_FORK	; north exit
	.byte	$ff			; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	pipe_extend_n_lzsa	; north bg
	.word	pipe_extend_down_s_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	DIRECTION_S	; special exit
	.byte	17,24		; special x
	.byte	34,40		; special y
	.word	extend_pipe-1	; special function

; CHANNEL_BOOK_ELEVATOR		-- outside book elevator, door closed
location28:
	.byte	CHANNEL_BOOK_E_OPEN	; north exit
	.byte	CHANNEL_BOOK_FORK	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	book_elevator_closed_n_lzsa	; north bg
	.word	book_elevator_s_lzsa		; south bg
	.word	$0000				; east bg
	.word	$0000				; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	$ff		; special exit

; CHANNEL_E_OPEN		-- outside book elevator, door open
location29:
	.byte	CHANNEL_BOOK_E_INSIDE_GND	; north exit
	.byte	CHANNEL_BOOK_FORK	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_S	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	book_elevator_open_n_lzsa	; north bg
	.word	book_elevator_s_lzsa		; south bg
	.word	$0000				; east bg
	.word	$0000				; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	$ff		; special exit

; CHANNEL_BOOK_E_INSIDE_GND		-- inside book elevator, gnd, door open
location30:
	.byte	$ff			; north exit
	.byte	CHANNEL_BOOK_ELEVATOR	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	$ff		; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	$ff		; north bg
	.word	book_elevator_inside_gnd_open_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_SOUTH
	.byte	DIRECTION_S	; special exit
	.byte	10,17		; special x
	.byte	6,46		; special y
	.word	book_elevator_close_door-1	; special function

; CHANNEL_BOOK_E_IN_CLOSED		-- inside book elevator, door closed
location31:
	.byte	$ff			; north exit
	.byte	CHANNEL_BOOK_E_INSIDE_GND	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	$ff		; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	$ff		; north bg
	.word	book_elevator_inside_gnd_closed_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_SOUTH
	.byte	DIRECTION_S	; special exit
	.byte	28,34		; special x
	.byte	28,36		; special y
	.word	book_elevator_handle-1	; special function

; CHANNEL_BOOK_E_INSIDE_TOP		-- inside book elevator, top, door open
location32:
	.byte	$ff			; north exit
	.byte	CHANNEL_BOOK_ROOM	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	$ff		; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	$ff		; north bg
	.word	book_elevator_inside_top_open_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_SOUTH
	.byte	DIRECTION_S	; special exit
	.byte	10,17		; special x
	.byte	6,46		; special y
	.word	book_elevator_close_door-1	; special function

; CHANNEL_BOOK_ROOM		-- the room with the myst book
location33:
	.byte	CHANNEL_BOOK_E_INSIDE_TOP	; north exit
	.byte	$ff			; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_S	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	book_room_n_lzsa	; north bg
	.word	book_room_s_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_SOUTH|BG_NORTH
	.byte	DIRECTION_S	; special function
	.byte	15,23		; special x
	.byte	30,44		; special y
	.word	book_room_grab_book-1	; special function

; CHANNEL_BOOK_CLOSED		-- myst book closed
location34:
	.byte	CHANNEL_BOOK_E_INSIDE_TOP	; north exit
	.byte	CHANNEL_BOOK_OPEN	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_S	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	book_room_n_lzsa	; north bg
	.word	book_mist_closed_s_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_SOUTH|BG_NORTH
	.byte	$ff		; special function

; CHANNEL_BOOK_OPEN		-- myst book open
location35:
	.byte	CHANNEL_BOOK_E_INSIDE_TOP	; north exit
	.byte	CHANNEL_BOOK_ROOM	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_S	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	book_room_n_lzsa	; north bg
	.word	book_mist_open_s_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_SOUTH|BG_NORTH
	.byte   DIRECTION_S
	.byte	24,32		; special x
	.byte	12,22		; special y
	.word	mist_link_book-1	; special function

; CHANNEL_ELEV1_OPEN		-- outside elevator1, open
location36:
	.byte	$ff			; north exit
	.byte	$ff			; south exit
	.byte	CHANNEL_FORK		; east exit
	.byte	CHANNEL_IN_ELEV1_OPEN	; west exit
	.byte	$ff		; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	DIRECTION_N	; east exit_dir
	.byte	DIRECTION_E	; west exit_dir
	.word	$0000				; north bg
	.word	$0000				; south bg
	.word	before_elev1_e_lzsa		; east bg
	.word	before_elev1_open_w_lzsa	; west bg
	.byte	BG_WEST|BG_EAST
	.byte	$ff

; CHANNEL_IN_ELEV1_CLOSED	-- inside elevator1, closed
location37:
	.byte	$ff			; north exit
	.byte	$ff			; south exit
	.byte	CHANNEL_IN_ELEV1_OPEN	; east exit
	.byte	$ff			; west exit
	.byte	$ff		; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	DIRECTION_E	; east exit_dir
	.byte	$ff		; west exit_dir
	.word	$0000			; north bg
	.word	$0000			; south bg
	.word	elevator1_closed_lzsa	; east bg
	.word	$0000			; west bg
	.byte	BG_EAST
	.byte	DIRECTION_E	; special exit
	.byte	26,34		; special x
	.byte	28,36		; special y
	.word	elev1_handle-1	; special function

; CHANNEL_VALVE1_ELEVATOR2	-- valve for elevator2
location38:
	.byte	CHANNEL_STEPS_FORK	; north exit
	.byte	CHANNEL_WIND_PATH	; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	valve_bottom_off_lzsa	; north bg
	.word	valve_top_off_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	DIRECTION_N|DIRECTION_S	; special exit
	.byte	15,25		; special x
	.byte	14,34		; special y
	.word	handle_valve1-1	; special function

; CHANNEL_VALVE2_TREE		-- valve by the big tree
location39:
	.byte	CHANNEL_PATH5		; north exit
	.byte	CHANNEL_PATH7		; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	valve_bottom_off_lzsa	; north bg
	.word	valve_top_off_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	DIRECTION_N|DIRECTION_S	; special exit
	.byte	15,25		; special x
	.byte	14,34		; special y
	.word	handle_valve2-1	; special function

; CHANNEL_VALVE3_BROKEN	-- valve to broken pipe
location40:
	.byte	$ff			; north exit
	.byte	$ff			; south exit
	.byte	$ff			; east exit
	.byte	CHANNEL_PATH4		; west exit
	.byte	$ff		; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	DIRECTION_W	; west exit_dir
	.word	$0000			; north bg
	.word	$0000			; south bg
	.word	$0000			; east bg
	.word	valve_bottom_off_lzsa	; west bg
	.byte	BG_WEST
	.byte	DIRECTION_W	; special exit
	.byte	15,25		; special x
	.byte	14,34		; special y
	.word	handle_valve3-1	; special function

; CHANNEL_VALVE4_ELEVATOR1	-- valve for elevator1/pipe bridge
location41:
	.byte	CHANNEL_FORK		; north exit
	.byte	$ff			; south exit
	.byte	$ff			; east exit
	.byte	CHANNEL_PATH6		; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	$ff		; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	DIRECTION_W	; west exit_dir
	.word	valve_bottom_off_lzsa	; north bg
	.word	$0000			; south bg
	.word	$0000			; east bg
	.word	valve_top_off_lzsa	; west bg
	.byte	BG_NORTH|BG_WEST
	.byte	DIRECTION_N|DIRECTION_W	; special exit
	.byte	15,25		; special x
	.byte	14,34		; special y
	.word	handle_valve4-1	; special function

; CHANNEL_VALVE5_FORK	-- valve at major fork
location42:
	.byte	CHANNEL_PATH6		; north exit
	.byte	CHANNEL_PATH5		; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	valve_bottom_off_lzsa	; north bg
	.word	valve_top_off_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	DIRECTION_N|DIRECTION_S	; special exit
	.byte	15,25		; special x
	.byte	14,34		; special y
	.word	handle_valve5-1	; special function

; CHANNEL_VALVE6_ENTRY	-- valve at entry
location43:
	.byte	CHANNEL_PATH2		; north exit
	.byte	CHANNEL_PATH6		; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	valve_bottom_off_lzsa	; north bg
	.word	valve_top_off_lzsa	; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	DIRECTION_N|DIRECTION_S	; special exit
	.byte	15,25		; special x
	.byte	14,34		; special y
	.word	handle_valve6-1	; special function

; CHANNEL_PATH7		-- filling in a gap
location44:
	.byte	CHANNEL_STEPS_FORK	; north exit
	.byte	CHANNEL_PATH5		; south exit
	.byte	$ff			; east exit
	.byte	$ff			; west exit
	.byte	DIRECTION_N	; north exit_dir
	.byte	DIRECTION_S	; south exit_dir
	.byte	$ff		; east exit_dir
	.byte	$ff		; west exit_dir
	.word	path7_n_lzsa		; north bg
	.word	path7_s_lzsa		; south bg
	.word	$0000			; east bg
	.word	$0000			; west bg
	.byte	BG_NORTH|BG_SOUTH
	.byte	DIRECTION_S	; special exit
	.byte	17,21		; special x
	.byte	26,30		; special y
	.word	goto_valve2-1	; special function
