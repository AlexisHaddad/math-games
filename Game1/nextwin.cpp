#include "nextwin.h"
#include "gamemanager.h"

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
 *\param basket
 *\param game
 */
nextWin::nextWin(Basket * basket, gameManager * game)
{
    this->basket = basket;
    this->game = game;
    score = new QLabel("Score: " + (QString::number(this->basket->score)));
    if (this->basket->score >= 0)
    {
        sug = new QLabel("Level done! You can now choose to \nplay the next level or to restart this one.");

    }
    else
    {
        sug = new QLabel("Too bad! You can retry by clicking \non Restart Level or you can quit the game.");
    }
    nextLev = new QPushButton("Next Level");
    restartLev = new QPushButton("Restart Level");
    quitBut = new QPushButton("Quit");

    gridBox = new QGridLayout;

    gridBox->addWidget(score,0,2,1,2);
    gridBox->addWidget(sug,1,2,2,2);
    gridBox->addWidget(nextLev,3,0,1,2);
    gridBox->addWidget(restartLev,3,2,1,2);
    gridBox->addWidget(quitBut,3,4,1,2);

    setLayout(gridBox);

    connect(nextLev,SIGNAL(clicked()),this,SLOT(nextLevel()));              ///<nextLevel function when nextLev is clicked
    connect(restartLev,SIGNAL(clicked()),this,SLOT(restartLevel()));        ///<restartLevel function when restartLev is clicked
    connect(quitBut,SIGNAL(clicked()),this,SLOT(quit()));                   ///<quit function when quitBut is clicked

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
 * This is where the basket parameter is incremented if
 * the score is positive. Then the game is resumed.
 */
void nextWin::nextLevel()
{
    if (basket->score >= 0)
    {
        basket->parameter = basket->parameter + 1;
        game->timer->start(2000 - (basket->parameter-5)*500);
        game->fastTimer->start(200);
        game->levelTimer->start(60000);
        this->close();
    }
}

/**
 *\brief slot function
 *
 * If the player chooses to restart the level, the score
 * is set to zero, the basket parameter is set to its initial value
 * and the game is resumed.
 */
void nextWin::restartLevel()
{
    game->timer->start(2000 - (basket->parameter-5)*500);
    game->fastTimer->start(200);
    game->levelTimer->start(60000);
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
