#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> numbers;
    numbers.push_back(4);
    numbers.push_back(8);
    numbers.push_back(15);
    numbers.push_back(16);
    numbers.push_back(23);
    numbers.push_back(42);
    cout << "? " << 1 << " " << 2 << endl;
    cout << "? " << 2 << " " << 3 << endl;
    cout << "? " << 4 << " " << 5 << endl;
    cout << "? " << 5 << " " << 6 << endl;
    int ab, bc, de, ef;
    cin >> ab >> bc >> de >> ef;
    int a, b, c, d, e, f;
    for(int i = 0; i < 6; i++) {
        for(int j = i + 1; j < 6; j++) {
            int fi = numbers[i], se = numbers[j];
            if(fi * se == ab) {
                bool fise = bc % se == 0 && find(numbers.begin(), numbers.end(), bc / se) != numbers.end() && fi != bc / se && se != bc / se;
                if(fise) {
                    a = fi;
                    b = se;
                    c = bc / b;
                } else {
                    a = se;
                    b = fi;
                    c = bc / b;
                }
            }

            if(fi * se == de) {
                bool fise = ef % se == 0 && find(numbers.begin(), numbers.end(), ef / se) != numbers.end() && fi != ef / se && se != ef / se;
                if(fise) {
                    d = fi;
                    e = se;
                    f = ef / e;
                } else {
                    d = se;
                    e = fi;
                    f = ef / e;
                }
            }
        }
    }
    printf("! %d %d %d %d %d %d\n", a, b, c, d, e, f);
    return 0;
}
