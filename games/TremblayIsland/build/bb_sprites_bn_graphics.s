
@{{BLOCK(bb_sprites_bn_graphics)

@=======================================================================
@
@	bb_sprites_bn_graphics, 8x56@4, 
@	+ palette 16 entries, not compressed
@	+ 7 tiles not compressed
@	Total size: 32 + 224 = 256
@
@	Time-stamp: 2022-05-17, 22:36:30
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.18
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global bb_sprites_bn_graphicsTiles		@ 224 unsigned chars
	.hidden bb_sprites_bn_graphicsTiles
bb_sprites_bn_graphicsTiles:
	.word 0x01111119,0x1FF99991,0x1F999991,0x19999991,0x19999991,0x19999971,0x199997F1,0x01111110
	.word 0x01111110,0x1FF66661,0x1F666661,0x16666661,0x16666661,0x16666661,0x166666F1,0x01111110
	.word 0x0222222B,0x2FFBBBB2,0x2FBBBBB2,0x2BBBBBB2,0x2BBBBBB2,0x2BBBBBA2,0x2BBBBAF2,0x02222220
	.word 0x02222220,0x2CC88882,0x2C888882,0x28888882,0x28888882,0x28888882,0x288888C2,0x02222220
	.word 0x0111111E,0x1FFEEEE1,0x1FEEEEE1,0x1EEEEEE1,0x1EEEEEE1,0x1EEEEED1,0x1EEEEDF1,0x01111110
	.word 0x01111110,0x15544441,0x15444441,0x14444441,0x14444441,0x14444431,0x14444351,0x01111110
	.word 0x00644600,0x05F66650,0x6F666666,0x46666664,0x46666664,0x66666666,0x05666F50,0x00644600

	.section .rodata
	.align	2
	.global bb_sprites_bn_graphicsPal		@ 32 unsigned chars
	.hidden bb_sprites_bn_graphicsPal
bb_sprites_bn_graphicsPal:
	.hword 0x5CF8,0x0000,0x0000,0x0862,0x1084,0x18C6,0x10AE,0x4903
	.hword 0x0D42,0x6960,0x012B,0x056D,0x374A,0x5EF7,0x6F7B,0x7FFF

@}}BLOCK(bb_sprites_bn_graphics)
