#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QGraphicsScene>

class gamemanager3;

class mainmenu : public QWidget
{
    Q_OBJECT
public:
    explicit mainmenu(QWidget *parent = 0);
    mainmenu();
    mainmenu(gamemanager3 * game);
    QLabel * choose;
    QPushButton * addition;                ///<button "Addition"
    QPushButton * multiplication;          ///<button "Multiplication"
    QVBoxLayout * vBox;
    gamemanager3 * game;                   ///<gameManager class that it will use and edit
    int operation;                         ///<int to determine addition or multiplication
    
signals:
    
public slots:
    void chooseAdd();                       ///<function when choosing addition
    void chooseMult();                      ///<function when choosing addition
    
};

#endif // MAINMENU_H
