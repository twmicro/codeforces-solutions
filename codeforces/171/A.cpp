#include <bits/stdc++.h>
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
    int a, b; cin >> a >> b;
    string sb = to_string(b);
    reverse(sb.begin(), sb.end());
    b = stoi(sb);
    cout << a + b << endl;
} 