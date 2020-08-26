#ifndef GAMEMANAGER4_H
#define GAMEMANAGER4_H

#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

class nextWin;

/**
 *\file gamemanager4.h
 *\brief class for the Game Manager
 *
 * This class basically takes care of everything that is happening in the game.
 * It makes the levels go off every 2min by dispaying the nextWin
 */

class gamemanager4 : public QObject
{
    Q_OBJECT
public:
    gamemanager4();
    gamemanager4(QGraphicsScene * scene);
    ~gamemanager4();
    QGraphicsScene * scene;
    QPixmap image1;
    QGraphicsPixmapItem *item;
    QTimer * levelTimer;                ///<timer for next level
    nextWin * window;
    int level;                          ///<integer to change level difficulty (incremented each level)
    bool answer;

signals:

public slots:
    void nextLevel();
};

#endif // GAMEMANAGER4_H
