#ifndef GAMEMANAGER3_H
#define GAMEMANAGER3_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QLayout>
#include <QObject>
#include <QTimer>
#include "sframe.h"

/**
 *\file gamemanager3.h
 *\brief class for the Game Manager
 *
 * This class basically takes care of everything that is happening in the game.
 * It makes the square move according to the answers.
 * It shows the elapsed time according to the gameTimer along with the score.
 */

class sframe;
class mainmenu;
class nextwindow;
class restartwindow;

class gamemanager3 : public QObject
{
    Q_OBJECT
public:
    explicit gamemanager3(QObject *parent = 0);
    gamemanager3();
    gamemanager3(QGraphicsScene *scene, int level, int score, int operation);

    QGraphicsTextItem * inputTextItem;      ///TextItem to show the input number
    QString temp;                           ///<string in which the input number is stored
    QGraphicsScene *scene;                  ///<the game scene
    QPixmap imagebackground;                ///<background image
    QGraphicsPixmapItem *itembackground;    ///<item for background image
    QPixmap imageframe;                     ///<square frame image
    QGraphicsPixmapItem *itemframe;         ///<item for square frame

    nextwindow *nextWindow1;                ///<nextwindow that shows up after winning a level
    restartwindow *restartWindow1;          ///<restartwindow that shows up after losing a level

    QTimer *gameTimer;                      ///<timer for the game

    int inputNumber;                        ///<int number input by user

    int nextNumber;                         ///<int should be the next answer

    int operation;                          ///<int determines if it's addition or multiplication
    
    int *branch1;                           ///<int array to store answers of branch 1
    int *branch2;                           ///<int array to store answers of branch 2
    int *branch3;                           ///<int array to store answers of branch 3
    int *branch4;                           ///<int array to store answers of branch 4
    int stage;                              ///<int shows which stage the user's in
    int step1;                              ///<int shows which step is the user in branch 1
    int step2;                              ///<int shows which step is the user in branch 2
    int step3;                              ///<int shows which step is the user in branch 3
    int step4;                              ///<int shows which step is the user in branch 4
    int level;                              ///<int shows which level we're at
    int timer;                              ///<int timer
    int score;                              ///<int score
    int second;                             ///<int to check the time
    QGraphicsTextItem *clock;               ///<textitem for the timer
    QGraphicsTextItem *scoreItem;           ///<textitem for the score
    QGraphicsTextItem *inputLabel;          ///<textitem for the input number
    QGraphicsTextItem *numberArray1;        ///<textitem array to show the numbers of branch 1
    QGraphicsTextItem *numberArray2;        ///<textitem array to show the numbers of branch 2
    QGraphicsTextItem *numberArray3;        ///<textitem array to show the numbers of branch 3
    QGraphicsTextItem *numberArray4;        ///<textitem array to show the numbers of branch 4

    void showNumbers();                     ///<function to show the numbers in the array
    void fillArray(int);                    ///<function to fill the number arrays

signals:
    
public slots:
    void updateTimer();
    
};

#endif // GAMEMANAGER3_H
