#include "gamemanager2.h"
#include "nextwin.h"

/**
 *\file gamemanager2.cpp
 *\brief source file for gamamanger2.h
 */

/**
 *\brief default constructor
 */
gameManager2::gameManager2()
{

}

/**
 *\brief constructor of the gameManager2 class
 *
 * It takes as parameters the scene of the game to add and remove items from it.
 * It also takes mario to use is member variables/functions accordingly,
 * the textItem "score" to change it with the next level logic,
 * the integers numStairs and gameScore to use re-use them everytime.
 * This class is created again at each level and displays a different picture
 * for each level (different number of steps).
 * The logic is the same for each level: random fractions are generated in array
 * and displayed on the stairs.
 *\param scene
 *\param mario
 *\param score
 *\param numStairs
 *\param gameScore
 */
gameManager2::gameManager2(QGraphicsScene *scene, Mario *mario, int numStairs,int gameScore)
{

    this->scene = scene;
    this->mario = mario;
    this->score = score;
    this->numStairs=numStairs;
    this->gameScore=gameScore;
    marioTimer = new QTimer(this);
    gameTimer = new QTimer(this);
    result=0;
    step=0;
    second = 0;
    counter=0;
    coin1X=20+rand()%65;
    coin2X=160+(numStairs-3)*25+rand()%((15-numStairs)*25);
    coin2Y=170-((numStairs-3)*25);
    moving= false;
    numArray = new double[10];
    denomArray = new double[10];
    fracArray = new QGraphicsTextItem[10];

    image1.load("/home/alexis/Documents/Qt_Projects/Game2/stairs"+QString::number((this->numStairs)-1)+".png");
    item = new QGraphicsPixmapItem(image1.scaled(QSize(500,600),  Qt::KeepAspectRatio));
    this->scene->addItem(item);

    clock = new QGraphicsTextItem("Time: 0");
    clock->setPos(0,50);
    this->scene->addItem(clock);

    score = new QGraphicsTextItem("Score: " + QString::number(this->gameScore));
    this->scene->addItem(score);

    imagec1.load("/home/alexis/Documents/Qt_Projects/Game2/coin.png");
    itemc1 = new QGraphicsPixmapItem(imagec1.scaled(QSize(30,30),  Qt::KeepAspectRatio));
    itemc1->setPos(coin1X,230);
    this->scene->addItem(itemc1);

    imagec2.load("/home/alexis/Documents/Qt_Projects/Game2/coin.png");
    itemc2 = new QGraphicsPixmapItem(imagec2.scaled(QSize(30,30),  Qt::KeepAspectRatio));
    itemc2->setPos(coin2X,coin2Y);
    this->scene->addItem(itemc2);

    QPixmap image2("/home/alexis/Documents/Qt_Projects/Game2/mario.png");
    this->mario->marioImage = new QGraphicsPixmapItem(image2.scaled(QSize(50,50),  Qt::KeepAspectRatio));
    this->mario->marioImage->setPos(0,270);
    this->scene->addItem(mario->marioImage);


    for (int i=0;i<numStairs;i++)
    {
       numArray[i]=rand()%numStairs;
       denomArray[i]=rand()%numStairs+1;
       fracArray[i].setPlainText((QString::number(numArray[i]))+"/"+(QString::number(denomArray[i])));
       fracArray[i].setDefaultTextColor(Qt::black);
       fracArray[i].setPos(95+25*i,312-25*i);
       scene->addItem(&fracArray[i]);
    }
    connect(marioTimer, SIGNAL(timeout()), this, SLOT(marioMove()));        ///<marioMove function when marioTimer is timeout
    marioTimer->start(10);
}

/**
 *\brief destructor of the gameManager2 class
 */
gameManager2::~gameManager2()
{

}

/**
 *\brief slot function
 *
 * This function makes mario move.
 * It works like an FSM.
 * The game is divided in three stages:
 * Stage1: mario moves up to the bottom of the stairs,
 *         the player can jump and get the coins while moving
 * Stage2: mario waits for the player input. The input is computed
 *         and compared to the right answer. If it is correct mario
 *         moves up. If not, he moves down or stay at the same place(if on the floor)
 * Stage3: level is done and mario moves right to the end of the
 *         level, the player can jump and get the coins while moving
 */
