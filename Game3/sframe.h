#ifndef SFRAME_H
#define SFRAME_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QLayout>
#include <QGraphicsRectItem>

/**
 *\file sframe.h
 *\brief class for the sframe
 *
 * This sframe is a rectItem.
 * It is moved up,right or down with the correct/wrong answer or pressing the right arrow.
 * With it the player has to reach a castle
 * by answering correctly.
 *\author Ali Naji, Alexis Haddad
 */

class gamemanager3;
class nextwindow;
class restartwindow;

class sframe : public QGraphicsRectItem
{
public:
    sframe(gamemanager3*);
    gamemanager3 *game;     ///<gamemanager3 to get all the game information

    void keyPressEvent(QKeyEvent *event);

};

#endif // SFRAME_H
