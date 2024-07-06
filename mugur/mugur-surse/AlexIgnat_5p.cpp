#include <fstream>
#include <stack>
#include <string>
using namespace std;

ifstream f("mugur.in");
ofstream g("mugur.out");

int n, p, x;
string ss;
stack < int > st;

/// Pentru acest subtask, toate operatiile sunt de tip push

int main() {
	f >> n;
	for (int i = 1; i <= n; i++) {
		f >> p >> ss;
		if (ss == "push") {
			f >> x;
			st.push(x);
		}
		else {
			if (!st.empty()) st.pop();
		}
		if (st.empty()) g << -1 << '\n';
		else g << st.top() << '\n';
	}
	return 0;
}