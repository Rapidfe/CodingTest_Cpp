#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

//tuple 사용법
//tuple get으로 참조
//vector, map에 tuple 넣기
//tuple vector sorting
//const
//최대인 genre -> genre를 key로 하는 map
//더 큰 plays -> plays를 key로 하는 map (x)
//genre를 key로 하는 map을 plays로 정렬
//map의 value로 정렬하기는 어렵다 (vertor로 복사해서 정렬함)
//map의 key는 변경이 어렵다
//multimap은 insert로만
using namespace std;

bool cmp(const pair<string,int> &a, const pair<string,int> &b){
    return ( a.second > b.second );
}

bool cmp_arr(const pair<string,int> &a, const pair<string,int> &b){
    return ( a.second > b.second );
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    multimap<string,int> arr;
    vector<tuple<string,int,int>> arr_sorting;
    map<string,int> genres_playing;

    for(int i=0; i<genres.size(); i++){
        arr_sorting.push_back(make_tuple(genres[i], plays[i],i));
        //arr[genres[i]] = {plays[i], i};
        if( genres_playing.count(genres[i]) ){
            genres_playing[genres[i]] += plays[i];
        }else{
            genres_playing[genres[i]] = plays[i];
        }
    }

    vector<pair<string,int>> genres_sorting;
    copy(genres_playing.begin(), genres_playing.end(), back_inserter<vector<pair<string,int>>>(genres_sorting));
    sort(genres_sorting.begin(), genres_sorting.end(), cmp);

    sort(arr_sorting.begin(), arr_sorting.end(), cmp);
    for(int i=0; i<arr_sorting.size(); i++){
        arr.insert(tuple<string,int,int>(arr_sorting[i].first, arr_sorting[i].second));
        //arr[arr_sorting[i].first] = arr_sorting[i].second;
    }
    cout<<genres_sorting[0].first;
    answer.push_back((*arr.find(genres_sorting[0].first)).second);

    //sort(arr.begin(), arr.end(), cmp_arr);
    //*max_element(genres_playing)


    return answer;
}

int main(){
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};

    vector <int> answer = solution(genres, plays);
    cout<<"[";
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i];
        if(i != answer.size()-1)
            cout<<", ";
    }
    cout<<"]";

    return 0;
}
