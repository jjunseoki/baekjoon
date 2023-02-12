#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
	
int N; 
string str;
int ans = -987654321;

int cal(char oper, int a, int b) {			
	//cout << oper << endl;
	int answer = 0;
	if (oper == '+')
		answer = a + b;
	else if (oper == '-')
		answer = a - b;
	else if (oper == '*')
		answer = a * b;
	return answer;
}

//dfs
void Dfs(int idx, int val) {			
	//cout << idx << " " << val << endl;
	// Å»ÃâÁ¶°Ç
	if (idx >= N) {
		ans = max(ans, val);
		return;
	}

	char oper;
	if (idx == 0) oper = '+';
	else {
		oper = str[idx - 1];
	}
	// °ýÈ£¸¦ ¹­À» ¼ö ÀÖ´Â Á¶°Ç
	if (idx + 2 < N) {
		int k = cal(str[idx + 1], str[idx] - '0', str[idx + 2] - '0'); // °ýÈ£ ¹­Àº°Å ¿¬»ê
		Dfs(idx + 4, cal(oper, val, k));
	}
	// °ýÈ£¸¦ ¾È ¹­´Â Á¶°Ç
	Dfs(idx + 2, cal(oper, val, str[idx] - '0'));
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> str;

	Dfs(0,0);
	cout << ans;

	return 0;
}