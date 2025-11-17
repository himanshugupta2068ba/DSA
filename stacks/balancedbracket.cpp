#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool BalancedBrackets(string str) {
    stack<char>s;
    for(int i=0; i<str.length(); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            s.push(str[i]);
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
            if(s.empty())
                return false;
            char top_element = s.top();
            s.pop();
            if((top_element == '(' && str[i]!=')') || (top_element == '{' && str[i]!='}') || (top_element == '[' && str[i]!=']')){
                return false;
            }
        }
    
}
}
int main(){
    string str = "[{()}]";
    cout << "The given string is " << (BalancedBrackets(str)? "balanced" : "not balanced") << endl;
    return 0;
}