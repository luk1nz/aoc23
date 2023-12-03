#include <stdio.h>
#include <string.h>
#include <aoc23/aoc23.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

const int MAX_RED = 12;
const int MAX_GREEN = 13;
const int MAX_BLUE = 14;

typedef struct {
    int red;
    int green;
    int blue;
} CubeSet;

int parse_game_id(const char* buffer, int* game_id) {
    return sscanf(buffer, "Game %d:", game_id);
}

void update_max_counts(const char* token, int* red_max, int* green_max, int* blue_max) {
    char color[6];
    int count;
    if (sscanf(token, "%d %s", &count, color) == 2) {
        if (strcmp(color, "red") == 0) {
            *red_max = MAX(*red_max, count);
        } else if (strcmp(color, "green") == 0) {
            *green_max = MAX(*green_max, count);
        } else if (strcmp(color, "blue") == 0) {
            *blue_max = MAX(*blue_max, count);
        }
    }
}

CubeSet process_game(const char* buffer) {
    CubeSet color_counts = {.red = 0, .green = 0, .blue = 0};

    // Start the string after the Game ID section
    char* start_of_tokens = strstr(buffer, ":");

    // Separate the string into tokens, broken on the ';'
    char* end_str;
    char* token = strtok_r(start_of_tokens + 1, ";", &end_str);
    while (token != NULL) {
        // Further break the string into tokens, broken on the ','
        char* end_token;
        char* inner_token = strtok_r(token, ",", &end_token);
        while (inner_token != NULL) {
            update_max_counts(inner_token, &color_counts.red, &color_counts.green, &color_counts.blue);
            inner_token = strtok_r(NULL, ",", &end_token);
        }
        token = strtok_r(NULL, ";", &end_str);
    }

    return color_counts;
}

int main(void) {
    FILE* file = aoc_io_open_file("puzzle_input.txt", "r");

    if (!file) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    char buffer[255];
    int result = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        // parse out the Game ID
        int game_id;
        if (parse_game_id(buffer, &game_id) != 1) {
            fprintf(stderr, "Error parsing Game ID\n");
            fclose(file);
            return 1;
        }

        CubeSet color_counts = process_game(buffer);
        if (color_counts.blue > MAX_BLUE || color_counts.red > MAX_RED || color_counts.green > MAX_GREEN)
            continue;

        result += game_id;
    }

    printf("The result of the puzzle is: %d\n", result);

    fclose(file);
    return 0;
}
