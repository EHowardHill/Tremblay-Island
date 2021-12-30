
@{{BLOCK(horizontal_bar_bn_graphics)

@=======================================================================
@
@	horizontal_bar_bn_graphics, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2021-12-30, 07:43:03
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global horizontal_bar_bn_graphicsTiles		@ 32 unsigned chars
	.hidden horizontal_bar_bn_graphicsTiles
horizontal_bar_bn_graphicsTiles:
	.word 0xBBBBBBBB,0x21121121,0x67777777,0xA8AA8AAA,0xA99AA9A9,0x54453434,0xBBBBBBBB,0x00000000

	.section .rodata
	.align	2
	.global horizontal_bar_bn_graphicsPal		@ 32 unsigned chars
	.hidden horizontal_bar_bn_graphicsPal
horizontal_bar_bn_graphicsPal:
	.hword 0x0000,0x18CB,0x18CB,0x2110,0x2110,0x2130,0x2532,0x2531
	.hword 0x2957,0x2557,0x2957,0x7FFF,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(horizontal_bar_bn_graphics)
