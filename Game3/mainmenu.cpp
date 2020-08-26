#include "mainmenu.h"
#include "sframe.h"
#include "gamemanager3.h"

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
mainmenu::mainmenu(gamemanager3 * game)
{
    choose = new QLabel("Choose to have Addition or Multiplication numbers!");
    addition = new QPushButton("Addition");
    multiplication = new QPushButton("Multiplication");
    vBox = new QVBoxLayout;
    this->game = game;

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
    game->fillArray(0);
    game->gameTimer->start(1000);
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
    game->fillArray(1);
    game->gameTimer->start(1000);
    this->close();
}
