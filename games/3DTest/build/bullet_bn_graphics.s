
@{{BLOCK(bullet_bn_graphics)

@=======================================================================
@
@	bullet_bn_graphics, 16x32@4, 
@	+ palette 16 entries, not compressed
@	+ 8 tiles not compressed
@	Total size: 32 + 256 = 288
@
@	Time-stamp: 2022-03-16, 23:21:39
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global bullet_bn_graphicsTiles		@ 256 unsigned chars
	.hidden bullet_bn_graphicsTiles
bullet_bn_graphicsTiles:
	.word 0x00000000,0x00000000,0x00000000,0xCC000000,0xBBC00000,0x00BC0000,0x000BC000,0x000BC000
	.word 0x00000000,0x00000000,0x00000000,0x000000CC,0x00000CBB,0x0000CB00,0x000CB000,0x000CB000
	.word 0x000BC000,0x000BC000,0x00BC0000,0xBBC00000,0xCC000000,0x00000000,0x00000000,0x00000000
	.word 0x000CB000,0x000CB000,0x0000CB00,0x00000CBB,0x000000CC,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0xCC000000,0xBBC00000,0x55BC0000,0x445BC000,0xD45BC000
	.word 0x00000000,0x00000000,0x00000000,0x000000CC,0x00000CBB,0x0000CB55,0x000CB544,0x000CB54D
	.word 0xD45BC000,0x445BC000,0x55BC0000,0xBBC00000,0xCC000000,0x00000000,0x00000000,0x00000000
	.word 0x000CB54D,0x000CB544,0x0000CB55,0x00000CBB,0x000000CC,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global bullet_bn_graphicsPal		@ 32 unsigned chars
	.hidden bullet_bn_graphicsPal
bullet_bn_graphicsPal:
	.hword 0x03E0,0x0000,0x20D6,0x28FB,0x1B9F,0x1ADF,0x3AFF,0x32BF
	.hword 0x6BDF,0x157F,0x2A5F,0x19FF,0x197F,0x7FFF,0x001F,0x001F

@}}BLOCK(bullet_bn_graphics)
