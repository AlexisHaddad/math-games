#include "gamemanager5.h"
#include "sbox.h";
#include "mainmenu.h"
#include "nextwindow.h"
#include "restartwindow.h"


class sbox;

/**
 *\file gamemanager5.cpp
 *\brief source file for gamemanager5.h
 */


/**
 *\brief default constructor
 */
gamemanager5::gamemanager5(QObject *parent) :
    QObject(parent)
{
}

/**
 *\brief constructor of the gameManager class
 *
 * It takes as parameters the scene of the game to add and remove items from it.
 * It the level to determine the numbers and the array lengths.
 * It takes the textItem "score" to change it with the next level logic.
 * It takes the int "opreation" to check if the operation is addition or multiplication .
 *\param scene
 *\param level
 *\param score
 *\param operation
 */
gamemanager5::gamemanager5(QGraphicsScene *s,sbox* b, int l, int sc, int c)
{
    this->scene = s;
    this->box = b;
    this->level = l;
    this->score = sc;
    this->character=c;

    gameTimer = new QTimer(this);

    state = "0";
    second = 0;
    counter = 0;

    box->move=0;

    imagebackground.load("/home/EECE435/Game5/background.png");
    itembackground = new QGraphicsPixmapItem(imagebackground.scaled(QSize(595,595),  Qt::KeepAspectRatio));
    this->scene->addItem(itembackground);

    imagedoors.load("/home/EECE435/Game5/doors.jpg");
    itemdoors = new QGraphicsPixmapItem(imagedoors.scaled(QSize(400,400),  Qt::KeepAspectRatio));
    itemdoors->setPos(100,100);

    clock = new QGraphicsTextItem("Time: 0");
    clock->setDefaultTextColor(Qt::white);
    clock->setPos(0,0);
    this->scene->addItem(clock);

    scoreItem = new QGraphicsTextItem("Score: " + QString::number(this->score));
    scoreItem->setDefaultTextColor(Qt::white);
    scoreItem->setPos(100,0);
    this->scene->addItem(scoreItem);

    connect(gameTimer, SIGNAL(timeout()), this, SLOT(updateTimer()));   ///<update function when timer is timeout

}

/**
 *\brief slot function
 *
 * This is where the timer and score are updated.
 */
