#include "mario.h"

/**
 *\file mario.cpp
 *\brief source file for mario.h
 */

/**
 *\brief constructor of the Mario class
 *
 * This is where all the member variables are instantiated.
 */
Mario::Mario()
{

    stage=1;
    score=0;
    numerator = -1;
    denominator = -1;
    temp = "";
    flag = false;
    done = 0;
    answer = 0;
    jump = 0;
    move=false;
    fraction = new QGraphicsTextItem();
}

/**
 *\brief destructor of the Mario class
 */
Mario::~Mario()
{

}

/**
 *\brief keyPressEvent function of mario
 *
 * This function is what lets the player input number.
 * Mario is set to focus and moves according to the flags.
 * These are set depending on the player's input which should be in this fashion:
 * First enter a number(numerator), then slash, then another number(denominator) then return.
 * The parameter "event" detects key presses. So we use if statements
 * to implement the logic of the input of the player
 *\param event
 */
void Mario::keyPressEvent(QKeyEvent * event)
{
    if (stage==2)
    {
    if ((event->key() == Qt::Key_0) ||
            (event->key() == Qt::Key_1) ||
            (event->key() == Qt::Key_2) ||
            (event->key() == Qt::Key_3) ||
            (event->key() == Qt::Key_4) ||
            (event->key() == Qt::Key_5) ||
            (event->key() == Qt::Key_6) ||
            (event->key() == Qt::Key_7) ||
            (event->key() == Qt::Key_8) ||
            (event->key() == Qt::Key_9))
    {
            temp = temp + event->text();
            fraction->setPlainText(fraction->toPlainText()+event->text());
            done=1;
    }
    else if (event->key() == Qt::Key_Slash)
    {
        if((flag==false) && (done==4) )
        {
            flag=true;
            numerator=temp.toDouble();
            fraction->setPlainText(fraction->toPlainText()+"/");
            temp="";
            done=1;
        }
    }

    else if (event->key()==Qt::Key_Return)
        {
            if ((temp.toDouble())!=0 && (flag==true))
            {
                flag=false;
                denominator=temp.toDouble();
                fraction->setPlainText("");
                temp="";
                done=2;
            }
        }
    }
    else if (event->key()==Qt::Key_Up)
    {
        if (move==false)
        move=true;
    }
}
