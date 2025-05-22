#include <iostream>

using namespace std;

int N, K;
int arr[1000];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    
    int maxCount = 0;
    for(int i = 0; i < N; i++) {
        int count = 0;
        for(int j = 0; j < N; j++) {
            if(arr[j] <= arr[i]+K && arr[j] >= arr[i]) count++;
        }
        maxCount = max(count, maxCount);
    }
    cout << maxCount;
    return 0;
}