#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QGraphicsScene>
#include <QObject>
#include <QLayout>
#include "basket.h"
#include "egg.h"

class pauseWin;

class nextWin;

/**
 *\file gamemanager.h
 *\brief class for the Game Manager
 *
 * This class basically takes care of everything that is happening in the game.
 * It creates the randomly falling Eggs according to timer.
 * It updates the score according to fastTimer.
 * It changes levels according to levelTimer.
 */
class gameManager: public QObject
{
        Q_OBJECT
public:
    gameManager();
    gameManager(QGraphicsScene * scene, Basket * basket, QGraphicsTextItem * score);
    ~gameManager();
    QGraphicsScene * scene;
    Basket * basket;                                    ///<basket to use basket member variables/functions
    QTimer * timer;                                     ///<timer to instantiate Eggs (1s)
    QTimer * fastTimer;                                 ///<timer to update the score rapidly (0.2s)
    QTimer * levelTimer;                                ///<timer to next level (60s)
    QGraphicsTextItem * score;                          ///<textItem to display the score
    nextWin * nextWindow;                               ///<nextWin to be opened when levelTimer is timeout
    void pauseGame();

signals:

public slots:
    void update();
    void newLevel();
    void updateScore();
};

#endif // GAMEMANAGER_H
