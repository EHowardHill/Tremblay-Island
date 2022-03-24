
@{{BLOCK(variable_8x16_font_yellow_bn_graphics)

@=======================================================================
@
@	variable_8x16_font_yellow_bn_graphics, 8x16@4, 
@	+ palette 16 entries, not compressed
@	+ 2 tiles not compressed
@	Total size: 32 + 64 = 96
@
@	Time-stamp: 2022-03-24, 04:15:58
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global variable_8x16_font_yellow_bn_graphicsTiles		@ 64 unsigned chars
	.hidden variable_8x16_font_yellow_bn_graphicsTiles
variable_8x16_font_yellow_bn_graphicsTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000CDD,0x00000CDD,0x00000CDD
	.word 0x00000CDD,0x00000CDD,0x00000CCC,0x00000CDD,0x00000CCC,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global variable_8x16_font_yellow_bn_graphicsPal		@ 32 unsigned chars
	.hidden variable_8x16_font_yellow_bn_graphicsPal
variable_8x16_font_yellow_bn_graphicsPal:
	.hword 0x03E0,0x2D06,0x2CED,0x20D6,0x1CFC,0x318C,0x4189,0x219E
	.hword 0x5E0C,0x5E2C,0x2A5F,0x52F0,0x0000,0x6317,0x43FF,0x0001

@}}BLOCK(variable_8x16_font_yellow_bn_graphics)
