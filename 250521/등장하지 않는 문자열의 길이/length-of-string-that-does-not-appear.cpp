#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int N;
string str;

int main() {
    cin >> N;
    cin >> str;

    // Please write your code here.
    // 문자열 내의 어떤 substring도 반복되지 않는 최소 길이
    for(int i = 1; i <= N; i++) {
        bool is_only_one = true;
        unordered_set<string> s;
        
        for(int j = 0; j <= N-i; j++) {
            string sub_str = str.substr(j, i); // i 길이의 substr
            if(s.count(sub_str) == 1) {
                is_only_one = false;
                break;
            }
            s.insert(sub_str);
        }
        if(is_only_one) {
            cout << i;
            return 0;
        }
    }
    return 0;
}