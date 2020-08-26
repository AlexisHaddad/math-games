#include "restartwindow.h"
#include "gamemanager5.h"
#include "sbox.h"

/**
 *\file restartwindow.cpp
 *\brief source file for restartwindow.h
 */

/**
 *\brief default constructor
 */
restartwindow::restartwindow(QWidget *parent) :
    QWidget(parent)
{
}

/**
 *\brief constructor of the restartwindow class
 *
 * This is where everything is instantiated.
 * The buttons and labels are added to the grid layout.
 *
 *\param game
 *\param sbox
 */
restartwindow::restartwindow(gamemanager5* game, sbox* frame)
{
    this->game = game;
    this->frame = frame;
        scoreLabel = new QLabel("Score: " + (QString::number(this->game->score)));
        sug = new QLabel("Too bad! You didn't finish on time! \nYou can retry by clicking on Restart Level.");
        restartLev = new QPushButton("Restart Level");

        gridBox = new QGridLayout;

        gridBox->addWidget(scoreLabel,0,2,1,2);
        gridBox->addWidget(sug,1,2,2,2);
        gridBox->addWidget(restartLev,3,1,1,2);

        setLayout(gridBox);

        connect(restartLev,SIGNAL(clicked()),this,SLOT(restartLevel()));        ///<restartLevel function when restartLev is clicked
}

/**
 *\brief slot function
 *
 * If the player chooses to restart the level, the score
 * is set to zero, the level parameter is set to its initial value
 * and the game is re-initialized.
 */
void restartwindow::restartLevel()
{
      game->scene->removeItem(game->itembackground);
      game->scene->removeItem(game->itemframe);
      game->scene->removeItem(game->scoreItem);
      game->scene->removeItem(game->clock);

      gamemanager5 *game2= new gamemanager5(game->scene, game->box, game->level, 0,game->character);

      game2->showpic(game->character);
      game2->gameTimer->start(1000);
          this->close();
}
