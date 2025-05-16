#include <iostream>

using namespace std;

int k, n;
int arr[10][20];

bool isWon(int idx, int a, int b) {
    int a_idx, b_idx;
    for(int i = 0; i < n; i++) {
        if(arr[idx][i] == a) a_idx = i;
        else if(arr[idx][i] == b) b_idx = i;
    }
    return a_idx < b_idx;
}

int main() {
    cin >> k >> n;

    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];

    // Please write your code here.
    bool isAlwaysWin = true;
    int count = 0;
    int l;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            isAlwaysWin = true; // (i,j) 순서쌍
            for(l = 0; l < k; l++) {
                if(!isWon(l, i, j)) {
                    isAlwaysWin = false;
                    break;
                }
            }
            if(isAlwaysWin) count++;
        }
    }
    cout << count;
    return 0;
}