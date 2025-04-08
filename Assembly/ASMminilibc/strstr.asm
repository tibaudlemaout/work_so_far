BITS 64
section .text
global strstr

strstr:
    ; rdi points to the main string
    ; rsi points to the substring to search for
    ; If the substring is an empty string, return the main string
    cmp byte [rsi], 0
    je strstr_return
    ; Loop until the end of the main string
    strstr_loop:
        ; Save the current position in the main string
        mov rcx, rdi
        ; Inner loop to compare the substring
        strstr_inner_loop:
            ; Load the current characters
            mov al, [rcx]
            mov bl, [rsi]
            ; Compare the characters
            cmp al, bl
            jne strstr_continue_outer
            ; If characters are equal, move to the next characters
            inc rcx
            inc rsi
            ; Check if the end of the substring is reached
            cmp byte [rsi], 0
            je strstr_found
            ; Repeat the inner loop
            jmp strstr_inner_loop
        strstr_continue_outer:
            ; Move to the next character in the main string
            inc rdi
            ; Check if the end of the main string is reached
            cmp byte [rdi], 0
            je strstr_not_found
            ; Repeat the outer loop
            jmp strstr_loop
        strstr_found:
            mov rax, rcx ; Return the position of the first occurrence of the substring in the main string
            ret
        strstr_not_found:
            xor rax, rax ; Return NULL if the substring is not found
            ret
    strstr_return:
        mov rax, rdi ; Return the main string if the substring is an empty string
        ret
