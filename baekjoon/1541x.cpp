#include<iostream>
#include<vector>
#include<string>
using namespace std;

string str;
int result = 0;
bool isMinus;

int main() {
	cin >> str;
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '-' || str[i] == '+' || i == str.size()) {
			if (isMinus) {
                result -= stoi(num);
                num = "";
            }
            else {
                result += stoi(num);
                num = "";
            }
        }
        else {
            num += input[i];
        }

        if (input[i] == '-') {
            isMinus = true;
        }
    }

    cout << result;
}

			}
		}
	}
}