#include <iostream>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i -1; j++) {
            if(arr[j] > arr[j+1]) {
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
