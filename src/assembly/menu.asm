section .data

msgHead1 db "░██████╗██████╗░░█████╗░░█████╗░███████╗  ██╗███╗░░██╗██╗░░░██╗░█████╗░██████╗░███████╗██████╗░░██████╗",10
msgHead1Len equ $-msgHead1

msgHead2 db "██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔════╝  ██║████╗░██║██║░░░██║██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔════╝",10
msgHead2Len equ $-msgHead2

msgHead3 db "╚█████╗░██████╔╝███████║██║░░╚═╝█████╗░░  ██║██╔██╗██║╚██╗░██╔╝███████║██║░░██║█████╗░░██████╔╝╚█████╗░",10
msgHead3Len equ $-msgHead3

msgHead4 db "░╚═══██╗██╔═══╝░██╔══██║██║░░██╗██╔══╝░░  ██║██║╚████║░╚████╔╝░██╔══██║██║░░██║██╔══╝░░██╔══██╗░╚═══██╗",10
msgHead4Len equ $-msgHead4

msgHead5 db "██████╔╝██║░░░░░██║░░██║╚█████╔╝███████╗  ██║██║░╚███║░░╚██╔╝░░██║░░██║██████╔╝███████╗██║░░██║██████╔╝",10
msgHead5Len equ $-msgHead5

msgHead6 db "╚═════╝░╚═╝░░░░░╚═╝░░╚═╝░╚════╝░╚══════╝  ╚═╝╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝╚═════╝░╚══════╝╚═╝░░╚═╝╚═════╝░",10
msgHead6Len equ $-msgHead6

headerDelay dq 1, 1000000

clearScr db 27,"[H",27,"[2J"
clearScrLen equ $-clearScr

section .text

; Print macro declaration
; %1 : Message
; %2: Length
%macro print 2
    mov rax, 1
    mov rdi, 1
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

; Get input declaration
; %1 : Time to wait (nanoseconds)
%macro wait 1
    mov rax, 35
    mov rdi, %1
    mov rsi, 0
    syscall
%endmacro


global printMenu
printMenu:
    ; Clears screen 
    print clearScr, clearScrLen

    ; Prints the header message
    print msgHead1, msgHead1Len
    wait headerDelay
    
    print msgHead2, msgHead2Len
    wait headerDelay

    print msgHead3, msgHead3Len
    wait headerDelay

    print msgHead4, msgHead4Len
    wait headerDelay

    print msgHead5, msgHead5Len
    wait headerDelay

    print msgHead6, msgHead6Len
    wait headerDelay

    ret