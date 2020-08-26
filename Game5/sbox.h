#ifndef SBOX_H
#define SBOX_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QLayout>
#include <QGraphicsRectItem>

class gamemanager5;

class sbox : public QGraphicsRectItem
{
public:
    sbox();
    //gamemanager5 *game;     ///<gamemanager5 to get all the game information
    int move;


    void keyPressEvent(QKeyEvent *event);
};

#endif // SBOX_H
