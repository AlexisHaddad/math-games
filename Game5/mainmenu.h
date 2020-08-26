#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>

class gamemanager5;

class mainmenu : public QWidget
{
    Q_OBJECT
public:
    explicit mainmenu(QWidget *parent = 0);
    mainmenu();
    mainmenu(gamemanager5 * game, QGraphicsView* view);
    QLabel * choose;
    QPushButton * addition;                ///<button "Addition"
    QPushButton * multiplication;          ///<button "Multiplication"
    QVBoxLayout * vBox;
    gamemanager5 * game;                   ///<gameManager class that it will use and edit
    QGraphicsView * view;
    int operation;                         ///<int to determine addition or multiplication

signals:

public slots:
    void chooseAdd();                       ///<function when choosing addition
    void chooseMult();                      ///<function when choosing addition

};

#endif // MAINMENU_H
