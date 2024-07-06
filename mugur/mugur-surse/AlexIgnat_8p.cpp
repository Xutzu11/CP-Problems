#include <fstream>
#include <stack>
#include <set>
#include <string>
using namespace std;

ifstream f("mugur.in");
ofstream g("mugur.out");

/// Pentru acest subtask, N <= 5000

int n, p, x;
string ss;
stack < int > st;
set < int > s;
int ops[100005];

void solve() {
	for (auto k : s) {
		if (ops[k] == -1) {
			if (!st.empty()) st.pop();
		}
		else st.push(ops[k]);
	}
	if (st.empty()) g << -1 << '\n';
	else g << st.top() << '\n';
	while (!st.empty()) st.pop();
}

void push() {
	f >> x;
	ops[p] = x;
	s.insert(p);
	solve();
}

void pop() {
	ops[p] = -1;
	s.insert(p);
	solve();
}



int main() {
	f >> n;
	for (int i = 1; i <= n; i++) {
		f >> p >> ss;
		if (ss == "push") {
			push();
		}
		else pop();
	}
	return 0;
}