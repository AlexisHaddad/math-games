#ifndef NEXTWINDOW_H
#define NEXTWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QGraphicsScene>
#include "gamemanager5.h"

class gamemanager5;
class sbox;

class nextwindow : public QWidget
{
    Q_OBJECT
public:
    explicit nextwindow(QWidget *parent = 0);
    nextwindow(gamemanager5 *, sbox*);
    gamemanager5 * game;                     ///<gameManager class that we will use and edit
    sbox *frame;
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
