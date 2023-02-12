#include <iostream>
using namespace std;

int L, P, V;
int i = 1;

int main() {
	while (true) {
		int result = 0;
		cin >> L >> P >> V;
		if ((L == 0) && (P == 0) && (V == 0)) break;
		else {
			if (P < V) {
				result = (V / P * L) + (V%P > L? L:V%P);

				cout << "Case " << i++ << ": " << result << endl;
			}
		}
	}
}