#include <bits/stdc++.h>
#include "testlib.h"
#define st first
#define nd second
using namespace std;

typedef pair<int, int> ii;

const int finalState = 123456789;
const vector<ii> mov = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
const vector<int> p10 = {
    1, 10, 100, 
    1000, 10000, 100000, 
    1000000, 10000000, 100000000
};

int swap(int u, int i, int j) {
    int x = (u / p10[8 - i]) % 10, y = (u / p10[8 - j]) % 10;
    return u - x * p10[8 - i] + y * p10[8 - i]
             - y * p10[8 - j] + x * p10[8 - j];
}

vector<string> initState() {
    queue<ii> qu;
    map<int, int> dist;
    map<int, int> ways;

    dist[finalState] = 0;
    ways[finalState] = 1;
    qu.push({finalState, 8});

    while (!qu.empty()) {
        auto [u, uPos] = qu.front(); qu.pop();
        
        for (int i = 0; i < 4; ++i) {
            ii _vPos = {uPos / 3 + mov[i].st, uPos % 3 + mov[i].nd};
            if (0 > _vPos.st || _vPos.st >= 3 || 0 > _vPos.nd || _vPos.nd >= 3) continue;
            int vPos = _vPos.st * 3 + _vPos.nd;

            int v = swap(u, uPos, vPos);
            if (!dist.count(v)) {
                dist[v] = dist[u] + 1;
                ways[v] = ways[u];
                qu.push({v, vPos});
            }
            else {
                ways[v] += ways[u];
            }
        }
    }

    vector<string> state;
    for (auto [u, d] : dist) 
        if (ways[u] >= 10) {
            string uStr = to_string(u);
            uStr[uStr.find('9')] = 'X';
            state.push_back(uStr);
        }
    shuffle(state.begin(), state.end());

    return state;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    vector<string> state = initState();
    
    // Compile solution
    system("g++ sol.cpp -o sol");

    int nTest = 100;
    for (int iTest = 0; iTest < nTest; ++iTest) {
        clock_t begin = clock();
        string fileInp = "./tests/" + to_string(iTest);
        string fileAns = "./tests/" + to_string(iTest) + ".a";

        // Generate file input
        ofstream fo(fileInp);
        fo << 10 << "\n";
        for (int i = iTest * 10; i < (iTest + 1) * 10; ++i) {
            fo << state[i] << "\n";
        }
        fo.close();

        // Generate file answer
        system(("./sol " + fileInp + " " + fileAns).c_str());

        clock_t end = clock();
        cout << fixed << "Testcase " << iTest << ": " << (end - begin + 0.0) / CLOCKS_PER_SEC << "s\n";
    }
    return 0;
}