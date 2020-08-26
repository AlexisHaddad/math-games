#ifndef NEXTWIN_H
#define NEXTWIN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include "basket.h"

class gameManager;

/**
 *\file nextwin.h
 *\brief class for the Next Level Window
 *
 * This is a widget that opens after levelTimer is timeout (60s)
 * It consists of labels and buttons and the player can choose
 * to restart the level or play the next level if his score is positive.
 * The next level consists of faster created and falling eggs and the basket
 * moves fast according to the integer "parameter" in the basket.
 * He also has the choice to quit the game.
 */
class nextWin : public QWidget
{
    Q_OBJECT
public:
    nextWin();
    nextWin(Basket *, gameManager *);
    ~nextWin();
    gameManager * game;                     ///<gameManager class that we will use and edit
    Basket * basket;                        ///<basket to use its member variables/functions
    QLabel * score;
    QLabel * sug;
    QPushButton * nextLev;                  ///<button "Next Level"
    QPushButton * restartLev;               ///<button "Restart Level"
    QPushButton * quitBut;                  ///<button "Quit"
    QGridLayout * gridBox;

signals:

public slots:
    void nextLevel();
    void restartLevel();
    void quit();
};

#endif // NEXTWIN_H
