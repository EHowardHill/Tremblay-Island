
@{{BLOCK(chop_bar_bn_graphics)

@=======================================================================
@
@	chop_bar_bn_graphics, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2021-09-18, 06:57:35
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global chop_bar_bn_graphicsTiles		@ 128 unsigned chars
	.hidden chop_bar_bn_graphicsTiles
chop_bar_bn_graphicsTiles:
	.word 0xEEEE0000,0xDDDE0000,0xBBBE0000,0xDDDE0000,0xDCCE0000,0xCACE0000,0xACCE0000,0xCABE0000
	.word 0x00000EEE,0x00000EDD,0x00000EDB,0x00000EBA,0x00000EDD,0x00000EBC,0x00000ECC,0x00000EBC
	.word 0xCC8E0000,0xC88E0000,0x886E0000,0x853E0000,0x321E0000,0x211E0000,0x111E0000,0xEEEE0000
	.word 0x00000EDA,0x00000EBC,0x00000E88,0x00000EA9,0x00000E75,0x00000E54,0x00000E32,0x00000EEE

	.section .rodata
	.align	2
	.global chop_bar_bn_graphicsPal		@ 32 unsigned chars
	.hidden chop_bar_bn_graphicsPal
chop_bar_bn_graphicsPal:
	.hword 0x3D25,0x0868,0x0C88,0x0C89,0x0CA9,0x0CA9,0x10A9,0x10AA
	.hword 0x10AA,0x10AB,0x14CB,0x10CB,0x10CB,0x10CC,0x7FFF,0x0000

@}}BLOCK(chop_bar_bn_graphics)
