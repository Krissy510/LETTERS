/*
ID: 63011293
Name: Raviphas Sananpanichkul
Final Project
OBJECT-ORIENTED CONCEPTS AND PROGRAMMING
Teacher: Sarun Intakosum
University: King Mongkut's Institute of Technology Ladkrabang
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFileInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Home path for DB
    home_path = getCurrentDir();
    //Connect SQL
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(home_path + "pScore.db");
    mydb.open();
    //Initialize QQTimer
    player_timer = new QTimer();
    enemy_timer = new QTimer();
    enemy_timer2 = new QTimer();
    bg_timer = new QTimer();
    //Setup UI
    ui->setupUi(this);
    setFixedSize(size());
    //Add tutorial to stacked widget
    ui->stackedWidget->insertWidget(1,&tutorial);

    // Add all bt to bt Vec
    btVec = {ui->chrbt0,ui->chrbt0_2,ui->chrbt0_3,ui->chrbt0_4,
             ui->chrbt0_5,ui->chrbt0_6,ui->chrbt0_7,ui->chrbt0_8,
             ui->chrbt0_9,ui->chrbt0_10,ui->chrbt0_11,ui->chrbt0_12,
             ui->chrbt0_13,ui->chrbt0_14,ui->chrbt0_15,ui->chrbt0_16,
             ui->chrbt0_17,ui->chrbt0_18,ui->chrbt0_19,ui->chrbt0_20,
             ui->chrbt0_21,ui->chrbt0_22,ui->chrbt0_23,ui->chrbt0_24};
    // Add all anslbl to ansLblVec
    ansVec = {ui->anslbl,ui->anslbl_2,ui->anslbl_3,ui->anslbl_4,ui->anslbl_5,
              ui->anslbl_6,ui->anslbl_7,ui->anslbl_8,ui->anslbl_9,ui->anslbl_10};
    //set defualt sound volume
    soundVol = 15;
    //Set media path for effect
    effect.setMedia(QUrl("qrc:/sounds/sound/slash.mp3"));
    effect.setVolume(soundVol);
    //Set media path for BG
    bg_player.setMedia(QUrl("qrc:/sounds/sound/bgMenu.mp3"));
    bg_player.setVolume(soundVol);
    bg_player.play();
    //connect move menu with backBT in tutorial
    connect(&tutorial, SIGNAL(backClicked()), this, SLOT(move_menu()));
    //connect change enemy
    connect(enemy_timer2,SIGNAL(timeout()),this,SLOT(swapEnemy()));
     //connect for looping the bg
    connect(bg_timer, SIGNAL(timeout()), this, SLOT(looping_bg()));
    bg_timer->start(1000);
    //connect blinking func
    connect(enemy_timer, SIGNAL(timeout()), this, SLOT(func_blink_enemy()));
    //connect blinking func
    connect(player_timer, SIGNAL(timeout()), this, SLOT(func_blink_player()));
    //set up bt mute
    ui->muteBt->setCheckable(true);
    //intialize method
    initializer();
}


MainWindow::~MainWindow()
{
    delete ui;
    //close db when finish
    mydb.close();
}

QString MainWindow::getCurrentDir()
{
    char buff[PATH_MAX]; //the maximum length for a path is MAX_PATH, which is defined as 260
    getcwd( buff, PATH_MAX ); //Get the current working directory pathname
    string current_working_dir(buff);
    return QString::fromStdString(current_working_dir) + "\\";
}

void MainWindow::looping_bg()
{
    if(bg_player.state() == QMediaPlayer::StoppedState){
        bg_player.play();
    }
}

void MainWindow::slash_sound()
{
    effect.stop();
    effect.play();
}

void MainWindow::dead_sound()
{
    bg_player.setMedia(QUrl("qrc:/sounds/sound/dead.mp3"));
    bg_player.play();
}



// setup things

void MainWindow::initializer()
{
    player_time= 0; enemy_time= 0;enemy_time2= 0; numEnemy = 0; shop_score = 0;
    ui->atkbt->setEnabled(false);
    countSP = 0;
    win=false;
    //set bt
    setBoolAll(true);
    reset_vocab();
    //set empty user string
    userString = "";
    update_anslbl();
    //hide slash
    ui->enemyslash->hide();
    ui->playerslash->hide();
    //enemy
    enemy = GenerateEnemy::createEnemy("Monster");
    enemy->fullHeal();
    ui->enemylbl->setPixmap(QPixmap(":/img/img/0.png"));
     ui->enemylbl->show();
    //player
    ui->playerlbl->setPixmap(QPixmap(":/img/img/player.png"));
    player.resetDefualt();
    ui->playerlbl->show();
    //Set value
    update_item();
    update_score();
    update_score_shop();
    update_score_board();
    update_numEn();
    ui->scorelbl_3->setText(QString::number(player.getScore()));
    ui->dismeslbl->setText("Monster: Umbrequito");
    //connect health bar
    update_health();

}

void MainWindow::setCor()
{
    ui->checklbl->setPixmap(QPixmap(":/img/img/correct.png"));
}

void MainWindow::setInCor()
{
    ui->checklbl->setPixmap(QPixmap(":/img/img/incorrect.png"));
}

void MainWindow::setBoolAll(bool setBool)
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

void MainWindow::setBoolAllBT(bool setBool)
{
    foreach(QPushButton* bt, btVec){
        bt->setEnabled(setBool);
    }
}

void MainWindow::setEneName(int idEn)
{
    if(idEn == 0)
        ui->dismeslbl->setText("Monster: Umbrequito");
    else if(idEn == 1)
        ui->dismeslbl->setText("Monster: I P");
    else if(idEn == 2)
        ui->dismeslbl->setText("Monster:YEET");
    else if(idEn == 3){
        QString temp = "BEST,The Stoner";
        if(enemy->getCondition() == 1){
            temp.insert(15,"(Vocab > 3 letters)");
        }
        else if(enemy->getCondition() == 2){
            temp.insert(15,"(SP char > 1 letters)");
        }
        ui->dismeslbl->setText(temp);
    }
    else if(idEn == 4)
        ui->dismeslbl->setText("Monster: Angry Boi");
    else if(idEn == 5)
        ui->dismeslbl->setText("Monster: Earth, The Handsome");
    else if(idEn == 6)
        ui->dismeslbl->setText("Monster: Mickey Mouse, The drug dealer");
    else if(idEn == 7){
        QString temp = "Ricado,The OLD MEME";
        if(enemy->getCondition() == 1){
            temp.insert(19,"(Vocab > 3 letters)");
        }
        else if(enemy->getCondition() == 2){
            temp.insert(19,"(SP char > 1 letter)");
        }
        ui->dismeslbl->setText(temp);
    }
}

// visual func

void MainWindow::update_charbt()
{
    QString temp1 =QString::fromStdString(voCore.getCharPool());
    for(int i = 0; i < 24; i++){
        btVec.at(i)->setText(temp1.at(i));
    }
}

void MainWindow::update_anslbl()
{
    QString emp = "";
    for(int i = 0; i < userString.length(); i++){
        ansVec.at(i)->setText(userString.at(i));
    }
    for(int i = userString.length(); i < 10 ; i++){
         ansVec.at(i)->setText(emp);
    }
}

void MainWindow::update_score()
{
    QString temp = QString::number(player.getScore());
    temp.insert(0,"Score: ");
    ui->scorelbl->setText(temp);
}

void MainWindow::update_score_shop()
{
    QString temp = QString::number(shop_score);
    temp.insert(0,"Score: ");
    ui->scorelbl_2->setText(temp);
}

void MainWindow::check_out()
{
    for(int i = 0; i < 3; i++){
        player.setItem(i+1,cart.at(i));
    }
    if(cart.at(3) == 1){
        player.setArmour(0.8);
    }
    if(cart.at(4) == 1){
        player.setATK(1.2*player.getATKbase());
    }
    if(cart.at(5) == 1){
        player.setArmour(2);
        player.setMultiplier(2.00);
        QPixmap godSkin(":/img/img/godskin.png");
        ui->playerlbl->setPixmap(godSkin);
    }
    update_item();
    player.setScore(shop_score);
    update_score();
}

int MainWindow::check_username(QString username)
{
    if(username.length() == 0)
        return 0;
    else if(username.length() > 19)
        return 1;
    for(int i = 0; i < username.length(); i++){
        if(username[i].isSpace()){
            return 2;
        }
    }
    return 3;
}

void MainWindow::blink_enemy()
{

    ui->playerslash->show();
    slash_sound();
    enemy_time = 0;
    enemy_timer->start(50);
}

void MainWindow::func_blink_enemy()
{
    if(enemy_time == 3){
        ui->playerslash->hide();
    }
    if(enemy_time == 6){
        enemy_timer->stop();
        enemy_time = 0;
        if(enemy->isAlive())
            ui->enemylbl->show();
        else
            ui->enemylbl->hide();
    }
    else{
        if(ui->enemylbl->isHidden())
            ui->enemylbl->show();
        else
            ui->enemylbl->hide();
        enemy_time++;
    }
}

void MainWindow::blink_player()
{
    player_time = 0;
    player_timer->start(50);
}

void MainWindow::func_blink_player()
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
        if(player.isAlive())
            ui->playerlbl->show();
        else{
            ui->playerlbl->hide();
            dead_sound();
            QMessageBox::about(this,"GAME OVER","YOU LOSE\nGET GUD\nNEXT TIME THEN");
            move_menu();
            initializer();
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

void MainWindow::swapEnemy()
{
    if(!enemy_timer->isActive()){
        if(enemy_time2 == 0){
            if(numEnemy%4 != 3 && numEnemy%4 != 0){
                ui->dismeslbl->setText("Hmm... What Kind of Monster will it be?");
                enemy->fullHeal();
             }
            else if(numEnemy%4 == 0 && numEnemy > 0){
                if(numEnemy == 4){
                    enemy = GenerateEnemy::createEnemy("Monster");
                    ui->dismeslbl->setText("Best quit his job and sells you item instead");
                }
            }
            else if(numEnemy%4 == 3){
                enemy = GenerateEnemy::createEnemy("Boss");
                bg_player.stop();
                bg_player.setMedia(QUrl("qrc:/sounds/sound/Tension.mp3"));
                bg_player.play();
                if(numEnemy == 3){
                    ui->dismeslbl->setText("You feel like something dangerous is coming");
                }
                else if(numEnemy == 7){
                    ui->dismeslbl->setText("The last boss huh?");
                }
            }

        }
        else if(enemy_time2 == 5){
            update_numEn();
            enemy_time2 = 0;
            enemy_timer2->stop();
            // Sound
            if(numEnemy%4 == 3){
                bg_player.stop();
                if(numEnemy == 3)
                    bg_player.setMedia(QUrl("qrc:/sounds/sound/bgbest2.mp3"));
                else if(numEnemy == 7)
                    bg_player.setMedia(QUrl("qrc:/sounds/sound/Lastboss.mp3"));
                bg_player.play();
            }
            else{
                if(numEnemy%4 == 0 && numEnemy > 0){
                    //dev test
                    move_shop();
                }
            }
            QString newloc = ":/img/img/.png";
            setEneName(numEnemy);
            newloc.insert(10,QString::number(numEnemy));
            QPixmap newPic(newloc);
            ui->enemylbl->setPixmap(newPic);
            ui->enemylbl->show();
            update_health();
            setBoolAll(true);
        }
        enemy_time2++;
    }
    // Swap Texture

}

void MainWindow::nextEnemy()
{
    enemy_time2 = 0;
    enemy_timer2->start(1000);
}

void MainWindow::update_health()
{
    double temp = player.getPercentHP();
    ui->playerhpbar->setValue(temp*100.0);
    temp = enemy->getPercentHP();
    ui->enemyhpbar->setValue(temp*100.0);
}

void MainWindow::update_item()
{
    int tempAM = player.getAmountItem(1);
    QString temp = QString::number(tempAM);
    temp.insert(0,'x');
    if(tempAM == 0){
        ui->usePotion->setEnabled(false);
    }
    else{
        ui->usePotion->setEnabled(true);
    }
    ui->potionAmlbl->setText(temp);
    tempAM = player.getAmountItem(2);
    if(tempAM == 0){
        ui->useMul->setEnabled(false);
    }
    else{
        ui->useMul->setEnabled(true);
    }
    temp = QString::number(tempAM);
    temp.insert(0,'x');
    ui->mullAMlbl->setText(temp);
    tempAM = player.getAmountItem(3);
    if(tempAM == 0){
        ui->useMax->setEnabled(false);
    }
    else{
        ui->useMax->setEnabled(true);
    }
    temp = QString::number(tempAM);
    temp.insert(0,'x');
    ui->maxAmlbl->setText(temp);
}

void MainWindow::update_numEn()
{
    if(numEnemy+1 != 9){
        QString newtext = "Enemy: /8";
        newtext.insert(7,QString::number(numEnemy+1));
        ui->enenumlbl->setText(newtext);
    }
}

//reset func

void MainWindow::resetall()
{
    player.fullHeal();
    for(int i = 1; i < 4 ; i++){
    player.setItem(i,0);
    }
    enemy->fullHeal();
}

void MainWindow::reset_vocab()
{
    voCore.clearPool();
    voCore.addRandom();
    voCore.scramble();
    countSP = 0;
    update_charbt();
    on_clrbt_clicked();
}

void MainWindow::reset_cart()
{
/*
 * 0:Potion
 * 1:Multi
 * 2:Max
 * 3:BodyShield
 * 4:SpecialInk
 * 5:Ultimate Ring
*/ 
    cart = {0,0,0,0,0,0};
}

