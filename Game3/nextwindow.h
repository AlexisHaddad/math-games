#ifndef NEXTWINDOW_H
#define NEXTWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QGraphicsScene>
#include "gamemanager3.h"

class gamemanager3;
class sframe;

class nextwindow : public QWidget
{
    Q_OBJECT
public:
    explicit nextwindow(QWidget *parent = 0);
    nextwindow(gamemanager3 *, sframe*);
    gamemanager3 * game;                     ///<gameManager class that we will use and edit
    sframe *frame;
    int score;
    int level;
    int operation;
    QGraphicsScene *scene;
    QLabel * scoreLabel;
    QLabel * sug;
    QPushButton * nextLev;                  ///<button "Next Level"
    QPushButton * restartLev;               ///<button "Restart Level"
    QGridLayout * gridBox;
    
signals:
    
public slots:
    void nextLevel();
    void restartLevel();
    
};

#endif // NEXTWINDOW_H
