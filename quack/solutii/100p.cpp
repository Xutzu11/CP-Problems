#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>
using namespace std;

ifstream f("quack.in");
ofstream g("quack.out");

string s;
int kmp[1000005];
int n, k = 0, maxlen = 0;
set < int > ln;

int main() {
	f >> s;
    n = s.size();

    int i = 1;
    while (i < n) {
        if (s[i] == s[k]) {
            k++;
            kmp[i] = k;
            i++;
        }
        else if (k != 0) {
            k = kmp[k - 1];
        }
        else {
            kmp[i] = 0;
            i++;
        }
    }
    k = kmp[n - 1];
    while (k != 0) {
        ln.insert(k);
        k = kmp[k - 1];
    }
    for (int i = 1; i < n - 1; i++) {
        if (ln.count(kmp[i])) {
            maxlen = max(maxlen, kmp[i]);
        }
    }
    if (maxlen == 0) g << "O nu, e o capcana!";
    else g << s.substr(0, maxlen);
	return 0;
}