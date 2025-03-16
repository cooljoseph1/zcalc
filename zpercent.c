#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "z_to_percentile.h"

static void dispatch_line (const char *line)
{
    float z_score = atof(line);
    printf("%f\n", z_to_percentile(z_score));
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
        
        // Remove end 'z' if it exists, and strip newline
        if (line[len - 1] == 'z') {
            line[len - 1] = 0;
        } else {
            line[len] = 0;
        }
        
        dispatch_line(line);
    }

    return EXIT_SUCCESS;
}
