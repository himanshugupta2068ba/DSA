#include<iostream>
using namespace std;
int main(){
    int i,n,m,j;
    
    cout<<"enter number of rows";
    cin>>n;
    cout<<"enter number of coloumns";
    cin>>m;
    for(i=1;i<=n;i++)
    {
       int count=i;
        for(j=1;j<=i;j++)
        {
            cout<<count;
            count--;
        }
     cout<<endl;
      
    }

    }