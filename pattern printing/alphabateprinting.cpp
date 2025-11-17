#include<iostream>
using namespace std;
int main(){
    int i,n,m,j;
    char ch='a';
    cout<<"enter number of rows";
    cin>>n;
    cout<<"enter number of coloumns";
    cin>>m;
    for(i=1;i<=n;i++)
    {
        // char ch='a';

        for(j=1;j<=i;j++)
        {
            cout<<ch;
            // ch+=1;//ascii value of ais 97
            //ascii value of A is 65
        }
    cout<<endl;
      ch+=1;
    }

    }