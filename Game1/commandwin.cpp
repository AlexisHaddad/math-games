#include "commandwin.h"

/**
 *\file commandwin.cpp
 *\brief source file for commandwin.h
 */

/**
 *\brief default constructor
 */
commandWin::commandWin()
{

}


/**
 *\brief constructor for the commandWin class
 *
 * It takes as parameter gameManager "game" to control the game accordingly
 *\param game
 */
commandWin::commandWin(gameManager * game)
{
    choose = new QLabel("Choose to catch Even or Odd falling eggs ...");
    even = new QPushButton("Even");
    odd = new QPushButton("Odd");
    vBox = new QVBoxLayout;
    this->game = new gameManager(game->scene,game->basket,game->score);

    vBox->addWidget(choose);
    vBox->addWidget(even);
    vBox->addWidget(odd);

    this->setLayout(vBox);

    this->show();

    connect(even,SIGNAL(clicked()),this,SLOT(chooseEven()));        ///<chooseEven function when even is clicked
    connect(odd,SIGNAL(clicked()),this,SLOT(chooseOdd()));          ///<chooseOdd function when odd is clicked

}

/**
 *\brief destructor of the commandWin class
 */
commandWin::~commandWin()
{

}

/**
 *\brief slot function
 *
 * This function sets the boolean "even" to true since
 * the player chose to get the even eggs.
 * It then starts the game by starting the timers and it
 * closes the commandWin
 */
void commandWin::chooseEven()
{
    game->basket->even = true;
    game->timer->start(2000 - (game->basket->parameter-5)*500);
    game->fastTimer->start(200);
    game->levelTimer->start(60000);
    this->close();
}

/**
 *\brief slot function
 *
 * This function sets the boolean "even" to false since
 * the player chose to get the odd eggs.
 * It then starts the game by starting the timers and it
 * closes the commandWin
 */
void commandWin::chooseOdd()
{
    game->basket->even = false;
    game->timer->start(2000 - (game->basket->parameter-5)*500);
    game->fastTimer->start(200);
    game->levelTimer->start(60000);
    this->close();
}
