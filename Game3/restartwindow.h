#ifndef RESTARTWINDOW_H
#define RESTARTWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QGraphicsScene>
#include "gamemanager3.h"

class gamemanager3;
class sframe;

class restartwindow : public QWidget
{
    Q_OBJECT
public:
    explicit restartwindow(QWidget *parent = 0);
    restartwindow(gamemanager3 *, sframe*);
    gamemanager3 * game;                     ///<gameManager class that we will use and edit
    sframe *frame;
    int score;
    int level;
    int operation;
    QGraphicsScene *scene;
    QLabel * scoreLabel;
    QLabel * sug;
    QPushButton * restartLev;               ///<button "Restart Level"
    QGridLayout * gridBox;
    
signals:
    
public slots:
    void restartLevel();
    
};

#endif // RESTARTWINDOW_H
