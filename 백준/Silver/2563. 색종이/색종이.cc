#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include <vector>
#define MAX 101
using namespace std;

int cnt = 0;
int arr[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); 
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int x, y;
        cin >> x >> y;
        for(int i = y; i < y+10; i++){
            for(int j=x; j < x+10; j++){
                if(!arr[i][j]){
                    cnt++;
                    arr[i][j]=1;
                }
            }
        }
    }
    cout << cnt;
	return 0;	
}