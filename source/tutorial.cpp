/*
ID: 63011293
Name: Raviphas Sananpanichkul
Final Project
OBJECT-ORIENTED CONCEPTS AND PROGRAMMING
Teacher: Sarun Intakosum
University: King Mongkut's Institute of Technology Ladkrabang
*/

#include "tutorial.h"
#include "ui_tutorial.h"
#include <QDebug>
#include <QTime>

Tutorial::Tutorial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tutorial)
{
    ui->setupUi(this);
    // set up timer
    player_timer = new QTimer();
    enemy_timer = new QTimer();

    // Set media
    effect.setMedia(QUrl("qrc:/sounds/sound/slash.mp3"));
    effect.setVolume(15);

    // Add all bt to bt Vec
    btVec = {ui->chrbt0,ui->chrbt0_2,ui->chrbt0_3,ui->chrbt0_4,ui->chrbt0_5,ui->chrbt0_6,ui->chrbt0_7,ui->chrbt0_8,ui->chrbt0_9,ui->chrbt0_10,ui->chrbt0_11,ui->chrbt0_12
            ,ui->chrbt0_13,ui->chrbt0_14,ui->chrbt0_15,ui->chrbt0_16,ui->chrbt0_17,ui->chrbt0_18,ui->chrbt0_19,ui->chrbt0_20,ui->chrbt0_21,ui->chrbt0_22,ui->chrbt0_23,ui->chrbt0_24};

    // Add all anslbl to ansLblVec
    ansVec = {ui->anslbl,ui->anslbl_2,ui->anslbl_3,ui->anslbl_4,ui->anslbl_5,ui->anslbl_6,ui->anslbl_7,ui->anslbl_8,ui->anslbl_9,ui->anslbl_10};

    //connect blinking func to enemyTimer
    connect(enemy_timer, SIGNAL(timeout()), this, SLOT(func_blink_enemy()));

    //connect blinking func to playerTimer
    connect(player_timer, SIGNAL(timeout()), this, SLOT(func_blink_player()));

    //Set defualt pic for both player and monster
    ui->playerlbl->setPixmap(QPixmap(":/img/img/player.png"));
    ui->enemylbl->setPixmap(QPixmap(":/img/img/enemytt.png"));

    //Set name for enemy
     ui->dismeslbl->setText("Monster: Zombie Turtle");

    //call out the initalizer/reseter
    initializer();

}

Tutorial::~Tutorial()
{
    delete ui;
}

//sound

void Tutorial::slash_sound()
{
    effect.stop();
    effect.play();
}

// initial func / reset all func

void Tutorial::initializer()
{
    // reset all int value
    player_time= 0; enemy_time= 0;countSP = 0;
    //reset the vocab
    reset_vocab();
    //set empty user string
    userString = "";
    // reset the ans lbl
    update_anslbl();
    //hide slash
    ui->enemyslash->hide();
    ui->playerslash->hide();
    // reset enemy
    enemy.fullHeal(); //enemy full heal
    ui->enemylbl->show(); //force enemy lbl to show
    // reset player
    player.resetDefualt(); // reset all for obj player
    ui->playerlbl->show(); // player enemy lbl to show

    //Only for tutorial
    //add 99 item to each type of item
    for(int i = 1; i < 4 ; i++){
        player.setItem(i,99);
    }
    //Set value
    update_item();
    update_score();

    //connect health bar
    update_health();

    //set bt
    setBoolAll(true);
}

//Set Photo

void Tutorial::setCor()
{
    QPixmap cor(":/img/img/correct.png");
    ui->checklbl->setPixmap(cor);
}

void Tutorial::setInCor()
{
    QPixmap incor(":/img/img/incorrect.png");
    ui->checklbl->setPixmap(incor);
}

//Set enable

void Tutorial::setBoolAll(bool setBool)
{
    // Set item bool
    if(setBool){
        if(player.getAmountItem(1) == 0)
          ui->usePotion->setEnabled(!setBool);
        else
          ui->usePotion->setEnabled(setBool);
        if(player.getAmountItem(2) == 0 || player.getItemEffect())
          ui->useMul->setEnabled(!setBool);
        else
          ui->useMul->setEnabled(setBool);
        if(player.getAmountItem(3) == 0)
          ui->useMax->setEnabled(!setBool);
        else
          ui->useMax->setEnabled(setBool);
    }
    else{
       ui->usePotion->setEnabled(setBool);
       ui->useMul->setEnabled(setBool);
       ui->useMax->setEnabled(setBool);
    }
    setBoolAllBT(setBool);
    //set btClr
    ui->clrbt->setEnabled(setBool);
}