void gamemanager5::updateTimer()
{
    second++;
    this->clock->setPlainText("Time: " + QString::number(this->second));
    if (second%100==0)
    {
        score=score-level;
        this->scoreItem->setPlainText("Score: " + QString::number(this->score));
    }

    if (luck==0 && counter <=1)
    {
        if (box->move==1)
            box->move=2;
        else if (box->move==2)
            box->move=1;
    }

    if (box->move==1 && counter<=1)
    {this->score = this->score-this->level;}
    else if (box->move==2 && counter<=1)
    {this->score = this->score+5;}
    scoreItem->setPlainText("Score: " + QString::number(this->score));

    if (state == "0")
    {   if (counter ==0)
        {
            showNumbers();
            counter++;
        }
        if (box->move==1)
        {
            scene->removeItem(itemdoors);
            scene->removeItem(itemoption1);
            scene->removeItem(itemoption2);
            scene->removeItem(question);
            if (counter<12)
            {
                itemframe->setPos(itemframe->x()+5,itemframe->y());
                counter++;
            }
            else if (counter<20)
            {
                itemframe->setPos(itemframe->x(),itemframe->y()-5);
                counter++;
            }
            else if (counter <31)
            {
                itemframe->setPos(itemframe->x()+5,itemframe->y());
                counter++;
            }
            else if (counter<45)
                        {
                            itemframe->setPos(itemframe->x(),itemframe->y()-5);
                            counter++;
                        }
            else if (counter<55)
                        {
                            itemframe->setPos(itemframe->x()-5,itemframe->y());
                            counter++;
                        }
            else if (counter<90)
                        {
                            itemframe->setPos(itemframe->x(),itemframe->y()-5);
                            counter++;
                        }
            else if (counter<101)
                        {
                            itemframe->setPos(itemframe->x()+5,itemframe->y());
                            counter++;
                        }
            else if (counter<113)
                        {
                            itemframe->setPos(itemframe->x(),itemframe->y()-5);
                            counter++;
                        }
            else if (counter<136)
                        {
                            itemframe->setPos(itemframe->x()-5,itemframe->y());
                            counter++;
                        }
            else if (counter<193)
                        {
                            itemframe->setPos(itemframe->x(),itemframe->y()+5);
                            counter++;
                        }
            else if (counter == 193)
            {
                state = "1x";
                counter = 0;
                box->move=0;
            }
        }
        else if (box->move==2)
        {
            scene->removeItem(itemdoors);
            scene->removeItem(itemoption1);
            scene->removeItem(itemoption2);
            scene->removeItem(question);
            if (counter ==0)
            {
                 showNumbers();
                 counter++;
             }
            if (counter<26)
            {
                itemframe->setPos(itemframe->x(),itemframe->y()+5);
                counter++;
            }
            else if (counter<35)
            {
                itemframe->setPos(itemframe->x()+5,itemframe->y());
                counter++;
            }
            else if (counter ==35)
            {
                state = "1y";
                counter = 0;
                box->move=0;
            }
        }
    }
    else if (state=="1x")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<58)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<81)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter <93)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<104)
                                {
                                    itemframe->setPos(itemframe->x()-5,itemframe->y());
                                    counter++;
                                }
                    else if (counter<139)
                                {
                                    itemframe->setPos(itemframe->x(),itemframe->y()+5);
                                    counter++;
                                }
                    else if (counter<149)
                                {
                                    itemframe->setPos(itemframe->x()+5,itemframe->y());
                                    counter++;
                                }
                    else if (counter<163)
                                {
                                    itemframe->setPos(itemframe->x(),itemframe->y()+5);
                                    counter++;
                                }
                    else if (counter<172)
                                {
                                    itemframe->setPos(itemframe->x()-5,itemframe->y());
                                    counter++;
                                }
                    else if (counter<180)
                                {
                                    itemframe->setPos(itemframe->x(),itemframe->y()+5);
                                    counter++;
                                }
                    else if (counter<193)
                                {
                                    itemframe->setPos(itemframe->x()-5,itemframe->y());
                                    counter++;
                                }
                    else if (counter == 193)
                    {
                        state = "0";
                        counter = 0;
                        box->move=0;
                    }
                }
                else if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    state = "0";
                    counter = 0;
                    box->move=0;
                    itemframe->setPos(10,350);
                }
    }
    else if (state=="1y")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<13)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<22)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter == 22)
                    {
                        state = "2x";
                        counter = 0;
                        box->move=0;
                    }
                }
                else if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<11)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<25)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter == 25)
                    {
                        state = "2y";
                        counter = 0;
                        box->move=0;
                    }
                }
    }
    else if (state=="2x")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    state = "0";
                    counter = 0;
                    box->move=0;
                    itemframe->setPos(10,350);
                }
                else if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<10)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<22)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter == 22)
                    {
                        state = "1y";
                        counter = 0;
                        box->move=0;
                    }
                }
    }
    else if (state=="2y")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<14)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter == 14)
                    {
                        state = "3x";
                        counter = 0;
                        box->move=0;
                    }
                }
                else if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<11)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter == 11)
                    {
                        state = "3y";
                        counter = 0;
                        box->move=0;
                    }
                }
    }
    else if (state=="3x")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    state = "0";
                    counter = 0;
                    box->move=0;
                    itemframe->setPos(10,350);
                }
                else if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<14)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter == 14)
                    {
                        state = "2y";
                        counter = 0;
                        box->move=0;
                    }
                }
    }
    else if (state=="3y")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<13)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<24)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter == 24)
                    {
                        state = "4x";
                        counter = 0;
                        box->move=0;
                    }
                }
                else if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<12)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<23)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<35)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<45)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<56)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter<70)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<80)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<101)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<115)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter == 115)
                    {
                        state = "4y";
                        counter = 0;
                        box->move=0;
                    }

                }
    }
    else if (state=="4x")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    state = "0";
                    counter = 0;
                    box->move=0;
                    itemframe->setPos(10,350);
                }
                else if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<12)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter<24)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter == 24)
                    {
                        state = "3y";
                        counter = 0;
                        box->move=0;
                    }
                }
    }
    else if (state=="4y")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<30)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<40)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<50)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<85)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter<95)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<110)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<125)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<150)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter<160)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<170)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<180)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter == 180)
                    {
                        state = "5x";
                        counter = 0;
                        box->move=0;
                    }
                }
                else if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<20)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<30)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter == 30)
                    {
                        state = "5y";
                        counter = 0;
                        box->move=0;
                    }
                }
    }
    else if (state=="5x")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    state = "0";
                    counter = 0;
                    box->move=0;
                    itemframe->setPos(10,350);
                }
                else if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<11)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<21)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter<31)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<56)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<71)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<86)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter<96)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<131)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<141)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<151)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter<180)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter == 180)
                    {
                        state = "4y";
                        counter = 0;
                        box->move=0;
                    }
                }
    }
    else if (state=="5y")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<25)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<35)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter == 35)
                    {
                        state = "6x";
                        counter = 0;
                        box->move=0;
                    }
                }
                else if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<35)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<50)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter == 50)
                    {
                        state = "6y";
                        counter = 0;
                        box->move=0;
                    }
                }
    }
    else if (state=="6x")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    state = "0";
                    counter = 0;
                    box->move=0;
                    itemframe->setPos(10,350);
                }
                else if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<11)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<35)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter == 35)
                    {
                        state = "5y";
                        counter = 0;
                        box->move=0;
                    }
                }
    }
    else if (state=="6y")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<25)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<45)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<80)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<100)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter == 100)
                    {
                        state = "7x";
                        counter = 0;
                        box->move=0;
                    }
                }
                else if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<25)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<45)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<55)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<65)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter<90)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<102)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter == 102)
                    {
                        state = "win";
                        counter = 0;
                        box->move=0;
                    }
                }
    }
    else if (state=="7x")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<15)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<40)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter<65)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<75)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter<85)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<120)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<130)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<150)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<160)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<170)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter == 170)
                    {
                        state = "8x";
                        counter = 0;
                        box->move=0;
                    }
                }
                else if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<21)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<56)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<76)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter<100)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter == 100)
                    {
                        state = "6y";
                        counter = 0;
                        box->move=0;
                    }
                }
    }
    else if (state=="8x")
    {
        if (counter ==0)
                {
                    showNumbers();
                    counter++;
                }
                if (box->move==1)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    state = "0";
                    counter = 0;
                    box->move=0;
                    itemframe->setPos(10,350);
                }
                else if (box->move==2)
                {
                    scene->removeItem(itemdoors);
                    scene->removeItem(itemoption1);
                    scene->removeItem(itemoption2);
                    scene->removeItem(question);
                    if (counter<11)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<21)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<41)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter<51)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter<86)
                    {
                        itemframe->setPos(itemframe->x()-5,itemframe->y());
                        counter++;
                    }
                    else if (counter<96)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<106)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<131)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()-5);
                        counter++;
                    }
                    else if (counter<156)
                    {
                        itemframe->setPos(itemframe->x()+5,itemframe->y());
                        counter++;
                    }
                    else if (counter<170)
                    {
                        itemframe->setPos(itemframe->x(),itemframe->y()+5);
                        counter++;
                    }
                    else if (counter == 170)
                    {
                        state = "7x";
                        counter = 0;
                        box->move=0;
                    }
                }
    }
    else if (state == "win")
    {
        this->gameTimer->stop();
        if (this->score>=10)
        {
            nextWindow1 = new nextwindow(this,this->box);
            nextWindow1->show();
        }
        else if (this->score<10)
        {
            restartWindow1 = new restartwindow(this,this->box);
            restartWindow1->show();
        }
    }
}

