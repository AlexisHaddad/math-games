#ifndef GAMEMANAGER5_H
#define GAMEMANAGER5_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QLayout>
#include <QObject>
#include <QTimer>
#include "sbox.h"

/**
 *\file gamemanager3.h
 *\brief class for the Game Manager
 *
 * This class basically takes care of everything that is happening in the game.
 * It makes the square move according to the answers.
 * It shows the elapsed time according to the gameTimer along with the score.
 */

class sbox;
class mainmenu;
class nextwindow;
class restartwindow;

class gamemanager5 : public QObject
{
    Q_OBJECT
public:
    explicit gamemanager5(QObject *parent = 0);
    gamemanager5();
    gamemanager5(QGraphicsScene *scene, sbox* box, int level, int score, int character);

    sbox* box;
    QGraphicsTextItem * inputTextItem;      ///TextItem to show the input number
    QString temp;                           ///<string in which the input number is stored
    QGraphicsScene *scene;                  ///<the game scene
    QPixmap imagebackground;                ///<background image
    QGraphicsPixmapItem *itembackground;    ///<item for background image
    QPixmap imageframe;                     ///<square frame image
    QGraphicsPixmapItem *itemframe;         ///<item for square frame
    QPixmap imagedoors;                     ///<square frame image
    QGraphicsPixmapItem *itemdoors;         ///<item for square frame
    QGraphicsTextItem *itemoption1;
    QGraphicsTextItem *itemoption2;
    QGraphicsTextItem *question;

    nextwindow *nextWindow1;                ///<nextwindow that shows up after winning a level
    restartwindow *restartWindow1;          ///<restartwindow that shows up after losing a level

    QString state;
    QTimer *gameTimer;                      ///<timer for the game

    int number1;
    int number2;
    int option1;
    int option2;
    int luck;
    int counter;

    int character;                          ///<int determines if it's addition or multiplication

    int level;                              ///<int shows which level we're at
    int timer;                              ///<int timer
    int score;                              ///<int score
    int second;                             ///<int to check the time
    QGraphicsTextItem *clock;               ///<textitem for the timer
    QGraphicsTextItem *scoreItem;           ///<textitem for the score

    void showNumbers();
    void showpic(int);


signals:

public slots:
    void updateTimer();

};

#endif // GAMEMANAGER5_H
