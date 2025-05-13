#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> v;
int N, K;

int main() {
    // Please write your code here.
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v.push_back({v1, v2});
    }

    int sum = 0;
    int maxSum = 0;

    for(int i = 0; i <= 100; i++) {
        sum = 0;
        for(int j = 0; j < N; j++) {
            if(v[j].second < i-K || v[j].second > i+K) continue;
            sum += v[j].first;
        }
        maxSum = max(sum, maxSum);
    }
    cout << maxSum;
    return 0;
}