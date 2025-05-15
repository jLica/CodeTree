#include <iostream>

using namespace std;

int N;
int x[100];
int y[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    // Please write your code here.
    int max_area = 0;
    int area;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j || (x[i] != x[j] && y[i] != y[j])) continue;
            for(int k = 0; k < N; k++) {
                if(x[i]==x[j]) {
                    if(y[i] == y[k]) {
                        area = abs(y[i]-y[j])*abs(x[i]-x[k]);
                        max_area = max(max_area, area);
                    }
                    else if(y[j] == y[k]) {
                        area = abs(y[i]-y[j])*abs(x[j]-x[k]);
                        max_area = max(max_area, area);
                    }
                }
                else if(y[i]==y[j]) {
                    if(x[i]==x[k]) {
                        area = abs(x[i]-x[j])*abs(y[i]-y[k]);
                        max_area = max(max_area, area);
                    }
                    else if(x[j]==x[k]) {
                        area = abs(x[i]-x[j])*abs(y[j]-y[k]);
                        max_area = max(max_area, area);
                    }
                }
            }
        }
    }
    cout << max_area;
    return 0;
}