//atk func

void MainWindow::player_attack_monster(shared_ptr<Monster>ot_enemy)
{
    ui->playerslash->show();
     ot_enemy->tookDMG(player.calDMG(10,6));
    if(!ot_enemy->isAlive()){
        if(player.getItemEffect()){
            player.addScore(ot_enemy->getScore()*2*player.getMultiplier());
            ui->useMul->setEnabled(1);
            player.setItemEffect(false);
        }
        else{
            player.addScore(ot_enemy->getScore()*player.getMultiplier());
        }
        if(numEnemy == 7){
            win = true;
        }
        else{
            numEnemy++;
        }
    }
    update_health();
    update_score();
}

void MainWindow::player_attack_monster(shared_ptr<Monster>ot_enemy,int length, int sp)
{
    if(numEnemy%4 == 3){
        if(enemy->getCondition() == 1){
            if(length > 3){
                ot_enemy->tookDMG(player.calDMG(length,sp));
            }
        }
        else if(enemy->getCondition() == 2){
            if(sp > 1){
                ot_enemy->tookDMG(player.calDMG(length,sp));
            }
        }
    }
    else
        ot_enemy->tookDMG(player.calDMG(length,sp));
    if(!ot_enemy->isAlive()){
        if(player.getItemEffect()){
            player.addScore(ot_enemy->getScore()*2*player.getMultiplier());
            player.addScore(100*length*2*player.getMultiplier());
            player.addScore(200*sp*2*player.getMultiplier());
            ui->useMul->setEnabled(true);
            player.setItemEffect(false);
        }
        else{
            player.addScore(ot_enemy->getScore()*player.getMultiplier());
            player.addScore(100*length*player.getMultiplier());
            player.addScore(200*sp*player.getMultiplier());
        }
        if(numEnemy == 7){
            win = true;
        }
        else{
            numEnemy++;
        }
    }
    else{
    if(player.getItemEffect()){
        player.addScore(100*length*2*player.getMultiplier());
        player.addScore(200*sp*2*player.getMultiplier());
        ui->useMul->setEnabled(1);
        player.setItemEffect(false);
    }
    else{
        player.addScore(100*length*player.getMultiplier());
        player.addScore(200*sp*player.getMultiplier());
    }
    }
    update_health();
    update_score();
}

