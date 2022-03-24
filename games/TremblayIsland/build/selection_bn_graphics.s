
@{{BLOCK(selection_bn_graphics)

@=======================================================================
@
@	selection_bn_graphics, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2022-03-24, 04:15:58
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global selection_bn_graphicsTiles		@ 128 unsigned chars
	.hidden selection_bn_graphicsTiles
selection_bn_graphicsTiles:
	.word 0x33333330,0x11111113,0x00000013,0x00000013,0x00000013,0x00000013,0x00000013,0x00000013
	.word 0x03333333,0x31111111,0x32000000,0x32000000,0x32000000,0x32000000,0x32000000,0x32000000
	.word 0x00000013,0x00000013,0x00000013,0x00000013,0x00000013,0x00000013,0x22222223,0x33333330
	.word 0x32000000,0x32000000,0x32000000,0x32000000,0x32000000,0x32000000,0x32222222,0x03333333

	.section .rodata
	.align	2
	.global selection_bn_graphicsPal		@ 32 unsigned chars
	.hidden selection_bn_graphicsPal
selection_bn_graphicsPal:
	.hword 0x1860,0x5A2C,0x66D2,0x7FFF,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(selection_bn_graphics)
