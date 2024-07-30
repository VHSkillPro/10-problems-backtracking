#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

/**
 * Generate a random test case
 * @param n: number of tiles
 * @param h: number of rows
 * @param w: number of columns
 * @param seed: random seed
 */
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int h = atoi(argv[2]);
    int w = atoi(argv[3]);

    cout << n << " " << h << " " << w << "\n";
    for (int i = 0; i < n; i++) 
        cout << rnd.next(1, min(10, h + 2)) << " " << rnd.next(1, min(10, w + 2)) << "\n";

    return 0;
}