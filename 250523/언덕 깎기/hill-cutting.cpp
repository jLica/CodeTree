#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int N;
int heights[1000];

int get_cost(int height) {
    int result = 0;
    for(int i = 0; i < N; i++) {
        if(heights[i] < height) { // 최소 기준에 못 미치는 경우
            result += pow((height-heights[i]), 2);
            continue;
        }
        int difference = heights[i] - height;
        if(difference > 17) {
            result += pow((difference-17), 2);
        }
    }
    return result;
}

int main() {
    cin >> N;
    int min_height = INT_MAX;
    int max_height = INT_MIN;

    for (int i = 0; i < N; i++) {
        cin >> heights[i];
        min_height = min(heights[i], min_height);
        max_height = max(heights[i], max_height);
    }

    // Please write your code here.
    int min_cost = INT_MAX;
    for(int i = min_height; i <= max_height; i++) { // 최소 기준에 맞추기 위한 비용을 계산
        min_cost = min(get_cost(i), min_cost);
    }
    cout << min_cost;
    return 0;
}