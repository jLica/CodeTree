#include <iostream>
#include <algorithm>

using namespace std;

int N, B;
int P[1000];
int S[1000];
int CP[1000];

int main() {
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> S[i];
    }

    // Please write your code here.
    int maxCount = 0;
    int students = 0;
    int totalPrice = 0;
    for(int i = 0; i < N; i++) { // 각 학생에게 쿠폰 적용 반복
        for(int j = 0; j < N; j++) {
            if(j==i) {
                CP[j] = P[j]*0.5 + S[j];
                continue;
            }
            CP[j] = P[j]+S[j];
        }
        sort(CP, CP+N);
        students = 0;
        totalPrice = 0;
        for(int j = 0; j < N; j++) {
            if(totalPrice + CP[j] <= B) {
                totalPrice += CP[j];
                students++;
            }
            else break;
        }
        maxCount = max(maxCount, students);
    }
    cout << maxCount;
    return 0;
}