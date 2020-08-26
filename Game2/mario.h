#ifndef MARIO_H
#define MARIO_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

/**
 *\file mario.h
 *\brief class for the Mario
 */

class Mario : public QGraphicsRectItem
{
public:
    Mario();
    ~Mario();
    QGraphicsPixmapItem *marioImage;        ///<image of mario
    QGraphicsTextItem *fraction;            ///<textItem to display the user's input
    int stage;                              ///<integer to store which stage the player is on
    int score;                              ///<integer to score the score
    double numerator;                       ///<double to store the input numerator
    double denominator;                     ///<double to store the input denominator
    double answer;                          ///<double to compute numerator/denominator
    int jump;                               ///<integer to store how much mario has to jump
    QString temp;                           ///<string to store the player's input
    bool flag;                              ///<boolean to check if the player is inputting the numerator or the denominator
    bool move;                              ///<boolean to check if mario is moving
    int done;

    void keyPressEvent(QKeyEvent *event);
};

#endif // MARIO_H
