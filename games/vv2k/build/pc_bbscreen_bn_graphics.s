
@{{BLOCK(pc_bbscreen_bn_graphics)

@=======================================================================
@
@	pc_bbscreen_bn_graphics, 256x256@4, 
@	+ palette 16 entries, not compressed
@	+ 42 tiles (t|f|p reduced) not compressed
@	+ regular map (flat), not compressed, 32x32 
@	Total size: 32 + 1344 + 2048 = 3424
@
@	Time-stamp: 2021-11-24, 02:02:34
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global pc_bbscreen_bn_graphicsTiles		@ 1344 unsigned chars
	.hidden pc_bbscreen_bn_graphicsTiles
pc_bbscreen_bn_graphicsTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x555556EE
	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0xBEE55555
	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55BEE555
	.word 0x555556EE,0x555556EE,0x555556EE,0x6DEEEDEE,0xEEEEEEEE,0xEEDBADEE,0xED5556EE,0xE65556EE
	.word 0x55555555,0x55555555,0x55555555,0xEEEEE555,0xEEEEB555,0xD655555D,0x5555555E,0xEEED555E
	.word 0xBEE55555,0xBEE55555,0xBEE55555,0xBEE555BE,0xBEE556EE,0xBEE55DEE,0xBEE55DED,0xBEE55DEE

	.word 0x55BEE555,0x55BEE555,0x55BEE555,0x55BEE555,0x55BEE555,0x55BEE555,0x55BEE555,0x55BEE555
	.word 0x55555555,0x555AEED5,0x555AEEE5,0x555AEEE5,0x555AEEE5,0x555AEEE5,0xEEEEEEE5,0xEEEEEEE5
	.word 0xE65556EE,0xED5556EE,0xEEDA6DEE,0xEEEEEEEE,0x6DEEEEDE,0x55555555,0xDEED55DE,0xEEED6EEE
	.word 0xEEEED55E,0x6ADEEA5E,0x55AEED5D,0xEEEEE655,0xEEEEB555,0x55555555,0xEB5DEEEE,0xEEDBEEEE
	.word 0xBEE55DEE,0xDEE55DED,0xEEE55DED,0xEED56EEE,0xED55DEED,0x55555555,0x556DEEEE,0x56EEEEEE
	.word 0x55BEE555,0x55DEE555,0x5AEEE55A,0x5EEED55E,0x5EED555E,0x55555555,0x6DEEEEED,0xEEEEEEEE
	.word 0x55555555,0x555DEED5,0x555DEED5,0x555DEED5,0x555DEED5,0x555DEED5,0xB55DEED5,0xEA5DEED5
	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0xED55DEEE,0xEED55DEE

	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0xD55DEEEE,0xD5EEEEEE
	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0xE5555DEE,0xE5555DEE
	.word 0x55555555,0x55555555,0x55555555,0x5EED5555,0x5EEEA555,0x5EEEA555,0xEEEEEEEE,0xEEEEEEEE
	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x555556EE,0x555556EE
	.word 0xEEEEEEE5,0x555AEEE5,0x555AEEE5,0x555AEEE5,0x555AEEE5,0x555AEEE5,0x555AEEE5,0xEEEEEEE5
	.word 0xEEEDDEEE,0xEEEEEEED,0xDEEEEEE5,0xDEEEEEE5,0xDEEEEEE5,0xDEEEEEE5,0xDEEDEEED,0xDEEDDEEE
	.word 0xEEEDEEEE,0xDEEE555B,0x6EEEA555,0xEEEED555,0xEEEED555,0xAEEEB555,0xDEEE5555,0xEEED5555
	.word 0x5EEEEEEE,0xBEEEA555,0xDEED5555,0xEEEEEEEE,0xEEEEEEEE,0xEDAAAAAA,0xEDAD5555,0xEADEEEEE

	.word 0xEEEEEEEE,0xEED55555,0xEEEEEEDA,0xEEEEEEEE,0xEEEEEEEE,0xEEA556EE,0xEED555EE,0xEEEEEEEE
	.word 0xEE6DEEDD,0xEEEDEEDD,0xEEEEEEDE,0xEEEEEEDE,0xEEEEEEDE,0xEE6EEEDE,0xEB5DEEDE,0xD55DEEDE
	.word 0xEEED55DE,0xDEEE555E,0x6EEEA556,0x5EEED55D,0x5EEED56E,0x5EEEA5EE,0xDEEE5DEE,0xEEED6EEE
	.word 0xDDEEEEEE,0xDEEED555,0xEEEE5555,0xEEEE5555,0xEEEE5555,0xEEEE6555,0xDEEED555,0xDDEEEEEE
	.word 0xE5555DEE,0xE5555DEE,0xE5555DEE,0xE5555DEE,0xE5555DEE,0xE5555DEE,0xED555EEE,0xEEEEEEEE
	.word 0xDEEEEDEE,0x5EEEAAEE,0x5EEEAAEE,0x5EEEAAEE,0x5EEEAAEE,0x5EEEAAEE,0x6EEE6AEE,0xEEEE5AEE
	.word 0x555556DD,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555DEE
	.word 0xEEEEEEE5,0xEEEEDEE5,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555

	.word 0xDEED5EEE,0xDEED55DE,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0xEEE55555,0xED555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0xE6EEEEEE,0x65DEEEEE,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0xEEEEEEEE,0xEDDEEEED,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0x655DEEEE,0x555DEEEE,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0xEEE5EEEE,0xED5DEEEB,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0x55EEEEEE,0x555DEEEE,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0xEEEEEEEE,0xEDEEEEE6,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555

	.word 0xEEED5AEE,0xEED55AEE,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0x55555DEE,0x55555DEE,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555

	.section .rodata
	.align	2
	.global pc_bbscreen_bn_graphicsMap		@ 2048 unsigned chars
	.hidden pc_bbscreen_bn_graphicsMap
pc_bbscreen_bn_graphicsMap:
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0002,0x0001,0x0003,0x0004
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0005,0x0006,0x0007,0x0008
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0009,0x000A,0x000B,0x000C,0x000D
	.hword 0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0014,0x0015,0x0016,0x0017,0x0018
	.hword 0x0019,0x001A,0x001B,0x001C,0x001D,0x001E,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x001F,0x0020,0x0021,0x0022,0x0023
	.hword 0x0024,0x0025,0x0026,0x0027,0x0028,0x0029,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.section .rodata
	.align	2
	.global pc_bbscreen_bn_graphicsPal		@ 32 unsigned chars
	.hidden pc_bbscreen_bn_graphicsPal
pc_bbscreen_bn_graphicsPal:
	.hword 0x0000,0x1442,0x1C62,0x0865,0x1086,0x2083,0x24A5,0x14A8
	.hword 0x14E9,0x110A,0x216D,0x29D0,0x75EB,0x3613,0x7FFF,0x0000

@}}BLOCK(pc_bbscreen_bn_graphics)