#include <iostream>

using namespace std;

int A, B, C;

int main() {
    cin >> A >> B >> C;

    // Please write your code here.
    int max_value = 0;
    int value = 0;
    for(int i = 0; i <= C/A+1; i++) {
        value = A*i;
        for(int j = 0; j <= C/B+1; j++) {
            value += B;
            if(value <= C)
                max_value = max(value, max_value);
        }
    }
    cout << max_value;
    return 0;
}