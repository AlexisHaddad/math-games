#ifndef PAUSEWIN_H
#define PAUSEWIN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include "commandwin.h"

class gameManager;

/**
 *\file pausewin.h
 *\brief class for the Pause Window
 *
 * This is a widget that opens when the Escape button is pressed.
 * It contains three buttons that let the user resume, restart or quit the game.
 */
class pauseWin : public QWidget
{
    Q_OBJECT
public:
    pauseWin();
    pauseWin(gameManager * game);
    ~pauseWin();
    QLabel * title;
    QPushButton * resume;                   ///<button "Resume"
    QPushButton * restart;                  ///<button "Restart"
    QPushButton * quit;                     ///<button "Quit"
    QVBoxLayout * vBox;
    gameManager * game;                     ///<gameManager class to use and edit it

signals:

public slots:
    void resumeGame();
    void restartGame();
    void quitGame();
};

#endif // PAUSEWIN_H
