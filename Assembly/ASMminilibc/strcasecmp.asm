BITS 64
section .text
global strcasecmp

strcasecmp:
    ; rdi points to the first string
    ; rsi points to the second string
    ; Loop until characters are different or we reach the end of either string
    strcasecmp_loop:; Load the current characters
        mov al, [rdi]
        mov bl, [rsi]
        ; Convert characters to lowercase
        call convert_to_lowercase
        mov bl, al  ; Update the second character to its lowercase form
        cmp al, bl ; Compare the characters
        je strcasecmp_continue
        sub al, bl ; If characters are different, return the difference
        ret
    strcasecmp_continue:
        cmp al, 0 ; If the current characters are equal, check for the end of the strings
        je strcasecmp_done
        ; Move to the next character in each string
        inc rdi
        inc rsi
        ; Repeat the loop
        jmp strcasecmp_loop
    strcasecmp_done:
        xor rax, rax ; Strings are equal, return 0
        ret
convert_to_lowercase:
    ; Convert the character in al to lowercase
    cmp al, 'A'
    jl convert_to_lowercase_done
    cmp al, 'Z'
    jg convert_to_lowercase_done
    add al, 32  ; Difference between uppercase and lowercase letters

convert_to_lowercase_done:
    ret
