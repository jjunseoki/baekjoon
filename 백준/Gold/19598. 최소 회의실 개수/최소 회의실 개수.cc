#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> start_time(N);
    vector<int> end_time(N);

    for(int i = 0; i < N; i++){
        cin >> start_time[i] >> end_time[i];
    }

    sort(start_time.begin(), start_time.end());
    sort(end_time.begin(), end_time.end());

    int room = 0;
    int max_room = 0; 
    int i = 0, j = 0;

    while (i < N) {
        if (start_time[i] < end_time[j]) {
            room++;  
            i++;
        } else {
            room--;  
            j++;
        }
        max_room = max(max_room, room); 
    }
    cout << max_room;
    return 0;
}