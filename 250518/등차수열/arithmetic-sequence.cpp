#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100];
int K[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Please write your code here.
    fill(K, K+100, 0);

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if((a[i]+a[j])%2 != 0) continue;
            K[(a[i]+a[j])/2]++;
        }
    }
    int maxCount = 0;
    for(int i = 0; i < 100; i++) {
        maxCount = max(maxCount, K[i]);
    }
    cout << maxCount;
    return 0;
}