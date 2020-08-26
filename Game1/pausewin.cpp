#include "pausewin.h"
#include "gamemanager.h"

/**
 *\file pausewin.cpp
 *\brief source file for pauswin.h
 */

/**
 *\brief default constructor
 */
pauseWin::pauseWin()
{

}

/**
 *\brief constructor of the pauseWin class
 *
 * This is where everything is instantiated.
 * The buttons and labels are added to the virtical layout .
 * The gameManager timers are all stopped to pause the game.
 *\param game
 */
pauseWin::pauseWin(gameManager * game)
{
    title = new QLabel("Pause Game");
    resume = new QPushButton("Resume");
    restart = new QPushButton("Restart");
    quit = new QPushButton("Quit");
    vBox = new QVBoxLayout;
    this->game = game;

    vBox->addWidget(title);
    vBox->addWidget(resume);
    vBox->addWidget(restart);
    vBox->addWidget(quit);

    setLayout(vBox);

    connect(resume,SIGNAL(clicked()),this,SLOT(resumeGame()));          ///<resumeGame function when resume is clicked
    connect(restart,SIGNAL(clicked()),this,SLOT(restartGame()));        ///<restartGame function when restart is clicked
    connect(quit,SIGNAL(clicked()),this,SLOT(quitGame()));              ///<quitGame function when quit is clicked.

    this->game->timer->stop();
    this->game->fastTimer->stop();
    this->game->levelTimer->stop();
}

/**
 *\brief destructor of the pauseWin class
 */
pauseWin::~pauseWin()
{

}

/**
 *\brief slot function
 *
 * This sets the pause boolean in the basket back to its
 * initial value (false). It resumes the game and closes
 * the widget.
 */
void pauseWin::resumeGame()
{
    game->basket->pause = false;
    game->timer->start(2000 - (game->basket->parameter-5)*500);
    game->fastTimer->start(200);
    game->levelTimer->start(60000);
    this->close();
}

/**
 *\brief slot function
 *
 * This sets the pause boolean in the basket back to is
 * initial value (false). It also sets the score to 0 and
 * basket parameter to 5 (initial value).
 * The Command Window is reopenned to restart the game
 * and the player can choose even/odd. The widget is closed.
 */
void pauseWin::restartGame()
{
    game->basket->pause = false;
    game->basket->score = 0;
    game->basket->parameter = 5;
    commandWin * commandWindow = new commandWin(game);
    commandWindow->show();
    this->close();
}

/**
 *\brief slot function
 *
 * This closes the widget annd the game.
 */
void pauseWin::quitGame()
{
    this->close();

}
