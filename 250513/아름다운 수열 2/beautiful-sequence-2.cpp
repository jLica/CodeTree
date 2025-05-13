#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[100], B[100];

bool isBeautiful(int startIdx) {
    int* arr = new int[M];
    bool result = true;
    //A의 연속 부분집합 <-> B
    for(int i = 0; i < M; i++) {
        arr[i] = A[startIdx+i];
    }
    sort(arr, arr+M);

    for(int i = 0; i < M; i++) {
        if(arr[i] != B[i]) {
            result = false;
            break;
        }
    }
    delete[] arr;
    return result;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < M; i++) cin >> B[i];

    // Please write your code here.
    int count = 0;

    sort(B, B+M);

    for(int i = 0; i <= N-M; i++) {
        if(isBeautiful(i)) count++;
    }

    cout << count;
    return 0;
}