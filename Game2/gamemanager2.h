#ifndef GAMEMANAGER2_H
#define GAMEMANAGER2_H

#include <QGraphicsScene>
#include <QLayout>
#include <QObject>
#include <QTimer>
#include "mario.h"

class nextWin;

/**
 *\file gamemanager2.h
 *\brief class for the Game Manager
 *
 * This class basically takes care of everything that is happening in the game.
 * It makes mario move according to the marioTimer.
 * It shows the elapsed time according to the gameTimer.
 */

class gameManager2 : public QObject
{
    Q_OBJECT
public:
    gameManager2();
    gameManager2(QGraphicsScene *scene, Mario *mario, int numStairs, int gameScore);
    ~gameManager2();
    QGraphicsScene *scene;
    QPixmap image1;
    QGraphicsPixmapItem *item;
    QPixmap imagec1;
    QGraphicsPixmapItem *itemc1;
    QPixmap imagec2;
    QGraphicsPixmapItem *itemc2;
    Mario *mario;
    QGraphicsTextItem *score;
    QGraphicsTextItem *clock;
    QTimer *marioTimer;                 ///<timer to make mario move (0.01s)
    QTimer *gameTimer;                  ///<timer to display the elapsed time (0.1s)
    int step;                           ///<integer to keep track of what step mario is on
    int second;                         ///<integer to count the elapsed time
    int counter;
    int coin1X;
    int coin2X;
    int coin2Y;
    int gameScore;                      ///<integer to keep track of the score
    double result;                      ///<double to calculate the result of the value entered
    bool moving;                        ///<boolean that determines if mario is moving or not
    int numStairs;                      ///<integer that determines the number of stairs in the level
    double *numArray;                   ///<array of double values of the numerators randomly generated
    double *denomArray;                 ///<array of double values of the denominators randomly generated
    QGraphicsTextItem *fracArray;       ///<textItem to display the player input
    nextWin * nextWindow;               ///<nextWindow to be openned when level is done

    
signals:
    
public slots:
    void marioMove();
};

#endif // GAMEMANAGER2_H
