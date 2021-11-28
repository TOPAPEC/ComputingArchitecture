global shaker_sort

swap:
        push    rbp
        mov     rbp, rsp
        push    rbx
        mov     QWORD  [rbp-72], rdi
        mov     QWORD  [rbp-80], rsi
        mov     rax, QWORD  [rbp-72]
        mov     rcx, QWORD  [rax]
        mov     rbx, QWORD  [rax+8]
        mov     QWORD  [rbp-64], rcx
        mov     QWORD  [rbp-56], rbx
        mov     rcx, QWORD  [rax+16]
        mov     rbx, QWORD  [rax+24]
        mov     QWORD  [rbp-48], rcx
        mov     QWORD  [rbp-40], rbx
        mov     rax, QWORD  [rax+32]
        mov     QWORD  [rbp-32], rax
        mov     rax, QWORD  [rbp-72]
        mov     rdx, QWORD  [rbp-80]
        mov     rcx, QWORD  [rdx]
        mov     rbx, QWORD  [rdx+8]
        mov     QWORD  [rax], rcx
        mov     QWORD  [rax+8], rbx
        mov     rcx, QWORD  [rdx+16]
        mov     rbx, QWORD  [rdx+24]
        mov     QWORD  [rax+16], rcx
        mov     QWORD  [rax+24], rbx
        mov     rdx, QWORD  [rdx+32]
        mov     QWORD  [rax+32], rdx
        mov     rax, QWORD  [rbp-80]
        mov     rcx, QWORD  [rbp-64]
        mov     rbx, QWORD  [rbp-56]
        mov     QWORD  [rax], rcx
        mov     QWORD  [rax+8], rbx
        mov     rcx, QWORD  [rbp-48]
        mov     rbx, QWORD  [rbp-40]
        mov     QWORD  [rax+16], rcx
        mov     QWORD  [rax+24], rbx
        mov     rdx, QWORD  [rbp-32]
        mov     QWORD  [rax+32], rdx
        nop
        mov     rbx, QWORD  [rbp-8]
        leave
        ret
shaker_sort:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 48
        mov     QWORD  [rbp-40], rdi
        mov     DWORD  [rbp-44], esi
        mov     eax, DWORD  [rbp-44]
        sub     eax, 1
        mov     DWORD  [rbp-4], eax
        mov     DWORD  [rbp-8], 0
        mov     eax, DWORD  [rbp-44]
        sub     eax, 1
        mov     DWORD  [rbp-12], eax
.L11:
        mov     eax, DWORD  [rbp-8]
        mov     DWORD  [rbp-16], eax
        jmp     .L3
.L6:
        mov     eax, DWORD  [rbp-16]
        cdqe
        lea     rdx, [0+rax*8]
        mov     rax, QWORD  [rbp-40]
        add     rax, rdx
        mov     rax, QWORD  [rax]
        movsd   xmm0, QWORD  [rax]
        mov     eax, DWORD  [rbp-16]
        cdqe
        add     rax, 1
        lea     rdx, [0+rax*8]
        mov     rax, QWORD  [rbp-40]
        add     rax, rdx
        mov     rax, QWORD  [rax]
        movsd   xmm1, QWORD  [rax]
        comisd  xmm0, xmm1
        jbe     .L4
        mov     eax, DWORD  [rbp-16]
        cdqe
        add     rax, 1
        lea     rdx, [0+rax*8]
        mov     rax, QWORD  [rbp-40]
        add     rax, rdx
        mov     rdx, QWORD  [rax]
        mov     eax, DWORD  [rbp-16]
        cdqe
        lea     rcx, [0+rax*8]
        mov     rax, QWORD  [rbp-40]
        add     rax, rcx
        mov     rax, QWORD  [rax]
        mov     rsi, rdx
        mov     rdi, rax
        call    swap
        mov     eax, DWORD  [rbp-16]
        mov     DWORD  [rbp-4], eax
.L4:
        add     DWORD  [rbp-16], 1
.L3:
        mov     eax, DWORD  [rbp-16]
        cmp     eax, DWORD  [rbp-12]
        jl      .L6
        mov     eax, DWORD  [rbp-4]
        mov     DWORD  [rbp-12], eax
        mov     eax, DWORD  [rbp-12]
        mov     DWORD  [rbp-20], eax
        jmp     .L7
.L10:
        mov     eax, DWORD  [rbp-20]
        cdqe
        lea     rdx, [0+rax*8]
        mov     rax, QWORD  [rbp-40]
        add     rax, rdx
        mov     rax, QWORD  [rax]
        movsd   xmm1, QWORD  [rax]
        mov     eax, DWORD  [rbp-20]
        cdqe
        sal     rax, 3
        lea     rdx, [rax-8]
        mov     rax, QWORD  [rbp-40]
        add     rax, rdx
        mov     rax, QWORD  [rax]
        movsd   xmm0, QWORD  [rax]
        comisd  xmm0, xmm1
        jbe     .L8
        mov     eax, DWORD  [rbp-20]
        cdqe
        sal     rax, 3
        lea     rdx, [rax-8]
        mov     rax, QWORD  [rbp-40]
        add     rax, rdx
        mov     rdx, QWORD  [rax]
        mov     eax, DWORD  [rbp-20]
        cdqe
        lea     rcx, [0+rax*8]
        mov     rax, QWORD  [rbp-40]
        add     rax, rcx
        mov     rax, QWORD  [rax]
        mov     rsi, rdx
        mov     rdi, rax
        call    swap
        mov     eax, DWORD  [rbp-20]
        mov     DWORD  [rbp-4], eax
.L8:
        sub     DWORD  [rbp-20], 1
.L7:
        mov     eax, DWORD  [rbp-20]
        cmp     eax, DWORD  [rbp-8]
        jg      .L10
        mov     eax, DWORD  [rbp-4]
        mov     DWORD  [rbp-8], eax
        mov     eax, DWORD  [rbp-8]
        cmp     eax, DWORD  [rbp-12]
        jl      .L11
        nop
        nop
        leave
        ret