global sqrt
global distance
global __x86.get_pc_thunk.ax

extern _GLOBAL_OFFSET_TABLE_


SECTION .text

sqrt:
        endbr32
        push    ebp
        mov     ebp, esp
        sub     esp, 24
        call    __x86.get_pc_thunk.ax
        add     eax, _GLOBAL_OFFSET_TABLE_-$
        mov     edx, dword [ebp+8H]
        mov     dword [ebp-18H], edx
        mov     edx, dword [ebp+0CH]
        mov     dword [ebp-14H], edx
        fld     qword [L_003+eax]
        fstp    qword [ebp-8H]
        fld     qword [ebp-18H]
        fstp    qword [ebp-10H]
        jmp     L_002

L_001:  fld     qword [ebp-18H]
        fdiv    qword [ebp-10H]
        fadd    qword [ebp-10H]
        fld     qword [L_004+eax]
        fdivp   st1, st0
        fstp    qword [ebp-10H]
L_002:  fld     qword [ebp-18H]
        fdiv    qword [ebp-10H]
        fld     qword [ebp-10H]
        fsubrp  st1, st0
        fld     qword [ebp-8H]
        fxch    st1
        fcomip  st0  , st1
        fstp    st0
        ja      L_001
        fld     qword [ebp-10H]
        leave
        ret


distance:
        endbr32
        push    ebp
        mov     ebp, esp
        sub     esp, 16
        call    __x86.get_pc_thunk.ax
        add     eax, _GLOBAL_OFFSET_TABLE_-$
        mov     eax, dword [ebp+8H]
        mov     dword [ebp-8H], eax
        mov     eax, dword [ebp+0CH]
        mov     dword [ebp-4H], eax
        mov     eax, dword [ebp+10H]
        mov     dword [ebp-10H], eax
        mov     eax, dword [ebp+14H]
        mov     dword [ebp-0CH], eax
        fld     qword [ebp-8H]
        fld     st0
        fmulp   st1, st0
        fld     qword [ebp-10H]
        fmul    st0  , st0
        faddp   st1, st0
        lea     esp, [esp-8H]
        fstp    qword [esp]
        call    sqrt
        add     esp, 8
        leave
        ret

