	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2

gUnk_089FB770:: @ 089FB770
	.byte 00, 0x0d, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00

gUnk_089FB780:: @ 089FB780
.ifdef EU
	.incbin "baserom_eu.gba", 0xB07090, 0x0000F44
.else
	.incbin "baserom.gba", 0x9FB780, 0x0000F44
.endif
@ More sprites in demo
.ifdef DEMO
	.incbin "baserom_demo.gba", 0x9FD0F4, 0xC0
gUnk_089FD1B4::
	.incbin "baserom_demo.gba", 0x9FD1B4, 0x140
gUnk_089FD2F4::
	.incbin "baserom_demo.gba", 0x9FD2F4, 0x845D
gUnk_08A05751::
	.incbin "baserom_demo.gba", 0xA05751, 0x116e
gUnk_08A068BF::
	.incbin "baserom_demo.gba", 0xA068BF, 0x81
.endif
