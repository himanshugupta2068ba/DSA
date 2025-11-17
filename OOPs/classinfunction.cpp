//pasing class object to function
#include<iostream>
using namespace std;

class Player{
 private:
    int health;
    int age;
    int score;
    bool alive;
 public:
  int getHealth(){
    return health;
  }
  int getAge(){
    return age;
  }
  int getScore(){
    return score;
  }
  int isAlive(){
    return alive;
  }
  void setHealth(int health){
    this->health=health; //this ka matlab is wale class ka health
  }
   void setAge(int age){
    this->age=age; //this ka matlab is wale class ka health
  }
  void setScore(int score){
    this->score=score; //this ka matlab is wale class ka health
  }
  void setAlive(bool alive){
    this->alive=alive; //this ka matlab is wale class ka health
  }
 };
 void add(Player a,Player b){
    cout<<a.getScore()+b.getScore();
 }
 Player getMaxScore(Player a, Player b){
    if(a.getScore()>b.getHealth())
     return a;
    else
     return b;
 }
 int main(){
  Player Himanshu;//object creation statically
  Player Ragahav;//compile time,static

  Player *King=new Player; //run time, dynamically allocation
  
  Himanshu.setAge(21);
  Himanshu.setScore(200);
  Himanshu.setAlive(true);
  Himanshu.setHealth(100);

  Ragahav.setAge(21);
  Ragahav.setScore(100);
  Ragahav.setAlive(true);
  Ragahav.setHealth(100);

  King->setHealth(79);//->used for dynammically defined objects
  
  add (Himanshu,Ragahav);cout<<endl;
  Player ABC=getMaxScore(Himanshu,Ragahav);
  cout<<ABC.getScore();
 }