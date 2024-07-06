#include <fstream>
#include <stack>
#include <string>
#include <set>
using namespace std;

/// Pentru acest subtask, toate operatiile push apar inaintea operatiilor pop
/// Ideea acestui subtask cuprinde si o posibila solutie pentru subtask-urile
/// in care toate operatiile sunt push sau in care indicii sunt ordonati crescator

ifstream f("mugur.in");
ofstream g("mugur.out");

int n, p, x;
string ss;
set < int > s;
int ops[100005];

void solve() {
	if (s.empty()) g << -1 << '\n';
	else g << ops[*(--s.end())] << '\n';
}

void push() {
	f >> x;
	ops[p] = x;
	s.insert(p);
	solve();
}

void pop() {
	if (!s.empty() && *s.begin() < p)
		s.erase(--s.lower_bound(p));	
	solve();
}

int main() {
	f >> n;
	for (int i = 1; i <= n; i++) {
		f >> p >> ss;
		if (ss == "push") {
			push();
		}
		else {
			pop();
		}
	}
	return 0;
}