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
 * Test implementation of the "combo" library.
 *
 * @author    Djordje Jocic <office@djordjejocic.com>
 * @copyright 2022 All Rights Reserved
 * @version   1.0.0
 *
 * @param int argc
 *   Number of passed arguments.
 * @return char* argv[]
 *   Array containing passed arguments.
 */
int main(int argc, char* argv[]) {

    int set[] = { 1, 2, 3, 4 };
    int set_len = sizeof(set) / sizeof(int);

    int* combo;
    int  combo_len;

    int sum;

    Combinations c(set, set_len, 2);

    combo = c.init(&combo_len);

    while (c.has_next()) {

        // Get & Print Next Combination

        c.next(Combinations::BY_VALUE);

        c.print();

        // Do Something With The Values

        sum = 0;

        for (int i = 0; i < combo_len; i++) {
            sum += combo[i];
        }

        cout << "[*] S = " << sum << endl;
    }
}
