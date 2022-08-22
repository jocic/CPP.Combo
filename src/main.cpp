#include "combo.h"

/**
 *
 */
int main(int argc, char *argv[]) {

    int set[] = { 1, 2, 3, 4 };
    int set_len = sizeof(set) / sizeof(int);

    int *combo = (int*)calloc(set_len, sizeof(int));
    int  combo_len = set_len;

    Combinations c(set, set_len, 1, 3);

    while (c.has_next()) {
        c.next(combo, combo_len, Combinations::BY_VALUE); // OR Combinations::BY_INDICES
        c.print(combo, combo_len);
    }
}