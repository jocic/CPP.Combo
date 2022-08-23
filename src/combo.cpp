/*******************************************************************\
|* Author: Djordje Jocic                                           *|
|* Year: 2022                                                      *|
|* License: MIT License (MIT)                                      *|
|* =============================================================== *|
|* Personal Website: http://www.djordjejocic.com/                  *|
|* =============================================================== *|
|* Permission is hereby granted, free of charge, to any person     *|
|* obtaining a copy of this software and associated documentation  *|
|* files (the "Software"), to deal in the Software without         *|
|* restriction, including without limitation the rights to use,    *|
|* copy, modify, merge, publish, distribute, sublicense, and/or    *|
|* sell copies of the Software, and to permit persons to whom the  *|
|* Software is furnished to do so, subject to the following        *|
|* conditions.                                                     *|
|* --------------------------------------------------------------- *|
|* The above copyright notice and this permission notice shall be  *|
|* included in all copies or substantial portions of the Software. *|
|* --------------------------------------------------------------- *|
|* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, *|
|* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES *|
|* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND        *|
|* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT     *|
|* HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,    *|
|* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, RISING     *|
|* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR   *|
|* OTHER DEALINGS IN THE SOFTWARE.                                 *|
\*******************************************************************/

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
Combinations::Combinations(int *set, int n, int k) {

    if (set == NULL) {
        throw std::invalid_argument("[x] Provided set can't be NULL...");
    } else if (n <= 0) {
        throw std::invalid_argument("[x] Invalid length provided...");
    } else if (k < 1 || k > n) {
        throw std::invalid_argument("[x] Invalid subset range provided...");
    }

    this->set     = set;
    this->set_len = n;

    this->k = k;

    this->i = 0;
    this->j = 1;
    this->z = n;

    this->__init_map();
}

/**
 *
 */
int* Combinations::init(int *len) {

    this->combo = (int*)calloc(this->set_len, sizeof(int));

    *len = this->k;

    this->init_ran = true;

    return this->combo;
}

/**
 *
 */
bool Combinations::has_next() {

    if (!this->init_ran) {
        throw std::invalid_argument("[x] Not initialized...");
    }

    if (this->k == 1) {
        return this->map[0] != this->set_len - 1;
    }

    return !(this->map[0] == this->set_len - 1 && this->map[this->k - 1] == this->set_len - 2);
}

/**
 *
 */
void Combinations::next(int type) {

    if (!this->init_ran) {
        throw std::invalid_argument("[x] Not initialized...");
    }

    test:

    this->map[this->i]++;

    if (this->map[this->i] >= this->z) {

        this->map[this->j]++;

        if (this->map[this->j] >= this->z - 1) {

            this->i = this->j;
            this->j = this->i + 1;

            this->z--;
            goto test;
        }

        this->__normalize_map(this->j);
    }

    for (int i = 0, j; i < this->k && i < this->set_len; i++) {

        j = this->map[i];

        this->combo[i] = type == Combinations::BY_VALUE ? this->set[j] : j;
    }
}

/**
 *
 */
void Combinations::print() {

    if (!this->init_ran) {
        throw std::invalid_argument("[x] Not initialized...");
    }

    int len = this->k;
    int *arr_cb = this->combo;

    cout << "[*] C = { ";

    while (len-- > 1) {
        cout << *arr_cb++ << ", ";
    }

    cout << *arr_cb << " }" << endl;
}

/**
 *
 */
void Combinations::reset(){

    if (!this->init_ran) {
        throw std::invalid_argument("[x] Not initialized...");
    }
}

/**
 *
 */
void Combinations::__init_map() {

    this->map     = (int*)calloc(this->set_len, sizeof(int));
    this->map_len = this->set_len;

    for (int i = 0, j = this->k - 1; i < k; i++, j--) {
        this->map[i] = j;
    }

    this->map[0]--;
}

/**
 *
 */
void Combinations::__normalize_map(int index) {

    for (int j = this->map[index]; index >= 0; index--, j++) {
        map[index] = j;
    }
}
