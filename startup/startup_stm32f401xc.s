.syntax unified
.cpu cortex-m4
.thumb

.global  Reset_Handler
.extern  SystemInit
.extern  main

.section .isr_vector, "a", %progbits
.align  2
.long   _estack           /* SP initial value */
.long   Reset_Handler     /* PC initial value (Thumb symbol ok) */
/* بقیه بردارها فعلاً صفر */
.long   0  /* NMI */
.long   0  /* HardFault */
.long   0  /* MemManage */
.long   0  /* BusFault */
.long   0  /* UsageFault */
.long   0,0,0,0
.long   0  /* SVC */
.long   0  /* DebugMon */
.long   0  /* Reserved */
.long   0  /* PendSV */
.long   0  /* SysTick */

.text
.align  2
.type   Reset_Handler, %function
Reset_Handler:
    bl  SystemInit
    bl  main
1:  b   1b
.size   Reset_Handler, .-Reset_Handler
