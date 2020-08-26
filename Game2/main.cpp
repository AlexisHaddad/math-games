#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "mario.h"
#include "gamemanager2.h"

/**
 *\brief instaniates all the initial items needed for the game
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(scene);


    Mario *mario = new Mario();


    gameManager2 game(scene,mario,3,0);

    mario->setRect(0,0,5,5);
    mario->setPos(10,280);
    mario->setFlag(QGraphicsItem::ItemIsFocusable);
    mario->setFocus();
    scene->addItem(mario);

    view->setFixedSize(505,370);
    view->show();
    return a.exec();

}
