#include "mainmenu.h"
#include "sbox.h"
#include "gamemanager5.h"

/**
 *\file mainmenu.cpp
 *\brief source file for mainmenu.h
 */

/**
 *\brief default constructor
 */
mainmenu::mainmenu(QWidget *parent) :
    QWidget(parent)
{

}

/**
 *\brief constructor for the mainmenu class
 *
 * It takes as parameter gameManager "game" to control the game accordingly
 *\param game
 */
mainmenu::mainmenu(gamemanager5 * game, QGraphicsView* view)
{
    choose = new QLabel("Choose your character!");
    addition = new QPushButton("Alex");
    multiplication = new QPushButton("Ali");
    vBox = new QVBoxLayout;
    this->game = game;
    this->view = view;

    vBox->addWidget(choose);
    vBox->addWidget(addition);
    vBox->addWidget(multiplication);

    this->setLayout(vBox);

    this->show();

    connect(addition,SIGNAL(clicked()),this,SLOT(chooseAdd()));        ///<chooseAdd function when addition is clicked
    connect(multiplication,SIGNAL(clicked()),this,SLOT(chooseMult()));          ///<chooseMult function when multiplication is clicked
}

/**
 *\brief slot function
 *
 * This function sets the operation to 0 since
 * the player chose to get the addition.
 * It then starts the game by filling the arrays accordingly,
 * starting the timers and closing the commandWin
 */
void mainmenu::chooseAdd()
{
    game->showpic(0);
    game->gameTimer->start(50);
    this->close();
}

/**
 *\brief slot function
 *
 * This function sets the operation to 1 since
 * the player chose to get the multiplication.
 * It then starts the game by filling the arrays accordingly,
 * starting the timers and closing the commandWin
 */
void mainmenu::chooseMult()
{
    game->showpic(1);
    game->gameTimer->start(50);
    this->close();
}
