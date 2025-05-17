#include <iostream>

using namespace std;

int N, C, G, H;
int Ta[1000], Tb[1000];

int main() {
    cin >> N >> C >> G >> H;

    for (int i = 0; i < N; i++) {
        cin >> Ta[i] >> Tb[i];
    }

    // Please write your code here.
    int sum = 0;
    int maxSum = 0;

    for(int i = 0; i <= 1000; i++) {
        sum = 0;
        for(int j = 0; j < N; j++) {
            if(i < Ta[j]) sum += C;
            else if(i >= Ta[j] && i <= Tb[j]) sum += G;
            else sum += H;
        }
        maxSum = max(sum, maxSum);
    }
    cout << maxSum;
    return 0;
}