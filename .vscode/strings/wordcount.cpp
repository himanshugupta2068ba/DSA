#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
    string str="himanshu is the king and born to rule the world.";
    stringstream ss(str);
    string temp;
    vector<string>v;
    while(ss>>temp){
        v.push_back(temp);
    }
    int max=0;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        int count=1;
        if(v[i]==v[i+1]){
            count++;
        }
        if(count>max) max=count;
    }
    for(int i=0;i<v.size();i++){
        int count=1;
        if(v[i]==v[i+1]){
            count++;
        }
        if(count==max) cout<<v[i]<<" "<<count<<endl;
    }

}