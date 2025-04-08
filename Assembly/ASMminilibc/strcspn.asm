BITS 64
section .text
global strcspn

strcspn:
    ; rdi points to the main string
    ; rsi points to the set of characters to search for
    ; Initialize counter to zero
    xor rax, rax
    ; Loop until the end of the main string
    strcspn_loop:
        ; Save the current position in the main string
        mov rcx, rdi
        ; Inner loop to compare each character in the set
        strcspn_inner_loop:
            ; Load the current characters
            mov al, [rcx]
            mov bl, [rsi]
            ; Check if the current character in the main string matches any in the set
            cmp al, bl
            je strcspn_done
            ; Check if the end of the set is reached
            cmp byte [rsi], 0
            je strcspn_continue_outer
            ; Move to the next character in the set
            inc rsi
            ; Repeat the inner loop
            jmp strcspn_inner_loop
        strcspn_continue_outer:
            ; Increment counter
            inc rax
            ; Move to the next character in the main string
            inc rdi
            ; Check if the end of the main string is reached
            cmp byte [rdi], 0
            je strcspn_done
            ; Reset the set pointer to the beginning
            mov rsi, rbx
            ; Repeat the outer loop
            jmp strcspn_loop
        strcspn_done:
            ; Result is in rax
            ret
