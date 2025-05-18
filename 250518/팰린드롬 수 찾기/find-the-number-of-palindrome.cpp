#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int X, Y;

bool isSatisfied(int num) {
    string s = to_string(num);
    string s_reverse = to_string(num);
    reverse(s_reverse.begin(), s_reverse.end());
    if(s.compare(s_reverse) == 0) return true;
    return false;
}

int main() {
    cin >> X >> Y;

    // Please write your code here.
    int count = 0;
    for(int i = X; i <= Y; i++) {
        if(isSatisfied(i)) count++;
    }
    cout << count;
    return 0;
}