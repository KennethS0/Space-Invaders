section .data
msgHeader db " _____                        _____                    _", 10,"/  ___|                      |_   _|                  | |", 10,"\ `--. _ __   __ _  ___ ___    | | _ ____   ____ _  __| | ___ _ __ ___", 10, " `--. \ '_ \ / _` |/ __/ _ \   | || '_ \ \ / / _` |/ _` |/ _ \ '__/ __|", 10, "/\__/ / |_) | (_| | (_|  __/  _| || | | \ V / (_| | (_| |  __/ |  \__ \", 10, "\____/| .__/ \__,_|\___\___|  \___/_| |_|\_/ \__,_|\__,_|\___|_|  |___/", 10,"      | |                                                              ", 10,"      |_|                                                              ", 10
msgHeaderLen equ $-msgHeader

msgSeparator db "======================================================================="
msgSeparatorLen equ $-msgSeparator

section .text

; Print macro declaration
%macro print 2
    mov rax, 1
    mov rdi, 1
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

global printMenu
printMenu:
    print msgHeader, msgHeaderLen
    print msgSeparator, msgSeparatorLen
    ret