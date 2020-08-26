#ifndef COMMANDWIN_H
#define COMMANDWIN_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include "gamemanager.h"

/**
 *\file gamemanager.h
 *\brief class for the Command Window
 *
 * This window is shown at the beginning of the game.
 * The player can choose there whether to catch even or odd eggs.
 */

class commandWin : public QWidget
{
    Q_OBJECT
public:
    commandWin();
    commandWin(gameManager * game);
    ~commandWin();
    QLabel * choose;
    QPushButton * even;                 ///<button "Even"
    QPushButton * odd;                  ///<button "Odd"
    QVBoxLayout * vBox;
    gameManager * game;                 ///<gameManager class that it will use and edit

signals:

public slots:
    void chooseEven();
    void chooseOdd();
};

#endif // COMMANDWIN_H
