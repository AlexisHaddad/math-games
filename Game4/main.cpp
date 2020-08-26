#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "square.h"
#include "gamemanager4.h"


/**
 *\brief instaniates all the initial items needed for the game
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(scene);

    QPixmap imagebackground;
    imagebackground.load("/home/EECE435/Game4/background.jpg");
    QGraphicsPixmapItem *itembackground;
    itembackground = new QGraphicsPixmapItem(imagebackground.scaled(QSize(700,700),  Qt::KeepAspectRatio));
    scene->addItem(itembackground);

    gamemanager4 * game = new gamemanager4(scene);

    Square * box = new Square(game,rand()%10 + 1,"");

    box->setRect(0,0,55,55);
    box->setPos((rand()%13 + 1)*50,(rand()%13 + 1)*50);
    box->setFlag(QGraphicsItem :: ItemIsFocusable);
    box->setFocus();
    box->display->setPos(box->x()+17,box->y()+17);
    box->item->setPos(box->pos());
    scene->addItem(box->item);

    scene->addItem(box);
    scene->addItem(box->display);
    scene->setSceneRect(0,0,700,700);
    view->setFixedSize(710,710);
    view->show();
    return a.exec();
}
