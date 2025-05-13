#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<pair<int,int>> v2;
int N;

pair<int, int> count(int a, int b) {
    int count1 = 0, count2 = 0;
    int tens = 1;
    int digits_a[3], digits_b[3];
    for(int i = 0; i < 3; i++) {
        //123/100 = 1 -> 1%10 = 1
        //123/10 = 12 -> 12%10 = 2
        int digit_a = (a/tens)%10;
        int digit_b = (b/tens)%10;

        digits_a[i] = digit_a;
        digits_b[i] = digit_b;

        tens *= 10;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(digits_a[i] == digits_b[j]) {
                if(i==j) count1++;
                else count2++;
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
    int guessNumber, count1, count2;
    for(int i = 0; i < N; i++) {
        cin >> guessNumber >> count1 >> count2;
        v.push_back(guessNumber);
        v2.push_back({count1,count2});
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