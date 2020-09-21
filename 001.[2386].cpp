#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int tests;
    cin>>tests;
    int lines, res;
    for(int i=0; i<tests; i++){
        res = 0;
        cin>>lines;
        int nums;
        unordered_map<int,int> resMap;
        for(int j=0; j<lines; j++){
            cin>>nums;
            unordered_map<int,int>::iterator iter = resMap.find(nums);
            if( iter!=resMap.end() ){
                if( iter->second == 1 ){
                    iter->second = 0;
                    res--;
                }else{
                    iter->second = 1;
                    res++;
                }
            }else{
                resMap[nums] = 1;
                res++;
            }
        }
        cout<<"#"<<i+1<<" "<<res<<endl;
    }
    return 0;
}
