#include <fstream>
#include <map>
#include <string>
using namespace std;

ifstream f("muguras.in");
ofstream g("muguras.out");

map < string, string > mp;

int n;
string s, v;
string var, op, s1, s2;

long long aparitii(string a, string b) { /// returneaza numarul de aparitii al sirului b in sirul a
	long long count = 0;
	if (a.size() < b.size()) return 0;
	for (int i = 0; i < a.size() - b.size() + 1; i++) {
		int ok = 1;
		for (int j = 0; j < b.size() && ok; j++) {
			if (a[i + j] != b[j]) {
				ok = 0;
			}
		}
		count += ok;
	}
	return count;
}

void atribuire1() {
	f >> s1;
	mp[var] = s1;
}

void atribuire2() {
	f >> s1 >> op >> s2;
	mp[var] = mp[s1] + mp[s2];
}

int main() {
	f >> n >> s >> v;
	for (int i = 1; i <= n; i++) {
		f >> var >> op;
		if (op[0] == ':') atribuire1();
		else atribuire2();
	}
	g << aparitii(mp[v], s);
	return 0;
}