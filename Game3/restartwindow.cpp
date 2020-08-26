#include "restartwindow.h"
#include "gamemanager3.h"
#include "sframe.h"

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
 *\param sframe
 */
restartwindow::restartwindow(gamemanager3* game, sframe* frame)
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
    for(int i=0;i<=(game->step1);i++)
      {
          game->scene->removeItem(&(game->numberArray1[i]));
      }
      for(int i=0;i<=(game->step2);i++)
      {
          game->scene->removeItem(&(game->numberArray2[i]));
      }
      for(int i=0;i<=(game->step3);i++)
      {
          game->scene->removeItem(&(game->numberArray3[i]));
      }
      for(int i=0;i<=(game->step4);i++)
      {
          game->scene->removeItem(&(game->numberArray4[i]));
      }

      game->scene->removeItem(frame);
      game->scene->removeItem(game->itembackground);
      game->scene->removeItem(game->itemframe);
      game->scene->removeItem(game->scoreItem);
      game->scene->removeItem(game->clock);

      frame->clearFocus();

      gamemanager3 *game2= new gamemanager3(game->scene, game->level, 0,game->operation);
      sframe *frame2 = new sframe(game2);
      frame2->setRect(0,0,0,0);
      frame2->setPos(75,495);
      frame2->setFlag(QGraphicsItem::ItemIsFocusable);
      frame2->setFocus();
      game2->scene->addItem(frame2);
      game2->fillArray(game->operation);
      game2->gameTimer->start(1000);
          this->close();
}
