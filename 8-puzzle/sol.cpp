#include <bits/stdc++.h>
#define taskname "sol"
#define st first
#define nd second
using namespace std;

typedef pair<int, int> ii;
const int finalState = 123456789;
const vector<ii> mov = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
const vector<char> direct = {'D', 'L', 'R', 'U'};
const vector<int> p10 = {
    1, 10, 100, 
    1000, 10000, 100000, 
    1000000, 10000000, 100000000
};
int nTest = 1;

map<int, int> dist;

void Input() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> nTest;
}

int swap(int u, int i, int j) {
    int x = (u / p10[8 - i]) % 10, y = (u / p10[8 - j]) % 10;
    return u - x * p10[8 - i] + y * p10[8 - i]
             - y * p10[8 - j] + x * p10[8 - j];
}

void Init() {
    queue<ii> qu;

    dist[finalState] = 0;
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
                qu.push({v, vPos});
            }
        }
    }
}

void Solve() {
    string sStr; cin >> sStr;
    int sPos = sStr.find('X');
    sStr[sPos] = '9';
    int s = stoi(sStr);

    string curPath = "";
    vector<string> ansPath; 
    function<void(int, int)> dfs = [&](int u, int uPos) {
        if (u == finalState) {
            ansPath.push_back(curPath);
            return;
        }

        for (int i = 0; i < 4; ++i) {
            ii _vPos = {uPos / 3 + mov[i].st, uPos % 3 + mov[i].nd};
            if (0 > _vPos.st || _vPos.st >= 3 || 0 > _vPos.nd || _vPos.nd >= 3) continue;
            int vPos = _vPos.st * 3 + _vPos.nd;

            int v = swap(u, uPos, vPos);
            if (dist[v] + 1 == dist[u]) {
                curPath += direct[i];
                dfs(v, vPos);
                curPath.pop_back();
            }
        }
    };
    dfs(s, sPos);

    cout << dist[s] << "\n";
    sort(ansPath.begin(), ansPath.end());
    for (const string &path : ansPath) cout << path << "\n";
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        freopen(argv[1], "r", stdin);
        freopen(argv[2], "w", stdout);
    }
    Input();
    Init();
    while (nTest--) Solve();
    return 0;
}