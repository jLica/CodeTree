#include <iostream>
#include <string>

using namespace std;

int N;
string str;

int main() {
    cin >> N;
    cin >> str;

    // Please write your code here.
    // 문자열 내의 어떤 substring도 반복되지 않는 최소 길이
    for(int i = 1; i <= str.length(); i++) {
        bool isOnlyOne = true;
        for(int j = 0; j <= str.length()-i; j++) {
            string sub_str = str.substr(j, i); // i 길이의 substr
            for(int k = 0; k <= str.length()-i; k++) {
                if(k == j) continue;
                string sub_str2 = str.substr(k, i);
                if(sub_str.compare(sub_str2) == 0) {
                    isOnlyOne = false;
                    break;
                }
            }
        }
        if(isOnlyOne) {
            cout << i;
            return 0;
        }
    }
    return 0;
}