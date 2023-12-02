#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <aoc23/aoc23.h>

static inline int get_digit_at_index(const char *line, uint8_t index, int direction) {
    for (uint8_t i = index; line[i] != '\0' && i < strlen(line) && i >= 0; i += direction) {
        char c = line[i];
        if (isdigit(c))
            return c - '0';
    }
    return -1;
}

static inline int get_digit_from_front(const char *line) {
    return get_digit_at_index(line, 0, 1);
}

static inline int get_digit_from_back(const char *line) {
    return get_digit_at_index(line, strlen(line) - 1, -1);
}

int main(void) {
    FILE *file = aoc_io_open_file("puzzle_input.txt", "r");

    char buffer[255];
    int result = 0;
    while (fgets(buffer, 255, file)) {
        buffer[strcspn(buffer, "\n\r")] = '\0';

        int first_digit = get_digit_from_front(buffer);
        int second_digit = get_digit_from_back(buffer);

        if (first_digit == -1) {
            fprintf(stderr, "Error finding first digit in string: %s\n", buffer);
            goto close_file_and_exit;
        }

        if (second_digit == -1) {
            fprintf(stderr, "Error finding second digit in string: %s\n", buffer);
            goto close_file_and_exit;
        }

        result += first_digit * 10 + second_digit;
    }

    printf("The result of the puzzle is: %i\n", result);

    fclose(file);
    return 0;

close_file_and_exit:
    fclose(file);
    exit(1);
}
