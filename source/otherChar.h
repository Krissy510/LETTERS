/*
ID: 63011293
Name: Raviphas Sananpanichkul
Final Project
OBJECT-ORIENTED CONCEPTS AND PROGRAMMING
Teacher: Sarun Intakosum
University: King Mongkut's Institute of Technology Ladkrabang
*/

#ifndef OTHERCHAR_H
#define OTHERCHAR_H
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include "entity.h"
#include "item.h"

class Player : public Entity
{
    private:
        vector<shared_ptr<Item>> inventory;
        double armour;
        double scoreMul;
        bool item_effect; //Multiply score item
    public:
        //defult constructor
        Player(){
            setHP(800);
            setMaxHP(800);
            setATK(30);
            setArmour(1.00);
            setScore(0);
            setItemEffect(false);
            setMultiplier(1.00);
            //Added consumable
            inventory.push_back(GenerateItem::createItem("Potion"));
            inventory.push_back(GenerateItem::createItem("Multiplier"));
            inventory.push_back(GenerateItem::createItem("MaxATK"));
        }
        ~Player(){}
        //score Multiplier
        void setMultiplier(double newMultiplier){
            scoreMul = newMultiplier;
        }
        double getMultiplier(){
            return scoreMul;
        }
        //Armour
        void setArmour(double newval){
            armour = newval;
        }
        double getArmour(){
            return armour;
        }
        //Inventory
        void setItem(int itemID, int newAmount){
            for(auto&& elem: inventory){
                if(elem->getItemID()== itemID){
                    elem->setAmount(newAmount);
                }
            }
        }
        int getAmountItem(int itemID){
            for(auto&& elem: inventory){
                    if(elem->getItemID() == itemID)
                        return elem->getAmount();
            }
            return 0;
        }

        //Action
        int calDMG(int length, int sp){
            double addlength = 1 + (0.2*length);
            double addsp = 1 + (0.2*sp);
            int outDMG = getATKbase() * addlength * addsp;
            return outDMG;
        }
        void tookDMG(int outDMG){
            int cHealth = getHP();
            cHealth -= (outDMG*armour);
            setHP(cHealth);
            if (!isAlive()){
                setHP(0);
            }
        }
        // Consumable effect and usage
        bool getItemEffect(){
            return item_effect;
        }
        void setItemEffect(bool effect){
            item_effect = effect;
        }
        void heal_potion(){
            int maxHealth = getMaxHP();
            int heal_val = 0.2*maxHealth;
            heal(heal_val);
        }
        void useItem(int itemID){
            if(getAmountItem(itemID) != 0){
                for(auto&& elem: inventory){
                    if(elem->getItemID()== itemID){
                        switch (itemID)
                        {
                        case 1:
                            heal_potion();
                            break;
                        case 2:
                            //Multiplier
                            item_effect = true;
                            break;
                        case 3:
                            //Max ATK
                            break;
                        default:
                            break;
                        }
                        elem->useItem();
                    }
                }
            }
        }
        //reset
        void resetDefualt(){
            setHP(800);
            setMaxHP(800);
            setATK(30);
            setArmour(1);
            setMultiplier(1.00);
            setScore(0);
            setItemEffect(false);
            for(auto && item: inventory){
                item->resetItem();
            }
        }
};

class Monster : public Entity
{
    private:
        int condition;
    public:
        Monster(){
            setMaxHP(300);
            setHP(300);
            setATK(10);
            setScore(500);
        }
        ~Monster(){}
        int calDMG(){
            double rng = ((rand()%121)+80)/100.0;
            int baseATK = getATKbase();
            double monsterBoost = (0.5*(1-getPercentHP()))+1;
            double deci = rng*monsterBoost;
            int outDMG = baseATK*deci;
            return outDMG;
        }

        void tookDMG(int outDMG){
            int cHealth = getHP();
            cHealth -= (outDMG);
            if (cHealth <= 0){
                setHP(0);
            }
            else{
                setHP(cHealth);
            }
        }
        void setCondition(){
            condition = rand()%2+1;
        }
        int getCondition(){
            return condition;
        }
};

class Boss : public Monster
{
    
    public:
        Boss(){
            setMaxHP(800);
            setHP(800);
            setATK(20);
            setScore(2000);
            setCondition();
        }
        ~Boss(){}

};

class GenerateEnemy{
    public:
    static shared_ptr<Monster> createEnemy(string enemyType){
        if(enemyType == "Monster"){
            return make_shared<Monster>();
        }
        else if(enemyType == "Boss"){
            return make_shared<Boss>();
        }
        else{
            return nullptr;
        }
    }
};

#endif // OTHERCHAR_H
