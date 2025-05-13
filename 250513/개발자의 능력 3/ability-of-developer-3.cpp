#include <iostream>
#include <climits>

using namespace std;

int abilities[6];

int main() {
    int total = 0;
    for (int i = 0; i < 6; i++) {
        cin >> abilities[i];
        total += abilities[i];
    }

    // Please write your code here.
    int minDifference = INT_MAX;
    int difference = 0;
    int sum = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = i+i; j < 5; j++) {
            for(int k = j+1; k < 6; k++) {
                sum = abilities[i]+abilities[j]+abilities[k];
                difference = abs((total-sum)-sum);
                minDifference = min(difference, minDifference);
            }
        }
    }
    cout << minDifference;
    return 0;
}