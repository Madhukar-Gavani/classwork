Section .data
 mesbef db "data before transfer" , 10
 mesbeflen equ $-mesbef
 mesaft db "data after transfer" , 10
 mesaftlen equ $-mesaft
 surblk db 0Ah,02h,22h,98h,09h
 surblklen equ 05
 desblk times 8 db 0
 space db 20h

%macro display 2
mov eax , 4
mov ebx , 1
mov ecx , %1
mov edx , %2
int 80h
%endmacro

Section .bss
  dispbuff resb 02
  
Section .text
Global _start

 
_start:
   display mesbef , mesbeflen
   call showblk
;   call procedure
   jmp exit1

showblk:
  mov esi , surblk
  call dispblk_proc
  ret

exit1:
   display mesaft , mesaftlen
   call showblk1
   display space , 02

exit:
   mov eax , 1
   mov ebx , 0
   int 80h

dispblk_proc:
     mov ecx , surblklen
    
redisp:
   push ecx
   mov bl , [esi]
   call disp_blocks
   inc esi
   display space , 1
   pop  ecx
   loop redisp
   ret 

;procedure: 
;    mov esi , surblk
;    mov edi , desblk
;    mov ecx , surblklen


;blkup:
;    mov al , [esi]
;    mov [edi] , al
;    inc esi
;    inc edi
;    loop blkup
;    ret

  
showblk1:  
  mov esi , desblk
  call dispblk_proc
  ret
  
disp_blocks:
     mov ecx , 02
     mov edi, dispbuff

dup:
  rol bl , 4
  mov al , bl
  and al , 0fh
  cmp al , 09
  jbe dskip
  add al , 07h

dskip:
  add al , 30h
  mov [edi] , al 
  inc edi
  loop dup
  display dispbuff , 10
   ret


