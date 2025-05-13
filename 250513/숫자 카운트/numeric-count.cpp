#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<pair<int,int>> v2;
int N;

pair<int, int> count(int a, int b) {
    vector<int> v_a, v_b;
    int tens = 1;
    for(int i = 0; i < 3; i++) {
        v_a.push_back((a%(tens*10)-a%tens)/(tens));
        v_b.push_back((b%(tens*10)-b%tens)/(tens));
        tens *= 10;
    }
    // 324
    // 4 2 3
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(v_a[i] == v_b[j]) {
                if(i == j) {
                    count1++;
                }
                else {
                    count2++;
                }
            }
        }
    }
    return {count1, count2};
}

bool satisfied(int a, int b, const pair<int, int>& p) {
    const pair<int, int> p2 = count(a, b);

    return p == p2;
}

int main() {
    // Please write your code here.
    cin >> N;
    int a1, a2, a3;
    for(int i = 0; i < N; i++) {
        cin >> a1 >> a2 >> a3;
        v.push_back(a1);
        v2.push_back({a2,a3});
    }
    int num;
    int count = 0;
    bool isSatisfied = true;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            if(i == j) continue;
            for(int k = 1; k <= 9; k++) {
                if(k == i || k == j) continue;
                num = i*100 + j*10 + k;
                isSatisfied = true;
                for(int l = 0; l < N; l++) {
                    if(!satisfied(num, v[l], v2[l])) {
                        isSatisfied = false;
                        break;
                    }
                }
                if(isSatisfied) {
                    count++;
                }
            }
        }
    }
    cout << count;
    return 0;
}