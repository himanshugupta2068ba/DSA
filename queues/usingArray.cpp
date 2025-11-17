#include <iostream>
#include<vector>
using namespace std;

class Queue{
  public:
    int f;
    int b;
    // int arr[5];
    vector<int>arr;
    Queue(int val){
        f=-1;
        b=-1;
        vector<int>v(val);
        arr=v;
    }
    void push(int val){
        if(b==arr.size()-1){
            cout<<"Queue is ful"<<endl;
            return;
        }
        arr[b]=val;
        b++;
    }
    void pop(){
        if(f-b==0){
            cout<<"queue is empty";
            return;
        }
        f++;
    }
    int front(){
        if(f-b==0){
            cout<<"Queue is empty";
            return -1;
        }
        return arr[f];
    }
    int back(){
          if(f-b==0){
            cout<<"Queue is empty";
            return -1;
        }
        return arr[b-1];
    }
    int size(){
        return b-f;
    }
    bool empty(){
        if(f-b==0) return true;
        else return false;
    }
    void display(){
     for(int i=f;i<b;i++){
        cout<<arr[i]<<" ";
     }
     cout<<endl;
    }

};


int main() {
    Queue q(5);
     
}
//problem in array implementation
//->after poping the array size wastages