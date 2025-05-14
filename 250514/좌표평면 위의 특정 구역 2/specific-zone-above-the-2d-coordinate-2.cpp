#include <iostream>
#include <climits>

using namespace std;

int N;
int x[100], y[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    // Please write your code here.
    int max_x = INT_MIN, max_y = INT_MIN;
    int min_area = INT_MAX;
    for(int i = 0; i < N; i++) { // 건너뛸 인덱스
        max_x = INT_MIN;
        max_y = INT_MIN;
        for(int j = 0; j < N-1; j++) { // 탐색 시작
            if(j==i) continue;
            for(int k = j+1; k < N; k++) {
                if(k==i) continue;
                max_x = max(max_x, abs(x[j]-x[k]));
                max_y = max(max_y, abs(y[j]-y[k]));
            }
        }
        min_area = min(min_area, max_x*max_y); 
    }
    cout << min_area;
    return 0;
}