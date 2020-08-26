#include "square.h"
#include "gamemanager4.h"

/**
 *\file square.cpp
 *\brief source file for square.h
 */

/**
 *\brief default constructor
 */
Square::Square()
{
    image1.load("/home/EECE435/Game4/sblock.png");
    item = new QGraphicsPixmapItem(image1.scaled(QSize(60,60),  Qt::KeepAspectRatio));
    display = new QGraphicsTextItem();
    number = 0 ;
    game = new gamemanager4();
    character = "";
}

/**
 *\brief constructor of the Square class
 *
 * This constructor gets the image for the square and creates either
 * a number square or a character square.
 *\param game
 *\param n
 *\param a
 */
Square::Square(gamemanager4 * game,int n, QString a)
{
    image1.load("/home/EECE435/Game4/sblock.png");
    item = new QGraphicsPixmapItem(image1.scaled(QSize(60,60),  Qt::KeepAspectRatio));
    if (a == "")
    {
        number = n;
        character = QString::number(n);
    }
    else
    {
        number = 0;
        character = a;
    }
    this->game = game;
    display = new QGraphicsTextItem(character);
}

/**
 *\brief default destructor
 */
Square::~Square()
{

}

/**
 *\brief keyPressEvent of a squae
 *
 * In this function, the logic depends on which square the focus is set
 * If the square is a number square, 4 squares are created in the direction
 * chosen by the player and the form a random equation
 * If the square is an "=" square, then an adequate equation is created
 * and the blocks are placed differently than before.
 *\param event
 */
