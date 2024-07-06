#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

ifstream f("soldatei.in");
ofstream g("soldatei.out");

struct Soldat {
	long long viata, atac;
	char tab, dir;
};

int n, m;
vector < Soldat > soldati;
vector < Soldat > st;

void solve() {
	st.clear(); soldati.clear();
	f >> n >> m;
	for (int i = 1; i <= n; i++) {
		Soldat r;
		f >> r.tab >> r.dir >> r.viata >> r.atac;
		soldati.push_back(r);
	}
	for (int i = 1; i <= m; i++) {
		Soldat r;
		f >> r.tab >> r.dir >> r.viata >> r.atac;
		soldati.push_back(r);
	}
	for (int i = 0; i < n + m; i++) {
		st.push_back(soldati[i]);
		while (st.size() > 1 && st[st.size() - 2].dir == 'D' && st[st.size() - 1].dir == 'S') {
			Soldat s2 = st.back(); st.pop_back();
			Soldat s1 = st.back(); st.pop_back();
			if (s1.tab == s2.tab) {
				Soldat s3;
				s3.viata = s1.viata + s2.viata;
				s3.atac = max(s1.atac, s2.atac);
				s3.dir = s1.viata > s2.viata ? s1.dir : (s1.viata == s2.viata ? 'S' : s2.dir);
				s3.tab = s1.tab;
				st.push_back(s3);
			}
			else {
				long long atac1 = s1.viata / s2.atac + (s1.viata % s2.atac != 0); // nr de atacuri pt a omori s1
				long long atac2 = s2.viata / s1.atac + (s2.viata % s1.atac != 0); // nr de atacuri pt a omori s2
				if (atac1 > atac2) {
					s1.viata -= atac2 * s2.atac;
					st.push_back(s1);
				}
				else if (atac2 > atac1) {
					s2.viata -= atac1 * s1.atac;
					st.push_back(s2);
				}
			}
		}
	}
	g << st.size() << '\n';
	for (int i = 0; i < st.size(); i++) {
		g << st[i].tab << " " << st[i].dir << " " << st[i].viata << " " << st[i].atac << '\n';
	}
}

int main()
{
	solve();
	return 0;
}