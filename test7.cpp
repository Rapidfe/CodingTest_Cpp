#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;

    map<int,vector<int>> twoTeamMan;
    unordered_map<int,multiset<int>> salesOfTeam;
    unordered_set<int> notDoneTeam;
    for(vector<int> i : links){
        unordered_map<int,multiset<int>>::iterator finding = salesOfTeam.find(i[0]);
        if( finding != salesOfTeam.end() ){
            (finding->second).insert( sales[i[1]-1] );
        }else{
            notDoneTeam.insert(i[0]);
            multiset<int> tmp;
            tmp.insert( sales[i[0]-1] );
            tmp.insert( sales[i[1]-1] );
            salesOfTeam[i[0]] = tmp;
        }
    }
    for(vector<int> i : links){
        if( notDoneTeam.find(i[1]) != notDoneTeam.end() ){
            twoTeamMan[sales[i[1]-1]] = {i[1], i[0]};
        }
    }

    /*for(auto i=twoTeamMan.begin(); i!=twoTeamMan.end(); i++){
        cout<<i->first<<" "<<(i->second)[0]<<" "<<(i->second)[1]<<endl;
    }*/

    for(auto i=twoTeamMan.begin(); i!=twoTeamMan.end(); i++){
        if( notDoneTeam.find( (i->second)[0] ) != notDoneTeam.end() && notDoneTeam.find( (i->second)[1] ) != notDoneTeam.end() ){
            int twomin = *salesOfTeam[(i->second)[0]].begin() + *salesOfTeam[(i->second)[1]].begin();
            if( (i->first) <= twomin ){
                //cout<<i->first<<" team: "<<(i->second)[0]<<" "<<(i->second)[1]<<endl;
                answer += i->first;
                salesOfTeam[(i->second)[0]].erase( salesOfTeam[(i->second)[0]].find(i->first) );
                salesOfTeam[(i->second)[1]].erase( salesOfTeam[(i->second)[1]].find(i->first) );
                notDoneTeam.erase((i->second)[0]);
                notDoneTeam.erase((i->second)[1]);
            }
        }
    }
    for(auto i=notDoneTeam.begin(); i!=notDoneTeam.end(); i++){
        answer += *salesOfTeam[*i].begin();
    }

    return answer;
}

int main(){
    vector<int> sales = {14,17,15,18,19,14,13,16,28,17};
    vector<vector<int>> links = {{10, 8}, {1, 9}, {9, 7}, {5, 4}, {1, 5}, {5, 10}, {10, 6}, {1, 3}, {10, 2}};

    cout<<solution(sales, links);
    return 0;
}