void gameManager2::marioMove()
{
    second++;
    this->clock->setPlainText("Time: " + QString::number(this->second));
    if (second%6000==0)
    {
        gameScore=gameScore-(numStairs/3);
        this->score->setPlainText("Score: " + QString::number(this->gameScore));
    }
    if (mario->stage==1)
    {

     if ((mario->x()<=95))
        {
            mario->setPos(mario->x()+1,mario->y());
            mario->marioImage->setPos(mario->marioImage->x()+1,mario->marioImage->y());
            if(mario->move==true && counter<=10)
            {
                mario->setPos(mario->x(),mario->y()-5);
                mario->marioImage->setPos(mario->marioImage->x(),mario->marioImage->y()-5);
                counter++;
            }
            else if (mario->move==true && counter>10 && counter<=21)
            {
                mario->setPos(mario->x(),mario->y()+5);
                mario->marioImage->setPos(mario->marioImage->x(),mario->marioImage->y()+5);
                counter++;
                if(counter==21)
                {
                    if (mario->x()>=coin1X-35 && mario->x()<=coin1X+35)
                    {
                        gameScore=gameScore+2;
                        this->score->setPlainText("Score: " + QString::number(this->gameScore));
                        scene->removeItem(itemc1);
                    }
                }
            }
            else if (mario->move==true && counter>21)
            {
                counter=0;
                mario->move=false;
            }
        }

     else if (mario->x()>=95)
     {
         mario->setPos(mario->x(),280);
         mario->marioImage->setPos(mario->marioImage->x(),270);
         mario->stage=2;
     }
    }

    else if (mario->stage==3)
    {
     if ((mario->x()<=470))
        {
            mario->setPos(mario->x()+2,mario->y());
            mario->marioImage->setPos(mario->marioImage->x()+2,mario->marioImage->y());
            if(mario->move==true && counter<=10)
            {
                mario->setPos(mario->x(),mario->y()-5);
                mario->marioImage->setPos(mario->marioImage->x(),mario->marioImage->y()-5);
                counter++;
            }
            else if (mario->move==true && counter>10 && counter<=21)
            {
                mario->setPos(mario->x(),mario->y()+5);
                mario->marioImage->setPos(mario->marioImage->x(),mario->marioImage->y()+5);
                counter++;
                if(counter==21)
                {
                    if (mario->x()>=coin2X-35 && mario->x()<=coin2X+35)
                    {
                        gameScore=gameScore+2;
                        this->score->setPlainText("Score: " + QString::number(this->gameScore));
                        scene->removeItem(itemc2);
                    }
                }
            }
            else if (mario->move==true && counter>21)
            {
                counter=0;
                mario->move=false;
            }
        }
     else
     {
        marioTimer->stop();
        gameTimer->stop();
        nextWindow = new nextWin(mario, this);
        nextWindow->show();
     }
    }

    else if (mario->stage==2)
    {
        if (mario->done==0)
        {
            scene->addItem(mario->fraction);
            mario->done=3;
        }
        else if (mario->done==1)
        {
            mario->done=4;
            mario->fraction->setPos(mario->x()-5,mario->y()-25);
        }
        else if (mario->done==2)
        {
            mario->done=0;
            scene->removeItem(mario->fraction);
            mario->answer = (mario->numerator)/(mario->denominator);
            result = ((numArray[step])*(denomArray[step+1])+(numArray[step+1])*(denomArray[step]))/((denomArray[step])*(denomArray[step+1]));
            mario->jump = (mario->numerator)/(mario->denominator);
            if (result-mario->answer==0)
            {
                if (mario->jump==0)
                    {
                        mario->jump=1;
                    }
                if (step + mario->jump > numStairs-1)
                    {
                        mario->jump=numStairs-step-1;
                    }
                gameScore=gameScore+mario->jump;
                this->score->setPlainText("Score: " + QString::number(this->gameScore));
                mario->setPos(mario->x()+25*(mario->jump),mario->y()-25*(mario->jump));
                mario->marioImage->setPos(mario->marioImage->x()+25*(mario->jump),mario->marioImage->y()-25*(mario->jump));
                step=step+mario->jump;
                if (step==numStairs-1)
                    {
                        mario->stage=3;
                    }
            }
            else
            {
                gameScore=gameScore-(numStairs/3);
                    this->score->setPlainText("Score: " + QString::number(this->gameScore));
                if(step>0)
                {
                    mario->setPos(mario->x()-25,mario->y()+25);
                    mario->marioImage->setPos(mario->marioImage->x()-25,mario->marioImage->y()+25);
                    step--;
                }
            }
        }
    }
}

