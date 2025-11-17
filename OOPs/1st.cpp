#include<iostream>
using namespace std;
class Player{
    public:
    int score; //data members
    int health;
};
 int  main(){
    Player amit;
    amit.score=90;
    amit.health=100;
    cout<<amit.score<<endl;
    cout<<amit.health;
 }