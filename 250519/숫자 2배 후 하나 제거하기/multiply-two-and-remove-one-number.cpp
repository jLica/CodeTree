#include <iostream>
#include <climits>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int min_diff = INT_MAX;
    for(int i = 0; i < n; i++) { // 2배
        arr[i] *= 2;
        for(int j = 0; j < n; j++) { // 건너뛸 인덱스
            int diff = 0;
            
            for(int k = 0; k < n-1; k++) {
                if(k == j-1 && k < n-2) {
                    diff += abs(arr[k+2] - arr[k]);
                    continue;
                }
                if(k == j) continue;
                diff += abs(arr[k+1]-arr[k]);
            }
            min_diff = min(diff, min_diff);
        }
        arr[i] /= 2;
    }
    cout << min_diff;
    return 0;
}