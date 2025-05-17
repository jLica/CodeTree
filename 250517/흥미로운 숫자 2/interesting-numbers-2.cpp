#include <iostream>
#include <unordered_map>

using namespace std;

int X, Y;
int startIdx;

bool isInteresting(const int num) {
    unordered_map<int, int> m;
    int tmp = num;
    while(tmp > 0) {
        m[tmp%10]++;
        tmp /= 10;
    }
    if(m.size() != 2) return false;
    
    for(const auto& p : m) {
        if(p.second == 1) return true;
    }
    return false;
}

int main() {
    cin >> X >> Y;

    // Please write your code here.
    int count = 0;

    for(int i = X; i <= Y; i++) {
        if(isInteresting(i)) count++;
    }
    cout << count;
    return 0;
}