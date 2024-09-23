#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> music_cnt;
    map<string, vector<pair<int ,int>>> songs_pos;
    for(int i = 0; i < genres.size(); i++){
        music_cnt[genres[i]] += plays[i];
        songs_pos[genres[i]].push_back({plays[i], i});
    }
    
    // 속한 노래가 많이 재생된 장르를 먼저 수록
    vector<pair<string, int>> sorted_genres(music_cnt.begin(), music_cnt.end());
    sort(sorted_genres.begin(), sorted_genres.end(), [](pair<string, int>a, pair<string, int>b){
        return a.second > b.second;
    });
    
    // 장르 내에서 많이 재생된 노래를 먼저 수록
    for(auto& genre: sorted_genres){
        string genreName = genre.first;
        
        sort(songs_pos[genreName].begin(), songs_pos[genreName].end(), [](pair<int, int>a, pair<int, int>b){
            // 재생횟수가 같으면 고유 번호가 낮은 노래 먼저 수록
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        
        for (int i = 0; i < min(2, (int)songs_pos[genreName].size()); i++) {
            answer.push_back(songs_pos[genreName][i].second); 
        }
    }
    return answer;
}