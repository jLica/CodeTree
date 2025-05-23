#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<int> intersection(set<int>& s1, set<int>& s2) {
    set<int> result;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(result, result.begin())); // set_intersection을 이용한 개선
    return result;
}

int N, M, D, S;
int p[1000], m[1000], t[1000];
int sick_p[50], sick_t[50];
int main() {
    cin >> N >> M >> D >> S;
    set<int> bad_cheese_candidates;
    for (int i = 0; i < D; i++) {
        cin >> p[i] >> m[i] >> t[i];
        bad_cheese_candidates.insert(m[i]);
    }

    for (int i = 0; i < S; i++) {
        cin >> sick_p[i] >> sick_t[i];
    }

    // Please write your code here.
    //치즈의 수와 사람의 수가 적기 때문에 치즈별로 완전탐색을 하는 것이 좋아 보임

    set<int> ate_cheese;
    // 아픈 사람이 먹은 공통 치즈 구하기
    for(int i = 0; i < S; i++) {
        for(int j = 0; j < D; j++) {
            if(sick_p[i] != p[j] || sick_t[i] <= t[j]) continue;
            ate_cheese.insert(m[j]);
        }
        bad_cheese_candidates = intersection(bad_cheese_candidates, ate_cheese); // 아픈 사람이 공통으로 먹은 치즈 교집합
        ate_cheese.clear();
    }
    int maxCount = 0;
    set<int> consumer;

    // 각 상한 치즈 후보마다 먹은 사람 수를 확인
    for(int i : bad_cheese_candidates) {
        for(int j = 0; j < D; j++) {
            if(m[j] == i) consumer.insert(p[j]);
        }
        maxCount = max(maxCount, int(consumer.size()));
    }
    cout << maxCount;
    return 0;
}