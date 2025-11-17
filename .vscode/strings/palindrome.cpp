#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cout<<"enter string";
    cin>>s;
    int flag=-1;
    for(int i=0;i<s.length();i++){
        if(s[i]!=s[s.length()-1-i]){
           flag=0;
        }
        
    }
    if(flag==0) cout<<"not palindrome";
    else cout<<"palindrome";
   
}