void gamemanager5::showNumbers()
{
    scene->addItem(itemdoors);
    number1=rand()%(11+level*10);
    number2=rand()%(11+level*10);
    luck = rand()%2;
    if (luck==0)
    {
        option1 = number1%number2;
        option2 = rand()%(11+level*10);
        while (option2==option1)
        {
           option2 = rand()%(11+level*10);
        }
    }
    else if (luck==1)
    {
        option2 = number1%number2;
        option1 = rand()%(11+level*10);
        while (option1==option2)
        {
           option2 = rand()%(11+level*10);
        }
    }
    itemoption1 = new QGraphicsTextItem(QString::number(this->option1));
    itemoption1->setDefaultTextColor(Qt::white);
    itemoption1->setPos(220,250);
    scene->addItem(itemoption1);

    itemoption2 = new QGraphicsTextItem(QString::number(this->option2));
    itemoption2->setDefaultTextColor(Qt::white);
    itemoption2->setPos(320,250);
    scene->addItem(itemoption2);

    question = new QGraphicsTextItem(QString::number(this->number1) + " mod " + QString::number(this->number2));
    question->setDefaultTextColor(Qt::white);
    question->setPos(250,400);
    scene->addItem(question);
}
void gamemanager5::showpic(int i)
{
    this->character=i;
    imageframe.load("/home/EECE435/Game5/doors"+QString::number(i)+".png");
    itemframe = new QGraphicsPixmapItem(imageframe.scaled(QSize(60,60),  Qt::KeepAspectRatio));
    itemframe->setPos(10,350);
    this->scene->addItem(itemframe);
}
