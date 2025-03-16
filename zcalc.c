#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "z_to_percentile.h"
#include "percentile_to_z.h"

static void dispatch_line (const char *line)
{
    if (!strcmp(line, "exit") || !strcmp(line, "quit")) {
        puts("Goodbye!");
        exit(EXIT_SUCCESS);
    }

    size_t len = strlen(line);

    if (len > 1 && line[len - 1] == 'z') {
        float z_score = atof(line);
        printf("%.2f%%\n", z_to_percentile(z_score));
        return;
    }

    if (len > 1 && line[len - 1] == '%') {
        float percentile = atof(line);
        if (percentile < 0 || percentile > 100) {
            fputs("Percentile not between 0 and 100.\n", stderr);
        } else {
            printf("%.3fz\n", percentile_to_z(percentile));
        }
        return;
    }

    fputs("Invalid command. Try 76%, 2z, exit or quit.\n", stderr);
}

int main(void) {
    char line[100];

    while (1) {
        fputs("> ", stderr);
        if (!fgets(line, sizeof(line), stdin)) {
            fputs("\n", stderr);
            break;
        }
        
        line[strcspn(line, "\n")] = 0; // strip newline
        dispatch_line(line);
    }

    return EXIT_SUCCESS;
}
