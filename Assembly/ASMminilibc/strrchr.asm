BITS 64
section .text
global strrchr
strrchr:
    ; rdi points to the input string
    ; rsi contains the character to search for
    xor rcx, rcx
    mov rax, rdi
find_end_of_string:
    cmp byte [rax + rcx], 0
    je  end_of_string_found
    inc rcx ; Find the end of the string
    jmp find_end_of_string

end_of_string_found:
    dec rcx  ; Adjust to point to the last character of the string

search_backward: ; Loop backward through the string
    ; Check if the current character is equal to the search character
    cmp byte [rdi + rcx], sil
    je  character_found
    cmp rcx, 0 ; Check if we have reached the beginning of the string
    je  character_not_found
    dec rcx ; Continue searching backward
    jmp search_backward

character_found:
    lea rax, [rdi + rcx] ; Return a pointer to the last occurrence of the character
    ret

character_not_found:
    xor rax, rax ; Return NULL if the character is not found
    ret
