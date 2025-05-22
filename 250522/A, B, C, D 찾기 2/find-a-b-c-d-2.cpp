#include <iostream>

using namespace std;

int nums[15];
int original[41] = {};

int main() {
    for (int i = 0; i < 15; i++) {
        cin >> nums[i];
        original[nums[i]]++;
    }

    // Please write your code here.
    for(int i = 1; i <= 40; i++) {
        for(int j = i; j <= 40; j++) {
            if(i+j > 40) break;
            for(int k = j; k <= 40; k++) {
                if(i+j+k > 40) break;
                for(int l = k; l <= 40; l++) {
                    if(i+j+k+l > 40) break;
                    int created[40] = {};
                    created[i]++; created[j]++; created[k]++; created[l]++;
                    created[i+j]++; created[j+k]++; created[k+l]++; created[l+i]++; created[i+k]++; created[j+l]++;
                    created[i+j+k]++; created[i+j+l]++; created[i+k+l]++; created[j+k+l]++;
                    created[i+j+k+l]++;

                    bool isSame = true;
                    for(int m = 0; m < 40; m++) {
                        if(original[m] != created[m]) {
                            isSame = false;
                            break;
                        }
                    }
                    if(isSame) {
                        cout << i << " " << j << " " << k << " " << l;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}