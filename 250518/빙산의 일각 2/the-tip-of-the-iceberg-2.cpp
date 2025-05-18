#include <iostream>

using namespace std;

int n;
int h[100];

int count(int height) {
    bool nowInBlock = false;
    int result = 0;
    for(int i = 0; i < n; i++) {
        if(nowInBlock) {
            if(h[i] > height) continue;
            else nowInBlock = false;
        }
        else {
            if(h[i] <= height) continue;
            else {
                nowInBlock = true;
                result++;
            }
        }
    }
    return result;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    // Please write your code here.
    int maxCount = 0;
    for(int i = 1; i <= 1000; i++) {
        maxCount = max(count(i), maxCount);
    }
    cout << maxCount;
    return 0;
}