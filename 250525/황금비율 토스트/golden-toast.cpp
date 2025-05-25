#include <iostream>
#include <string>

using namespace std;

int n, m;
string s;

int main() {
    cin >> n >> m;
    cin >> s;

    string::iterator it = s.end();

    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;

        switch(command) {
            case 'L':
                if(it == s.begin()) break;
                it--;
                break;
            case 'R':
                if(it == s.end()) break;
                it++;
                break;
            case 'D':
                if(it == s.end()) break;
                it = s.erase(it);
                break;
            case 'P':
                char c;
                cin >> c;
                it = s.insert(it, c)+1;
                break;
        }
    }
    cout << s;
    return 0;
}
