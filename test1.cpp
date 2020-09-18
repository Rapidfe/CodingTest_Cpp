#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

char arr[] = {'~','!','@','#','$','%','^','&','*','(',')','=','+','[','{',']','}',':','?',',','<','>'};
unordered_set<char> special(arr, arr+23);

string solution(string new_id) {
    string answer = "";

    for(int i=0; i<new_id.size(); i++){
        if( special.find(new_id[i])==special.end() )
            new_id[i] = tolower(new_id[i]);
        else{
            new_id.erase(i,1);
            i--;
        }
    } // 1+2

    int dotchk = 0;
    for(int i=0; i<new_id.size(); i++){
        if( new_id[i] == '.' ){
            if( dotchk == 0 ) dotchk = 1;
            else{
                new_id.erase(i,1);
                i--;
            }
        }else if( dotchk == 1 ) dotchk = 0;
    } // 3

    if( new_id[0] == '.' ) new_id.erase(0,1);
    if( new_id[new_id.size()-1] == '.' ) new_id.erase(new_id.size()-1,1);
    // 4

    if( new_id.size() == 0 ) new_id = "a"; // 5

    if( new_id.size() > 15 ) new_id.erase(15,new_id.size()-15);
    if( new_id[new_id.size()-1] == '.' ) new_id.erase(new_id.size()-1,1); // 6

    while( new_id.size() < 3 ) new_id += new_id[new_id.size()-1]; // 7

    answer = new_id;
    return answer;
}

int main(){
    string new_id = "...!@BaT#*..y.abcdefghijklm";

    cout<<solution(new_id)<<endl;
    cout<<special.size();
    return 0;
}
