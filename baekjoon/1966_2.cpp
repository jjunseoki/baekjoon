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

		// ���� ����
		queue<pair<int, int>> docList;

		// ���� ���� �߿䵵�� �ٷ� �ľ��� �� �ֵ��� �켱���� ť ���
		priority_queue<int> maxImportance;

		// �μ� Ƚ��
		int printCount = 0;

		// ������ �Է�
		for (int i = 0; i < n; i++) {
			int value;
			cin >> value;

			docList.push(make_pair(i, value));
			maxImportance.push(value);
		}

		// �μ� ����
		while (!docList.empty()) {
			int index = docList.front().first;
			int importance = docList.front().second;

			// �߿䵵�� �� ���� ������ ���� ��� �� �ڷ� ����
			if (maxImportance.top() > importance) {
				docList.push(docList.front());
				docList.pop();
			}
			// �׷��� ������ �μ�
			else {
				docList.pop();
				maxImportance.pop();
				printCount++;

				// �ñ��� ������ �μ���� ���
				if (index == m) {
					// ��� ���
					cout << printCount << "\n";
					break;
				}
			}
		}
	}

	return 0;
}