#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

string inp[3];
int board[3][3];
int Count[9] = {};

int main() {
    for (int i = 0; i < 3; i++) cin >> inp[i];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = inp[i][j] - '0';
        }
    }

    // Please write your code here.
    set<pair<int,int>> s;
    int size = 0;

    // 행 기준
    for(int i = 0; i < 3; i++) {
        fill(Count, Count+9, 0);
        size = 0;
        for(int j = 0; j < 3; j++) {
            Count[board[i][j]-1]++;
        }
        for(int j = 0; j < 9; j++) {
            if(Count[j] > 0) size++;
        }
        if(size == 2) {
            int a1 = -1, a2 = -1;
            for(int j = 0; j < 9; j++) {
                if(Count[j] > 0) {
                    if(a1 == -1) a1 = j;
                    else a2 = j;
                }
            }
            if(a1 < a2) s.insert({a1, a2});
            else s.insert({a2, a1});
        }
    }
    // 열 기준
    for(int i = 0; i < 3; i++) {
        fill(Count, Count+9, 0);
        size = 0;
        for(int j = 0; j < 3; j++) {
            Count[board[j][i]-1]++;
        }
        for(int j = 0; j < 9; j++) {
            if(Count[j] > 0) size++;
        }
        if(size == 2) {
            int a1 = -1, a2 = -1;
            for(int j = 0; j < 9; j++) {
                if(Count[j] > 0) {
                    if(a1 == -1) a1 = j;
                    else a2 = j;
                }
            }
            if(a1 < a2) s.insert({a1, a2});
            else s.insert({a2, a1});
        }
    }
    // 대각선 기준
    fill(Count, Count+9, 0);
    size = 0;
    for(int i = 0; i < 3; i++) {
        Count[board[i][i]-1]++;
    }
    for(int j = 0; j < 9; j++) {
            if(Count[j] > 0) size++;
    }
    if(size == 2) {
            int a1 = -1, a2 = -1;
            for(int j = 0; j < 9; j++) {
                if(Count[j] > 0) {
                    if(a1 == -1) a1 = j;
                    else a2 = j;
                }
            }
            if(a1 < a2) s.insert({a1, a2});
            else s.insert({a2, a1});
        }
    // 역대각선 기준
    fill(Count, Count+9, 0);
    size = 0;
    for(int i = 0; i < 3; i++) {
        Count[board[2-i][i]-1]++;
    }
    for(int j = 0; j < 9; j++) {
            if(Count[j] > 0) size++;
    }
    if(size == 2) {
            int a1 = -1, a2 = -1;
            for(int j = 0; j < 9; j++) {
                if(Count[j] > 0) {
                    if(a1 == -1) a1 = j;
                    else a2 = j;
                }
            }
            if(a1 < a2) s.insert({a1, a2});
            else s.insert({a2, a1});
        }

    cout << s.size();
    return 0;
}