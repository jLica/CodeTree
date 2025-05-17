#include <iostream>

using namespace std;

int X, Y;

int figureSum(int num) {
    int tens = 1;
    // 12345 -> (12345 / 10000) % 10 -> 1
    // 12345 -> (12345 / 1000) % 10 -> 2
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += (num/tens)%10;
        tens *= 10;
    }
    return sum;
}

int main() {
    cin >> X >> Y;

    // Please write your code here.
    int maxSum = 0;
    for(int i = X; i <= Y; i++) {
        maxSum = max(figureSum(i), maxSum);
    }
    cout << maxSum;
    return 0;
}