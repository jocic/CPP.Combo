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

#ifndef COMBO_H

#define COMBO_H

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

    Combinations(int* set, int n, int k);

    int* init(int *len);
    bool has_next();
    void next(int type);
    void print();
    void print(int *arr, int len);
    void reset();

private:

    bool init_ran;

    int *combo;

    int *set, *map;
    int  set_len, map_len;

    int k;

    int i, j, z;

    void __init_map();
    void __normalize_map(int index);
};

#endif
