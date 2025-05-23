#include <iostream>
#include <climits>
using namespace std;

int n, m;
int a[100];
int sum[100] = {};

int max_count() {
    int result = 0;
    for(int i = 0; i < m; i++) {
        result = max(sum[i], result);
    }
    return result;
}

int min_max_count(int start_idx, int step) {
    if(step == m) {
        if(start_idx != n) return INT_MAX; // 마지막에 수가 남은 경우
        return max_count();
    }
    if(start_idx >= n) return INT_MAX; // 마지막이 아니지만 수가 안 남은 경우

    int result = INT_MAX;
    for(int i = 1; i < n; i++) { // 이번 스텝에서 더할 개수
        sum[step] = 0;
        for(int j = 0; j < i; j++) { // 실제로 더하는 과정
            sum[step] += a[start_idx+j];
        }
        result = min(result, min_max_count(start_idx+i, step+1));
    }
    return result;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Please write your code here.
    cout << min_max_count(0, 0);
    return 0;
}