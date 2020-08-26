#ifndef EGG_H
#define EGG_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include "basket.h"

/**
 *\file egg.h
 *\brief class for the Egg
 *
 * This class creates an ellipseItem on which there is an image (egg.png).
 * They are created in the gameManager class and they fall down
 * at random speeds from random x positions from top to bottom of the view.
 * They contain randomly generated numbers between 0 and 99.
 */

class Egg : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Egg();
    Egg(Basket * basket);
    ~Egg();
    QTimer * timer;                         ///<timer to make the Egg move (0.05s)
    Basket * basket;                        ///<basket to use its member variables/functions
    QGraphicsTextItem * numText;            ///<textItem to display the number
    QGraphicsPixmapItem * eggImage;         ///<image of the egg
    int num;                                ///<integer that has the random number
    int speed;                              ///<integer that determines the falling speed of the Egg
    
signals:
    
public slots:
    void update();
};

#endif // EGG_H
