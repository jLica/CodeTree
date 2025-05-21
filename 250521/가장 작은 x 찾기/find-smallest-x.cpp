#include <iostream>

using namespace std;

int n;
int a[10], b[10];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    // Please write your code here.
    bool isSatisfied = true;
    for(int i = 1; i <= 10000; i++) {
        isSatisfied = true;
        int num = i;
        for(int j = 0; j < n; j++) {
            num *= 2;
            if(num < a[j] || num > b[j]) {
                isSatisfied = false;
                break;
            }
        }
        if(isSatisfied) {
            cout << i;
            break;
        }
    }
    return 0;
}