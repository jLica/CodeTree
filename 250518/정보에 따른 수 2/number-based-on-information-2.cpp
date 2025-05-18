#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int T, a, b;
char c[1000];

int nearestDistance(int position, char alphabet) {
    int min_distance = INT_MAX;
    int distance;

    for(int i = position; i >= 0; i--) {
        if(c[i] == alphabet) {
            distance = position-i;
            min_distance = distance;
            break;
        }
    }
    for(int i = position; i < 1000; i++) {
        if(c[i] == alphabet) {
            distance = i-position;
            min_distance = min(distance, min_distance);
            break;
        }
    }
    return min_distance;
}

bool isSatisfied(int position) {
    int distance_S = nearestDistance(position, 'S');
    int distance_N = nearestDistance(position, 'N');
    return (distance_S <= distance_N);
}

int main() {
    cin >> T >> a >> b;

    int position;
    char alphabet;

    fill(c, c+1000, 'X');

    for (int i = 0; i < T; i++) {
        cin >> alphabet >> position;
        c[position-1] = alphabet;
    }

    // Please write your code here.
    int count = 0;
    for(int i = a-1; i <= b-1; i++) {
        if(isSatisfied(i)) count++;
    }
    cout << count;
    return 0;
}