BITS 64
section .text
global strchr

strchr:
    ; rdi points to the input string
    ; sil contains the character to search for

search_character: ; Loop through the string
    cmp byte [rdi], sil; Check if the current character is equal to the search character
    je  character_found
    cmp byte [rdi], 0 ; Check if we have reached the end of the string
    je  character_not_found
    inc rdi; Move to the next character in the string
    jmp search_character

character_found:
    lea rax, [rdi] ; Return a pointer to the first occurrence of the character
    ret

character_not_found:
    xor rax, rax ; Return NULL if the character is not found
    ret
