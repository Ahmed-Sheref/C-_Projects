/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *player_1_wins;
    QLabel *Tie_Times;
    QLabel *player_2_wins;
    QLabel *label_8;
    QPushButton *Button_player;
    QPushButton *Button_multi;
    QLabel *label_9;
    QLabel *Game_mode;
    QLabel *label_3;
    QPushButton *Reset_score;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1338, 600);
        QFont font;
        font.setWeight(QFont::Thin);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #000000;  /* Black background for the entire window */\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(910, 150, 100, 100));
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font-family: 'Comic Sans MS';\n"
"    background-color: #000000; /* Black background */\n"
"    border: 2px solid #FFFFFF; /* White border */\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: #FF7F00; /* Default color for X */\n"
"    text-align: center;\n"
"    padding: 0;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #000000; /* Darker gray when pressed */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #000000; /* Darker background for disabled buttons */\n"
"}\n"
"\n"
"QPushButton#O {\n"
"    color: #FF7F00; /* Orange color for O */\n"
"}e5"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(810, 250, 100, 100));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font-family: 'Comic Sans MS';\n"
"    background-color: #000000; /* Black background */\n"
"    border: 2px solid #FFFFFF; /* White border */\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: #FF7F00; /* Default color for X */\n"
"    text-align: center;\n"
"    padding: 0;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #000000; /* Darker gray when pressed */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #000000; /* Darker background for disabled buttons */\n"
"}\n"
"\n"
"QPushButton#O {\n"
"    color: #FF7F00; /* Orange color for O */\n"
"}e5"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(910, 250, 100, 100));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font-family: 'Comic Sans MS';\n"
"    background-color: #000000; /* Black background */\n"
"    border: 2px solid #FFFFFF; /* White border */\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: #FF7F00; /* Default color for X */\n"
"    text-align: center;\n"
"    padding: 0;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #000000; /* Darker gray when pressed */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #000000; /* Darker background for disabled buttons */\n"
"}\n"
"\n"
"QPushButton#O {\n"
"    color: #FF7F00; /* Orange color for O */\n"
"}e5"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(1110, 350, 100, 100));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font-family: 'Comic Sans MS';\n"
"    background-color: #000000; /* Black background */\n"
"    border: 2px solid #FFFFFF; /* White border */\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: #FF7F00; /* Default color for X */\n"
"    text-align: center;\n"
"    padding: 0;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #000000; /* Darker gray when pressed */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #000000; /* Darker background for disabled buttons */\n"
"}\n"
"\n"
"QPushButton#O {\n"
"    color: #FF7F00; /* Orange color for O */\n"
"}e5"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(710, 350, 100, 100));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font-family: 'Comic Sans MS';\n"
"    background-color: #000000; /* Black background */\n"
"    border: 2px solid #FFFFFF; /* White border */\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: #FF7F00; /* Default color for X */\n"
"    text-align: center;\n"
"    padding: 0;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #000000; /* Darker gray when pressed */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #000000; /* Darker background for disabled buttons */\n"
"}\n"
"\n"
"QPushButton#O {\n"
"    color: #FF7F00; /* Orange color for O */\n"
"}e5"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(1010, 250, 100, 100));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font-family: 'Comic Sans MS';\n"
"    background-color: #000000; /* Black background */\n"
"    border: 2px solid #FFFFFF; /* White border */\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: #FF7F00; /* Default color for X */\n"
"    text-align: center;\n"
"    padding: 0;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #000000; /* Darker gray when pressed */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #000000; /* Darker background for disabled buttons */\n"
"}\n"
"\n"
"QPushButton#O {\n"
"    color: #FF7F00; /* Orange color for O */\n"
"}e5"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(910, 350, 100, 100));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font-family: 'Comic Sans MS';\n"
"    background-color: #000000; /* Black background */\n"
"    border: 2px solid #FFFFFF; /* White border */\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: #FF7F00; /* Default color for X */\n"
"    text-align: center;\n"
"    padding: 0;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #000000; /* Darker gray when pressed */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #000000; /* Darker background for disabled buttons */\n"
"}\n"
"\n"
"QPushButton#O {\n"
"    color: #FF7F00; /* Orange color for O */\n"
"}e5"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(1010, 350, 100, 100));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font-family: 'Comic Sans MS';\n"
"    background-color: #000000; /* Black background */\n"
"    border: 2px solid #FFFFFF; /* White border */\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: #FF7F00; /* Default color for X */\n"
"    text-align: center;\n"
"    padding: 0;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #000000; /* Darker gray when pressed */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #000000; /* Darker background for disabled buttons */\n"
"}\n"
"\n"
"QPushButton#O {\n"
"    color: #FF7F00; /* Orange color for O */\n"
"}e5"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(810, 350, 100, 100));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font-family: 'Comic Sans MS';\n"
"    background-color: #000000; /* Black background */\n"
"    border: 2px solid #FFFFFF; /* White border */\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: #FF7F00; /* Default color for X */\n"
"    text-align: center;\n"
"    padding: 0;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #000000; /* Darker gray when pressed */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #000000; /* Darker background for disabled buttons */\n"
"}\n"
"\n"
"QPushButton#O {\n"
"    color: #FF7F00; /* Orange color for O */\n"
"}e5"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 50, 531, 111));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font1.setPointSize(35);
        font1.setItalic(false);
        font1.setStrikeOut(false);
        label->setFont(font1);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-family: 'Comic Sans MS';\n"
