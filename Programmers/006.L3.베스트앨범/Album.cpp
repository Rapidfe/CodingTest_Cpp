#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

//tuple ����
//tuple ���� : get<i>(tuple)
//vector, map�� tuple �ֱ�
//vector<tuple> sorting
//const
//�ִ��� genre ã�ƾߵ� -> genre�� key�� �ϴ� map
//�� ū plays -> plays�� key�� �ϴ� map (x)
//genre�� key�� �ϴ� map�� plays�� ����
//map�� value�� �����ϱ�� ��ƴ� (vertor�� �����ؼ� ������)
//map�� key�� ������ ��ƴ�
//multimap�� insert�θ�?
//map���� value���� : map.find()->second
using namespace std;

bool cmp(const tuple<string,int,int> &a, const tuple<string,int,int> &b){
    return ( get<1>(a) > get<1>(b) );
}

bool cmp_arr(const pair<string,int> &a, const pair<string,int> &b){
    return ( a.second > b.second );
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    multimap<string,vector<int>> arr;
    vector<tuple<string,int,int>> arr_sorting;
    map<string,int> genres_playing;

    for(int i=0; i<genres.size(); i++){
        arr_sorting.push_back(make_tuple(genres[i], plays[i],i));
        if( genres_playing.count(genres[i]) ){
            genres_playing[genres[i]] += plays[i];
        }else{
            genres_playing[genres[i]] = plays[i];
        }
    }

    vector<pair<string,int>> genres_sorting;
    copy(genres_playing.begin(), genres_playing.end(), back_inserter<vector<pair<string,int>>>(genres_sorting));
    sort(genres_sorting.begin(), genres_sorting.end(), cmp_arr);

    sort(arr_sorting.begin(), arr_sorting.end(), cmp);
    for(int i=0; i<arr_sorting.size(); i++){
        arr.insert(pair<string,vector<int>>(get<0>(arr_sorting[i]), {get<1>(arr_sorting[i]), get<2>(arr_sorting[i])}));
    }
    for(int i=0; i<genres_sorting.size(); i++){
        for(int j=0; j<2; j++){
            string best_genre = genres_sorting[i].first;
            auto this_iter = arr.find(best_genre);
            if(this_iter == arr.end()) break;
            answer.push_back(this_iter->second[1]);
            arr.erase(this_iter);
        }
    }


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
