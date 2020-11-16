# floatingpoint-add-syscall
This is an implementation of addition of 2 floating point numbers using integer operations, by making a system call in Linux.

**Allowed Inputs:** Positive floats

**Errors Thrown for:** Negative numbers, Zero Inputs, Overflow

**Error:** -1 is returned to the user from the wrapper for errors, which may be printed. System call uses IEEE format of INF for overflow error.

Sample outputs:

![P1](https://github.com/jainkhyati/floatingpoint-add-syscall/blob/main/test.png)

Files modified and added:

1. /usr/src/linux-5.2.9/add_syscall/add_syscall.c
2. /usr/src/linux-5.2.9/add_syscall/add_syscall.h
3. /usr/src/linux-5.2.9/add_syscall/Makefile
4. /usr/src/linux-5.2.9/Makefile
5. /usr/src/linux-5.2.9/arch/x86/entry/syscalls/syscall_64.tbl3
6. /usr/src/linux-5.2.9/include/asm-generic/syscalls.h
7. /usr/src/linux-5.2.9/include/linux/syscalls.h

## References
1. [Floating point addition](
https://www.geeksforgeeks.org/floating-point-representation-basics/)
2. [Creating linux syscalls](http://www.cs.albany.edu/~sdc/CSI500/Fal13/Labs/OwnSyscallV3plus/OwnSyscallFE.html)
