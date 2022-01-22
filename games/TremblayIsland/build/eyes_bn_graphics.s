
@{{BLOCK(eyes_bn_graphics)

@=======================================================================
@
@	eyes_bn_graphics, 16x32@4, 
@	+ palette 16 entries, not compressed
@	+ 8 tiles not compressed
@	Total size: 32 + 256 = 288
@
@	Time-stamp: 2022-01-22, 04:49:14
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global eyes_bn_graphicsTiles		@ 256 unsigned chars
	.hidden eyes_bn_graphicsTiles
eyes_bn_graphicsTiles:
	.word 0x00000000,0x22200000,0x88550000,0xA7BC5000,0x7DD8C240,0x03AAB310,0x039A8410,0x77ABC430
	.word 0x00000000,0x00000444,0x00004588,0x00005BAD,0x00C5FE9A,0x0096FFF6,0x0098FEF4,0x00F9EED7
	.word 0xDD7B6100,0xAA981300,0x98623000,0x42300000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x0006699D,0x000929BA,0x0000C25B,0x00000F64,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0xC8630000,0xABC61000,0xADDA5100,0x63AA9440,0x20AA9550,0x37D9B300,0xDD7AB400
	.word 0x00000000,0x0000448C,0x000858BA,0x00058FEA,0x00C5CFFF,0x00B8CFFC,0x00FFBFFE,0x00058FAD
	.word 0x9DDB5600,0xB9C43000,0x55560000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x000838BE,0x0000648B,0x00000C85,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global eyes_bn_graphicsPal		@ 32 unsigned chars
	.hidden eyes_bn_graphicsPal
eyes_bn_graphicsPal:
	.hword 0x0000,0x0825,0x1064,0x10A7,0x18A6,0x2527,0x314C,0x1D6F
	.hword 0x31AB,0x39F1,0x2E13,0x3E30,0x462F,0x2E16,0x4F18,0x6759

@}}BLOCK(eyes_bn_graphics)
