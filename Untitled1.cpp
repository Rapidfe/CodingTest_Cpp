#include <iostream>
#include <map>

using namespace std;

int main(){
    multimap<int,int> a;
    map<int,int> b;
    a.insert(pair<int,int>(1,2));
    //a[3] = 4;
    b.insert(pair<int,int>(1,2));
    b[3] = 4;

    for(auto i=a.begin(); i!=a.end(); i++){
        cout<<i->first<<" ";
        cout<<i->second<<endl;
    }
    cout<<endl;
    for(auto i=b.begin(); i!=b.end(); i++){
        cout<<i->first<<" ";
        cout<<i->second<<endl;
    }

    return 0;
}