"    color: white;\n"
"    background-color: transparent;\n"
"}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(410, 310, 291, 51));
        QFont font2;
        font2.setPointSize(20);
        font2.setWeight(QFont::Thin);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("    font-weight: 100; /* Thin font weight */\n"
"  color:white;     /* Set text color */\n"
"    background-color: transparent; /* Transparent background */"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 310, 61, 51));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("    font-weight: 100; /* Thin font weight */\n"
"  color:white;     /* Set text color */\n"
"    background-color: transparent; /* Transparent background */"));
        player_1_wins = new QLabel(centralwidget);
        player_1_wins->setObjectName("player_1_wins");
        player_1_wins->setGeometry(QRect(100, 380, 91, 41));
        player_1_wins->setFont(font2);
        player_1_wins->setStyleSheet(QString::fromUtf8("    font-weight: 100; /* Thin font weight */\n"
"  color:white;     /* Set text color */\n"
"    background-color: transparent; /* Transparent background */"));
        Tie_Times = new QLabel(centralwidget);
        Tie_Times->setObjectName("Tie_Times");
        Tie_Times->setGeometry(QRect(290, 380, 91, 41));
        Tie_Times->setFont(font2);
        Tie_Times->setStyleSheet(QString::fromUtf8("    font-weight: 100; /* Thin font weight */\n"
"  color:white;     /* Set text color */\n"
"    background-color: transparent; /* Transparent background */"));
        player_2_wins = new QLabel(centralwidget);
        player_2_wins->setObjectName("player_2_wins");
        player_2_wins->setGeometry(QRect(460, 380, 91, 41));
        player_2_wins->setFont(font2);
        player_2_wins->setStyleSheet(QString::fromUtf8("    font-weight: 100; /* Thin font weight */\n"
"  color:white;     /* Set text color */\n"
"    background-color: transparent; /* Transparent background */"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 310, 211, 51));
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("    font-weight: 100; /* Thin font weight */\n"
"  color:white;     /* Set text color */\n"
"    background-color: transparent; /* Transparent background */"));
        Button_player = new QPushButton(centralwidget);
        Button_player->setObjectName("Button_player");
        Button_player->setGeometry(QRect(50, 520, 101, 51));
        QFont font3;
        Button_player->setFont(font3);
        Button_player->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"        background-color: transparent;\n"
