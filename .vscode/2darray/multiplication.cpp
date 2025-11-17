#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"enter number of rows for 1st matrix";
    cin>>a;
    int b;
    cout<<"enter number of columns for 1st matrix";
    cin>>b;
    int c;
    cout<<"enter number of rows for 2nd matrix";
    cin>>c;
    int d;
    cout<<"enter number of columns in 2nd  matrix";
    cin>>d;
    if(b!=c){
        cout<<"multipllication not possible";
        return 0;
    }
    int arr1[a][b];
    cout<<"enter element in 1st matrix";
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>arr1[i][j];
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int arr2[c][d];
    for(int i=0;i<c;i++){
        for(int j=0;j<d;j++){
            cin>>arr2[i][j];
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<d;j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    //resultant matrix
    int res[a][d];
    for(int i=0;i<a;i++){
        for(int j=0;j<d;j++){
            res[i][j] = 0;
            
            for(int k=0;k<b;k++){
                res[i][j]+=arr1[i][k]*arr2[k][j];
                
            }
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<d;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}