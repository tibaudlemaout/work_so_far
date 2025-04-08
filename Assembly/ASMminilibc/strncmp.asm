BITS 64
section .text
global strncmp

strncmp:
    ; rdi points to the first string
    ; rsi points to the second string
    ; rdx contains the maximum number of characters to compare
    ; Loop until characters are different, we reach the end of either string,
    ; or we reach the maximum number of characters to compare
    strncmp_loop:
        cmp rdx, 0 ; Check if the maximum number of characters to compare is reached
        je strncmp_done
        ; Load the current characters
        mov al, [rdi]
        mov bl, [rsi]
        cmp al, bl ; Compare the characters
        je strncmp_continue
        cmp al, bl ; If characters are different, return the difference
        jl strncmp_lower
        cmp al, bl ; If characters are different, return the difference
        jg strncmp_greater;
        ret

    strncmp_continue:
        cmp al, 0 ; If the current characters are equal, check for the end of the strings
        je strncmp_done 
        ; Move to the next character in each string
        inc rdi
        inc rsi
        dec rdx ; Decrement the remaining characters to compare
        jmp strncmp_loop ; repeat the loop

    strncmp_done:
        xor rax, rax ; Strings are equal up to the specified number of characters, return 0
        ret
    
    strncmp_lower:
        mov rax, -1 ; set return to -1
        ret

    strncmp_greater:
        mov rax, 1 ;set return value to 1
        ret
