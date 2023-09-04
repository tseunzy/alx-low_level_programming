#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void error_exit(int code, const char *message) {
    dprintf(STDERR_FILENO, "Error: %s\n", message);
    exit(code);
}

int main(int argc, char *argv[]) {
    int fd_from, fd_to, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];
    
    if (argc != 3) {
        error_exit(97, "Usage: cp file_from file_to");
    }
    
    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1) {
        error_exit(98, "Can't read from file");
    }
    
    fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_to == -1) {
        error_exit(99, "Can't write to file");
    }
    
    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written == -1) {
            error_exit(99, "Can't write to file");
        }
    }
    
    if (bytes_read == -1) {
        error_exit(98, "Can't read from file");
    }
    
    if (close(fd_from) == -1 || close(fd_to) == -1) {
        error_exit(100, "Can't close fd");
    }
    
    return 0;
}

