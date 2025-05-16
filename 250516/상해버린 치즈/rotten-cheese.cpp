#include <iostream>
#include <algorithm>

using namespace std;

int N, M, D, S;
int p[1000], m[1000], t[1000];
int sick_p[50], sick_t[50];
bool badCheese[50];
bool consumedBadCheese[50];
int main() {
    cin >> N >> M >> D >> S;

    for (int i = 0; i < D; i++) {
        cin >> p[i] >> m[i] >> t[i];
    }

    for (int i = 0; i < S; i++) {
        cin >> sick_p[i] >> sick_t[i];
    }

    // Please write your code here.
    //치즈의 수와 사람의 수가 적기 때문에 치즈별로 완전탐색을 하는 것이 좋아 보임
    fill(badCheese, badCheese+M, false);
    fill(consumedBadCheese, consumedBadCheese+N, false);

    // 상한 치즈를 구분하는 단계
    for(int i = 0; i < S; i++) {
        for(int j = 0; j < D; j++) {
            if(sick_p[i] == p[j] && sick_t[i] > t[j]) {
                badCheese[m[j]-1] = true;
            }
        }
    }

    // 상한 치즈를 먹은 사람을 구분하는 단계
    for(int i = 0; i < M; i++) {
        if(!badCheese[i]) continue;

        for(int j = 0; j < D; j++) {
            if(m[j]-1 == i) { // 먹은 치즈가 상한 치즈면 
                consumedBadCheese[p[j]-1] = true;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < N; i++) {
        count += consumedBadCheese[i];
    }
    cout << count;
    return 0;
}