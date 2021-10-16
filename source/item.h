/*
ID: 63011293
Name: Raviphas Sananpanichkul
Final Project
OBJECT-ORIENTED CONCEPTS AND PROGRAMMING
Teacher: Sarun Intakosum
University: King Mongkut's Institute of Technology Ladkrabang
*/
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <QDebug>

using namespace std;

class Item //base class 
{
    private:
        string typeItem;
        int id;
        int amount = 0;
    public:
        Item(){}
        ~Item(){}
        //Item Type
        string getType(){
            return typeItem;
        }
        void setType(string theType){
            typeItem = theType;
        }
        //ID
        void setID(int itemid){
            id = itemid;
        }
        int getItemID(){
            return id;
        }
        //Amount
        int getAmount(){
            return amount;
        }
        void addAmount(){
            amount++;
        }
        void setAmount(int newAmount){
            amount = newAmount;
        }
        void resetItem(){
            amount = 0;
        }
        void useItem(){
            amount--;
         }
};

class Consumable : public Item{ 
    public:
        Consumable(){
            setType("Consumable");
        }     
};

class Potion : public Consumable{ // Item id 1
    public:
        Potion(){
           setID(1);
        }
};

class Multiplier : public Consumable{ // Item id 2
    public:
        Multiplier(){
            setID(2);
        }
};

class MaxATK : public Consumable{ // Item id 3
    public:
        MaxATK(){
            setID(3);
        }
};

class GenerateItem{
public:
    static shared_ptr<Item> createItem(string itemName){
    if(itemName == "Potion"){
        return make_shared<Potion>();
    }
    else if(itemName == "Multiplier"){
        return make_shared<Multiplier>();
    }
    else if(itemName == "MaxATK"){
        return make_shared<MaxATK>();
    }
    else{
        return nullptr;
    }
}
};

#endif // ENTITY_H
