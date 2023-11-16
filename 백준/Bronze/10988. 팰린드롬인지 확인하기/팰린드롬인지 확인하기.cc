#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int result = 1;
    for(int i = 0; i < str.size()/2; i++){
        if(str[i] != str[str.size() - i - 1]){
            cout << "0";
            return 0;
        }
    }
    cout << result; 
    return 0;
}