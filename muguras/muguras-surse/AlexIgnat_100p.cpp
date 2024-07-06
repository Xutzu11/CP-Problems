#include <fstream>
#include <map>
#include <string>
#include <iostream>
using namespace std;

ifstream f("muguras.in");
ofstream g("muguras.out");

struct Var {
	long long nr_ap;
	string suf, pref;
}aux;

map < string, Var > mp;

int n;
string s, v;
string var, op, s1, s2;

int aparitii(string a, string b) { /// returneaza numarul de aparitii al sirului b in sirul a
	int count = 0;
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
	aux.nr_ap = aparitii(s1, s);
	/// creare sufix cu maxim s.size() - 1 caractere
	if (s1.size() < s.size()) aux.suf = s1;
	else {
		for (int i = s1.size() - s.size() + 1; i < s1.size(); i++) {
			aux.suf += s1[i];
		}
	}
	/// creare prefix cu maxim s.size() - 1 caractere
	if (s1.size() < s.size()) aux.pref = s1;
	else {
		for (int i = 0; i < s.size() - 1; i++) {
			aux.pref += s1[i];
		}
	}
	mp[var] = aux;
}

void atribuire2() {
	f >> s1 >> op >> s2;
	int i = 0;
	aux.nr_ap = mp[s1].nr_ap + mp[s2].nr_ap + aparitii(mp[s1].suf + mp[s2].pref, s);
	aux.pref = mp[s1].pref;
	while (aux.pref.size() < s.size() - 1 && i < mp[s2].pref.size()) {
		aux.pref += mp[s2].pref[i];
		i++;
	}
	i = mp[s1].suf.size() - 1;
	aux.suf = mp[s2].suf;
	while (aux.suf.size() < s.size() - 1 && i >= 0) {
		aux.suf = mp[s1].suf[i] + aux.suf;
		i--;
	}
	mp[var] = aux;
}

int main() {
	f >> n >> s >> v;
	for (int i = 1; i <= n; i++) {
		f >> var >> op;
		aux.nr_ap = 0; aux.suf = aux.pref = "";
		if (op[0] == ':') atribuire1();
		else atribuire2();
	}
	g << mp[v].nr_ap;
	return 0;
}