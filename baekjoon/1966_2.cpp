#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		// 문서 정보
		queue<pair<int, int>> docList;

		// 가장 높은 중요도를 바로 파악할 수 있도록 우선순위 큐 사용
		priority_queue<int> maxImportance;

		// 인쇄 횟수
		int printCount = 0;

		// 데이터 입력
		for (int i = 0; i < n; i++) {
			int value;
			cin >> value;

			docList.push(make_pair(i, value));
			maxImportance.push(value);
		}

		// 인쇄 시작
		while (!docList.empty()) {
			int index = docList.front().first;
			int importance = docList.front().second;

			// 중요도가 더 높은 문서가 있을 경우 맨 뒤로 보냄
			if (maxImportance.top() > importance) {
				docList.push(docList.front());
				docList.pop();
			}
			// 그렇지 않으면 인쇄
			else {
				docList.pop();
				maxImportance.pop();
				printCount++;

				// 궁금한 문서가 인쇄됐을 경우
				if (index == m) {
					// 결과 출력
					cout << printCount << "\n";
					break;
				}
			}
		}
	}

	return 0;
}