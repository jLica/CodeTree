#include <iostream>
#include <map>
using namespace std;

int N, M;
int A[100], B[100];

bool isBeautiful(int startIdx) {
    bool result = true;
    map<int, int> m;// value, count
    for(int i = 0; i < M; i++) {
        m[A[i+startIdx]]++;
    }
    for(int i = 0; i < M; i++) {
        m[B[i]]--;
    }
    for(const auto& p : m) {
        if(p.second != 0) {
            result = false;
        }
    }
    return result;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < M; i++) cin >> B[i];

    // Please write your code here.
    int count = 0;
     for(int i = 0; i <= N-M; i++) {
        if(isBeautiful(i)) count++;
    }
    cout << count;
    return 0;
}