#include <iostream>

using namespace std;

int X, Y;

int main() {
    cin >> X >> Y;

    // Please write your code here.
    int count = 0;
    int num, size;
    for(int i = X; i <= Y; i++) {
        int figures[10] = {};
        size = 0;
        num = i;
        while(num > 0) {
            figures[num%10]++;
            num /= 10;
            size++;
        }
        for(int j = 0; j < 10; j++) {
            if(figures[j] == size-1) {
                count++;
                break;
            }
        }
    }
    cout << count;
    return 0;
}