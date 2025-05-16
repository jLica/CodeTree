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
    int next_price = 0;
    for(int i = 0; i < N; i++) {
        next_price = P[i];
        if(sum+next_price*0.5 > B) { // 1/2조차 못 지불
            num_student = i;
        }
        else if(sum+next_price > B) {
            if(chance_used) { // 1/2는 지불이 가능하나 이미 chance 사용
                num_student = i;
            }
            else {
                chance_used = true;
                sum += next_price*0.5;
            }
        }
        else { // 지불 가능
            sum += next_price;
        }
    }
    cout << num_student;
    return 0;
}