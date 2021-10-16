 /*
ID: 63011293
Name: Raviphas Sananpanichkul
Final Project
OBJECT-ORIENTED CONCEPTS AND PROGRAMMING
Teacher: Sarun Intakosum
University: King Mongkut's Institute of Technology Ladkrabang
*/

#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <QDebug>

using namespace std;

class Entity // base class x abstract class
{
    private:
        int maxHP;
        int hp;
        int atk_base;
        int score;
    public:
        Entity(){}
        ~Entity(){}
        //MAX HP
        void setMaxHP(int newMaxHP){
            maxHP = newMaxHP;
        }
        int getMaxHP(){
            return maxHP;
        }
        //HP
        void setHP(int newHP){
            hp = newHP;
        }
        int getHP(){
            return hp;
        }
        double getPercentHP(){
            double temp = (double)getHP();
            return (temp/getMaxHP());
        }

        virtual void tookDMG(int outDMG) = 0; // abstract method

        void fullHeal(){
            hp = maxHP;
        }

        void heal(int value){
            if((hp+value)>maxHP){
                hp = maxHP;
            }
            else{
                hp += value;
            }
        }
        //ATK_BASE
        void  setATK(int newATK){
            atk_base = newATK;
        }
        int getATKbase(){
            return atk_base;
        }
        //OTHER
        bool isAlive(){
            return (hp>0);
        }
        //Score
        void setScore(int newScore){
            score = newScore;
        }
        void addScore(int addedScore){
            score += addedScore;
        }
        int getScore(){
            return score;
        }
};



#endif // ENTITY_H
