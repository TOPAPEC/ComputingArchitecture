global perimeter_rectangle
perimeter_rectangle:
        section .text
        sub edi, esi
        sub edx, ecx
        add edi, edx
        add edi, edi
        pxor xmm0, xmm0
        cvtsi2sd xmm0, edi
        ret


global perimeter_triangle
perimeter_triangle:
        mov     eax, esi
        mov     r10d, edx
        mov     edx, edi
        sub     edx, esi
        mov     esi, ecx
        sub     esi, r8d
        sub     edi, r10d
        sub     ecx, r9d
        sub     eax, r10d
        sub     r8d, r9d
        imul    edi, edi
        imul    ecx, ecx
        add     edi, ecx
        pxor    xmm0, xmm0
        cvtsi2sd  xmm0, edi
        sqrtsd xmm0, xmm0
        imul    edx, edx
        imul    esi, esi
        add     edx, esi
        pxor    xmm1, xmm1
        cvtsi2sd  xmm1, edx
        sqrtsd xmm1, xmm1
        imul    eax, eax
        imul    r8d, r8d
        add     eax, r8d
        pxor    xmm2, xmm2
        cvtsi2sd  xmm2, eax
        sqrtsd xmm2, xmm2
        addsd   xmm0, xmm1
        addsd   xmm0, xmm2
        ret

global perimeter_circle
perimeter_circle:
        movapd  xmm1, xmm0
        pxor    xmm0, xmm0
        cvtsi2sd xmm0, esi
        mulsd   xmm0, xmm1
        pxor    xmm1, xmm1
        cvtsi2sd xmm1, edi
        mulsd   xmm0, xmm1
        ret



