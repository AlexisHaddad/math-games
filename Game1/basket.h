#ifndef BASKET_H
#define BASKET_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

/**
 *\file basket.h
 *\brief class for the Basket
 *
 * This basket is a rectItem on which there is a image (basket.png).
 * It is moved left and right with the right/left or A/D buttons.
 * With it the player has to catch eggs that are either even or odd
 * depending on what he decides.
 *\author Ali Naji, Alexis Haddad
 */

class Basket: public QGraphicsRectItem
{
public:
    Basket();
    ~Basket();
    int score;                                  ///<integer that stores the score of the player
    int parameter;                              ///<integer that is incremented with each level
    bool pause;                                 ///<boolean that is used to pause the game
    bool even;                                  ///<boolean that is set when the player chooses even/odd
    QGraphicsPixmapItem * basketImage;          ///<image of the basket
    void keyPressEvent(QKeyEvent * event);
};

#endif // BASKET_H