void MainWindow::monster_attack_player(Player &ot_player)
{
    ot_player.tookDMG(enemy->calDMG());
    update_health();
}

// use Item

void MainWindow::tutoItem(int itemID)
{
    player.useItem(itemID);
    update_item();
}

void MainWindow::funcCheck(QString temp2)
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

void MainWindow::check_able_purchase()
{
    if(shop_score < 15000 || cart.at(3)==1){
        ui->buyArmor->setEnabled(false);

    }
    else{
        ui->buyArmor->setEnabled(true);
    }
    if(shop_score < 15000 || cart.at(4)==1){
        ui->buySpInk->setEnabled(false);
    }
    else{
        ui->buySpInk->setEnabled(true);
    }
    if(shop_score < 10000 || cart.at(5)==1){
        ui->buyUlti->setEnabled(false);
    }
    else{
        ui->buyUlti->setEnabled(true);
    }
    if(shop_score < 5000){
        ui->buyPo->setEnabled(false);
        ui->buyMul->setEnabled(false);
        ui->buyMax->setEnabled(false);
    }
    else{
        ui->buyPo->setEnabled(true);
        ui->buyMul->setEnabled(true);
        ui->buyMax->setEnabled(true);
    }
}

//util func

/*
 * Index    Page
 * 0        Menu
 * 1        Tutorial
 * 2        Main Game
 * 3        Shop
 * 4        Win Menu
*/

