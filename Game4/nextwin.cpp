#include "nextwin.h"
#include "gamemanager4.h"

/**
 *\file nextwin.cpp
 *\brief source file for nextwin.h
 */

/**
 *\brief default constructor
 */
nextWin::nextWin()
{

}

/**
 *\brief constructor of the nextWin class
 *
 * This is where everything is instantiated.
 * The buttons and labels are added to the grid layout.
 * The "sug" label takes differen texts with respect to the score.
 *
 *\param mario
 *\param game
 */
nextWin::nextWin(gamemanager4 * game)
{
    this->game = game;
    this->game->levelTimer->stop();
    sug = new QLabel("Choose to play next level or to restart level");
    nextLev = new QPushButton("Next Level");
    restartLev = new QPushButton("Restart Level");
    quitBut = new QPushButton("Quit");

    gridBox = new QGridLayout;

    gridBox->addWidget(sug,1,2,2,2);
    gridBox->addWidget(nextLev,3,0,1,2);
    gridBox->addWidget(restartLev,3,2,1,2);
    gridBox->addWidget(quitBut,3,4,1,2);

    setLayout(gridBox);

    connect(nextLev,SIGNAL(clicked()),this,SLOT(nextLevel()));          ///<nextLevel function when nextLev is clicked
    connect(restartLev,SIGNAL(clicked()),this,SLOT(restartLevel()));    ///<restartLevel function when restartLev is clicked
    connect(quitBut,SIGNAL(clicked()),this,SLOT(quit()));               ///<quit function when quitBut is clicked

}

/**
 *\brief destructor of the nextWin class
 */
nextWin::~nextWin()
{

}

/**
 *\brief slot function
 *
 * If the player chooses to play the next level,
 * everything is removed from the scene and a new gameManager2
 * class is created with values passed from the previous level
 * incremented accordingly.
 */
void nextWin::nextLevel()
{
    game->scene->clear();
    game->level++;
    game->levelTimer->start(120000);
    Square * box = new Square(game,rand()%(10 + game->level*5),"");
    box->setFlag(QGraphicsItem::ItemIsFocusable);
    box->setRect(0,0,50,50);
    box->setPos((rand()%13 + 1)*50,(rand()%13 + 1)*50);
    box->display->setPos(box->x()+17,box->y()+17);
    game->scene->addItem(box);
    game->scene->addItem(box->display);
    this->close();
}

/**
 *\brief slot function
 *
 * If the player chooses to restart the level, the score
 * is set to zero, everything is removed from the scene
 * and a new gameManager2 class is created with initials values.
 */
void nextWin::restartLevel()
{
    game->scene->clear();
    game->levelTimer->start(120000);
    Square * box = new Square(game,rand()%(10 + game->level*5),"");
    box->setFlag(QGraphicsItem::ItemIsFocusable);
    box->setRect(0,0,50,50);
    box->setPos((rand()%13 + 1)*50,(rand()%13 + 1)*50);
    game->scene->addItem(box);
    this->close();
}

/**
 *\brief slot function
 *
 * This quits the game.
 */
void nextWin::quit()
{
    //go back to game menu
}
