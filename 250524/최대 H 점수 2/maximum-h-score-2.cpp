#include <iostream>

using namespace std;

int N, L;
int a[100];

int get_H_score(const int* arr) {
    for(int H = 0; H < 100; H++) {
        int count = 0;

        for(int i = 0; i < N; i++) {
            if(arr[i] >= H) count++;
            
        }
        if(count < H) {
            return H-1;
        }
    }
}

int main() {
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // Please write your code here.
    int plus = N;
    int initial_H = get_H_score(a);
    int count = 0;
    for(int i = 0; i < N; i++) {
        if(a[i] == initial_H-1) count++;
    }
    if(count <= L) cout << initial_H+1; // 최대 점수는 어차피 H+1
    else cout << initial_H;
    return 0;
}