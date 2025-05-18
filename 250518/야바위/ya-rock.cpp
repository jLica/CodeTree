#include <iostream>

using namespace std;

int N;
int a[100], b[100], c[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // Please write your code here.
    int score = 0;
    int maxScore = 0;
    int position = 0;
    for(int i = 1; i <= 3; i++) { // 초기 위치
        score = 0;
        position = i;
        for(int j = 0; j < N; j++) {
            if(a[j] == position) position = b[j];
            else if(b[j] == position) position = a[j];

            if(c[j] == position) score++;
        }
        maxScore = max(score, maxScore);
    }
    cout << maxScore;
    return 0;
}