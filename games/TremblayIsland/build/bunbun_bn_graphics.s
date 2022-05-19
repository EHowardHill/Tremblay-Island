
@{{BLOCK(bunbun_bn_graphics)

@=======================================================================
@
@	bunbun_bn_graphics, 8x16@4, 
@	+ palette 16 entries, not compressed
@	+ 2 tiles not compressed
@	Total size: 32 + 64 = 96
@
@	Time-stamp: 2022-05-17, 22:36:30
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.18
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global bunbun_bn_graphicsTiles		@ 64 unsigned chars
	.hidden bunbun_bn_graphicsTiles
bunbun_bn_graphicsTiles:
	.word 0x00111100,0x00131310,0x00131310,0x01113331,0x13331411,0x13442421,0x14311111,0x11111011
	.word 0x00111100,0x00131310,0x00113331,0x01331411,0x13442421,0x14311111,0x13111011,0x11110000

	.section .rodata
	.align	2
	.global bunbun_bn_graphicsPal		@ 32 unsigned chars
	.hidden bunbun_bn_graphicsPal
bunbun_bn_graphicsPal:
	.hword 0x03E0,0x0000,0x4E73,0x739C,0x7FFF,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(bunbun_bn_graphics)
