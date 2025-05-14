#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int n;
int x[100], y[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Please write your code here.
    int min_square = INT_MAX;
    int square;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            square = pow((x[i]-x[j]), 2) + pow((y[i]-y[j]), 2);
            min_square = min(min_square, square);
        }
    }
    cout << min_square;
    return 0;
}