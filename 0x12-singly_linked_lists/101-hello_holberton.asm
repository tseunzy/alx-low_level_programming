section .data
    message db "Hello, Holberton", 0xA  ; The string to be printed with a newline
    msg_len equ $ - message              ; Compute the length of the string

section .text
    extern printf                       ; Declare printf as an external function.

    global main                         ; The entry point for the program.
main:
    ; Prepare arguments for printf.
    mov rdi, message                    ; RDI holds the address of the string (first argument for printf).
    xor rax, rax                        ; Clear RAX register (to specify the number of floating point arguments for printf).

    ; Call printf.
    call printf

    ; Return from main.
    mov rax, 0                          ; Return code 0.
    ret

