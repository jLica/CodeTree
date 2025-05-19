#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

string inp[3];
int board[3][3];

void check_a_bingo(int a1, int a2, int a3, set<pair<int, int>>& s) {
    int size = 0;
    int Count[9] = {};
    vector<int> v;
    Count[a1-1]++; Count[a2-1]++; Count[a3-1]++; 
    for(int j = 0; j < 9; j++) {
        if(Count[j] > 0) v.push_back(j);
    }
    if(v.size() == 2) {
        s.insert({v[0], v[1]});
    }
}

int main() {
    for (int i = 0; i < 3; i++) cin >> inp[i];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = inp[i][j] - '0';
        }
    }

    // Please write your code here.
    set<pair<int,int>> s;
    for(int i = 0; i < 3; i++) {
        // 행 기준
        check_a_bingo(board[i][0], board[i][1], board[i][2], s);
        // 열 기준
        check_a_bingo(board[0][i], board[1][i], board[2][i], s);
    }
    // 대각선 기준
    check_a_bingo(board[0][0], board[1][1], board[2][2], s);
    // 역대각선 기준
    check_a_bingo(board[2][0], board[1][1], board[0][2], s);
    cout << s.size();
    return 0;
}