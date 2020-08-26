#include "gamemanager4.h"
#include "nextwin.h"


/**
 *\file gamemanager4.cpp
 *\brief source file for gamamanger4.h
 */

/**
 *\brief default constructor
 */
gamemanager4::gamemanager4()
{
    scene = new QGraphicsScene();
    answer = 1;
    level = 1;
    levelTimer = new QTimer(this);
}


/**
 *\brief constructor of the gamemanager4 class
 *
 * This constructor sets the intial values of the game that are handled
 * aterwards by keyPressEvent.
 * The connect statement is for the timer (2s)
 *\param scene
 */
gamemanager4::gamemanager4(QGraphicsScene *scene)
{
    this->scene = scene;
    answer = 1;
    level = 1;
    levelTimer = new QTimer(this);

    connect(levelTimer, SIGNAL(timeout()), this, SLOT(nextLevel()));
    levelTimer->start(1200000);
}

gamemanager4::~gamemanager4()
{

}

/**
 *\brief slot function
 *
 * It opens the next level window on the timer timeout
 */
void gamemanager4::nextLevel()
{
    window = new nextWin(this);
    window->show();
}
