#ifndef NEXTWIN_H
#define NEXTWIN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include "square.h"

class gamemanager4;

/**
 *\file nextwin.h
 *\brief class for the Next Level Window
 *
 * This is a widget that opens after stage 3 is done.
 * It consists of labels and buttons and the player can choose
 * to restart the level or play the next level if his score is greather
 * than the number of stairs in the level.
 * The next level is exactly the same thing but with one more stair.
 * He also has the choice to quit the game.
 */
class nextWin : public QWidget
{
    Q_OBJECT
public:
    nextWin();
    nextWin(gamemanager4 *);
    ~nextWin();
    gamemanager4 * game;                        ///<gameManager4 class that we will use and edit
    QLabel * sug;
    QPushButton * nextLev;                      ///<button "Next Level"
    QPushButton * restartLev;                   ///<button "Restart Level"
    QPushButton * quitBut;                      ///<button "Quit"
    QGridLayout * gridBox;

signals:

public slots:
    void nextLevel();
    void restartLevel();
    void quit();
};

#endif // NEXTWIN_H
