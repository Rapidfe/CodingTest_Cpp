#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main(){
    /*multimap<int,int> a;
    map<int,int> b;
    a.insert(pair<int,int>(1,2));
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
    }*/
    /*
    vector<int> a = {1,2,3,4,5};
    auto iter = a.begin();
    iter += 3;
    cout<<*iter<<endl;
    a.erase(iter);
    cout<<*iter<<endl;
    iter++;
    if(iter == a.end()) cout<<"oo"<<endl;
    cout<<*iter<<endl;*/

    /*
    string a = "abcde";
    cout<<a.size()<<endl;
    cout<<a.length()<<endl;
    if(a[0] == 'a') cout<<"yes"<<endl;*/

    /*
    set<int> b;
    b.insert(2);
    b.insert(1);
    b.insert(3);
    cout<<*(++b.begin())<<endl;
    vector<int> c;
    c.push_back(0);
    c[0] = *b.begin();*/

    /*
    if( "ABC" < "BCD") cout<<"ABC가 크다"<<endl;
    else cout<<"BCD가 크다"<<endl;*/

    /*
    map<string,int> ss;
    ss["11"] = 1;
    ss["22"] = 2;
    ss["33"] = 3;
    cout<<ss["11"]<<endl;*/

    vector<int> a = {1,2,3,4,5};
    auto iter = a.begin();
    cout<<*iter<<" "<<*(iter+4)<<" "<<*((++iter)-1)<<endl;



    return 0;
}
