/*
ID: 63011293
Name: Raviphas Sananpanichkul
Final Project
OBJECT-ORIENTED CONCEPTS AND PROGRAMMING
Teacher: Sarun Intakosum
University: King Mongkut's Institute of Technology Ladkrabang
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <memory>
#include "tutorial.h"

#define LAST_MONSTER 7

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    QString getCurrentDir();

    // sound

    void looping_bg();

    void slash_sound();

    void dead_sound();

    // initial func / reset all func

    void initializer();

    //set func

    //set photo

    void setCor();

    void setInCor();

    //Set enable

    void setBoolAll(bool setBool);

    void setBoolAllBT(bool setBool);

    void setEneName(int idEn);

    // update func

    void update_charbt();

    void update_anslbl();

    void update_score();

    void update_health();

    void update_item();

    void update_numEn();

    // timer func

    void blink_enemy();

    void func_blink_enemy();

    void blink_player();

    void func_blink_player();

    void swapEnemy();

    void nextEnemy();

    // reset func

    void resetall();

    void reset_vocab();

    //Util func

    // attack

    void player_attack_monster(shared_ptr<Monster>ot_enemy);

    void player_attack_monster(shared_ptr<Monster>ot_enemy,int length, int sp);

    void monster_attack_player(Player &ot_player);

    // use Item

    void tutoItem(int itemID);

    void funcCheck(QString temp);

    //move func

    void move_menu();

    void move_game();

    void move_tuto();

    void move_con();

    void move_highScore();

    void move_shop();

    //shop func

    void check_able_purchase();

    void reset_cart();

    void update_score_shop();

    void check_out();

    //Congrat func
    int check_username(QString username);

    //bt func

    // MENU BT
    void on_playBT_clicked();

    void on_highscoreBT_clicked();

    void on_tutoriaBT_clicked();

    void on_quitBT_clicked();

    //INGAME BT
    void on_atkbt_clicked();

    void on_clrbt_clicked();

    void on_useMax_clicked();

    void on_usePotion_clicked();

    void on_useMul_clicked();

    //WORD BT
    void on_chrbt0_clicked();

    void on_chrbt0_2_clicked();

    void on_chrbt0_3_clicked();

    void on_chrbt0_4_clicked();

    void on_chrbt0_5_clicked();

    void on_chrbt0_6_clicked();

    void on_chrbt0_7_clicked();

    void on_chrbt0_8_clicked();

    void on_chrbt0_9_clicked();

    void on_chrbt0_10_clicked();

    void on_chrbt0_11_clicked();

    void on_chrbt0_12_clicked();

    void on_chrbt0_13_clicked();

    void on_chrbt0_14_clicked();

    void on_chrbt0_15_clicked();

    void on_chrbt0_16_clicked();

    void on_chrbt0_17_clicked();

    void on_chrbt0_18_clicked();

    void on_chrbt0_19_clicked();

    void on_chrbt0_20_clicked();

    void on_chrbt0_21_clicked();

    void on_chrbt0_22_clicked();

    void on_chrbt0_23_clicked();

    void on_chrbt0_24_clicked();

    //Shop method

    void on_buyPo_clicked();

    void on_buyMul_clicked();

    void on_buyMax_clicked();

    void on_buyArmor_clicked();

    void on_buySpInk_clicked();

    void on_buyUlti_clicked();

    void on_clrbt_shop_clicked();

    void on_finishbt_clicked();

    //Con func

    void on_skipBt_clicked();

    void on_saveBt_clicked();

    //High Score func

    void update_score_board();

    void on_backbt_clicked();

    void on_findbt_clicked();

    void on_muteBt_clicked(bool checked);

    void on_addSoundBT_clicked();

    void on_lowSoundBT_clicked();

private:
   Ui::MainWindow *ui;
   Tutorial tutorial;
   QString userString;
   QTimer *player_timer, *enemy_timer, *enemy_timer2, *bg_timer;
   QVector<QPushButton *> btVec;
   QVector<QLabel *> ansVec;
   QMediaPlayer bg_player, effect;
   QSqlDatabase mydb;
   QString home_path;
   int player_time, enemy_time, enemy_time2, numEnemy, shop_score, soundVol;
   vector<int> cart;
   Player player;
   shared_ptr<Monster> enemy;
   bool win;
   int countSP ;
   Vocab voCore;

};
#endif // MAINWINDOW_H
