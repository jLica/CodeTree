#include <iostream>
#include <set>
#include <climits>

using namespace std;

int ability[6];
// 3팀의 difference 중 가장 큰 차이를 리턴
int difference(int a1, int a2, int b1, int b2, int c1, int c2) {
    int ability_team[3] = {ability[a1]+ability[a2], ability[b1]+ability[b2], ability[c1]+ability[c2]};
    int maxDiff = INT_MIN;
    int diff = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = i+1; j < 3; j++) {
            diff = abs(ability_team[i] - ability_team[j]);
            maxDiff = max(maxDiff, diff);
        }
    }
    return maxDiff;
}
int main() {
    for (int i = 0; i < 6; i++) {
        cin >> ability[i];
    }

    // Please write your code here.
    // 6개 수가 전부 다른 상황. 중복은 허용
    set<int> s;
    int minDifference = INT_MAX;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            for(int k = 0; k < 6; k++) {
                for(int l = 0; l < 6; l++) {
                    for(int m = 0; m < 6; m++) {
                        for(int n = 0; n < 6; n++) {
                            s.insert(i);s.insert(j);s.insert(k);s.insert(l);s.insert(m);s.insert(n);
                            if(s.size() < 6) {
                                s.clear();
                                continue;
                            }
                            // 중복 아닌 상황
                            minDifference = min(minDifference, difference(i,j,k,l,m,n));
                            s.clear();

                        }
                    }
                }
            }
        }
    }
    cout << minDifference;
    return 0;
}