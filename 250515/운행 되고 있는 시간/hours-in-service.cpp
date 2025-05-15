#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N;
int A[100], B[100];
bool Time[1000];

int getRunningTime(int skipIdx) {
    fill(Time, Time+1000, false); // fill 함수 이용
    int result = 0;

    for(int i = 0; i < N; i++) {
        if(i == skipIdx) continue;
        for(int j = A[i]-1; j <= B[i]-2; j++) {
            Time[j] = true;
        }
    }
    for(int i = 0; i < 1000; i++) {
        result += Time[i];
    }
    return result;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // Please write your code here.
    int maxRunningTime = 0;

    for(int i = 0; i < N; i++) {
        // 겹칠 수 있음
        // 1~6, 5~9면?
        maxRunningTime = max(maxRunningTime, getRunningTime(i));
    }
    cout << maxRunningTime;
    return 0;
}