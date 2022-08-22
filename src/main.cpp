#include "combo.h"

/**
 *
 */
int main(int argc, char *argv[]) {

    int set[] = { 1, 2, 3, 4 };
    int set_len = sizeof(set) / sizeof(int);

    int *combo;
    int  combo_len;

    Combinations c(&set[0], set_len, "1-3");
    //Combinations c(&set[0], set_len, 1, 3);
    //Combinations c(&set[0], set_len, 2);

    combo = c->init(&combo_len);

    while (c.has_next()) {

        c.next(Combinations::BY_VALUE);
        //c.next(Combinations::BY_INDICES);

        c.print();

        for (int i = 0; i < combo_len; i++) {
            // do stuff
        }
    }
}
