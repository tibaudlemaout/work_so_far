section .text
global strpbrk

strpbrk:
    ; rdi points to the main string
    ; rsi points to the set of characters to search for
    ; Loop until the end of the main string
    strpbrk_loop:
        ; Save the current position in the main string
        mov rcx, rdi
        ; Inner loop to compare each character in the set
        strpbrk_inner_loop:
            ; Load the current characters
            mov al, [rcx]
            mov bl, [rsi]
            cmp al, bl ; Check if the current character in the main string matches any in the set
            je strpbrk_found
            cmp byte [rsi], 0 ; Check if the end of the set is reached
            je strpbrk_continue_outer
            inc rsi; Move to the next character in the set
            ; Repeat the inner loop
            jmp strpbrk_inner_loop
        strpbrk_found:
            ; Return the position of the first occurrence of any character in the set
            mov rax, rcx
            ret
        strpbrk_continue_outer:
            ; Move to the next character in the main string
            inc rdi
            ; Check if the end of the main string is reached
            cmp byte [rdi], 0
            je strpbrk_not_found
            ; Reset the set pointer to the beginning
            mov rsi, rbx
            ; Repeat the outer loop
            jmp strpbrk_loop

        strpbrk_not_found:
            ; Return NULL if no character in the set is found in the main string
            xor rax, rax
            ret
