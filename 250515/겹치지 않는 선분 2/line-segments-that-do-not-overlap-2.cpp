#include <iostream>
#include <algorithm>

using namespace std;

int N;
int x1[100], x2[100];
bool overlapped[100];

bool isOverlapped(int i, int j) {
    return ((x1[i]>x1[j] && x2[i]<x2[j])||(x1[i]<x1[j] && x2[i]>x2[j]));
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x1[i] >> x2[i];
    }

    // Please write your code here.
    // a1 <= b1 && a2 >= b2
    // a1 >= b1 && a2 <= b2
    // (b1-a1)*(b2-a2) <= 0
    fill(overlapped, overlapped+N, false);
    int count = 0;
    for(int i = 0; i < N-1; i++) {
        for(int j = i+1; j < N; j++) {
            if(isOverlapped(i, j)) {
                overlapped[i] = true;
                overlapped[j] = true;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        if(!overlapped[i]) count++;
    }
    cout << count;
    return 0;
}