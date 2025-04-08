BITS 64
section .text
global memset

memset:
    ; rdi points to the dest buffer
    ; rsi contains the value (byte) to set
    ; rdx contains the number of bytes to set
    ; Check if the number of bytes is zero
    test rdx, rdx
    jz memset_done

    ; Fill the buffer with the specified value
    memset_loop:
        mov [rdi], sil  ; Store the value in the dest buffer
        inc rdi         ; Move to the next byte
        dec rdx         ; Decrement number of bytes
        jnz memset_loop ; Continue the loop

    memset_done:
        ret
