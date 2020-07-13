#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const tuple<int,string,int> &a, const tuple<int,string,int> &b){
    return ( get<2>(a) > get<2>(b) );
}

int main(){
    vector<tuple<int,string,int>> musics;
    musics.push_back(make_tuple(0,"classic",200));
    musics.push_back(make_tuple(1,"pop",100));
    musics.push_back(make_tuple(2,"classic",150));
    musics.push_back(make_tuple(3,"pop",600));

    sort(musics.begin(), musics.end(), cmp);

    cout<<get<2>(musics[0])<<endl;
    cout<<get<2>(musics[1])<<endl;
    cout<<get<2>(musics[2])<<endl;
    cout<<get<2>(musics[3])<<endl;

    map<string,vector<int>> arr;
    arr["classic"] = {100, 0};
    return 0;
}
