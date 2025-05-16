#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int N, M, D, S;
int p[1000], m[1000], t[1000];
int sick_p[50], sick_t[50];
bool bad_cheese[50]; // 치즈마다 얼마나 많은 사람이 먹었는지
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
    fill(bad_cheese, bad_cheese+M, false);

    // 상한 치즈를 구분하는 단계
    for(int i = 0; i < S; i++) {
        for(int j = 0; j < D; j++) {
            if(sick_p[i] == p[j] && sick_t[i] > t[j]) { // 아픈 사람이 아프기 전에 먹은 치즈
                bad_cheese[m[j]-1] = true;
            }
        }
    }
    
    int maxCount = 0;
    set<int> s;

    for(int i = 0; i < M; i++) {
        if(!bad_cheese[i]) continue;
        for(int j = 0; j < D; j++) {
            if(m[j]-1 == i) { // 상한 것 같은 치즈를 먹은 적이 있다
                s.insert(p[j]);
            }
        }
        maxCount = max(maxCount, int(s.size())); // 가장 많은 사람이 먹은 "상한 것 같은 치즈"
        s.clear();
    }
    cout << maxCount;
    return 0;
}