BITS 64
section .text
global strlen

strlen:
    ; rdi points to the input string
    xor rax, rax ;Initialize counter to 0

    strlen_loop:
        mov bl, [rdi] ; Load the current character
        cmp bl, 0 ; Check if the current character is null (end of string)
        je strlen_done
        inc rax ; Increment counter
        inc rdi ; Move to the next character in the string
        jmp strlen_loop ; Repeat the loop
    strlen_done:
        ; Result is in rax
        ret