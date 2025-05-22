#include <iostream>
#include <string>
#include <climits>

using namespace std;

int N;
string seat;

int min_distance() {
    bool nowCounting = false;
    int distance = 1;
    int result = INT_MAX;
    for(int i = 0; i < N; i++) {
        if(seat[i] == '1') {
            if(!nowCounting) {
                nowCounting = true;
                distance = 0;
            }
            else {
                result = min(distance, result);
                distance = 0;
            }
        }
        distance++;
    }
    return result;
}

int main() {
    cin >> N;
    cin >> seat;

    // Please write your code here.
    int max_min_distance = 0;
    for(int i = 0; i < N-1; i++) {
        if(seat[i] == '1') continue;
        seat[i] = '1';
        for(int j = i+1; j < N; j++) {
            if(seat[j] == '1') continue;
            seat[j] = '1';
            max_min_distance = max(min_distance(), max_min_distance);
            seat[j] = '0';
        }
        seat[i] = '0';
    }
    cout << max_min_distance;
    return 0;
}