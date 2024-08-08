#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

/**
 * Generate testcases for connect-wire
 * @param n: number of wires
 * @param zeroAns: if true, the answer will be 0
 * @param seed: random seed
 */
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = atoi(argv[1]);
    int zeroAns = atoi(argv[2]);

    int a = rnd.next(1, 1000);
    int b = rnd.next(1, 1000);
    int c = rnd.next(1, 1000);

    vector<int> l(n);
    for (int i = 0; i < n; ++i)
        l[i] = rnd.next(1, 1000);

    if (zeroAns) {
        a = l[0];
        b = l[1];
        c = l[2];
    }

    cout << n << " " << a << " " << b << " " << c << "\n";
    for (int i = 0; i < n; ++i)
        cout << l[i] << " \n"[i == n - 1];

    return 0;
}