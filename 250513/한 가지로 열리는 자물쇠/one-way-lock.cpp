#include <iostream>

using namespace std;

int N;
int a, b, c;

int main() {
    cin >> N;
    cin >> a >> b >> c;

    // Please write your code here.
    int count=0;

    for(int i = 1; i <= N; i++) {
        if(abs(a-i) <= 2) {
            count += N*N;
            continue;
        }
        for(int j = 1; j <= N; j++) {
            if(abs(b-j) <= 2) {
                count += N;
                continue;
            }
            for(int k = 1; k <= N; k++) {
                if(abs(c-k) <= 2) {
                    count++;
                }
            }
        }
    }
    cout << count;
    return 0;
}