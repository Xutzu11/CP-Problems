#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>
using namespace std;

ifstream f("quack.in");
ofstream g("quack.out");

string s, t;
int n, k = 0, maxlen = 0;

int main() {
	f >> s;
	t = s.substr(1, s.size() - 2);
	for (int i = s.size(); i >= 1 && maxlen == 0; i--) {
		if (s.substr(0, i) == s.substr(s.size() - i, i)) {
			if (t.find(s.substr(0, i)) != string::npos) {
				maxlen = i;
			}
		}
	}
	if (maxlen == 0) g << "O nu, e o capcana!";
	else g << s.substr(0, maxlen);
	return 0;
}