
@{{BLOCK(pc_highlight_bn_graphics)

@=======================================================================
@
@	pc_highlight_bn_graphics, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2022-03-10, 17:41:44
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global pc_highlight_bn_graphicsTiles		@ 128 unsigned chars
	.hidden pc_highlight_bn_graphicsTiles
pc_highlight_bn_graphicsTiles:
	.word 0xEEFFEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0xCCCCCCCC,0xBBBBBBBB,0xABBABAAB,0x99999999
	.word 0xEEEEFEEE,0xEEEEEEEE,0xDDDDDDDD,0xCCDCCDDD,0xCCCCCCCC,0xBBBBBBCC,0xAAAAAAAA,0x99999999
	.word 0x88898888,0x77777777,0x65655556,0x55555555,0x44444444,0x22242424,0x33333333,0x11111111
	.word 0x78777789,0x77777777,0x55555555,0x54555555,0x44444444,0x22222222,0x33333333,0x11111111

	.section .rodata
	.align	2
	.global pc_highlight_bn_graphicsPal		@ 32 unsigned chars
	.hidden pc_highlight_bn_graphicsPal
pc_highlight_bn_graphicsPal:
	.hword 0x0000,0x6961,0x6980,0x6982,0x69A4,0x69C5,0x6DC4,0x6DE6
	.hword 0x69E8,0x6E07,0x6E09,0x6E28,0x6E2A,0x6E4B,0x726C,0x6E8C

@}}BLOCK(pc_highlight_bn_graphics)
