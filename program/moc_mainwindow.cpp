/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../LETTERS/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[102];
    char stringdata0[1575];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "getCurrentDir"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "looping_bg"
QT_MOC_LITERAL(4, 37, 11), // "slash_sound"
QT_MOC_LITERAL(5, 49, 10), // "dead_sound"
QT_MOC_LITERAL(6, 60, 11), // "initializer"
QT_MOC_LITERAL(7, 72, 6), // "setCor"
QT_MOC_LITERAL(8, 79, 8), // "setInCor"
QT_MOC_LITERAL(9, 88, 10), // "setBoolAll"
QT_MOC_LITERAL(10, 99, 7), // "setBool"
QT_MOC_LITERAL(11, 107, 12), // "setBoolAllBT"
QT_MOC_LITERAL(12, 120, 10), // "setEneName"
QT_MOC_LITERAL(13, 131, 4), // "idEn"
QT_MOC_LITERAL(14, 136, 13), // "update_charbt"
QT_MOC_LITERAL(15, 150, 13), // "update_anslbl"
QT_MOC_LITERAL(16, 164, 12), // "update_score"
QT_MOC_LITERAL(17, 177, 13), // "update_health"
QT_MOC_LITERAL(18, 191, 11), // "update_item"
QT_MOC_LITERAL(19, 203, 12), // "update_numEn"
QT_MOC_LITERAL(20, 216, 11), // "blink_enemy"
QT_MOC_LITERAL(21, 228, 16), // "func_blink_enemy"
QT_MOC_LITERAL(22, 245, 12), // "blink_player"
QT_MOC_LITERAL(23, 258, 17), // "func_blink_player"
QT_MOC_LITERAL(24, 276, 9), // "swapEnemy"
QT_MOC_LITERAL(25, 286, 9), // "nextEnemy"
QT_MOC_LITERAL(26, 296, 8), // "resetall"
QT_MOC_LITERAL(27, 305, 11), // "reset_vocab"
QT_MOC_LITERAL(28, 317, 21), // "player_attack_monster"
QT_MOC_LITERAL(29, 339, 19), // "shared_ptr<Monster>"
QT_MOC_LITERAL(30, 359, 8), // "ot_enemy"
QT_MOC_LITERAL(31, 368, 6), // "length"
QT_MOC_LITERAL(32, 375, 2), // "sp"
QT_MOC_LITERAL(33, 378, 21), // "monster_attack_player"
QT_MOC_LITERAL(34, 400, 7), // "Player&"
QT_MOC_LITERAL(35, 408, 9), // "ot_player"
QT_MOC_LITERAL(36, 418, 8), // "tutoItem"
QT_MOC_LITERAL(37, 427, 6), // "itemID"
QT_MOC_LITERAL(38, 434, 9), // "funcCheck"
QT_MOC_LITERAL(39, 444, 4), // "temp"
QT_MOC_LITERAL(40, 449, 9), // "move_menu"
QT_MOC_LITERAL(41, 459, 9), // "move_game"
QT_MOC_LITERAL(42, 469, 9), // "move_tuto"
QT_MOC_LITERAL(43, 479, 8), // "move_con"
QT_MOC_LITERAL(44, 488, 14), // "move_highScore"
QT_MOC_LITERAL(45, 503, 9), // "move_shop"
QT_MOC_LITERAL(46, 513, 19), // "check_able_purchase"
QT_MOC_LITERAL(47, 533, 10), // "reset_cart"
QT_MOC_LITERAL(48, 544, 17), // "update_score_shop"
QT_MOC_LITERAL(49, 562, 9), // "check_out"
QT_MOC_LITERAL(50, 572, 14), // "check_username"
QT_MOC_LITERAL(51, 587, 8), // "username"
QT_MOC_LITERAL(52, 596, 17), // "on_playBT_clicked"
QT_MOC_LITERAL(53, 614, 22), // "on_highscoreBT_clicked"
QT_MOC_LITERAL(54, 637, 20), // "on_tutoriaBT_clicked"
QT_MOC_LITERAL(55, 658, 17), // "on_quitBT_clicked"
QT_MOC_LITERAL(56, 676, 16), // "on_atkbt_clicked"
QT_MOC_LITERAL(57, 693, 16), // "on_clrbt_clicked"
QT_MOC_LITERAL(58, 710, 17), // "on_useMax_clicked"
QT_MOC_LITERAL(59, 728, 20), // "on_usePotion_clicked"
QT_MOC_LITERAL(60, 749, 17), // "on_useMul_clicked"
QT_MOC_LITERAL(61, 767, 17), // "on_chrbt0_clicked"
QT_MOC_LITERAL(62, 785, 19), // "on_chrbt0_2_clicked"
QT_MOC_LITERAL(63, 805, 19), // "on_chrbt0_3_clicked"
QT_MOC_LITERAL(64, 825, 19), // "on_chrbt0_4_clicked"
QT_MOC_LITERAL(65, 845, 19), // "on_chrbt0_5_clicked"
QT_MOC_LITERAL(66, 865, 19), // "on_chrbt0_6_clicked"
QT_MOC_LITERAL(67, 885, 19), // "on_chrbt0_7_clicked"
QT_MOC_LITERAL(68, 905, 19), // "on_chrbt0_8_clicked"
QT_MOC_LITERAL(69, 925, 19), // "on_chrbt0_9_clicked"
QT_MOC_LITERAL(70, 945, 20), // "on_chrbt0_10_clicked"
QT_MOC_LITERAL(71, 966, 20), // "on_chrbt0_11_clicked"
QT_MOC_LITERAL(72, 987, 20), // "on_chrbt0_12_clicked"
QT_MOC_LITERAL(73, 1008, 20), // "on_chrbt0_13_clicked"
QT_MOC_LITERAL(74, 1029, 20), // "on_chrbt0_14_clicked"
QT_MOC_LITERAL(75, 1050, 20), // "on_chrbt0_15_clicked"
QT_MOC_LITERAL(76, 1071, 20), // "on_chrbt0_16_clicked"
QT_MOC_LITERAL(77, 1092, 20), // "on_chrbt0_17_clicked"
QT_MOC_LITERAL(78, 1113, 20), // "on_chrbt0_18_clicked"
QT_MOC_LITERAL(79, 1134, 20), // "on_chrbt0_19_clicked"
QT_MOC_LITERAL(80, 1155, 20), // "on_chrbt0_20_clicked"
QT_MOC_LITERAL(81, 1176, 20), // "on_chrbt0_21_clicked"
QT_MOC_LITERAL(82, 1197, 20), // "on_chrbt0_22_clicked"
QT_MOC_LITERAL(83, 1218, 20), // "on_chrbt0_23_clicked"
QT_MOC_LITERAL(84, 1239, 20), // "on_chrbt0_24_clicked"
QT_MOC_LITERAL(85, 1260, 16), // "on_buyPo_clicked"
QT_MOC_LITERAL(86, 1277, 17), // "on_buyMul_clicked"
QT_MOC_LITERAL(87, 1295, 17), // "on_buyMax_clicked"
QT_MOC_LITERAL(88, 1313, 19), // "on_buyArmor_clicked"
QT_MOC_LITERAL(89, 1333, 19), // "on_buySpInk_clicked"
QT_MOC_LITERAL(90, 1353, 18), // "on_buyUlti_clicked"
QT_MOC_LITERAL(91, 1372, 21), // "on_clrbt_shop_clicked"
QT_MOC_LITERAL(92, 1394, 19), // "on_finishbt_clicked"
QT_MOC_LITERAL(93, 1414, 17), // "on_skipBt_clicked"
QT_MOC_LITERAL(94, 1432, 17), // "on_saveBt_clicked"
QT_MOC_LITERAL(95, 1450, 18), // "update_score_board"
QT_MOC_LITERAL(96, 1469, 17), // "on_backbt_clicked"
QT_MOC_LITERAL(97, 1487, 17), // "on_findbt_clicked"
QT_MOC_LITERAL(98, 1505, 17), // "on_muteBt_clicked"
QT_MOC_LITERAL(99, 1523, 7), // "checked"
QT_MOC_LITERAL(100, 1531, 21), // "on_addSoundBT_clicked"
QT_MOC_LITERAL(101, 1553, 21) // "on_lowSoundBT_clicked"

    },
    "MainWindow\0getCurrentDir\0\0looping_bg\0"
    "slash_sound\0dead_sound\0initializer\0"
    "setCor\0setInCor\0setBoolAll\0setBool\0"
    "setBoolAllBT\0setEneName\0idEn\0update_charbt\0"
    "update_anslbl\0update_score\0update_health\0"
    "update_item\0update_numEn\0blink_enemy\0"
    "func_blink_enemy\0blink_player\0"
    "func_blink_player\0swapEnemy\0nextEnemy\0"
    "resetall\0reset_vocab\0player_attack_monster\0"
    "shared_ptr<Monster>\0ot_enemy\0length\0"
    "sp\0monster_attack_player\0Player&\0"
    "ot_player\0tutoItem\0itemID\0funcCheck\0"
    "temp\0move_menu\0move_game\0move_tuto\0"
    "move_con\0move_highScore\0move_shop\0"
    "check_able_purchase\0reset_cart\0"
    "update_score_shop\0check_out\0check_username\0"
    "username\0on_playBT_clicked\0"
    "on_highscoreBT_clicked\0on_tutoriaBT_clicked\0"
    "on_quitBT_clicked\0on_atkbt_clicked\0"
    "on_clrbt_clicked\0on_useMax_clicked\0"
    "on_usePotion_clicked\0on_useMul_clicked\0"
    "on_chrbt0_clicked\0on_chrbt0_2_clicked\0"
    "on_chrbt0_3_clicked\0on_chrbt0_4_clicked\0"
    "on_chrbt0_5_clicked\0on_chrbt0_6_clicked\0"
    "on_chrbt0_7_clicked\0on_chrbt0_8_clicked\0"
    "on_chrbt0_9_clicked\0on_chrbt0_10_clicked\0"
    "on_chrbt0_11_clicked\0on_chrbt0_12_clicked\0"
    "on_chrbt0_13_clicked\0on_chrbt0_14_clicked\0"
    "on_chrbt0_15_clicked\0on_chrbt0_16_clicked\0"
    "on_chrbt0_17_clicked\0on_chrbt0_18_clicked\0"
    "on_chrbt0_19_clicked\0on_chrbt0_20_clicked\0"
    "on_chrbt0_21_clicked\0on_chrbt0_22_clicked\0"
    "on_chrbt0_23_clicked\0on_chrbt0_24_clicked\0"
    "on_buyPo_clicked\0on_buyMul_clicked\0"
    "on_buyMax_clicked\0on_buyArmor_clicked\0"
    "on_buySpInk_clicked\0on_buyUlti_clicked\0"
    "on_clrbt_shop_clicked\0on_finishbt_clicked\0"
    "on_skipBt_clicked\0on_saveBt_clicked\0"
    "update_score_board\0on_backbt_clicked\0"
    "on_findbt_clicked\0on_muteBt_clicked\0"
    "checked\0on_addSoundBT_clicked\0"
    "on_lowSoundBT_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      89,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  459,    2, 0x08 /* Private */,
       3,    0,  460,    2, 0x08 /* Private */,
       4,    0,  461,    2, 0x08 /* Private */,
       5,    0,  462,    2, 0x08 /* Private */,
       6,    0,  463,    2, 0x08 /* Private */,
       7,    0,  464,    2, 0x08 /* Private */,
       8,    0,  465,    2, 0x08 /* Private */,
       9,    1,  466,    2, 0x08 /* Private */,
      11,    1,  469,    2, 0x08 /* Private */,
      12,    1,  472,    2, 0x08 /* Private */,
      14,    0,  475,    2, 0x08 /* Private */,
      15,    0,  476,    2, 0x08 /* Private */,
      16,    0,  477,    2, 0x08 /* Private */,
      17,    0,  478,    2, 0x08 /* Private */,
      18,    0,  479,    2, 0x08 /* Private */,
      19,    0,  480,    2, 0x08 /* Private */,
      20,    0,  481,    2, 0x08 /* Private */,
      21,    0,  482,    2, 0x08 /* Private */,
      22,    0,  483,    2, 0x08 /* Private */,
      23,    0,  484,    2, 0x08 /* Private */,
      24,    0,  485,    2, 0x08 /* Private */,
      25,    0,  486,    2, 0x08 /* Private */,
      26,    0,  487,    2, 0x08 /* Private */,
      27,    0,  488,    2, 0x08 /* Private */,
      28,    1,  489,    2, 0x08 /* Private */,
      28,    3,  492,    2, 0x08 /* Private */,
      33,    1,  499,    2, 0x08 /* Private */,
      36,    1,  502,    2, 0x08 /* Private */,
      38,    1,  505,    2, 0x08 /* Private */,
      40,    0,  508,    2, 0x08 /* Private */,
      41,    0,  509,    2, 0x08 /* Private */,
      42,    0,  510,    2, 0x08 /* Private */,
      43,    0,  511,    2, 0x08 /* Private */,
      44,    0,  512,    2, 0x08 /* Private */,
      45,    0,  513,    2, 0x08 /* Private */,
      46,    0,  514,    2, 0x08 /* Private */,
      47,    0,  515,    2, 0x08 /* Private */,
      48,    0,  516,    2, 0x08 /* Private */,
      49,    0,  517,    2, 0x08 /* Private */,
      50,    1,  518,    2, 0x08 /* Private */,
      52,    0,  521,    2, 0x08 /* Private */,
      53,    0,  522,    2, 0x08 /* Private */,
      54,    0,  523,    2, 0x08 /* Private */,
      55,    0,  524,    2, 0x08 /* Private */,
      56,    0,  525,    2, 0x08 /* Private */,
      57,    0,  526,    2, 0x08 /* Private */,
      58,    0,  527,    2, 0x08 /* Private */,
      59,    0,  528,    2, 0x08 /* Private */,
      60,    0,  529,    2, 0x08 /* Private */,
      61,    0,  530,    2, 0x08 /* Private */,
      62,    0,  531,    2, 0x08 /* Private */,
      63,    0,  532,    2, 0x08 /* Private */,
      64,    0,  533,    2, 0x08 /* Private */,
      65,    0,  534,    2, 0x08 /* Private */,
      66,    0,  535,    2, 0x08 /* Private */,
      67,    0,  536,    2, 0x08 /* Private */,
      68,    0,  537,    2, 0x08 /* Private */,
      69,    0,  538,    2, 0x08 /* Private */,
      70,    0,  539,    2, 0x08 /* Private */,
      71,    0,  540,    2, 0x08 /* Private */,
      72,    0,  541,    2, 0x08 /* Private */,
      73,    0,  542,    2, 0x08 /* Private */,
      74,    0,  543,    2, 0x08 /* Private */,
      75,    0,  544,    2, 0x08 /* Private */,
      76,    0,  545,    2, 0x08 /* Private */,
      77,    0,  546,    2, 0x08 /* Private */,
      78,    0,  547,    2, 0x08 /* Private */,
      79,    0,  548,    2, 0x08 /* Private */,
      80,    0,  549,    2, 0x08 /* Private */,
      81,    0,  550,    2, 0x08 /* Private */,
      82,    0,  551,    2, 0x08 /* Private */,
      83,    0,  552,    2, 0x08 /* Private */,
      84,    0,  553,    2, 0x08 /* Private */,
      85,    0,  554,    2, 0x08 /* Private */,
      86,    0,  555,    2, 0x08 /* Private */,
      87,    0,  556,    2, 0x08 /* Private */,
      88,    0,  557,    2, 0x08 /* Private */,
      89,    0,  558,    2, 0x08 /* Private */,
      90,    0,  559,    2, 0x08 /* Private */,
      91,    0,  560,    2, 0x08 /* Private */,
      92,    0,  561,    2, 0x08 /* Private */,
      93,    0,  562,    2, 0x08 /* Private */,
      94,    0,  563,    2, 0x08 /* Private */,
      95,    0,  564,    2, 0x08 /* Private */,
      96,    0,  565,    2, 0x08 /* Private */,
      97,    0,  566,    2, 0x08 /* Private */,
      98,    1,  567,    2, 0x08 /* Private */,
     100,    0,  570,    2, 0x08 /* Private */,
     101,    0,  571,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, 0x80000000 | 29, QMetaType::Int, QMetaType::Int,   30,   31,   32,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   99,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->getCurrentDir();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->looping_bg(); break;
        case 2: _t->slash_sound(); break;
        case 3: _t->dead_sound(); break;
        case 4: _t->initializer(); break;
        case 5: _t->setCor(); break;
        case 6: _t->setInCor(); break;
        case 7: _t->setBoolAll((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setBoolAllBT((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setEneName((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->update_charbt(); break;
        case 11: _t->update_anslbl(); break;
        case 12: _t->update_score(); break;
        case 13: _t->update_health(); break;
        case 14: _t->update_item(); break;
        case 15: _t->update_numEn(); break;
        case 16: _t->blink_enemy(); break;
        case 17: _t->func_blink_enemy(); break;
        case 18: _t->blink_player(); break;
        case 19: _t->func_blink_player(); break;
        case 20: _t->swapEnemy(); break;
        case 21: _t->nextEnemy(); break;
        case 22: _t->resetall(); break;
        case 23: _t->reset_vocab(); break;
        case 24: _t->player_attack_monster((*reinterpret_cast< shared_ptr<Monster>(*)>(_a[1]))); break;
        case 25: _t->player_attack_monster((*reinterpret_cast< shared_ptr<Monster>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 26: _t->monster_attack_player((*reinterpret_cast< Player(*)>(_a[1]))); break;
        case 27: _t->tutoItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->funcCheck((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->move_menu(); break;
        case 30: _t->move_game(); break;
        case 31: _t->move_tuto(); break;
        case 32: _t->move_con(); break;
        case 33: _t->move_highScore(); break;
        case 34: _t->move_shop(); break;
        case 35: _t->check_able_purchase(); break;
        case 36: _t->reset_cart(); break;
        case 37: _t->update_score_shop(); break;
        case 38: _t->check_out(); break;
        case 39: { int _r = _t->check_username((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 40: _t->on_playBT_clicked(); break;
        case 41: _t->on_highscoreBT_clicked(); break;
        case 42: _t->on_tutoriaBT_clicked(); break;
        case 43: _t->on_quitBT_clicked(); break;
        case 44: _t->on_atkbt_clicked(); break;
        case 45: _t->on_clrbt_clicked(); break;
        case 46: _t->on_useMax_clicked(); break;
        case 47: _t->on_usePotion_clicked(); break;
        case 48: _t->on_useMul_clicked(); break;
        case 49: _t->on_chrbt0_clicked(); break;
        case 50: _t->on_chrbt0_2_clicked(); break;
        case 51: _t->on_chrbt0_3_clicked(); break;
        case 52: _t->on_chrbt0_4_clicked(); break;
        case 53: _t->on_chrbt0_5_clicked(); break;
        case 54: _t->on_chrbt0_6_clicked(); break;
        case 55: _t->on_chrbt0_7_clicked(); break;
        case 56: _t->on_chrbt0_8_clicked(); break;
        case 57: _t->on_chrbt0_9_clicked(); break;
        case 58: _t->on_chrbt0_10_clicked(); break;
        case 59: _t->on_chrbt0_11_clicked(); break;
        case 60: _t->on_chrbt0_12_clicked(); break;
        case 61: _t->on_chrbt0_13_clicked(); break;
        case 62: _t->on_chrbt0_14_clicked(); break;
        case 63: _t->on_chrbt0_15_clicked(); break;
        case 64: _t->on_chrbt0_16_clicked(); break;
        case 65: _t->on_chrbt0_17_clicked(); break;
        case 66: _t->on_chrbt0_18_clicked(); break;
        case 67: _t->on_chrbt0_19_clicked(); break;
        case 68: _t->on_chrbt0_20_clicked(); break;
        case 69: _t->on_chrbt0_21_clicked(); break;
        case 70: _t->on_chrbt0_22_clicked(); break;
        case 71: _t->on_chrbt0_23_clicked(); break;
        case 72: _t->on_chrbt0_24_clicked(); break;
        case 73: _t->on_buyPo_clicked(); break;
        case 74: _t->on_buyMul_clicked(); break;
        case 75: _t->on_buyMax_clicked(); break;
        case 76: _t->on_buyArmor_clicked(); break;
        case 77: _t->on_buySpInk_clicked(); break;
        case 78: _t->on_buyUlti_clicked(); break;
        case 79: _t->on_clrbt_shop_clicked(); break;
        case 80: _t->on_finishbt_clicked(); break;
        case 81: _t->on_skipBt_clicked(); break;
        case 82: _t->on_saveBt_clicked(); break;
        case 83: _t->update_score_board(); break;
        case 84: _t->on_backbt_clicked(); break;
        case 85: _t->on_findbt_clicked(); break;
        case 86: _t->on_muteBt_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 87: _t->on_addSoundBT_clicked(); break;
        case 88: _t->on_lowSoundBT_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 89)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 89;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 89)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 89;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
