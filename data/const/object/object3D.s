	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_081216BC:: @ 081216BC
	.4byte sub_0808CF08
	.4byte sub_0808CF5C
	.4byte sub_0808D064

gUnk_081216C8:: @ 081216C8
.ifdef EU
    @ TODO only small differences
	.incbin "baserom_eu.gba", 0x120E10, 0x0000014
.else
	.incbin "baserom.gba", 0x1216C8, 0x0000014
.endif
