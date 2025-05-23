#include <iostream>
#include <climits>
using namespace std;

int n, m;
int a[100];
int count[100] = {};

bool is_possible(int limit) { // 현재 최댓값을 만족하게끔 앞에서부터 제한을 두면서 더하고, 그렇게 더한 partition이 m개를 넘지 않는지를 검사
    int count = 1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(sum+a[i] <= limit) {
            sum += a[i];
            continue;
        }
        sum = a[i];
        count++; // sum에 다음 것을 담을 수 없다면 다음으로 넘어감
    }
    return (count <= m);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Please write your code here.
    for(int i = a[0]; i <= 10000; i++) {
        if(is_possible(i)) {
            cout << i;
            break;
        }
    }
    return 0;
}