void MainWindow::move_menu()
{
    ui->stackedWidget->setCurrentIndex(0);
    bg_player.stop();
    bg_player.setMedia(QUrl("qrc:/sounds/sound/bgMenu.mp3"));
    bg_player.play();
}

void MainWindow::move_game()
{
    ui->stackedWidget->setCurrentIndex(2);
    bg_player.stop();
    bg_player.setMedia(QUrl("qrc:/sounds/sound/battle.mp3"));
    bg_player.play();
}

void MainWindow::move_tuto()
{
    ui->stackedWidget->setCurrentIndex(1);
    bg_player.stop();
    bg_player.setMedia(QUrl("qrc:/sounds/sound/battle.mp3"));
    bg_player.play();
}

void MainWindow::move_con()
{
    QMessageBox::about(this,"YOU WIN","Easy isn't it?");
    ui->scorelbl_3->setText(QString::number(player.getScore()));
    ui->stackedWidget->setCurrentIndex(4);
    bg_player.stop();
    bg_player.setMedia(QUrl("qrc:/sounds/sound/congrat.mp3"));
    bg_player.play();
}

void MainWindow::move_highScore()
{
    bg_player.stop();
    bg_player.setMedia(QUrl("qrc:/sounds/sound/highscoreBG.mp3"));
    bg_player.play();
    update_score_board();
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::move_shop()
{
    bg_player.stop();
    bg_player.setMedia(QUrl("qrc:/sounds/sound/bgShop.mp3"));
    bg_player.play();
    reset_cart();
    ui->stackedWidget->setCurrentIndex(3);
    shop_score = player.getScore();
    update_score_shop();
    check_able_purchase();
}

//bt func

void MainWindow::on_atkbt_clicked()
{
    player_attack_monster(enemy,userString.length(),countSP);
    reset_vocab();
    setBoolAll(false);    
    blink_enemy();
    if(enemy->isAlive()){
        blink_player();
    }
    else{
        if(win){
            move_con();
        }
        else{
            nextEnemy();
        }
    }
}

void MainWindow::on_clrbt_clicked()
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

void MainWindow::on_useMax_clicked()
{
    player_attack_monster(enemy);
    tutoItem(3);
    reset_vocab();
    setBoolAll(false);
    blink_enemy();
    if(enemy->isAlive()){
        blink_player();
    }
    else{
        if(win){
            move_con();
        }
        else{
            nextEnemy();
        }
    }
}

void MainWindow::on_usePotion_clicked()
{
    tutoItem(1);
    update_health();
    update_item();
}

void MainWindow::on_playBT_clicked()
{
    move_game();
}

void MainWindow::on_highscoreBT_clicked()
{
    update_score_board();
    move_highScore();
}

void MainWindow::on_tutoriaBT_clicked()
{
    move_tuto();
}

void MainWindow::on_quitBT_clicked()
{
    this->close();
}

void MainWindow::on_useMul_clicked()
{
    tutoItem(2);
    update_item();
    ui->useMul->setEnabled(false);
}

void MainWindow::on_chrbt0_clicked()
{
    ui->chrbt0->setEnabled(false);
    funcCheck(ui->chrbt0->text());
}
void MainWindow::on_chrbt0_2_clicked(){
    ui->chrbt0_2->setEnabled(false);
    funcCheck(ui->chrbt0_2->text());
}
void MainWindow::on_chrbt0_3_clicked(){
    ui->chrbt0_3->setEnabled(false);
    funcCheck(ui->chrbt0_3->text());
}
void MainWindow::on_chrbt0_4_clicked(){
    ui->chrbt0_4->setEnabled(false);
    countSP++;
    ui->chrbt0_4->setStyleSheet("color: rgb(191, 191, 191);background-color: rgb(191, 191, 191); border-radius: 0;");
    funcCheck(ui->chrbt0_4->text());
}
void MainWindow::on_chrbt0_5_clicked(){
    ui->chrbt0_5->setEnabled(false);
    funcCheck(ui->chrbt0_5->text());
}
void MainWindow::on_chrbt0_6_clicked(){
    ui->chrbt0_6->setEnabled(false);
    funcCheck(ui->chrbt0_6->text());
}
void MainWindow::on_chrbt0_7_clicked(){
    ui->chrbt0_7->setEnabled(false);
    funcCheck(ui->chrbt0_7->text());

}
void MainWindow::on_chrbt0_8_clicked(){
    ui->chrbt0_8->setEnabled(false);
    countSP++;
    ui->chrbt0_8->setStyleSheet("color: rgb(191, 191, 191);background-color: rgb(191, 191, 191); border-radius: 0;");
    funcCheck(ui->chrbt0_8->text());
}
void MainWindow::on_chrbt0_9_clicked(){
    ui->chrbt0_9->setEnabled(false);
    countSP++;
    ui->chrbt0_9->setStyleSheet("color: rgb(191, 191, 191);background-color: rgb(191, 191, 191); border-radius: 0;");
    funcCheck(ui->chrbt0_9->text());
}
void MainWindow::on_chrbt0_10_clicked(){
    ui->chrbt0_10->setEnabled(false);
    funcCheck(ui->chrbt0_10->text());
}
void MainWindow::on_chrbt0_11_clicked(){
    ui->chrbt0_11->setEnabled(false);
    funcCheck(ui->chrbt0_11->text());
}
void MainWindow::on_chrbt0_12_clicked(){
    ui->chrbt0_12->setEnabled(false);
    funcCheck(ui->chrbt0_12->text());
}
void MainWindow::on_chrbt0_13_clicked(){
    ui->chrbt0_13->setEnabled(false);
    funcCheck(ui->chrbt0_13->text());
}
void MainWindow::on_chrbt0_14_clicked(){
    ui->chrbt0_14->setEnabled(false);
    countSP++;
    ui->chrbt0_14->setStyleSheet("color: rgb(191, 191, 191);background-color: rgb(191, 191, 191); border-radius: 0;");
    funcCheck(ui->chrbt0_14->text());
}
void MainWindow::on_chrbt0_15_clicked(){
    ui->chrbt0_15->setEnabled(false);
    funcCheck(ui->chrbt0_15->text());
}
void MainWindow::on_chrbt0_16_clicked(){
    ui->chrbt0_16->setEnabled(false);
    funcCheck(ui->chrbt0_16->text());
}
void MainWindow::on_chrbt0_17_clicked(){
    ui->chrbt0_17->setEnabled(false);
    funcCheck(ui->chrbt0_17->text());
}
void MainWindow::on_chrbt0_18_clicked(){
    ui->chrbt0_18->setEnabled(false);
    funcCheck(ui->chrbt0_18->text());
}
void MainWindow::on_chrbt0_19_clicked(){
    ui->chrbt0_19->setEnabled(false);
    countSP++;
    ui->chrbt0_19->setStyleSheet("color: rgb(191, 191, 191);background-color: rgb(191, 191, 191); border-radius: 0;");
    funcCheck(ui->chrbt0_19->text());
}
void MainWindow::on_chrbt0_20_clicked(){
    ui->chrbt0_20->setEnabled(false);
    funcCheck(ui->chrbt0_20->text());
}
void MainWindow::on_chrbt0_21_clicked(){
    ui->chrbt0_21->setEnabled(false);
    funcCheck(ui->chrbt0_21->text());
}
void MainWindow::on_chrbt0_22_clicked(){
    ui->chrbt0_22->setEnabled(false);
    funcCheck(ui->chrbt0_22->text());
}
void MainWindow::on_chrbt0_23_clicked(){
    ui->chrbt0_23->setEnabled(false);
    funcCheck(ui->chrbt0_23->text());
}
void MainWindow::on_chrbt0_24_clicked(){
    ui->chrbt0_24->setEnabled(false);
    countSP++;
    ui->chrbt0_24->setStyleSheet("color: rgb(191, 191, 191);background-color: rgb(191, 191, 191); border-radius: 0;");
    funcCheck(ui->chrbt0_24->text());
}


void MainWindow::on_buyPo_clicked()
{
    cart.at(0)++;
    shop_score -= 5000;
    check_able_purchase();
    update_score_shop();

}

void MainWindow::on_buyMul_clicked()
{
    cart.at(1)++;
    shop_score -= 5000;
    check_able_purchase();
    update_score_shop();
}

void MainWindow::on_buyMax_clicked()
{
    cart.at(2)++;
    shop_score -= 5000;
    check_able_purchase();
    update_score_shop();
}

void MainWindow::on_buyArmor_clicked()
{
    cart.at(3)++;
    shop_score -= 15000;
    check_able_purchase();
    update_score_shop();
}

void MainWindow::on_buySpInk_clicked()
{
    cart.at(4)++;
    shop_score -= 15000;
    check_able_purchase();
    update_score_shop();
}

void MainWindow::on_buyUlti_clicked()
{
    cart.at(5)++;
    shop_score -= 10000;
    check_able_purchase();
    update_score_shop();
}


void MainWindow::on_clrbt_shop_clicked()
{
    shop_score = player.getScore();
    check_able_purchase();
    reset_cart();
    update_score_shop();
}

void MainWindow::on_finishbt_clicked()
{
    check_out();
    reset_cart();
    move_game();
}

void MainWindow::on_skipBt_clicked()
{
    move_menu();
    initializer();
}



void MainWindow::on_saveBt_clicked()
{
    QString username = ui->lineEdit_username->text();
    int check_us = check_username(username);
    if(check_us == 0){
         ui->errorlbl->setText("Invalid: Username isn't entered");
    }
    else if(check_us == 1){
       ui->errorlbl->setText("Invalid: Username must be less than 19 characters");
    }
    else if(check_us == 2){
       ui->errorlbl->setText("Invalid: Username contain a space");
    }
    else{
        ui->errorlbl->setText("");
        int oldhighscore,newhighscore = player.getScore();
        QSqlQuery qry;
        qry.prepare("SELECT highscore FROM playerdb WHERE username = :us");
        qry.bindValue(":us", username);
        if(qry.exec()){
            int count{0};
            while(qry.next()){
                count++;
                oldhighscore = qry.value(0).toInt();
            }
            if(count==0){
                qry.prepare("INSERT INTO playerdb (username, highscore) VALUES (:us, :newHHS)");
                qry.bindValue(":newHHS", newhighscore);
                qry.bindValue(":us", username);
                if(qry.exec()){
                    initializer();
                    QMessageBox::about(this,"Saved!","Your record was successfully saved");
                    move_menu();
                }
                else{
                    QMessageBox::warning(this,"ERROR","Your record was not saved");
                    qDebug() << qry.lastError().text();
                }
            }
            else if(count == 1){
                if(newhighscore < oldhighscore)
                    ui->errorlbl->setText("Your new score is lower than your highscore");
                else if(newhighscore == oldhighscore)
                    ui->errorlbl->setText("Your new score equal your highscore");
                else{
                    qry.prepare("UPDATE playerdb SET highscore = :newHHS WHERE username = :us");
                    qry.bindValue(":newHHS", newhighscore);
                    qry.bindValue(":us", username);
                    if(qry.exec()){
                        initializer();
                        QMessageBox::about(this,"Updated!","Your record was successfully updated");
                        move_menu();
                    }
                    else{
                        QMessageBox::warning(this,"ERROR","Your record was not updated");
                        qDebug() << qry.lastError().text();
                    }
                }
            }
        }
        else{
            qDebug() << "Check for dup not success";
        }
    }

}

void MainWindow::update_score_board()
{
   QSqlQuery qry;
   QString rank="Rank\n",highscore="HighScore\n",username="Username\n";
   qry.prepare("SELECT * FROM playerdb ORDER BY highscore DESC");
   if(qry.exec()){
       int count{0};
      while(qry.next() && count < 13){
          rank.push_back(QString::number(count+1) +"\n");
          highscore.push_back(qry.value(1).toString() + "\n");
          username.push_back(qry.value(0).toString() + "\n");
          count++;
      }
      ui->ranklbl->setText(rank);
      ui->scoreboardlbl->setText(highscore);
      ui->usernamelbl->setText(username);
   }
   else{
       qDebug() << "The update scoreboard  not success";
       qDebug() << qry.lastError().text();
   }

}

void MainWindow::on_backbt_clicked()
{
    ui->userle->clear();
    move_menu();
}

void MainWindow::on_findbt_clicked()
{

    QString rank,highscore, usUsername = ui->userle->text();
    QSqlQuery qry;
    bool exist{false};
    qry.prepare("SELECT * FROM playerdb ORDER BY highscore DESC");
    if(qry.exec()){
        int count{0};
       while(qry.next()){
           QString dbUsername = qry.value(0).toString();
           if(usUsername.compare(dbUsername) == 0){
            highscore = qry.value(1).toString();
            rank = QString::number(count+1);
            exist = true;
           }
           count++;
       }
       if(!exist){
           QMessageBox::warning(this,"Not found","Sorry, the entered username was not found.\nPlease try other username.");
       }
       else{
           QString text = "Username: " + usUsername + "\nRank: " + rank + "\nHighscore: " + highscore;
           QMessageBox::information(this,"Found",text);
       }
    }
    else{
        qDebug() << "The find bt not success";
    }
}

void MainWindow::on_muteBt_clicked(bool checked)
{
    if(checked){
        ui->muteBt->setText("Unmute");
        bg_player.setVolume(0);
        effect.setVolume(0);
    }
    else{
        ui->muteBt->setText("Mute");
        bg_player.setVolume(soundVol);
    }
}

void MainWindow::on_addSoundBT_clicked()
{
    soundVol++;
    bg_player.setVolume(soundVol);
    effect.setVolume(soundVol);
}

void MainWindow::on_lowSoundBT_clicked()
{
    if(soundVol > 0){
        soundVol--;
        bg_player.setVolume(soundVol);
        effect.setVolume(soundVol);
    }
}
