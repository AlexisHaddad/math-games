#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QKeyEvent>

class Line;

class gamemanager4;

/**
 *\file square.h
 *\brief class for the Squares
 *
 * These are the squares that appear in the scene.
 * They have an integer and a Qstring as memeber variables
 * since this is what we need from them to build equations
 */

class Square : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Square();
    Square(gamemanager4*,int,QString);
    ~Square();
    QPixmap image1;
    QGraphicsPixmapItem *item;
    gamemanager4 * game;
    QGraphicsTextItem * display;
    int number;
    QString character;

    void keyPressEvent(QKeyEvent * event);

signals:

public slots:
};

#endif // SQUARE_H
