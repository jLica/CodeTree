#include <iostream>
#include <unordered_set>

using namespace std;

int N, K;
int num[100];

int how_many_exploded(int bomb_num) {
    int result = 0;
    unordered_set<int> s;

    for(int i = 0; i < N-K; i++) {
        if(num[i] != bomb_num) continue;
        
        for(int j = i+1; j <= i+K; j++) {
            if(num[j] == bomb_num) {
                s.insert(i);
                s.insert(j);
            }
        }
    }
    return s.size();
}

int main() {
    cin >> N >> K;
    int max_num = 0;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        max_num = max(num[i], max_num);
    }

    // Please write your code here.
    int max_bomb_count = 0;
    int max_bomb_num = 0;

    for(int i = max_num; i >= 0; i--) {
        int count = how_many_exploded(i);
        if(count > max_bomb_count) {
            max_bomb_count = count;
            max_bomb_num = i;
        }
    }
    cout << max_bomb_num;
    return 0;
}