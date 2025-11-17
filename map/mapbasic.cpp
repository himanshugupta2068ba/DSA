#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int>m;
    pair<string,int>p1;
    p1.first="hims";
    p1.second=21;
    pair<string,int>p2;
    p2.first="king";
    p2.second=34;
    m.insert(p1);
    m.insert(p2);
//simple method to insert
    m["aimas"]=21;
    for(pair<string,int>p:m){ //auto we can use instead of datatype
        cout<<p.first<<" "<<p.second<<endl;
    }

    m.erase("hims");
}