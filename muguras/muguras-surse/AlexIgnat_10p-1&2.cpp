#include <fstream>
#include <map>
using namespace std;

ifstream f("muguras.in");
ofstream g("muguras.out");

map < string, long long > mp;

int n;
char s;
string v;
string var, op, s1, s2;

long long aparitii(string a, char c) { /// returneaza numarul de aparitii al caracterului c in sirul a
	long long count = 0;
	for (char k : a) {
		if (k == c) count++;
	}
	return count;
}

void atribuire1() {
	f >> s1;
	mp[var] = aparitii(s1, s);
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
	g << mp[v];
	return 0;
}