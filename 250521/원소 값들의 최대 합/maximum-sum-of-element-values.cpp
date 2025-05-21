#include <iostream>

using namespace std;

int n, m;
int arr[100];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int maxSum = 0;
    for(int i = 0; i < n; i++) {
        int point = i;
        int sum = arr[point];
        for(int j = 0; j < m-1; j++) {
            point = arr[i]-1;
            sum += arr[point];
        }
        maxSum = max(sum, maxSum);
    }
    cout << maxSum;
    return 0;
}