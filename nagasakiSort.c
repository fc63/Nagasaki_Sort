#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* nagasakiSort(int* fallout, int fallout_size, int* survivors) {
    if (fallout_size <= 1) {
        *survivors = fallout_size;
        return fallout;
    }

    int max_iterations = (int)log2(fallout_size); 
    int* safe_zone = (int*)malloc(max_iterations * sizeof(int));
    int population = 0;

    safe_zone[population++] = fallout[0];

    for (int i = 1; i < fallout_size && population < max_iterations; i++) {
        if (fallout[i] >= safe_zone[population - 1]) {
            safe_zone[population++] = fallout[i];
        }
    }

    for (int i = 1; i < population; i++) {
        if (safe_zone[i] < safe_zone[i - 1]) {
            free(safe_zone);
            *survivors = 0;
            return NULL;
        }
    }

    *survivors = population;
    return safe_zone;
}

int main() {
    int fallout[] = {1, 5, 2, 3, 8, 6, 7, 10, 12, 11, 88, 45, 35, 68, 9, 687, 5, 23, 56, 78, 43, 90, 15, 27, 19, 50, 73, 81, 96, 102, 67, 38, 29, 59, 123, 134, 144, 199, 210, 305, 407, 506, 608, 701, 85, 95, 107, 207, 307, 408, 510, 612, 750, 888, 920, 1001, 1115, 1212, 1325, 1423, 1538, 1647, 1777, 1899, 1934, 2000};
    
    int fallout_size = sizeof(fallout) / sizeof(fallout[0]);
    printf("The size of the given array: %d\n", fallout_size);
    int survivors;
    int* safe_zone = nagasakiSort(fallout, fallout_size, &survivors);

    if (safe_zone == NULL) {
        printf("After the blast... unfortunately, no survivors detected. Everything is gone!\n");
    } else {
        printf("Survivors from the blast (Nagasaki Sort Result):\n");
        for (int i = 0; i < survivors; i++) {
            printf("%d ", safe_zone[i]);
        }
        printf("\nEvacuation successful! Number of survivors: %d\n", survivors);
        free(safe_zone);
    }

    return 0;
}
