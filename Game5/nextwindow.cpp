#include "nextwindow.h"
#include "gamemanager5.h"
#include "sbox.h"

/**
 *\file nextwindow.cpp
 *\brief source file for nextwindow.h
 */

/**
 *\brief default constructor
 */
nextwindow::nextwindow(QWidget *parent) :
    QWidget(parent)
{
}

/**
 *\brief constructor of the nextwindow class
 *
 * This is where everything is instantiated.
 * The buttons and labels are added to the grid layout.
 *
 *\param game
 *\param sbox
 */
nextwindow::nextwindow(gamemanager5* game, sbox* frame)
{
    this->game = game;
    this->frame = frame;
        scoreLabel = new QLabel("Score: " + (QString::number(this->game->score)));
        sug = new QLabel("Level done! You can now choose to \nplay the next level or to restart this one.");
        nextLev = new QPushButton("Next Level");
        restartLev = new QPushButton("Restart Level");

        gridBox = new QGridLayout;

        gridBox->addWidget(scoreLabel,0,2,1,2);
        gridBox->addWidget(sug,1,2,2,2);
        gridBox->addWidget(nextLev,3,0,1,2);
        gridBox->addWidget(restartLev,3,2,1,2);

        setLayout(gridBox);

        connect(nextLev,SIGNAL(clicked()),this,SLOT(nextLevel()));              ///<nextLevel function when nextLev is clicked
        connect(restartLev,SIGNAL(clicked()),this,SLOT(restartLevel()));        ///<restartLevel function when restartLev is clicked
}

/**
 *\brief slot function
 *
 * This is where the level parameter is incremented and
 * and everything is re-initialized with the new score and level.
 */
void nextwindow::nextLevel()
{
    if (game->level<5)
    {game->level = game->level + 1;}

    game->scene->removeItem(game->itembackground);
    game->scene->removeItem(game->itemframe);
    game->scene->removeItem(game->scoreItem);
    game->scene->removeItem(game->clock);

    gamemanager5 *game2= new gamemanager5(game->scene, game->box, game->level, game->score,game->character);
    game2->showpic(game->character);
    game2->gameTimer->start(50);
        this->close();
}

/**
 *\brief slot function
 *
 * If the player chooses to restart the level, the score
 * is set to zero, the level parameter is set to its initial value
 * and the game is re-initialized.
 */
void nextwindow::restartLevel()
{
      //game->scene->removeItem(frame);
      game->scene->removeItem(game->itembackground);
      game->scene->removeItem(game->itemframe);
      game->scene->removeItem(game->scoreItem);
      game->scene->removeItem(game->clock);

      //frame->clearFocus();

      gamemanager5 *game2= new gamemanager5(game->scene, game->box, game->level, 0,game->character);
      //sbox *frame2 = new sbox();
      //frame2->setRect(0,0,0,0);
      //frame2->setPos(75,495);
      //frame2->setFlag(QGraphicsItem::ItemIsFocusable);
      //frame2->setFocus();
      //game2->scene->addItem(frame2);
      game2->showpic(game->character);
      game2->gameTimer->start(50);
          this->close();
}
