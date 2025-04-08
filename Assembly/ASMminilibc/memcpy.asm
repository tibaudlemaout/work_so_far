BITS 64
section .text
global memcpy

memcpy:
    ; rdi points to the destination buffer
    ; rsi points to the source buffer
    ; rdx contains the number of bytes to copy
    ; Check for overlapping memory regions
    cmp rdi, rsi
    jae memcpy_no_overlap
    sub rsi, rdx
    cmp rsi, rdi
    jae memcpy_no_overlap

    ; Handle overlapping (copy backward)
    memcpy_backward:
        mov al, [rsi + rdx - 1]  ; Load the last byte from the source
        mov [rdi + rdx - 1], al   ; Store it in the destination
        dec rdx                   ; Decrement the remaining number of bytes
        jnz memcpy_backward      ; Continue the loop if not all bytes are processed
        jmp memcpy_done

    memcpy_no_overlap:
        ; Copy
        memcpy_forward:
            mov al, [rsi]       ; Load the current byte from the source
            mov [rdi], al       ; Store it in the destination
            inc rsi             ; Move to the next byte in the source
            inc rdi             ; Move to the next byte in the destination
            dec rdx             ; Decrement the remaining number of bytes
            jnz memcpy_forward  ; Continue the loop if not all bytes are processed

    memcpy_done:
        ; Return the pointer to the destination buffer
        ret
