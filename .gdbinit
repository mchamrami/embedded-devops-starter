set confirm off
set pagination off
set breakpoint pending on
file build/firmware.elf
target remote :3333
break main
continue
frame
