#include "cmdtxt.h"
#include <Windows.h>

int main()
{
    //cursor_show(); probar
    //cursor_hide();
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        Sleep(500);
        cursor_right_reset(20);
    }
    
    return 0;
}