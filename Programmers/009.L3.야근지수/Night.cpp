#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

//end iterator가 erase되면 자동으로 --된다

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    map<int,int> sorted;
    int counting, total=0;

    for(int i=0; i<works.size(); i++){
        if( sorted.count(works[i])==0 )
            counting = count(works.begin(), works.end(), works[i]);
            sorted.insert(pair<int,int> (works[i], counting));
            //answer += pow(works[i], 2)*(counting);
    }
    for(auto i=sorted.end(); i!=sorted.begin();){
        auto tmp_i = i;
        tmp_i--;
        auto tmp_i2 = tmp_i;
        tmp_i2--;
        total += tmp_i->second;
        if( total >= n ){
            if(tmp_i2->first == (tmp_i->first)-1)
                tmp_i2->second += tmp_i->second - (total-n);
            else
                sorted.insert(pair<int,int> ((tmp_i->first)-1, tmp_i->second - (total-n)));
            if( total == n )
                sorted.erase(tmp_i);
            else
                tmp_i->second -= tmp_i->second - (total-n);
            break;
            //answer -= pow(tmp_i->first, 2)*(tmp_i->second - diff);
        }else{
            if(tmp_i->first == 1) return 0;
            if(tmp_i2->first == (tmp_i->first)-1)
                tmp_i2->second += tmp_i->second;
            else
                sorted.insert(pair<int,int> ((tmp_i->first)-1, tmp_i->second));
            sorted.erase(tmp_i);
            //answer -= pow(tmp_i->first, 2)*(tmp_i->second);
        }
    }
    for(auto i=sorted.begin(); i!=sorted.end(); i++){
        //cout<<i->first<<": "<<i->second<<endl;
        answer += pow(i->first, 2)*(i->second);
    }
    return answer;
}

int main(){
    vector<int> works = {4,3,3};
    int n = 4;
    //cout<<works.size();
    cout<<solution(n, works);
    return 0;
}
