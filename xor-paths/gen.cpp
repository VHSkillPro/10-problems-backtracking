#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const ll MAX_A = 1e18;

vector<vector<ll>> trace(20, vector<ll>(20));

void place(int x, int y, int n, int m, ll k, vector<vector<ll>> &a) {
    if (x == n - 1 && y == m - 1) {
        a[x][y] = k;
        return ;
    }

    a[x][y] = rnd.next(0ll, MAX_A);
    
    if (x + 1 < n) {
        if (a[x + 1][y] != -1) {
            int choose = rnd.next(0, 1);
            if (choose) {
                a[x][y] = trace[x + 1][y] ^ k;
            }
        }
        else {
            trace[x + 1][y] = k ^ a[x][y];
            place(x + 1, y, n, m, k ^ a[x][y], a);
        }
    }

    if (y + 1 < m) {
        if (a[x][y + 1] != -1) {
            int choose = rnd.next(0, 1);
            if (choose) {
                a[x][y] = trace[x][y + 1] ^ k;
            }
        }
        else {
            trace[x][y + 1] = k ^ a[x][y];
            place(x, y + 1, n, m, k ^ a[x][y], a);
        }
    }
}

/**
 * Generate a random test case
 * @param n: number of rows
 * @param m: number of columns
 * @param large_answer: whether to generate a large answer
 */
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int large_answer = atoi(argv[3]);

    ll k;
    if (large_answer) k = rnd.next(0, 1);
    else k = rnd.next(0ll, MAX_A);

    vector<vector<ll>> a(n, vector<ll>(m, -1));
    if (large_answer) {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                a[i][j] = rnd.next(0, 1);
    } else {
        place(0, 0, n, m, k, a);
    }

    cout << n << " " << m << " " << k << "\n";
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cout << a[i][j] << " \n"[j == m - 1];

    return 0;
}