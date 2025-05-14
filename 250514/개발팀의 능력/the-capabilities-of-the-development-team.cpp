#include <iostream>
#include <climits>
using namespace std;

int abilities[5];
int total;

// 모든 팀의 능력치가 달라질 수 있으면 정상 값, 없으면 INT_MAX
int difference(int i, int j, int k) {
    int ability_team[3] = {abilities[i]+abilities[j], abilities[k], total-ability_team[0]-ability_team[1]};
    int diff = 0;
    int maxDiff = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = i+1; j < 3; j++) {
            if(ability_team[i] == ability_team[j]) {
                return INT_MAX;
            }
            diff = abs(ability_team[i]-ability_team[j]);
            maxDiff = max(maxDiff, diff);
        }
    }
    return maxDiff;
}

int main() {
    // Please write your code here.
    total = 0;
    int minDiff = INT_MAX;
    for(int i = 0; i < 5; i++) {
        cin >> abilities[i];
        total += abilities[i];
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i == j) continue;
            for(int k = 0; k < 5; k++) {
                if(i == k || j == k) continue;
                minDiff = min(minDiff, difference(i,j,k));
            }
        }
    }
    if(minDiff == INT_MAX) cout<< -1;
    else cout << minDiff;
    return 0;
}