#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include <cstdlib>

using namespace std;

class Combinations {

public:

    static int BY_VALUE;
    static int BY_MAP;

    Combinations(int *set, int n, char *k);
    Combinations(int *set, int n, int k);
    Combinations(int *set, int n, int k_min, int k_max);

    bool has_next();
    void next(int *arr, int len, int type);
    void print(int *arr, int len);
    void reset();

private:

    int *set, *map;
    int  set_len, map_len;

    int k, k_min, k_max;

    int i, j, z;

    void __parse_subset_range(char *k, int *min, int *max);
    void __init_map();
    void __normalize_map(int index);
};
