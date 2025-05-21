#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int n, m;
int a[100], b[100];
unordered_map<string, int> um;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        if(a[i] > b[i]) {
            um[to_string(b[i])+to_string(a[i])]++;
        }
        else {
            um[to_string(a[i])+to_string(b[i])]++;
        }
    }

    // Please write your code here.
    int maxCount = 0;
    for(const auto& p : um) {
        maxCount = max(p.second, maxCount);
    }
    cout << maxCount;
    return 0;
}