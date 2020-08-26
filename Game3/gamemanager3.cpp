#include "gamemanager3.h"
#include "sframe.h";
#include "mainmenu.h"
#include "nextwindow.h"
#include "restartwindow.h"

/**
 *\file gamemanager3.cpp
 *\brief source file for gamemanager3.h
 */


/**
 *\brief default constructor
 */
gamemanager3::gamemanager3(QObject *parent) :
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
gamemanager3::gamemanager3(QGraphicsScene *s, int l, int sc, int o)
{
    this->scene = s;
    this->level = l;
    this->score = sc;
    this->operation=o;

    inputTextItem = new QGraphicsTextItem();
    inputTextItem->setPos(410,500);
    temp = "";

    gameTimer = new QTimer(this);

    second = 0;

    stage = 1;
    step1 = 1;
    step2 = 1;
    step3 = 1;
    step4 = 1;

    inputNumber = 0;

    branch1 = new int[7+level];
    branch2 = new int[5+level];
    branch3 = new int[4+level];
    branch4 = new int[4+level];

    branch1[0]=1;
    branch1[1]=rand()%(level+1)+1;

    branch2[0]=2;
    branch2[1]=rand()%(level+2)+1;

    branch3[0]=3;
    branch3[1]=rand()%(level+3)+1;

    branch4[0]=4;
    branch4[1]=rand()%(level+5)+1;

    numberArray1 = new QGraphicsTextItem[7+level];
    numberArray2 = new QGraphicsTextItem[5+level];
    numberArray3 = new QGraphicsTextItem[4+level];
    numberArray4 = new QGraphicsTextItem[4+level];


    imagebackground.load("/home/EECE435/Game3/background"+QString::number(this->level)+".png");
    itembackground = new QGraphicsPixmapItem(imagebackground.scaled(QSize(500,600),  Qt::KeepAspectRatio));
    this->scene->addItem(itembackground);

    imageframe.load("/home/EECE435/Game3/sframe.png");
    itemframe = new QGraphicsPixmapItem(imageframe.scaled(QSize(65,65),  Qt::KeepAspectRatio));
    itemframe->setPos(51,475);
    this->scene->addItem(itemframe);

    scene->addItem(inputTextItem);

    clock = new QGraphicsTextItem("Time: 0");
    clock->setPos(0,0);
    this->scene->addItem(clock);

    inputLabel = new QGraphicsTextItem("Input: ");
    inputLabel->setPos(350,500);
    this->scene->addItem(inputLabel);

    scoreItem = new QGraphicsTextItem("Score: " + QString::number(this->score));
    scoreItem->setPos(100,0);
    this->scene->addItem(scoreItem);

    numberArray1[0].setPlainText(QString::number(branch1[0]));
    numberArray1[0].setDefaultTextColor(Qt::black);
    numberArray1[0].setPos(65,503);
    scene->addItem(&numberArray1[0]);

    numberArray2[0].setPlainText(QString::number(branch2[0]));
    numberArray2[0].setDefaultTextColor(Qt::black);
    numberArray2[0].setPos(102,182+10+158);
    scene->addItem(&numberArray2[0]);

    numberArray3[0].setPlainText(QString::number(branch3[0]));
    numberArray3[0].setDefaultTextColor(Qt::black);
    numberArray3[0].setPos(216,182+10+158);
    scene->addItem(&numberArray3[0]);

    numberArray4[0].setPlainText(QString::number(branch4[0]));
    numberArray4[0].setDefaultTextColor(Qt::black);
    numberArray4[0].setPos(334,182+10+158);
    scene->addItem(&numberArray4[0]);

    showNumbers();

    connect(gameTimer, SIGNAL(timeout()), this, SLOT(updateTimer()));   ///<update function when timer is timeout
}

/**
 *\brief slot function
 *
 * This is where the timer and score are updated.
 */
void gamemanager3::updateTimer()
{
    second++;
    this->clock->setPlainText("Time: " + QString::number(this->second));
    if (second%5==0)
    {
        score=score-level;
        this->scoreItem->setPlainText("Score: " + QString::number(this->score));
    }
}

/**
 *\brief show function
 *
 * Shows the numbers on the screen.
 */
void gamemanager3::showNumbers()
{

    for (int i=1;i<step1+1;i++)
    {
       numberArray1[i].setPlainText(QString::number(branch1[i]));
       numberArray1[i].setDefaultTextColor(Qt::black);
       numberArray1[i].setPos(75,360-25*i+158);
       scene->addItem(&numberArray1[i]);
    }

    for (int i=1;i<step2+1;i++)
    {
       numberArray2[i].setPlainText(QString::number(branch2[i]));
       numberArray2[i].setDefaultTextColor(Qt::black);
       numberArray2[i].setPos(88+25*i,182+158);
       scene->addItem(&numberArray2[i]);
    }

    for (int i=1;i<step3+1;i++)
    {
       numberArray3[i].setPlainText(QString::number(branch3[i]));
       numberArray3[i].setDefaultTextColor(Qt::black);
       numberArray3[i].setPos(203+25*i,182+158);
       scene->addItem(&numberArray3[i]);
    }

    for (int i=1;i<step4+1;i++)
    {
       numberArray4[i].setPlainText(QString::number(branch4[i]));
       numberArray4[i].setDefaultTextColor(Qt::black);
       numberArray4[i].setPos(320+25*i,182+158);
       scene->addItem(&numberArray4[i]);
    }
}

/**
 *\brief fill function
 *
 * Fills the 4 arrays with numbers.
 * Takes operation to to fill with addition or multiplication.
 *\param operation
 */
void gamemanager3::fillArray(int op)
{
    operation=op;
    if (op==0)
        nextNumber = branch1[0] + branch1[1];
    else if (op==1)
        nextNumber = branch1[0] * branch1[1];

    for (int i=2;i<7+level;i++)
    {
        if (op ==0)
       branch1[i]=branch1[i-2]+branch1[i-1];
        else if (op ==1)
       branch1[i]=branch1[i-2]*branch1[i-1];
    }

    for (int i=2;i<5+level;i++)
    {
        if (op ==0)
       branch2[i]=branch2[i-2]+branch2[i-1];
        else if (op ==1)
       branch2[i]=branch2[i-2]*branch2[i-1];
    }

    for (int i=2;i<4+level;i++)
    {
        if (op ==0)
       branch3[i]=branch3[i-2]+branch3[i-1];
        else if (op ==1)
       branch3[i]=branch3[i-2]*branch3[i-1];
    }

    for (int i=2;i<4+level;i++)
    {
        if (op ==0)
       branch4[i]=branch4[i-2]+branch4[i-1];
        else if (op ==1)
       branch4[i]=branch4[i-2]*branch4[i-1];
    }
}
