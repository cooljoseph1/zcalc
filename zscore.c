#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "percentile_to_z.h"

static void dispatch_line (const char *line)
{
    float percentile = atof(line);
    if (percentile < 0 || percentile > 100) {
        fputs("Percentile not between 0 and 100.\n", stderr);
    } else {
        printf("%f\n", percentile_to_z(percentile));
    }

    return;
}

int main(void) {
    char line[100];

    while (1) {
        if (!fgets(line, sizeof(line), stdin)) {
            break;
        }

        int len = strcspn(line, "\n");
        if (len == 0) {
            printf("\n");
            continue;
        }
        
        // Remove end '%' if it exists, and strip newline
        if (line[len - 1] == '%') {
            line[len - 1] = 0;
        } else {
            line[len] = 0;
        }

        dispatch_line(line);
    }

    return EXIT_SUCCESS;
}