void Tutorial::setBoolAllBT(bool setBool)
{
    foreach(QPushButton* bt, btVec){
        bt->setEnabled(setBool);
    }
}

//Timer func

void Tutorial::blink_enemy()
{

    ui->playerslash->show();
    slash_sound();
    enemy_time = 0;
    enemy_timer->start(50);
}

void Tutorial::func_blink_enemy()
{
    if(enemy_time == 3){
        ui->playerslash->hide();
    }
    if(enemy_time == 6){
        enemy_timer->stop();
        enemy_time = 0;
        ui->enemylbl->show();
        if(!enemy.isAlive())
            enemy.fullHeal();
    }
    else{
        if(ui->enemylbl->isHidden())
            ui->enemylbl->show();
        else
            ui->enemylbl->hide();
        enemy_time++;
    }
}

void Tutorial::blink_player()
{
    player_time = 0;
    player_timer->start(50);

}

void Tutorial::func_blink_player()
{
    if(!enemy_timer->isActive()){
    if(player_time == 0){
        monster_attack_player(player);
        ui->enemyslash->show();
        slash_sound();
    }
    else if(player_time == 3){
        ui->enemyslash->hide();
    }
    if(player_time == 6){
        player_timer->stop();
        player_time = 0;
        setBoolAll(true);
        ui->playerlbl->show();
        if(!player.isAlive()){
            player.fullHeal();
        }
    }
    else{
        if(ui->playerlbl->isHidden())
                ui->playerlbl->show();
         else
            ui->playerlbl->hide();
        player_time++;
    }
  }
}

//update func

void Tutorial::update_charbt()
{
    QString temp1 =QString::fromStdString(voCore.getCharPool());
    for(int i = 0; i < 24; i++){
        btVec.at(i)->setText(temp1.at(i));
    }
}

void Tutorial::update_anslbl()
{
    QString emp = "";
    for(int i = 0; i < userString.length(); i++){
        ansVec.at(i)->setText(userString.at(i));
    }
    for(int i = userString.length(); i < 10 ; i++){
         ansVec.at(i)->setText(emp);
    }
}

void Tutorial::update_score()
{
    QString temp = QString::number(player.getScore());
    temp.insert(0,"Score: ");
    ui->scorelbl->setText(temp);
}

void Tutorial::update_health()
{
    ui->playerhpbar->setValue(player.getPercentHP()*100.0);
    ui->enemyhpbar->setValue(enemy.getPercentHP()*100.0);
}

void Tutorial::update_item()
{
    QString temp = QString::number(player.getAmountItem(1));
    temp.insert(0,'x');
    ui->potionAmlbl->setText(temp);
    temp = QString::number(player.getAmountItem(2));
    temp.insert(0,'x');
    ui->mullAMlbl->setText(temp);
    temp = QString::number(player.getAmountItem(3));
    temp.insert(0,'x');
    ui->maxAmlbl->setText(temp);
}

// reset

void Tutorial::reset_vocab()
{
    voCore.clearPool();
    voCore.addRandom();
    voCore.scramble();
    countSP = 0;
    update_charbt();
    on_clrbt_clicked();
}

//Util func

// attack

void Tutorial::player_attack_monster(Monster &ot_enemy)
{
    ui->playerslash->show();
    ot_enemy.tookDMG(player.calDMG(10,6));
    if(!ot_enemy.isAlive()){
        if(player.getItemEffect()){
            player.addScore(ot_enemy.getScore()*2);
            ui->useMul->setEnabled(true);
            player.setItemEffect(false);
        }
        else
            player.addScore(ot_enemy.getScore());
        ot_enemy.fullHeal();
    }
    else{
         if(player.getItemEffect()){
             ui->useMul->setEnabled(true);
             player.setItemEffect(false);
         }
    }
    if(player.getScore() >= 100000000)
        player.setScore(0);
    update_health();
    update_score();
}

