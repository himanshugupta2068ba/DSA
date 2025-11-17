#include<iostream>
#include<vector>
using namespace std;
void printSubset(string ans ,string original,vector<string>&v){
    if(original==""){
        v.push_back(ans);
        return;
    }
    char ch=original[0];
    printSubset(ans,original.substr(1),v);
    printSubset(ans+ch,original.substr(1),v);
}

int main(){
 string str="abc";
 vector<string>v;
 printSubset("",str,v);
 for(string ele :v){
    cout<<ele<<endl;
 }
}