#include<iostream>
#include<string>
using namespace std;
int  main(){
    string s;
    // string vowel="aeiou";
    getline(cin,s);
    cout<<s<<endl;
    s[0]='b';
    cout<<s;
}