void Tutorial::player_attack_monster(Monster &ot_enemy,int length, int sp)
{
    ui->playerslash->show();
    ot_enemy.tookDMG(player.calDMG(length,sp));
    if(!ot_enemy.isAlive()){
        if(player.getItemEffect()){
            player.addScore(ot_enemy.getScore()*2*player.getMultiplier());
            player.addScore(100*length*2*player.getMultiplier());
            player.addScore(200*sp*2*player.getMultiplier());
            ui->useMul->setEnabled(true);
            player.setItemEffect(false);
        }
        else{
            player.addScore(ot_enemy.getScore()*player.getMultiplier());
            player.addScore(100*length*player.getMultiplier());
            player.addScore(200*sp*player.getMultiplier());
        }
    }
   else{
        if(player.getItemEffect()){
            player.addScore(100*length*2);
            player.addScore(200*sp*2);
            ui->useMul->setEnabled(true);
            player.setItemEffect(false);
        }
        else{
            player.addScore(100*length);
            player.addScore(200*sp);
        }
    }
    if(player.getScore() >= 100000000)
        player.setScore(0);
    update_health();
    update_score();
}

void Tutorial::monster_attack_player(Player &ot_player)
{
    ot_player.tookDMG(enemy.calDMG());
    if(!ot_player.isAlive())
        ot_player.fullHeal();
    update_health();
}

//Use item

void Tutorial::tutoItem(int itemID)
{
    player.useItem(itemID);
    if(player.getAmountItem(itemID) == 0){
        player.setItem(itemID,99);
    }
    update_item();
}

void Tutorial::funcCheck(QString temp2)
{
    userString.push_back(temp2);
    update_anslbl();
    string temp = userString.toStdString();
    if(voCore.isVocab(temp)){
        setCor();
        ui->atkbt->setEnabled(true);
    }
   else{
        setInCor();
        ui->atkbt->setEnabled(false);
    }
    if(userString.length() == 10){
        setBoolAllBT(false);
    }
}

//Button func

//Action func

void Tutorial::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    initializer();
    emit backClicked();

}

void Tutorial::on_atkbt_clicked()
{
    player_attack_monster(enemy,userString.length(),countSP);
    reset_vocab();
    setBoolAll(false);
    blink_enemy();
    blink_player();
    setBoolAll(true);
}

void Tutorial::on_clrbt_clicked()
{
    userString.clear();
    update_anslbl();
    foreach(QPushButton* bt, btVec){
        bt->setEnabled(true);
    }
    QString ogB = "color: white;background-color: rgb(191, 191, 191); border-radius: 0;";
    ui->chrbt0_4->setStyleSheet(ogB);
    ui->chrbt0_8->setStyleSheet(ogB);
    ui->chrbt0_9->setStyleSheet(ogB);
    ui->chrbt0_14->setStyleSheet(ogB);
    ui->chrbt0_19->setStyleSheet(ogB);
    ui->chrbt0_24->setStyleSheet(ogB);
    setInCor();
    ui->atkbt->setEnabled(false);
    countSP = 0;
}

//Item func

void Tutorial::on_useMax_clicked()
{
    player_attack_monster(enemy);
    tutoItem(3);
    reset_vocab();
    setBoolAll(false);
    blink_enemy();
    blink_player();
}

void Tutorial::on_usePotion_clicked()
{
    tutoItem(1);
    update_health();
}

void Tutorial::on_useMul_clicked()
{
    tutoItem(2);
    ui->useMul->setEnabled(false);
}

// Character button

