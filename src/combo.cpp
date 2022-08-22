#include "combo.h"

/**
 *
 */
int Combinations::BY_VALUE;

/**
 *
 */
int Combinations::BY_MAP;

/**
 *
 */
Combinations::Combinations(int *set, int n, char *k) {

    int k_min, k_max;

    __parse_subset_range(k, &k_min, &k_max);

    Combinations(set, n, k_min, k_max);
}

/**
 *
 */
Combinations::Combinations(int *set, int n, int k) {

    Combinations(set, n, k, k);
}

/**
 *
 */
Combinations::Combinations(int *set, int n, int k_min, int k_max) {

    if (set == NULL) {
        throw std::invalid_argument("[x] Provided set can't be NULL...");
    } else if (n <= 0) {
        throw std::invalid_argument("[x] Invalid length provided...");
    } else if (k_min < 0 || k_min > k_max) {
        throw std::invalid_argument("[x] Invalid subset range provided...");
    }

    this->set     = set;
    this->set_len = n;

    this->map     = (int*)calloc(n, sizeof(int));
    this->map_len = n;

    this->k = k_min;

    this->i == 0;
    this->j == 1;
    this->z == n;
}

/**
 *
 */
bool Combinations::has_next() {

    return true;
}

/**
 *
 */
void Combinations::next(int *arr, int len, int type) {

    this->map[this->i]++;

    if (this->map[this->i] >= this->z) {

        this->map[this->j]++;

        if (this->map[this->j] >= this->z - 1) {

            this->i = this->j;
            this->j = this->i + 1;

            this->z--;
        }

        this->__normalize_map(j);

        for (int i = 0, j = 0; i < len && i < this->set_len; j = this->map[i], i++) {
            arr[i] = this->set[j];
        }
    }
}

/**
 *
 */
void Combinations::print(int *arr, int len) {

    cout << "[*] C= ";

    while (len-- > 0) {
        cout << *arr++;
    }

    cout << endl;
}

/**
 *
 */
void Combinations::reset(){
}
/**
 *
 */
void Combinations::__parse_subset_range(char *k, int *min, int *max) {

    char *min_pt, *max_pt;

    min_pt = k;

    if ((max_pt = strchr(k, '-')) == NULL) {
        throw std::invalid_argument("[*] Invalid subset format provided...");
    }

    *max_pt = '\0';

    max_pt++;

    *min = atoi(min_pt);
    *max = atoi(max_pt);
}

/**
 *
 */
void Combinations::__init_map() {

    for (int i = 0; i < this->map_len; i++) {
        this->map[i] = i < k ? i : 0;
    }
}

/**
 *
 */
void Combinations::__normalize_map(int index) {

    for (int j = this->map[index]; index >= 0; index--, j++) {
        map[index] = j;
    }
}
