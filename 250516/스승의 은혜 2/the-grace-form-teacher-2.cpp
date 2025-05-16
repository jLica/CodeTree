#include <iostream>
#include <algorithm>

using namespace std;

int N, B;
int P[1000];

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    // Please write your code here.
    // 좀 오래 걸리더라도 최솟값부터 더하는 게 맞아 보임
    // 그럼 그냥 sort
    sort(P, P+N);
    int sum = 0;
    int num_student = 0;
    bool chance_used = false;
    for(int i = 0; i < N; i++) {
        if(sum + P[i] <= B) {
            num_student++;
            sum += P[i];
        }
        else if(sum + P[i]*0.5 <= B) {
            if(chance_used) break;
            else {
                chance_used = true;
                num_student++; 
                sum += P[i]*0.5;
            }
        }
    }
    cout << num_student;
    return 0;
}