Section .data
    soubef db "source data before transfer: " , 2
    soubeflen equ $-soubef
    desbef db "destination data before transer: ", 2
    desbeflen equ $-desbef
    souaft db "source data after transfer: " , 2
    souaftlen equ $-souaft
    desaft db "destination data after transer: ", 2
    desaftlen equ $-desaft
    newline db 10 , 10
    newlen equ $-newline
    space db 20h , 10
    sourblk db 40h,65h,08h,78h,44h
    sourlen equ 5
    destblk times 5 db 0
    
 Section .bss
   displaybuff resb 2
  
%macro display 2
 mov eax , 4
 mov ebx , 1
 mov ecx , %1
 mov edx , %2
 int 80h
%endmacro
   
   Section .text
   Global _start
   
_start:
      display soubef , soubeflen
      call printblock
      display newline , newlen
      display desbef , desbeflen
      call printdesbl
      display newline , newlen
      call procedure
      jmp exit1
    
exit1:
       display souaft , souaftlen
       call printblock
       display newline , newlen 
       display desaft , desaftlen
       call printdesbl
       display newline , newlen
       jmp exit
   

printblock:
        mov esi , sourblk
        call print_block
        ret

printdesbl:
        mov esi , destblk 
        call print_block
        ret
  
exit:
       mov eax , 1
       mov ebx , 0
       int 80h
   
procedure:
      mov esi , sourblk
      mov edi , destblk
      mov ecx , sourlen

dowork:
      mov al , [esi]
      mov [edi] , al
      inc esi
      inc edi
      loop dowork
      ret

print_block:
      mov ecx , sourlen
  
printing:
      push ecx
      mov bl , [esi]
      call change
      inc esi
      display space , 1
      pop ecx
      loop printing
      ret
 
change:  
      mov ecx , 02 
      mov edi , displaybuff
 
conversion:
     rol bl , 4
     mov al , bl
     and al , 0fh
     cmp al , -09
     jbe dataadd
     add al , 07h

dataadd:
    add al ,30h
    mov [edi],al
    inc edi
    loop conversion
    display displaybuff , 2
    ret
