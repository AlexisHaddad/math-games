#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "gamemanager5.h"
#include "sbox.h"
#include "mainmenu.h"

/**
 *\brief instaniates all the initial items needed for the game
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(scene);

    sbox *frame = new sbox();
    frame->setRect(0,0,0,0);
    frame->setPos(75,495);
    scene->addItem(frame);
    frame->setFlag(QGraphicsItem::ItemIsFocusable);
    frame->setFocus();

    view->setFixedSize(600,600);
    view->show();


    gamemanager5 *game = new gamemanager5(scene,frame, 1, 0, 0);
    mainmenu Menu1(game, view);


    return a.exec();

}

