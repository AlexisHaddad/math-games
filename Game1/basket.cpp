#include "basket.h"

/**
 *\file basket.cpp
 *\brief source file for basket.h
 */


/**
 *\brief default constructor for the Basket class
 *
 * It instantiates all the components of the class.
 * Base value for "score" is 0 and for "parameter" is 5 (design choice).
 * "pause" is set to false and "even" is set to true as default values.
 * The image of the basket is also created here.
 */
Basket::Basket()
{
    score = 0;
    parameter = 5;
    pause = false;
    even = true;
    QPixmap image1("/home/alexis/Documents/Qt_Projects/Game1/basket.png");
    basketImage = new QGraphicsPixmapItem(image1.scaled(QSize(180,180), Qt::KeepAspectRatio));

}

/**
 *\brief destructor of the Basket class
 */
Basket::~Basket()
{

}

/**
 *\brief keyPressEvent function of the basket
 *
 * This function is what makes the basket move left and right.
 * The Basket is set to focus in the main function so that it can work.
 * The parameter "event" detects key presses. So we use if statements
 * to implement the logic of the movement of the basket
 *
 *\param event
 */
void Basket::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
    {
        if(x() + 5 + 100 <= 500 )
        {
            setPos(x() + parameter + 2, y());
            basketImage->setPos(x() - 60, y() - 35);
        }
    }
    else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
    {
        if(x() -5 >= 0 )
        {
            setPos(x() - parameter - 2, y());
            basketImage->setPos(x() - 60, y() - 35);
        }
    }
    else if (event->key() == Qt::Key_Escape)
    {
        pause = true;
    }
}
