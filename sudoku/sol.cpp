#include <bits/stdc++.h>
using namespace std;

void solveSudoku(vector<vector<char>>& board) {
    vector<vector<char>> ans;
    vector<vector<bool>> row(9, vector<bool>(10, false));
    vector<vector<bool>> col(9, vector<bool>(10, false));
    vector<vector<bool>> square(9, vector<bool>(10, false));
    vector<pair<int, int>> cells;

    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j) 
            if (board[i][j] != '.') {
                int c = board[i][j] - '0';

                row[i][c] = true;
                col[j][c] = true;

                int s_row = i / 3;
                int s_col = j / 3;
                square[s_row * 3 + s_col][c] = true;
            }
    
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j) 
            if (board[i][j] == '.') 
                cells.push_back({i, j});

    bool haveAns = false;
    function<void(int)> backtrack = [&](int i) {
        if (haveAns) return ;

        if (i == cells.size()) {
            haveAns = true;
            ans = board;
            return ;
        }

        int r = cells[i].first;
        int c = cells[i].second;
        int s = (r / 3) * 3 + c / 3;

        for (int d = 1; d <= 9; ++d) {
            if (row[r][d] || col[c][d] || square[s][d]) continue;
            
            board[r][c] = char(d + '0');
            row[r][d] = col[c][d] = square[s][d] = true;

            backtrack(i + 1);

            board[r][c] = '.';
            row[r][d] = col[c][d] = square[s][d] = false;
        }
    };
    backtrack(0);

    board = ans;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (argc > 1) {
        freopen(argv[1], "r", stdin);
        freopen(argv[2], "w", stdout);
    }

    vector<vector<char>> board(9, vector<char>(9));
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            cin >> board[i][j];

    solveSudoku(board);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            cout << board[i][j];
        cout << "\n";
    }

    return 0;
}