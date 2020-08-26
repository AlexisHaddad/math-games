#include "sframe.h"
#include "gamemanager3.h";
#include "nextwindow.h"
#include "restartwindow.h"

/**
 *\file sframe.cpp
 *\brief source file for sframe.h
 */


/**
 *\brief default constructor for the sframe class
 *
 * It instantiates all the components of the class.
 * It takes all the game information from gamemanager3
 */
sframe::sframe(gamemanager3 *game)
{
    this->game = game;
}

/**
 *\brief keyPressEvent function of the sframe
 *
 * This function is what makes the sframe move after checking the answer.
 * It is used whenever a number is pressed or the Enter, Right Arrow or Backslash keys.
 * The sframe is set to focus in the main function so that it can work.
 * The parameter "event" detects key presses. So we use if statements
 * to implement the logic of the movement of the sframe.
 *
 *\param event
 */
void sframe::keyPressEvent(QKeyEvent * event)
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
            game->temp = game->temp + event->text();
            game->inputTextItem->setPlainText(game->inputTextItem->toPlainText()+event->text());
    }
    else if (event->key()==Qt::Key_Return)
    {
        game->inputNumber=game->temp.toInt();
        game->inputTextItem->setPlainText(game->inputTextItem->toPlainText());
        game->temp="";
        if (game->inputNumber==game->nextNumber)
        {
            if (game->stage == 1)
            {
                if (game->step1<6+game->level)
                {
                    game->score = game->score+(game->step1)*(game->level);
                    game->scoreItem->setPlainText("Score: " + QString::number(game->score));
                    game->step1++;
                    game->nextNumber=game->branch1[game->step1+1];
                    this->setPos(this->x(),this->y()-39);
                    game->itemframe->setPos(game->itemframe->x(),game->itemframe->y()-39);
                    game->numberArray1[game->step1].setPlainText(QString::number(game->branch1[game->step1]));
                    game->numberArray1[game->step1].setDefaultTextColor(Qt::black);
                    game->numberArray1[game->step1].setPos(this->pos());
                    game->scene->addItem(&game->numberArray1[game->step1]);
                    if (game->step1==6+game->level)
                    {
                        game->gameTimer->stop();
                        if (game->second<=(30+game->level*30+game->operation*30))
                        {game->nextWindow1 = new nextwindow(game,this);
                        game->nextWindow1->show();}
                        else
                        {game->restartWindow1 = new restartwindow(game,this);
                        game->restartWindow1->show();}
                    }
                }
            }
            if (game->stage == 2)
            {
                if (game->step2<4+game->level)
                {
                    game->score = game->score+game->step2*(game->level);
                    game->scoreItem->setPlainText("Score: " + QString::number(game->score));
                    game->step2++;
                    game->nextNumber=game->branch2[game->step2+1];
                    if (game->step2<4)
                    {
                        this->setPos(this->x()+38,this->y());
                        game->itemframe->setPos(game->itemframe->x()+38,game->itemframe->y());
                    }
                    else
                    {
                        this->setPos(this->x(),this->y()-39);
                        game->itemframe->setPos(game->itemframe->x(),game->itemframe->y()-39);
                    }
                    game->numberArray2[game->step2].setPlainText(QString::number(game->branch2[game->step2]));
                    game->numberArray2[game->step2].setDefaultTextColor(Qt::black);
                    game->numberArray2[game->step2].setPos(this->pos());
                    game->scene->addItem(&game->numberArray2[game->step2]);
                    if (game->step2==4+game->level)
                      {
                        game->gameTimer->stop();
                        if (game->second<=(30+30*game->level+game->operation*30))
                        {game->nextWindow1 = new nextwindow(game,this);
                        game->nextWindow1->show();}
                        else
                        {game->restartWindow1 = new restartwindow(game,this);
                        game->restartWindow1->show();}
                    }
                }
            }
            if (game->stage == 3)
            {
                if (game->step3<3+game->level)
                {
                    game->score = game->score+game->step3*(game->level);
                    game->scoreItem->setPlainText("Score: " + QString::number(game->score));
                    game->step3++;
                    game->nextNumber=game->branch3[game->step3+1];
                    if (game->step3<4)
                    {
                        this->setPos(this->x()+38,this->y());
                        game->itemframe->setPos(game->itemframe->x()+38,game->itemframe->y());
                    }
                    else
                    {
                         this->setPos(this->x(),this->y()-39);
                         game->itemframe->setPos(game->itemframe->x(),game->itemframe->y()-39);
                    }
                    game->numberArray3[game->step3].setPlainText(QString::number(game->branch3[game->step3]));
                    game->numberArray3[game->step3].setDefaultTextColor(Qt::black);
                    game->numberArray3[game->step3].setPos(this->pos());
                    game->scene->addItem(&game->numberArray3[game->step3]);
                    if (game->step3==3+game->level)
                       {
                        game->gameTimer->stop();
                        if (game->second<=(30+30*game->level+game->operation*30))
                        {game->nextWindow1 = new nextwindow(game,this);
                        game->nextWindow1->show();}
                        else
                        {
                            game->restartWindow1 = new restartwindow(game,this);
                            game->restartWindow1->show();
                        }
                    }
                }
            }
            if (game->stage == 4)
            {
                if (game->step4<3+game->level)
                {
                    game->score = game->score+game->step4*(game->level);
                    game->scoreItem->setPlainText("Score: " + QString::number(game->score));
                    game->step4++;
                    game->nextNumber=game->branch4[game->step4+1];
                    if (game->step4<4)
                    {
                        this->setPos(this->x()+38,this->y());
                        game->itemframe->setPos(game->itemframe->x()+38,game->itemframe->y());
                    }
                    else
                    {
                        this->setPos(this->x(),this->y()-39);
                        game->itemframe->setPos(game->itemframe->x(),game->itemframe->y()-39);
                    }
                    game->numberArray4[game->step4].setPlainText(QString::number(game->branch4[game->step4]));
                    game->numberArray4[game->step4].setDefaultTextColor(Qt::black);
                    game->numberArray4[game->step4].setPos(this->pos());
                    game->scene->addItem(&game->numberArray4[game->step4]);
                    if (game->step4==3+game->level)
                    {
                        game->gameTimer->stop();
                        if (game->second<=(30+30*game->level+game->operation*30))
                        {game->nextWindow1 = new nextwindow(game,this);
                        game->nextWindow1->show();}
                        else
                        {
                            game->restartWindow1 = new restartwindow(game,this);
                            game->restartWindow1->show();
                        }
                    }
                }
            }
        }
        else
        {
            if (game->stage == 1)
            {
                if (game->step1>1 && game->step1<6+game->level)
                {
                    game->score = game->score-game->step1*(game->level);
                    game->scoreItem->setPlainText("Score: " + QString::number(game->score));
                    this->setPos(75,497);
                    game->itemframe->setPos(51,474);
                    game->nextNumber=game->branch1[2];
                    for (int i=2;i<game->step1+1;i++)
                    {
                       game->scene->removeItem(&game->numberArray1[i]);
                    }
                    game->step1=1;
                }
            }
            if (game->stage == 2)
            {
                if (game->step2>1 && game->step2<4+game->level)
                {
                    game->score = game->score-game->step2*(game->level);
                    game->scoreItem->setPlainText("Score: " + QString::number(game->score));
                    this->setPos(88+25,340);
                    game->itemframe->setPos(90,320);
                    game->nextNumber=game->branch2[2];
                    for (int i=2;i<game->step2+1;i++)
                    {
                       game->scene->removeItem(&game->numberArray2[i]);
                    }
                    game->step2=1;
                }
            }
            if (game->stage == 3)
            {
                if (game->step3>1 && game->step3<3+game->level)
                {
                    game->score = game->score-game->step3*(game->level);
                    game->scoreItem->setPlainText("Score: " + QString::number(game->score));
                    this->setPos(203+25,340);
                    game->itemframe->setPos(205,320);
                    game->nextNumber=game->branch3[2];
                    for (int i=2;i<game->step3+1;i++)
                    {
                       game->scene->removeItem(&game->numberArray3[i]);
                    }
                    game->step3=1;
                }
            }
            if (game->stage == 4)
            {
                if (game->step4>1 && game->step4<3+game->level)
                {
                    game->score = game->score-game->step4*(game->level);
                    game->scoreItem->setPlainText("Score: " + QString::number(game->score));
                    this->setPos(320+25,340);
                    game->itemframe->setPos(320,320);
                    game->nextNumber=game->branch4[2];
                    for (int i=2;i<game->step4+1;i++)
                    {
                       game->scene->removeItem(&game->numberArray4[i]);
                    }
                    game->step4=1;
                }
            }
        }
    }
    else if (event->key()==Qt::Key_Right)
    {
        if (game->stage == 1 && game->step1 ==5)
        {
            game->stage++;
            game->nextNumber=game->branch2[2];
            this->setPos(this->x()+38,this->y());
            game->itemframe->setPos(game->itemframe->x()+38,game->itemframe->y());
        }

       else if  ((game->stage==2) && (game->step2==3))
        {
            game->stage++;
            game->nextNumber=game->branch3[2];
            this->setPos(this->x()+38,this->y());
            game->itemframe->setPos(game->itemframe->x()+38,game->itemframe->y());
        }

        else if  ((game->stage==3) && (game->step3==3))
        {
            game->stage++;
            game->nextNumber=game->branch4[2];
            this->setPos(this->x()+38,this->y());
            game->itemframe->setPos(game->itemframe->x()+38,game->itemframe->y());
        }
    }
    else if (event->key()==Qt::Key_Backspace)
    {
        game->temp="";
    }
    game->inputTextItem->setPlainText(game->temp);
}
