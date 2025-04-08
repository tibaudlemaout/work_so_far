BITS 64
section .text
global strcmp

strcmp:
    ; rdi points to the first string
    ; rsi points to the second string
    ; Loop until characters are different or we reach the end of either string
    strcmp_loop:
        ; Load the current characters
        mov al, [rdi]
        mov bl, [rsi]
        cmp al, bl ; Compare the characters
        je strcmp_continue
        cmp al, bl ; If characters are different, return the difference
        jl strcmp_lower
        cmp al, bl
        jg strcmp_greater
        ret

    strcmp_continue:
        cmp al, 0 ; If the current characters are equal, check for the end of the strings
        je strcmp_done
        ; Move to the next character in each string
        inc rdi
        inc rsi
        ; Repeat the loop
        jmp strcmp_loop

    strcmp_done:
        xor rax, rax ; Strings are equal, return 0
        ret

    strcmp_lower:
        mov rax, -1
        ret
    
    strcmp_greater:
        mov rax, 1
        ret
