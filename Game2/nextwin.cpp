#include "nextwin.h"
#include "gamemanager2.h"

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
nextWin::nextWin(Mario * mario, gameManager2 * game)
{
    this->mario = mario;
    this->game = game;
    score = new QLabel("Score: " + (QString::number(this->game->gameScore)));
    if (this->game->gameScore >= game->numStairs)
    {
        sug = new QLabel("Level done! You can now choose to play the next level or to restart this one.");

    }
    else
    {
        sug = new QLabel("Too bad! You can retry by clicking on Restart Level or you can quit the game.");
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
    if (game->gameScore >= game->numStairs)
    {
        for(int i=0;i<(game->numStairs);i++)
        {
            game->scene->removeItem(&(game->fracArray[i]));
        }
        game->numStairs = game->numStairs + 1;
        game->scene->removeItem(mario);
        game->scene->removeItem(mario->marioImage);
        Mario *mario2 = new Mario();
        mario2->setRect(0,0,5,5);
        mario2->setPos(10,280);
        game->mario->clearFocus();
        mario2->setFlag(QGraphicsItem::ItemIsFocusable);
        mario2->setFocus();
        mario2->score = game->mario->score;
        gameManager2 *game2 = new gameManager2(game->scene,mario2,game->numStairs,game->gameScore);
        game2->scene->addItem(mario2);
        this->close();
    }
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
    game->mario->score=0;
    for(int i=0;i<(game->numStairs);i++)
    {
        game->scene->removeItem(&(game->fracArray[i]));
    }
    game->scene->removeItem(mario);
    game->scene->removeItem(mario->marioImage);
    game->score->setPlainText("Score: 0");
    Mario *mario2 = new Mario();
    mario2->setRect(0,0,5,5);
    mario2->setPos(10,280);
    game->mario->clearFocus();
    mario2->setFlag(QGraphicsItem::ItemIsFocusable);
    mario2->setFocus();
    mario2->score = game->mario->score;
    gameManager2 *game2 = new gameManager2(game->scene,mario2,game->numStairs,0);
    game2->scene->addItem(mario2);
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
