#include <iostream>

using namespace std;

int N;
int a1, b1, c1;
int a2, b2, c2;

int distance(int a, int b) {
    int distance1 = abs(a-b);
    int distance2 = abs(abs(a-b)-N);
    return min(distance1, distance2);
}

int main() {
    cin >> N;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    // Please write your code here.
    int count = 0;
    for(int i = 1; i <= N; i++) {
        if(distance(a1, i) > 2 && distance(a2, i) > 2) {
            continue;
        }
        for(int j = 1; j <= N; j++) {
            if(distance(b1, j) > 2 && distance(b2, j) > 2) {
                continue;
            }
            for(int k = 1; k <= N; k++) {
                if((distance(a1, i) <= 2 && distance(b1, j) <= 2 && distance(c1, k) <= 2)||(distance(a2, i) <= 2 && distance(b2, j) <= 2 && distance(c2, k) <= 2)) {
                    count++;
                }
            }
        }
    }
    cout << count;
    return 0;
}