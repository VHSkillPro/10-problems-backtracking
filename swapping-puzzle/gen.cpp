#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

/**
 * Generate a random test case
 * @param h: number of rows
 * @param w: number of columns
 * @param haveAns: whether to generate the answer
 */
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int h = atoi(argv[1]);
    int w = atoi(argv[2]);
    int haveAns = atoi(argv[3]);

    int a[6][6];
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            a[i][j] = rnd.next(1, 1'000'000'000);

    int p[6], q[6];
    for (int i = 1; i <= h; ++i) p[i] = i;
    for (int i = 1; i <= w; ++i) q[i] = i;

    shuffle(p + 1, p + h + 1);
    shuffle(q + 1, q + w + 1);

    int b[6][6];
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            b[i][j] = a[p[i]][q[j]];

    if (!haveAns) {
        while (b[1][1] == a[p[1]][q[1]])
            b[1][1] = rnd.next(1, 1'000'000'000);
    }

    cout << h << " " << w << endl;
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            cout << a[i][j] << " \n"[j == w];

    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            cout << b[i][j] << " \n"[j == w];

    return 0;
}