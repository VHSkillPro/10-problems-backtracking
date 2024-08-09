#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

/**
 * Generate a random test case
 * @param n: number of rows
 * @param k: size of polymino
 */
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    vector<string> grid(n, string(n, '.'));
    for (int i = 1; i <= n * n / 4; ++i) {
        int x = rnd.next(0, n - 1);
        int y = rnd.next(0, n - 1);
        grid[x][y] = '#';
    }

    cout << n << " " << k << "\n";
    for (int i = 0; i < n; ++i)
        cout << grid[i] << "\n";
        
    return 0;
}