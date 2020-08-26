#include "sbox.h"
//#include "gamemanager5.h"

sbox::sbox()
{
    move = 0;
}

void sbox::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_A)
        {
            move = 1;
        }
    else if (event->key() == Qt::Key_B)
    {
        move = 2;
    }
}
