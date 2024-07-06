#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>
using namespace std;

ifstream f("quack.in");
ofstream g("quack.out");

string s, t;
int kmp[1000005];
int n, k = 0, maxlen = 0;
set < string > set1;
set < string > set2;


int main() {
	f >> s;
	string s1 = "";
	for (int i = 0; i < s.size(); i++) {
		s1 += s[i];
		set1.insert(s1);
	}
	string s2 = "";
	for (int i = s.size() - 1; i >= 0; i--) {
		s2 = s[i] + s2;
		if (set1.find(s2) != set1.end())
			set2.insert(s2);
	}
	t = s.substr(1, s.size() - 2);
	for (auto ss : set2) {
		if (t.find(ss) != string::npos) {
			if (ss.size() > maxlen) {
				maxlen = ss.size();
			}
		}
	}
	if (maxlen == 0) g << "O nu, e o capcana!";
	else g << s.substr(0, maxlen);
	return 0;
}