#include <iostream>
#include <climits>

using namespace std;

int n, k;
int arr[100];

int get_cost(int minimum) {
    int cost = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] < minimum) cost += minimum-arr[i];
        else if(arr[i] > minimum+k) cost += arr[i]-minimum-k;
    }
    return cost;
}

int main() {
    cin >> n >> k;
    int min_num = INT_MAX;
    int max_num = INT_MIN;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        min_num = min(arr[i], min_num);
        max_num = max(arr[i], max_num);
    }

    // Please write your code here.
    int min_cost = INT_MAX;
    for(int i = min_num; i <= max_num; i++) {
        min_cost = min(get_cost(i), min_cost);
    }
    cout << min_cost;
    return 0;
}