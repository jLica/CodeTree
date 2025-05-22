#include <iostream>

using namespace std;

int n;
int adjacent[1000];
int original[1000];

bool isOverlapped(int num, int idx) {
    for(int i = 0; i <= idx; i++) {
        if(original[i] == num) return true;
    }
    return false;
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> adjacent[i];
    }

    // Please write your code here.
    bool isConfirmed = true;
    for(int i = 1; i < adjacent[0]; i++) {
        // 앞에서부터 가능한 조합을 만들어가며 진행
        original[0] = i;
        isConfirmed = true;
        for(int j = 0; j < n-1; j++) {
            int next = adjacent[j] - original[j];
            if(isOverlapped(next, j)) {
                isConfirmed = false;
                break;
            }
            original[j+1] = next;
        }
        if(isConfirmed) break;
    }
    for(int i = 0; i < n; i++) {
        cout << original[i] << " ";
    }
    return 0;
}