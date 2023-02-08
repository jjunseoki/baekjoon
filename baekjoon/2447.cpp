#include<iostream>
#include<algorithm>

using namespace std;

void recur(int i, int j, int N) {
	// if 9  (1,1), (4, 1), (7, 1), (1, 4), (4,4), (7,4), (1,7), (4, 7) ()()
	if ((i / N) % 3 == 1 && (j / N) % 3 == 1) {
		cout << ' ';
	}
	else {
		if (N / 3 == 0)
			cout << '*';
		else
			recur(i, j, N / 3);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	//xรเ
	for (int i = 0; i < N; i++) {
		//yรเ
		for (int j = 0; j < N; j++) {
			recur(i, j, N);
		}
		cout << '\n';
	}
}