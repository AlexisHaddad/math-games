#include "gamemanager.h"
#include "nextwin.h"
#include "pausewin.h"

/**
 *\file gamemanager.cpp
 *\brief source file for gamemanager.h
 */


/**
 *\brief default constructor
 */
gameManager::gameManager()
{

}

/**
 *\brief constructor of the gameManager class
 *
 * It takes as parameters the scene of the game to add and remove items from it.
 * It also takes the basket to use is member variables/functions accordingly.
 * Finally it takes the textItem "score" to change it with the next level logic.
 *\param scene
 *\param basket
 *\param score
 */
gameManager::gameManager(QGraphicsScene * scene, Basket * basket, QGraphicsTextItem * score)
{
    this->scene = scene;
    this->basket = basket;
    this->score = score;
    timer = new QTimer(this);
    levelTimer = new QTimer(this);
    fastTimer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));                ///<update function when timer is timeout
    connect(fastTimer, SIGNAL(timeout()),this, SLOT(updateScore()));        ///<updateSCore function when fastTimer is timeout
    connect(levelTimer, SIGNAL(timeout()),this, SLOT(newLevel()));          ///<newLevel function when levelTimer is timeout
}

/**
 *\brief destructor of the gameManager class
 */
gameManager::~gameManager()
{

}

/**
 *\brief slot function
 *
 * This is where the Eggs are created every timer timeout (1s).
 * They are set at a random x position along with their image and
 * their number in the textItem. Then they are added to the scene.
 */
void gameManager::update()
{
    Egg * egg = new Egg(basket);
    egg->setRect(0,0,50,50);
    egg->setPos(rand()%(500-50) ,0);
    egg->eggImage->setPos(egg->x() - 1, egg->y() - 20);
    egg->numText->setPos(egg->x()+12,egg->y()+12);
    scene->addItem(egg);
    scene->addItem(egg->eggImage);
    scene->addItem(egg->numText);
}

/**
 *\brief slot function
 *
 * This function stops the game and opens the nextWindow.
 */
void gameManager::newLevel()
{
   timer->stop();
   fastTimer->stop();
   levelTimer->stop();
   nextWindow = new nextWin(basket, this);
   nextWindow->show();

}

/**
 *\brief slot function
 *
 * This function updates the score whenever needed.
 * It also checks is the game is paused or not by checking
 * the boolean "pause" in the basket.
 */
void gameManager::updateScore()
{
    this->score->setPlainText("Score: " + QString::number(this->basket->score));
    if (this->basket->pause == true)
    {
        pauseGame();
    }
}

/**
 *\brief pause function
 *
 * This function opens a pauseWin when it is called.
 * This happens when the boolean "pause" in the basket
 * is true.
 */
void gameManager::pauseGame()
{
    pauseWin * pauseWindow = new pauseWin(this);
    pauseWindow->show();
}
