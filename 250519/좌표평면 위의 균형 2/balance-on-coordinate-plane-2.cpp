#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int x[100];
int y[100];
int N;

int main() {
    // Please write your code here.
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    int min_max_count = INT_MAX;
    int max_count = 0;
    int count1, count2, count3, count4;
    int count[4];
    for(int i = 6; i <= 100; i+=2) { // x
        for(int j = 0; j <= 100; j+=2) { // y
            fill(count, count+4, 0);
            for(int k = 0; k < N; k++) {
                // 왼쪽 위
                if(x[k] < i && y[k] > j) count[0]++;
                // 왼쪽 아래
                else if(x[k] < i && y[k] < j) count[1]++;
                // 오른쪽 위
                else if(x[k] > i && y[k] > j) count[2]++;
                // 오른쪽 아래
                else if(x[k] > i && y[k] < j) count[3]++;
            }
            max_count = 0;
            for(int k = 0; k < 4; k++) {
                max_count = max(count[k], max_count);
            }
            min_max_count = min(max_count, min_max_count);
        }
    }
    cout << min_max_count;
    return 0;
}