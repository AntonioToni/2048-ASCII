#include "header.hpp"

int main()
{
    ShowConsoleCursor(false);
    srand(time(0));
    Board b;
    b.zero();
    b.generate();
    b.generate();
    char ch = 0;
    while (b.checkingame())
    {
        b.print();
        ch = getch();
        if(b.checkmovepossible(ch))
        {
            if (ch == 'a')
            {
                b.moveleft();
            }
            else if (ch == 'w')
            {
                b.moveup();
            }
            else if (ch == 's')
            {
                b.movedown();
            }
            else if (ch == 'd')
            {
                b.moveright();
            }
            if (ch == 'a' || ch == 's' || ch == 'w' || ch == 'd')
            {
                b.generate();
            }
        }
        if (b.checkwinlose())
        {
            b.print();
            if (b.winscreen()==false)
            {
                break;
            }
        }
    }
    b.print();
    b.losescreen();
    system("pause");
}