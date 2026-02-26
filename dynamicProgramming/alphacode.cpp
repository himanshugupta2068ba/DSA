// Problem
// Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:

// Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

// Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

// Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

// Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

// Alice: “How many different decodings?” Bob: “Jillions!”

// For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

// string decode(string &input){
//     string res="";
//     if(input.length()==1){
//         res+=(char)(64+input[0]-'0');
//     }else{
//         int num=(input[0]-'0')*10+(input[1]-'0');
//         res+=(char)(64+num);
//     }
//    return res;   
// }

vector<ll>dp;
int f(string &str,int i){
    if(i<=0) return 1;
    ll ans=0;
    if(str[i]-'0'>0){
        ans+=f(str,i-1);
    }
    if(str[i-1]-'0'>0 && (str[i-1]-'0')*10+ (str[i]-'0')<=26 ){
     ans+=f(str,i-2);
    }
  return ans;
}
 
int main(){
    string n;
    cin>>n;
    while(n[0]!=0){
        cout<<f(n,n.size()-1)<<endl;
        cin>>n;
    }
}