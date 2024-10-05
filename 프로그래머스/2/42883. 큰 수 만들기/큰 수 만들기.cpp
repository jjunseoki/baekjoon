#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    vector<char> v;
    string answer = "";
    
    for(int i = 0; i < number.size(); i++){ 
        char current = number[i];
        while (!v.empty() && k > 0 && v.back() < current) {
            v.pop_back(); 
            k--; 
        }
        v.push_back(current); 
    }

    while (k > 0) { 
        v.pop_back();
        k--;
    }

    answer = string(v.begin(), v.end()); 
    return answer; 
}
