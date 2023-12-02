#include <stdio.h>
#include <stdlib.h>

#include "aoc23/io.h"

FILE *aoc_io_open_file(const char *path, const char *mode) {
    FILE *file = fopen(path, mode);
    if (file == NULL) {
        perror("File failed to open\n");
        exit(1);
    }

    return file;
}