"        color: white;\n"
"        border: 2px solid white;\n"
"        font-size: 20px;\n"
"        padding: 10px;\n"
"    }\n"
"\n"
"    QPushButton:hover {\n"
"        background-color: rgba(255, 255, 255, 0.2);  /* Light hover effect */\n"
"        border-color: rgba(255, 255, 255, 0.5);  /* Slightly lighter border on hover */\n"
"    }\n"
"\n"
"    QPushButton:pressed {\n"
"        background-color: rgba(255, 255, 255, 0.4);  /* Darker background on click */\n"
"        border-color: rgba(255, 255, 255, 0.7);  /* Lighter border on click */\n"
"    }\n"
"\n"
"    QPushButton:focus {\n"
"        outline: none;  /* Remove focus outline */\n"
"    }"));
        Button_multi = new QPushButton(centralwidget);
        Button_multi->setObjectName("Button_multi");
        Button_multi->setGeometry(QRect(200, 520, 111, 51));
        Button_multi->setFont(font3);
        Button_multi->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"        background-color: transparent;\n"
"        color: white;\n"
"        border: 2px solid white;\n"
"        font-size: 20px;\n"
"        padding: 10px;\n"
"    }\n"
"\n"
"    QPushButton:hover {\n"
"        background-color: rgba(255, 255, 255, 0.2);  /* Light hover effect */\n"
"        border-color: rgba(255, 255, 255, 0.5);  /* Slightly lighter border on hover */\n"
"    }\n"
"\n"
"    QPushButton:pressed {\n"
"        background-color: rgba(255, 255, 255, 0.4);  /* Darker background on click */\n"
"        border-color: rgba(255, 255, 255, 0.7);  /* Lighter border on click */\n"
"    }\n"
"\n"
"    QPushButton:focus {\n"
"        outline: none;  /* Remove focus outline */\n"
"    }"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(1000, 530, 211, 51));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("    font-weight: 100; /* Thin font weight */\n"
"  color:white;     /* Set text color */\n"
"    background-color: transparent; /* Transparent background */"));
        Game_mode = new QLabel(centralwidget);
        Game_mode->setObjectName("Game_mode");
        Game_mode->setGeometry(QRect(1170, 530, 211, 51));
        Game_mode->setFont(font2);
        Game_mode->setStyleSheet(QString::fromUtf8("    font-weight: 100; /* Thin font weight */\n"
"  color:white;     /* Set text color */\n"
"    background-color: transparent; /* Transparent background */"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1230, 60, 49, 16));
        Reset_score = new QPushButton(centralwidget);
        Reset_score->setObjectName("Reset_score");
        Reset_score->setGeometry(QRect(1180, 30, 141, 51));
        Reset_score->setFont(font3);
        Reset_score->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"        background-color: transparent;\n"
"        color: white;\n"
"        border: 2px solid white;\n"
"        font-size: 20px;\n"
"        padding: 10px;\n"
"    }\n"
"\n"
"    QPushButton:hover {\n"
"        background-color: rgba(255, 255, 255, 0.2);  /* Light hover effect */\n"
"        border-color: rgba(255, 255, 255, 0.5);  /* Slightly lighter border on hover */\n"
"    }\n"
"\n"
"    QPushButton:pressed {\n"
"        background-color: rgba(255, 255, 255, 0.4);  /* Darker background on click */\n"
"        border-color: rgba(255, 255, 255, 0.7);  /* Lighter border on click */\n"
"    }\n"
"\n"
"    QPushButton:focus {\n"
"        outline: none;  /* Remove focus outline */\n"
"    }"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_1->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_9->setText(QString());
        pushButton_5->setText(QString());
        pushButton_4->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_6->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Pyramid Tic - Tac - Toe ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Player 2 (O) ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TIE", nullptr));
        player_1_wins->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Tie_Times->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        player_2_wins->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Player 1 (X) ", nullptr));
        Button_player->setText(QCoreApplication::translate("MainWindow", "1P  \360\237\221\244", nullptr));
        Button_multi->setText(QCoreApplication::translate("MainWindow", "2P  \360\237\221\245", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Game Mode : ", nullptr));
        Game_mode->setText(QCoreApplication::translate("MainWindow", "Multiplayer", nullptr));
        label_3->setText(QString());
        Reset_score->setText(QCoreApplication::translate("MainWindow", "Reset Score", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
