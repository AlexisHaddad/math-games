#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "basket.h"
#include "egg.h"
#include "stdlib.h"
#include "gamemanager.h"
#include "commandwin.h"

/**
 *\brief instaniates all the initial items needed for the game
 */

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    
    QPixmap image1("/home/alexis/Documents/Qt_Projects/Game1/sky.jpg");
    QGraphicsPixmapItem * background;
    background = new QGraphicsPixmapItem(image1.scaled(QSize(700,700)));
    background->setPos(-25,-25);
    scene->addItem(background);
    
    QPixmap image2("/home/alexis/Documents/Qt_Projects/Game1/grass.png");
    QGraphicsPixmapItem * grass;
    grass = new QGraphicsPixmapItem(image2.scaled(QSize(550,700), Qt::KeepAspectRatio));
    grass->setPos(-40,525);
    scene->addItem(grass);
    
    Basket * rect = new Basket();
    rect->setRect(0,0,80,80);
    rect->setPos(250 - 50, 600 - 100);
    rect->setFlag(QGraphicsItem :: ItemIsFocusable);
    rect->setFocus();
    rect->basketImage->setPos(rect->x() - 60, rect->y() - 35);


    QGraphicsTextItem * scoreText;
    scoreText = new QGraphicsTextItem("Score: " + QString::number(rect->score));
    scene->addItem(scoreText);

    gameManager * gameM = new gameManager(scene,rect,scoreText);

    commandWin commandWindow(gameM);

    scene->addItem(rect);
    scene->addItem(rect->basketImage);
    scene->setSceneRect(0,0,500,600);


    QGraphicsView * view = new QGraphicsView(scene);

    view->setFixedSize(510,610);

    view->show();

    return app.exec();
}

