/*
ID: 63011293
Name: Raviphas Sananpanichkul
Final Project
OBJECT-ORIENTED CONCEPTS AND PROGRAMMING
Teacher: Sarun Intakosum
University: King Mongkut's Institute of Technology Ladkrabang
*/

#ifndef TUTORIAL_H
#define TUTORIAL_H
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QMediaPlayer>
#include <QPixmap>
#include "otherChar.h"
#include "vocabBack.h"
namespace Ui {
class Tutorial;
}

class Tutorial : public QWidget
{
    Q_OBJECT

public:
    explicit Tutorial(QWidget *parent = nullptr);
    ~Tutorial();

private slots:
    //sound

    void slash_sound();

    // initial func / reset all func

    void initializer();

    //set func

    //set photo
    void setCor();

    void setInCor();

    //Set enable

    void setBoolAll(bool setBool);

    void setBoolAllBT(bool setBool);

   // timer func

    void blink_enemy();

    void func_blink_enemy();

    void blink_player();

    void func_blink_player();

    //update func

    void update_charbt();

    void update_anslbl();

    void update_score();

    void update_health();

    void update_item();

    // reset func

    void reset_vocab();

    //Util func

    // attack

    void player_attack_monster(Monster &ot_enemy);

    void player_attack_monster(Monster &ot_enemy,int length, int sp);

    void monster_attack_player(Player &ot_player);

    //use item

    void tutoItem(int itemID);

    void funcCheck(QString temp);

    // Button func

    // Item bt

    void on_useMax_clicked();

    void on_usePotion_clicked();

    void on_useMul_clicked();

    //Action Button

    void on_backButton_clicked();

    void on_atkbt_clicked();

    void on_clrbt_clicked();

    // Character button

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

    void on_nextBt_clicked();

    void on_backButton_2_clicked();

private:
    Ui::Tutorial *ui;
    QVector<QPushButton *> btVec;
    QVector<QLabel *> ansVec;
    QTimer *player_timer, *enemy_timer;
    QString userString;
    QMediaPlayer effect;
    int player_time, enemy_time;
    Player player;
    Monster enemy;
    int countSP;
    Vocab voCore;

signals:
    void backClicked();

};

#endif // TUTORIAL_H
