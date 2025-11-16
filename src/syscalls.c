#include <errno.h>
#include <stdint.h>
#include <sys/stat.h>
#include <stddef.h>

/* Heap boundaries defined by linker script */
extern unsigned char _end;       /* end of bss */
extern unsigned char _estack;    /* top of stack */

static unsigned char *heap_end = &_end;

void _exit(int status) {
    while (1);
}

int _write(int file, const char *ptr, int len) {
    (void)file;
    for (int i = 0; i < len; i++) {
        // در صورت نیاز می‌تونی خروجی printf را به UART بفرستی
    }
    return len;
}

int _read(int file, char *ptr, int len) {
    (void)file;
    return 0;
}

int _close(int file) {
    (void)file;
    return -1;
}

int _fstat(int file, struct stat *st) {
    (void)file;
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file) {
    (void)file;
    return 1;
}

int _lseek(int file, int ptr, int dir) {
    (void)file; (void)ptr; (void)dir;
    return 0;
}

void *_sbrk(ptrdiff_t incr) {
    unsigned char *prev_heap_end = heap_end;
    if (heap_end + incr >= &_estack) {
        errno = ENOMEM;
        return (void *)-1;
    }
    heap_end += incr;
    return (void *)prev_heap_end;
}
