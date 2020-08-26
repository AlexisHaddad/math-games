#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "gamemanager3.h"
#include "sframe.h"
#include "mainmenu.h"

/**
 *\brief instaniates all the initial items needed for the game
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(scene);


    gamemanager3 *game = new gamemanager3(scene, 1, 0, 0);
    mainmenu Menu1(game);

    sframe *frame = new sframe(game);

    frame->setRect(0,0,0,0);
    frame->setPos(75,495);
    scene->addItem(frame);
    frame->setFlag(QGraphicsItem::ItemIsFocusable);
    frame->setFocus();

    view->setFixedSize(503,567);
    view->show();
    return a.exec();

}
