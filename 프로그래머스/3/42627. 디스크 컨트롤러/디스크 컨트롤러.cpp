#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    // 요청 시점 오름차순 정렬
    sort(jobs.begin(), jobs.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int time = 0, idx = 0, total = 0, count = 0;

    while (count < jobs.size()) {
        // 현재 시점까지 들어온 작업을 힙에 삽입
        while (idx < jobs.size() && jobs[idx][0] <= time) {
            pq.push({jobs[idx][1], jobs[idx][0]});  // {소요시간, 요청시간}
            idx++;
        }

        if (!pq.empty()) {
            auto [duration, start] = pq.top(); pq.pop();
            time += duration;
            total += (time - start);  // 요청부터 종료까지 걸린 시간
            count++;
        } else {
            time = jobs[idx][0];  // 작업이 없으면 다음 작업까지 점프
        }
    }

    return total / jobs.size();
}