void Square::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Z)
    {
        //game->scene->removeItem(game->scene->items(Qt::SortOrder in));
    }
    if (game->answer == 1)
    {


        //------------------------------------------If the selected square is a NUMBER-------------------------------
        if (this->display->toPlainText() != "="
                && this->display->toPlainText() != "+"
                && this->display->toPlainText() != "-"
                && this->display->toPlainText() != "*"
                && this->display->toPlainText() != "/")
        {

            //-----------RIGHT----------------
            if (event->key() == Qt::Key_Right)
            {
                if (this->x() + 250 < 700)
                {
                    this->clearFocus();
                    game->answer = 0;
                    Square * box1 = new Square(game,0,"?");
                    box1->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box2 = new Square(game,rand()%(10 + game->level*5) + 1,"");
                    box2->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box3 = new Square(game,0,"=");
                    box3->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box4 = new Square(game,0,"");
                    box4->setFlag(QGraphicsItem :: ItemIsFocusable);
                    int temp = rand()%4 + 1;
                    if (temp == 1)
                    {
                        box1->character = "+";
                        box4->number = this->number + box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 2)
                    {
                        box1->character = "-";
                        box4->number = this->number - box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 3)
                    {
                        box1->character = "*";
                        box4->number = this->number * box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 4)
                    {
                        box1->character = "/";
                        box4->number = this->number / box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    box1->setRect(0,0,50,50);
                    box1->setPos(this->x() + 50, this->y());
                    box1->display->setPos(box1->x()+17,box1->y()+17);
                    box1->item->setPos(box1->pos());
                    game->scene->addItem(box1->item);
                    game->scene->addItem(box1);
                    game->scene->addItem(box1->display);

                    box2->setRect(0,0,50,50);
                    box2->setPos(this->x() + 100, this->y());
                    box2->display->setPos(box2->x()+17,box2->y()+17);
                    box2->item->setPos(box2->pos());
                    game->scene->addItem(box2->item);
                    game->scene->addItem(box2);
                    game->scene->addItem(box2->display);

                    box3->setRect(0,0,50,50);
                    box3->setPos(this->x() + 150, this->y());
                    box3->display->setPos(box3->x()+17,box3->y()+17);
                    box3->item->setPos(box3->pos());
                    game->scene->addItem(box3->item);
                    game->scene->addItem(box3);
                    game->scene->addItem(box3->display);

                    box4->setRect(0,0,50,50);
                    box4->setPos(this->x() + 200, this->y());
                    box4->display->setPos(box4->x()+17,box4->y()+17);
                    box4->item->setPos(box4->pos());
                    game->scene->addItem(box4->item);
                    game->scene->addItem(box4);
                    game->scene->addItem(box4->display);
                }
            }


            //-----------UP----------------
            else if (event->key() == Qt::Key_Up)
            {
                if (this->y() - 250 > 0)
                {
                    this->clearFocus();
                    game->answer = 0;
                    Square * box1 = new Square(game,0,"?");
                    box1->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box2 = new Square(game,rand()%(10 + (game->level)*5) + 1,"");
                    box2->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box3 = new Square(game,0,"=");
                    box3->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box4 = new Square(game,0,"");
                    box4->setFlag(QGraphicsItem :: ItemIsFocusable);
                    int temp = rand()%4 + 1;
                    if (temp == 1)
                    {
                        box1->character = "+";
                        box4->number = this->number + box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 2)
                    {
                        box1->character = "-";
                        box4->number = this->number - box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 3)
                    {
                        box1->character = "*";
                        box4->number = this->number * box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 4)
                    {
                        box1->character = "/";
                        box4->number = this->number / box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    box1->setRect(0,0,50,50);
                    box1->setPos(this->x(), this->y() - 50);
                    box1->display->setPos(box1->x()+17,box1->y()+17);
                    box1->item->setPos(box1->pos());
                    game->scene->addItem(box1->item);
                    game->scene->addItem(box1);
                    game->scene->addItem(box1->display);

                    box2->setRect(0,0,50,50);
                    box2->setPos(this->x(), this->y() - 100);
                    box2->display->setPos(box2->x()+17,box2->y()+17);
                    box2->item->setPos(box2->pos());
                    game->scene->addItem(box2->item);
                    game->scene->addItem(box2);
                    game->scene->addItem(box2->display);

                    box3->setRect(0,0,50,50);
                    box3->setPos(this->x(), this->y() - 150);
                    box3->display->setPos(box3->x()+17,box3->y()+17);
                    box3->item->setPos(box3->pos());
                    game->scene->addItem(box3->item);
                    game->scene->addItem(box3);
                    game->scene->addItem(box3->display);

                    box4->setRect(0,0,50,50);
                    box4->setPos(this->x(), this->y() - 200);
                    box4->display->setPos(box4->x()+17,box4->y()+17);
                    box4->item->setPos(box4->pos());
                    game->scene->addItem(box4->item);
                    game->scene->addItem(box4);
                    game->scene->addItem(box4->display);
                }
            }

            //-----------LEFT----------------
            else if (event->key() == Qt::Key_Left)
            {
                if (this->x() - 250 > 0)
                {
                    this->clearFocus();
                    game->answer = 0;
                    Square * box1 = new Square(game,0,"?");
                    box1->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box2 = new Square(game,rand()%(10 + game->level*5) + 1,"");
                    box2->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box3 = new Square(game,0,"=");
                    box3->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box4 = new Square(game,0,"");
                    box4->setFlag(QGraphicsItem :: ItemIsFocusable);
                    int temp = rand()%4 + 1;
                    if (temp == 1)
                    {
                        box1->character = "+";
                        box4->number = this->number + box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 2)
                    {
                        box1->character = "-";
                        box4->number = this->number - box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 3)
                    {
                        box1->character = "*";
                        box4->number = this->number * box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 4)
                    {
                        box1->character = "/";
                        box4->number = this->number / box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    box1->setRect(0,0,50,50);
                    box1->setPos(this->x() - 50, this->y());
                    box1->display->setPos(box1->x()+17,box1->y()+17);
                    box1->item->setPos(box1->pos());
                    game->scene->addItem(box1->item);
                    game->scene->addItem(box1);
                    game->scene->addItem(box1->display);

                    box2->setRect(0,0,50,50);
                    box2->setPos(this->x() - 100, this->y());
                    box2->display->setPos(box2->x()+17,box2->y()+17);
                    box2->item->setPos(box2->pos());
                    game->scene->addItem(box2->item);
                    game->scene->addItem(box2);
                    game->scene->addItem(box2->display);

                    box3->setRect(0,0,50,50);
                    box3->setPos(this->x() - 150, this->y());
                    box3->display->setPos(box3->x()+17,box3->y()+17);
                    box3->item->setPos(box3->pos());
                    game->scene->addItem(box3->item);
                    game->scene->addItem(box3);
                    game->scene->addItem(box3->display);

                    box4->setRect(0,0,50,50);
                    box4->setPos(this->x() - 200, this->y());
                    box4->display->setPos(box4->x()+17,box4->y()+17);
                    box4->item->setPos(box4->pos());
                    game->scene->addItem(box4->item);
                    game->scene->addItem(box4);
                    game->scene->addItem(box4->display);
                }
            }

            //-----------DOWN----------------
            else if (event->key() == Qt::Key_Down)
            {
                if (this->y() + 250 < 700)
                {
                    this->clearFocus();
                    game->answer = 0;
                    Square * box1 = new Square(game,0,"?");
                    box1->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box2 = new Square(game,rand()%(10 + game->level*5) + 1,"");
                    box2->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box3 = new Square(game,0,"=");
                    box3->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box4 = new Square(game,0,"");
                    box4->setFlag(QGraphicsItem :: ItemIsFocusable);
                    int temp = rand()%4 + 1;
                    if (temp == 1)
                    {
                        box1->character = "+";
                        box4->number = this->number + box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 2)
                    {
                        box1->character = "-";
                        box4->number = this->number - box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 3)
                    {
                        box1->character = "*";
                        box4->number = this->number * box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 4)
                    {
                        box1->character = "/";
                        box4->number = this->number / box2->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    box1->setRect(0,0,50,50);
                    box1->setPos(this->x(), this->y() + 50);
                    box1->display->setPos(box1->x()+17,box1->y()+17);
                    box1->item->setPos(box1->pos());
                    game->scene->addItem(box1->item);
                    game->scene->addItem(box1);
                    game->scene->addItem(box1->display);

                    box2->setRect(0,0,50,50);
                    box2->setPos(this->x(), this->y() + 100);
                    box2->display->setPos(box2->x()+17,box2->y()+17);
                    box2->item->setPos(box2->pos());
                    game->scene->addItem(box2->item);
                    game->scene->addItem(box2);
                    game->scene->addItem(box2->display);

                    box3->setRect(0,0,50,50);
                    box3->setPos(this->x(), this->y() + 150);
                    box3->display->setPos(box3->x()+17,box3->y()+17);
                    box3->item->setPos(box3->pos());
                    game->scene->addItem(box3->item);
                    game->scene->addItem(box3);
                    game->scene->addItem(box3->display);

                    box4->setRect(0,0,50,50);
                    box4->setPos(this->x(), this->y() + 200);
                    box4->display->setPos(box4->x()+17,box4->y()+17);
                    box4->item->setPos(box4->pos());
                    game->scene->addItem(box4->item);
                    game->scene->addItem(box4);
                    game->scene->addItem(box4->display);
                }
            }
        }

        //-------------------------------------if the square selected is =-----------------------------------------
        else if (this->display->toPlainText() == "=")
        {

            //-----------RIGHT----------------
            if (event->key() == Qt::Key_Right)
            {
                if (this->x() - 200 > 0)
                {
                    this->clearFocus();
                    game->answer = 0;
                    Square * box1 = new Square(game,rand()%(10 + game->level*5) + 1,"");
                    box1->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box2 = new Square(game,0,"?");
                    box2->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box3 = new Square(game,rand()%(10 + game->level*5) + 1,"");
                    box3->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box4 = new Square(game,0,"");
                    box4->setFlag(QGraphicsItem :: ItemIsFocusable);
                    int temp = rand()%4 + 1;
                    if (temp == 1)
                    {
                        box2->character = "+";
                        box4->number = box1->number + box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 2)
                    {
                        box2->character = "-";
                        box4->number = box1->number - box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 3)
                    {
                        box2->character = "*";
                        box4->number = box1->number * box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 4)
                    {
                        box2->character = "/";
                        box4->number = box1->number / box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    box1->setRect(0,0,50,50);
                    box1->setPos(this->x() - 150, this->y());
                    box1->display->setPos(box1->x()+17,box1->y()+17);
                    box1->item->setPos(box1->pos());
                    game->scene->addItem(box1->item);
                    game->scene->addItem(box1);
                    game->scene->addItem(box1->display);

                    box2->setRect(0,0,50,50);
                    box2->setPos(this->x() - 100, this->y());
                    box2->display->setPos(box2->x()+17,box2->y()+17);
                    box2->item->setPos(box2->pos());
                    game->scene->addItem(box2->item);
                    game->scene->addItem(box2);
                    game->scene->addItem(box2->display);

                    box3->setRect(0,0,50,50);
                    box3->setPos(this->x() - 50, this->y());
                    box3->display->setPos(box3->x()+17,box3->y()+17);
                    box3->item->setPos(box3->pos());
                    game->scene->addItem(box3->item);
                    game->scene->addItem(box3);
                    game->scene->addItem(box3->display);

                    box4->setRect(0,0,50,50);
                    box4->setPos(this->x() + 50, this->y());
                    box4->display->setPos(box4->x()+17,box4->y()+17);
                    box4->item->setPos(box1->pos());
                    game->scene->addItem(box4->item);
                    game->scene->addItem(box4);
                    game->scene->addItem(box4->display);
                }
            }

            //-----------UP----------------
            else if (event->key() == Qt::Key_Up)
            {
                if (this->y() + 200 < 700)
                {
                    this->clearFocus();
                    game->answer = 0;
                    Square * box1 = new Square(game,rand()%(10 + game->level*5) + 1,"");
                    box1->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box2 = new Square(game,0,"?");
                    box2->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box3 = new Square(game,rand()%(10 + game->level*5) + 1,"");
                    box3->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box4 = new Square(game,0,"");
                    box4->setFlag(QGraphicsItem :: ItemIsFocusable);
                    int temp = rand()%4 + 1;
                    if (temp == 1)
                    {
                        box2->character = "+";
                        box4->number = box1->number + box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 2)
                    {
                        box2->character = "-";
                        box4->number = box1->number - box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 3)
                    {
                        box2->character = "*";
                        box4->number = box1->number * box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 4)
                    {
                        box2->character = "/";
                        box4->number = box1->number / box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    box1->setRect(0,0,50,50);
                    box1->setPos(this->x(), this->y() + 150);
                    box1->display->setPos(box1->x()+17,box1->y()+17);
                    box1->item->setPos(box1->pos());
                    game->scene->addItem(box1->item);
                    game->scene->addItem(box1);
                    game->scene->addItem(box1->display);

                    box2->setRect(0,0,50,50);
                    box2->setPos(this->x(), this->y() + 100);
                    box2->display->setPos(box2->x()+17,box2->y()+17);
                    box2->item->setPos(box2->pos());
                    game->scene->addItem(box2->item);
                    game->scene->addItem(box2);
                    game->scene->addItem(box2->display);

                    box3->setRect(0,0,50,50);
                    box3->setPos(this->x(), this->y() + 50);
                    box3->display->setPos(box3->x()+17,box3->y()+17);
                    box3->item->setPos(box3->pos());
                    game->scene->addItem(box3->item);
                    game->scene->addItem(box3);
                    game->scene->addItem(box3->display);

                    box4->setRect(0,0,50,50);
                    box4->setPos(this->x(), this->y() - 50);
                    box4->display->setPos(box4->x()+17,box4->y()+17);
                    box4->item->setPos(box4->pos());
                    game->scene->addItem(box4->item);
                    game->scene->addItem(box4);
                    game->scene->addItem(box4->display);
                }
            }

            //-----------LEFT----------------
            else if (event->key() == Qt::Key_Left)
            {
                if (this->x() + 200 < 700)
                {
                    this->clearFocus();
                    game->answer = 0;
                    Square * box1 = new Square(game,rand()%(10 + game->level*5) + 1,"");
                    box1->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box2 = new Square(game,0,"?");
                    box2->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box3 = new Square(game,rand()%(10 + game->level*5) + 1,"");
                    box3->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box4 = new Square(game,0,"");
                    box4->setFlag(QGraphicsItem :: ItemIsFocusable);
                    int temp = rand()%4 + 1;
                    if (temp == 1)
                    {
                        box2->character = "+";
                        box4->number = box1->number + box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 2)
                    {
                        box2->character = "-";
                        box4->number = box1->number - box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 3)
                    {
                        box2->character = "*";
                        box4->number = box1->number * box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 4)
                    {
                        box2->character = "/";
                        box4->number = box1->number / box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    box1->setRect(0,0,50,50);
                    box1->setPos(this->x() + 150, this->y());
                    box1->display->setPos(box1->x()+17,box1->y()+17);
                    box1->item->setPos(box1->pos());
                    game->scene->addItem(box1->item);
                    game->scene->addItem(box1);
                    game->scene->addItem(box1->display);

                    box2->setRect(0,0,50,50);
                    box2->setPos(this->x() + 100, this->y());
                    box2->display->setPos(box2->x()+17,box2->y()+17);
                    box2->item->setPos(box2->pos());
                    game->scene->addItem(box2->item);
                    game->scene->addItem(box2);
                    game->scene->addItem(box2->display);

                    box3->setRect(0,0,50,50);
                    box3->setPos(this->x() + 50, this->y());
                    box3->display->setPos(box3->x()+17,box3->y()+17);
                    box3->item->setPos(box3->pos());
                    game->scene->addItem(box3->item);
                    game->scene->addItem(box3);
                    game->scene->addItem(box3->display);

                    box4->setRect(0,0,50,50);
                    box4->setPos(this->x() - 50, this->y());
                    box4->display->setPos(box4->x()+17,box4->y()+17);
                    box4->item->setPos(box1->pos());
                    game->scene->addItem(box4->item);
                    game->scene->addItem(box4);
                    game->scene->addItem(box4->display);
                }
            }

            //-----------DOWN----------------
            else if (event->key() == Qt::Key_Down)
            {
                if (this->y() - 200 > 0)
                {
                    this->clearFocus();
                    game->answer = 0;
                    Square * box1 = new Square(game,rand()%(10 + game->level*5) + 1,"");
                    box1->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box2 = new Square(game,0,"?");
                    box2->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box3 = new Square(game,rand()%(10 + game->level*5) + 1,"");
                    box3->setFlag(QGraphicsItem :: ItemIsFocusable);
                    Square * box4 = new Square(game,0,"");
                    box4->setFlag(QGraphicsItem :: ItemIsFocusable);
                    int temp = rand()%4 + 1;
                    if (temp == 1)
                    {
                        box2->character = "+";
                        box4->number = box1->number + box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 2)
                    {
                        box2->character = "-";
                        box4->number = box1->number - box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 3)
                    {
                        box2->character = "*";
                        box4->number = box1->number * box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    else if (temp == 4)
                    {
                        box2->character = "/";
                        box4->number = box1->number / box3->number;
                        box4->display->setPlainText(QString::number(box4->number));
                    }
                    box1->setRect(0,0,50,50);
                    box1->setPos(this->x(), this->y() - 150);
                    box1->display->setPos(box1->x()+17,box1->y()+17);
                    box1->item->setPos(box1->pos());
                    game->scene->addItem(box1->item);
                    game->scene->addItem(box1);
                    game->scene->addItem(box1->display);

                    box2->setRect(0,0,50,50);
                    box2->setPos(this->x(), this->y() - 100);
                    box2->display->setPos(box2->x()+17,box2->y()+17);
                    box2->item->setPos(box2->pos());
                    game->scene->addItem(box2->item);
                    game->scene->addItem(box2);
                    game->scene->addItem(box2->display);

                    box3->setRect(0,0,50,50);
                    box3->setPos(this->x(), this->y() - 50);
                    box3->display->setPos(box3->x()+17,box3->y()+17);
                    box3->item->setPos(box3->pos());
                    game->scene->addItem(box3->item);
                    game->scene->addItem(box3);
                    game->scene->addItem(box3->display);

                    box4->setRect(0,0,50,50);
                    box4->setPos(this->x(), this->y() + 50);
                    box4->display->setPos(box4->x()+17,box4->y()+17);
                    box4->item->setPos(box4->pos());
                    game->scene->addItem(box4->item);
                    game->scene->addItem(box4);
                    game->scene->addItem(box4->display);
                }
            }
        }
    }
    else
    {
        if (event->key() == Qt::Key_Plus ||
                event->key() == Qt::Key_Minus ||
                event->key() == Qt::Key_Slash ||
                event->key() == Qt::Key_Asterisk)
        {
            if (character == event->text())
            {
                display->setPlainText(character);
                game->answer = 1;
            }
            else
            {

            }

        }
    }
}
