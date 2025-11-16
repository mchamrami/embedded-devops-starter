ENTRY(Reset_Handler)
_estack = ORIGIN(RAM) + LENGTH(RAM);

MEMORY {
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K
  RAM   (rwx): ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS {
  .isr_vector : { KEEP(*(.isr_vector)) } > FLASH

  .text : {
    *(.text*)
    *(.rodata*)
    *(.glue_7) *(.glue_7t)
  } > FLASH

  .ARM.exidx : {
    __exidx_start = .;
    *(.ARM.exidx*)
    __exidx_end = .;
  } > FLASH

  .data : AT (ADDR(.text) + SIZEOF(.text) + SIZEOF(.ARM.exidx)) {
    _sdata = .; *(.data*) _edata = .;
  } > RAM

  .bss : {
    _sbss = .; *(.bss*) *(COMMON) _ebss = .;
  } > RAM

  _end = .;
}
