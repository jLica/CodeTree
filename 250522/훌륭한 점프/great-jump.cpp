#include <iostream>

using namespace std;

int n, k;
int arr[100];

int max_distance(int maximum) {
    int distance = 1;
    int result = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] <= maximum) {
            result = max(distance, result);
            distance = 1;
            continue;
        }
        distance++;
    }
    return result;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    for(int i = 1; i <= 100; i++) { // i가 최댓값이라 가정
        if(max_distance(i) <= k) {
            cout << i;
            break;
        }
    }
    return 0;
}