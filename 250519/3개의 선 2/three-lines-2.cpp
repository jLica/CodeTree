#include <iostream>

using namespace std;

int n;
int x[20], y[20];
int x_points[11] = {};
int y_points[11] = {};

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        x_points[x[i]]++;
        y_points[y[i]]++;
    }

    // Please write your code here.
    // greedy하게 탐색?

    for(int i = 0; i < 3; i++) {
        int x_max_count = -1;
        int y_max_count = -1;
        int x_max_idx;
        int y_max_idx;
        for(int j = 0; j <= 10; j++) {
            if(x_max_count < x_points[j]) {
                x_max_count = x_points[j];
                x_max_idx = j;
            }
            if(y_max_count < y_points[j]) {
                y_max_count = y_points[j];
                y_max_idx = j;
            }
        }
        if(y_max_count > x_max_count){
            y_points[y_max_idx] = 0;
            for(int k = 0; k < n; k++) {
                if(y[k] == y_max_idx) {
                    x_points[x[k]]--;
                }
            }
        }
        else {
            x_points[x_max_idx] = 0;
            for(int k = 0; k < n; k++) {
                if(x[k] == x_max_idx) {
                    y_points[y[k]]--;
                }
            }
        }

    }
    for(int i = 0; i <= 10; i++) {
        if(x_points[i] > 0 || y_points[i] > 0) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}