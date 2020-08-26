#include "egg.h"

/**
 *\file egg.cpp
 *\brief source file for egg.h
 */

/**
 *\brief default constructor
 */
Egg::Egg()
{

}

/**
 *\brief constructor of the Egg class
 *
 * It takes as parameter Basket "basket" to be able to use
 * the basket member variables/functions accordingly.
 * It initiates the timer to a very fast value (0.05s) and
 * and randomly generates "num" and "speed".
 * It also instantiates the image of the Egg.
 *\param basket
 */

Egg::Egg(Basket * basket)
{
    timer = new QTimer(this);
    timer->start(50);
    this->basket = basket;
    num = rand()%100;
    QPixmap image1("/home/alexis/Documents/Qt_Projects/Game1/egg.png");
    eggImage = new QGraphicsPixmapItem(image1.scaled(QSize(75,75), Qt::KeepAspectRatio));
    numText = new QGraphicsTextItem(QString::number(num));
    speed = (rand()%(basket->parameter)) + basket->parameter;

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));                ///<update funcion when timer is timeout
}

/**
 *\brief destructor of the Egg class
 */
Egg::~Egg()
{

}

/**
 *\brief slot function
 *
 * This function changes the position of the Egg and its image every 0.05s.
 * The first if statement is when an Egg fell (no catch):
 * depending on what the player chose (even/odd), if a valid Egg falls,
 * the score is decremented by 2, else nothing happens.
 * The second if statement is when an Egg is not entirely in the basket (no catch):
 * Same logic as before.
 * The third if statement is when an Egg is in the basket (catch):
 * depending on what the player chose (even/odd), if a valid Egg is caught,
 * the score is incremented by 2, else the score is decremented by 3.
 */
void Egg::update()
{
    basket->setFocus();
    setPos(x(),y() + speed);
    eggImage->setPos(eggImage->x(), eggImage->y() + speed);
    this->numText->setPos(this->numText->x(),this->numText->y() + speed);
    if((y() >= 570))
    {
        if (basket->even)
        {
            if (num%2 == 0)
            {
                basket->score = basket->score - 2;
                scene()->removeItem(eggImage);
                delete eggImage;
                scene()->removeItem(this->numText);
                delete this->numText;
                scene()->removeItem(this);
                delete this;
            }
            else
            {
                scene()->removeItem(eggImage);
                delete eggImage;
                scene()->removeItem(this->numText);
                delete this->numText;
                scene()->removeItem(this);
                delete this;
            }
        }
        else
        {
            if (num%2 == 0)
            {
                scene()->removeItem(eggImage);
                delete eggImage;
                scene()->removeItem(this->numText);
                delete this->numText;
                scene()->removeItem(this);
                delete this;
            }
            else
            {
                scene()->removeItem(eggImage);
                delete eggImage;
                basket->score = basket->score - 2;
                scene()->removeItem(this->numText);
                delete this->numText;
                scene()->removeItem(this);
                delete this;
            }
        }
    }
    else if ((((x() < basket->x() - 25) && (x() + 50 > basket->x() - 25)) ||
             ((x() < basket->x() + 125) && (x() + 50 > basket->x() + 125))) && (y() + 50 > 500))
    {
        if (basket->even)
        {
            if (num%2 == 0)
            {
                basket->score = basket->score - 2;
                scene()->removeItem(eggImage);
                delete eggImage;
                scene()->removeItem(this->numText);
                delete this->numText;
                scene()->removeItem(this);
                delete this;
            }
            else
            {
                scene()->removeItem(eggImage);
                delete eggImage;
                scene()->removeItem(this->numText);
                delete this->numText;
                scene()->removeItem(this);
                delete this;
            }
        }
        else
        {
            if (num%2 == 0)
            {
                scene()->removeItem(eggImage);
                delete eggImage;
                scene()->removeItem(this->numText);
                delete this->numText;
                scene()->removeItem(this);
                delete this;
            }
            else
            {
                basket->score = basket->score - 2;
                scene()->removeItem(eggImage);
                delete eggImage;
                scene()->removeItem(this->numText);
                delete this->numText;
                scene()->removeItem(this);
                delete this;
            }
        }
    }
    else if ((x() >= basket->x() - 25) && (x() + 50 <= basket->x() + 125) &&
             (y() + 50 <= 600 - 100 + basket->parameter) && (y() + 50 >= (500 - basket->parameter)))
    {
        if (basket->even)
        {
            if (num%2 == 0)
            {
                basket->score = basket->score + 2;
                scene()->removeItem(eggImage);
                delete eggImage;
                scene()->removeItem(this->numText);
                delete this->numText;
                scene()->removeItem(this);
                delete this;
            }
            else
            {
                scene()->removeItem(eggImage);
                delete eggImage;
                basket->score = basket->score - 3;
                scene()->removeItem(this->numText);
                delete this->numText;
                scene()->removeItem(this);
                delete this;
            }
        }
        else
        {
            if (num%2 == 0)
            {
                basket->score = basket->score - 3;
                scene()->removeItem(eggImage);
                delete eggImage;
                scene()->removeItem(this->numText);
                delete this->numText;
                scene()->removeItem(this);
                delete this;
            }
            else
            {
                basket->score = basket->score + 2;
                scene()->removeItem(eggImage);
                delete eggImage;
                scene()->removeItem(this->numText);
                delete this->numText;
                scene()->removeItem(this);
                delete this;
            }
        }
    }
}