void Tutorial::on_chrbt0_clicked()
{
    ui->chrbt0->setEnabled(false);
    funcCheck(ui->chrbt0->text());
}
void Tutorial::on_chrbt0_2_clicked(){
    ui->chrbt0_2->setEnabled(false);
    funcCheck(ui->chrbt0_2->text());
}
void Tutorial::on_chrbt0_3_clicked(){
    ui->chrbt0_3->setEnabled(false);
    funcCheck(ui->chrbt0_3->text());
}
void Tutorial::on_chrbt0_4_clicked(){
    ui->chrbt0_4->setEnabled(false);
    countSP++;
    ui->chrbt0_4->setStyleSheet("color: rgb(191, 191, 191);background-color: rgb(191, 191, 191); border-radius: 0;");
    funcCheck(ui->chrbt0_4->text());
}
void Tutorial::on_chrbt0_5_clicked(){
    ui->chrbt0_5->setEnabled(false);
    funcCheck(ui->chrbt0_5->text());
}
void Tutorial::on_chrbt0_6_clicked(){
    ui->chrbt0_6->setEnabled(false);
    funcCheck(ui->chrbt0_6->text());
}
void Tutorial::on_chrbt0_7_clicked(){
    ui->chrbt0_7->setEnabled(false);
    funcCheck(ui->chrbt0_7->text());

}
void Tutorial::on_chrbt0_8_clicked(){
    ui->chrbt0_8->setEnabled(false);
    countSP++;
    ui->chrbt0_8->setStyleSheet("color: rgb(191, 191, 191);background-color: rgb(191, 191, 191); border-radius: 0;");
    funcCheck(ui->chrbt0_8->text());
}
void Tutorial::on_chrbt0_9_clicked(){
    ui->chrbt0_9->setEnabled(false);
    countSP++;
    ui->chrbt0_9->setStyleSheet("color: rgb(191, 191, 191);background-color: rgb(191, 191, 191); border-radius: 0;");
    funcCheck(ui->chrbt0_9->text());
}
void Tutorial::on_chrbt0_10_clicked(){
    ui->chrbt0_10->setEnabled(false);
    funcCheck(ui->chrbt0_10->text());
}
void Tutorial::on_chrbt0_11_clicked(){
    ui->chrbt0_11->setEnabled(false);
    funcCheck(ui->chrbt0_11->text());
}
void Tutorial::on_chrbt0_12_clicked(){
    ui->chrbt0_12->setEnabled(false);
    funcCheck(ui->chrbt0_12->text());
}
void Tutorial::on_chrbt0_13_clicked(){
    ui->chrbt0_13->setEnabled(false);
    funcCheck(ui->chrbt0_13->text());
}
void Tutorial::on_chrbt0_14_clicked(){
    ui->chrbt0_14->setEnabled(false);
    countSP++;
    ui->chrbt0_14->setStyleSheet("color: rgb(191, 191, 191);background-color: rgb(191, 191, 191); border-radius: 0;");
    funcCheck(ui->chrbt0_14->text());
}
void Tutorial::on_chrbt0_15_clicked(){
    ui->chrbt0_15->setEnabled(false);
    funcCheck(ui->chrbt0_15->text());
}
void Tutorial::on_chrbt0_16_clicked(){
    ui->chrbt0_16->setEnabled(false);
    funcCheck(ui->chrbt0_16->text());
}
void Tutorial::on_chrbt0_17_clicked(){
    ui->chrbt0_17->setEnabled(false);
    funcCheck(ui->chrbt0_17->text());
}
void Tutorial::on_chrbt0_18_clicked(){
    ui->chrbt0_18->setEnabled(false);
    funcCheck(ui->chrbt0_18->text());
}
void Tutorial::on_chrbt0_19_clicked(){
    ui->chrbt0_19->setEnabled(false);
    countSP++;
    ui->chrbt0_19->setStyleSheet("color: rgb(191, 191, 191);background-color: rgb(191, 191, 191); border-radius: 0;");
    funcCheck(ui->chrbt0_19->text());
}
void Tutorial::on_chrbt0_20_clicked(){
    ui->chrbt0_20->setEnabled(false);
    funcCheck(ui->chrbt0_20->text());
}
void Tutorial::on_chrbt0_21_clicked(){
    ui->chrbt0_21->setEnabled(false);
    funcCheck(ui->chrbt0_21->text());
}
void Tutorial::on_chrbt0_22_clicked(){
    ui->chrbt0_22->setEnabled(false);
    funcCheck(ui->chrbt0_22->text());
}
void Tutorial::on_chrbt0_23_clicked(){
    ui->chrbt0_23->setEnabled(false);
    funcCheck(ui->chrbt0_23->text());
}
void Tutorial::on_chrbt0_24_clicked(){
    ui->chrbt0_24->setEnabled(false);
    countSP++;
    ui->chrbt0_24->setStyleSheet("color: rgb(191, 191, 191);background-color: rgb(191, 191, 191); border-radius: 0;");
    funcCheck(ui->chrbt0_24->text());
}


void Tutorial::on_nextBt_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Tutorial::on_backButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
