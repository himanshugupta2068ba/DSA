#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cout<<"enter string";
    cin>>s;
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!='a' and s[i]!='e' and s[i]!='i' and s[i]!='o' and s[i]!='u' and s[i]!='A' and s[i]!='E' and s[i]!='I' and s[i]!='O' and s[i]!='U'){
            count++;
        }
    }
    cout<<count;
}