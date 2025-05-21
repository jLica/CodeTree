#include <iostream>
#include <string>
#include <climits>

using namespace std;

int N;
string seat;

int MinDistance() {
    int distance = 0;
    int result = INT_MAX;
    for(int i = 0; i < N; i++) {
        if(seat[i] == '1') {
            if(distance > 0) result = min(distance, result);
            distance = 0;
        }
        distance++;
    }
    return result;
}

int main() {
    cin >> N;
    cin >> seat;

    // Please write your code here.
    int max_distance = 0;

    for(int i = 0; i < N; i++) {
        if(seat[i] == '1') continue;
        seat[i] = '1';
        max_distance = max(MinDistance(), max_distance);
        seat[i] = '0';
    }
    cout << max_distance;
    return 0;
}