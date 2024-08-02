#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> v(10000001);
    for(int i = 0; i < tangerine.size(); i++){
        v[tangerine[i]]++;
    }
    
    int i = 0;
    sort(v.rbegin(), v.rend());
    while(k > 0){
        k -= v[i];
        i++;
        answer++;
    }
    return answer;
}