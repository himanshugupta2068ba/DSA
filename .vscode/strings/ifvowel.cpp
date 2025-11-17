#include<iostream>
#include<string>
using namespace std;
int  main(){
    string s;
    // string vowel="aeiou";
    getline(cin,s);
    cout<<s<<endl;
    for(int i=0;s[i]!='\0';i++){
        if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'){
         cout<<s[i]<<" ";
        }
    }
}