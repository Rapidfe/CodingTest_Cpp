#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;

int main(){
    int test_case;
    int T;
    cin>>T;
    int N,M;
    for(test_case = 1; test_case <= T; ++test_case){
        cin>>N>>M;
        vector<int> mat(N*M);
        set<int> kinds;
        list<int> row;
        list<int> col;
        for(int i=0; i<N; i++) col.push_back(i);
        for(int i=0; i<M; i++) row.push_back(i);
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>mat[M*i+j];
                kinds.insert(mat[M*i+j]);
            }
        }
        int isNo;
        for(int k : kinds){
            isNo = 1;
            list<int>::iterator iter1;
            for(iter1=col.begin(); iter1!=col.end(); iter1++){
                int i = *iter1;
                int door = 1;
                for(int j=0; j<M; j++){
                    if( mat[M*i+j] != k && mat[M*i+j] != -1){
                        door = 0;
                        break;
                    }
                }
                if(door){
                    for(int j=0; j<M; j++){
                        mat[M*i+j] = -1;
                    }
                    isNo = 0;
                    iter1++;
                    col.remove(i);
                    iter1--;
                }
            }
            list<int>::iterator iter2;
            for(iter2=row.begin(); iter2!=row.end(); iter2++){
                int i = *iter2;
                int door = 1;
                for(int j=0; j<N; j++){
                    if( mat[M*j+i] != k && mat[M*j+i] != -1){
                        door = 0;
                        break;
                    }
                }
                if(door){
                    for(int j=0; j<N; j++){
                        mat[M*j+i] = -1;
                    }
                    isNo = 0;
                    iter2++;
                    row.remove(i);
                    iter2--;
                }
            }
            if(isNo) break;
        }
        cout<<"#"<<test_case;
        if(isNo) cout<<" NO"<<endl;
        else cout<<" YES"<<endl;
    }
    return 0;
}
