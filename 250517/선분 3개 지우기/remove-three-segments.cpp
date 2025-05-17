#include <iostream>

using namespace std;

int n;
int l[10], r[10];

bool isOverlapped(int skip1, int skip2, int skip3) {
    bool result = false;

    for(int i = 0; i < n-1; i++) {
        if(i == skip1 || i == skip2 || i == skip3) continue;
        for(int j = i+1; j < n; j++) {
            if(j == skip1 || j == skip2 || j == skip3) continue;    
            if((l[i] <= r[j] && l[j] <= r[i])) { // 겹침 조건 개선
                result = true;
                break;
            }
        }
    }
    return result;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    // Please write your code here.
    int count = 0;
    for(int i = 0; i < n-2; i++) {
        for(int j = i+1; j < n-1; j++) {
            for(int k = j+1; k < n; k++) {
                if(!isOverlapped(i,j,k)) count++;
            }
        }
    }
    cout << count;
    return 0;
}