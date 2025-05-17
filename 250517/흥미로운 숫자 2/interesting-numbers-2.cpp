#include <iostream>
#include <map>

using namespace std;

int X, Y;
int startIdx;

void update(int* figures) {
    for(int i = 6; i >= 0; i--) {
        if(figures[i] == 10) {
            figures[i] = 0;
            figures[i-1]++;
            if(i == startIdx) startIdx--;
        }
    }
}

void addOne(int* figures) {
    figures[6]++;
    if(figures[6] == 10) update(figures);
}

bool isInteresting(const int* figures) {
    map<int, int> m;
    //int startIdx;
    //for(startIdx = 0; startIdx < 7; startIdx++) {
    //    if(figures[startIdx] != 0) break;
    //}
    for(int i = startIdx; i < 7; i++) {
        m[figures[i]]++;
    }
    bool result = false;
    if(m.size() == 2) {
        for(const auto& p : m) {
            if(p.second == 1) result = true;
        }
    }
    return result;
}

int main() {
    cin >> X >> Y;

    // Please write your code here.
    int count = 0;
    int figures[7];

    int tens = 1;
    for(int i = 6; i >= 0; i--) {
        figures[i] = (X/tens)%10;
        if(figures[i] != 0) startIdx = i; // 초기 자릿수
        tens *= 10;
    }

    for(int i = X; i <= Y; i++) {
        if(isInteresting(figures)) count++;
        addOne(figures);
    }
    cout << count;
    return 0;
}