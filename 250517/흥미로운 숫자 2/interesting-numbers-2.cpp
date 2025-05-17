#include <iostream>
#include <map>

using namespace std;

int X, Y;

bool isInteresting(int num) {
    int tens = 1;
    int figure;
    map<int, int> m;
    while(num >= tens) {
        figure = (num/tens)%10;
        m[figure]++;
        tens *= 10;
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
    for(int i = X; i <= Y; i++) {
        if(isInteresting(i)) count++;
    }
    cout << count;
    return 0;
}