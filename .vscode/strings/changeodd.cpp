#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cout<<"enter string";
    cin>>s;
    for(int i=0;i<s.length();i++){
        if((i+1)%2!=0){
            s[i]='#';
        }
    }
    cout<<s;
}