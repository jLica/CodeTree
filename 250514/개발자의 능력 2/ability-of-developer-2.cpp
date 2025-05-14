#include <iostream>
#include <climits>

using namespace std;

int ability[6];
int total;

// 3팀의 difference 중 가장 큰 차이를 리턴
int difference(int i, int j, int k, int l) {
    int ability_team[3] = {ability[i]+ability[j], ability[k]+ability[l], total-ability_team[0]-ability_team[1]};
    int maxDiff = INT_MIN;
    int diff = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = i+1; j < 3; j++) {
            diff = abs(ability_team[i]-ability_team[j]);
            maxDiff = max(diff, maxDiff);
        }
    }
    return maxDiff;
}
int main() {
    total = 0;
    for (int i = 0; i < 6; i++) {
        cin >> ability[i];
        total += ability[i];
    }

    // Please write your code here.
    // 6개 수가 전부 다른 상황. 중복은 허용
    int minDifference = INT_MAX;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(i==j) continue;
            for(int k = 0; k < 6; k++) {
                if(i == k || j == k) continue;
                for(int l = 0; l < 6; l++) {
                    if(i == l || j == l || k == l) continue;
                    minDifference = min(minDifference, difference(i,j,k,l));
                }
            }
        }
    }
    cout << minDifference;
    return 0;
}