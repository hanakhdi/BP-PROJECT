#include <stdio.h>  
#include <stdlib.h>  
#include <windows.h>  
#include <conio.h>  
int coin=0;
void moveCharacter(int *i, int *j, char board[][64], int newI, int newJ) {  
 
    if (board[newI][newJ] == ' '|| board[newI][newJ] == '3') {
        if(board[newI][newJ] == '3')
            coin++;
        board[*i][*j] = ' '; 
        *i = newI; 
        *j = newJ;   
        board[*i][*j] = '$'; 
    }
    
}  
void jump(int *i,int *j,char board[][64]){
    
}

void printBoard(char board[][64])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            switch (board[i][j])
            {
            case '1':
                printf("🧱");
                break;
            case '2':
                printf("🟩");
                break;
            case '3':
                printf("📀");
                break;
            case '4':
                printf("🟫");
                break;
            case '5':
                printf("🐙");
                break;
            case '6':
                printf("🦖");
                break;
            case '7':
                printf("🌱");
                break;
            case '8':
                printf("🟧");
                break;
            case '9':
                printf("🚩");
                break;
            case '!':
                printf("🟨");
                break;
            case '$':
                printf("👻");
                break;
            case ' ':
                printf("  ");
                break;
            case '*':
                printf("🛡️");
                break;
            case '@':
                printf("🟦");
                break;
            case '&':
                printf("🟨");
                break;
            case '^':
                printf("🍄");
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
}  

void map1() {  
    SetConsoleOutputCP(CP_UTF8);  
    DWORD bytes_written;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);  

    char board[15][64] = {  
        "1111111111111111111111111111111111111111111111111111111111111111",  
        "1                       22                                     1",  
        "1                       22                                     1",  
        "1                      2222                                    1",  
        "1                 9         33              7                  1",  
        "1                111        111           4444                 1",  
        "1                      111                 44                  1",  
        "1                                     4444 44                  1",  
        "1                                      44  44                  1",  
        "1   11133                          7   44  44                  1",  
        "1      11!1                       4444 44  44     1881         1",  
        "1          111                     44  44  44     1  1    2222 1",  
        "1                            4444  44  44  44     1  1     22  1",  
        "1 $             33       5    44 6 446 446 446    1        22  1",  
        "1111111111111111111111111111111111111111111111111111111111111111"  
    };  

    int catX = 2;
    int catY = 12;  

    while (1) {  
        COORD origin = {0, 1};  
        SetConsoleCursorPosition(hStdout, origin);  
        printBoard(board);

        if (_kbhit()) { 
            char ch = _getch(); 
            if (ch == 'w' && catY > 0) moveCharacter(&catY, &catX, board, catY - 1, catX); // بالا  
            else if (ch == 's' && catY < 14) moveCharacter(&catY, &catX, board, catY + 1, catX); // پایین  
            else if (ch == 'a' && catX > 0) moveCharacter(&catY, &catX, board, catY, catX - 1); // چپ  
            else if (ch == 'd' && catX < 63) moveCharacter(&catY, &catX, board, catY, catX + 1); // راست  
        }  
    }  
}  

int main() {  
    SetConsoleOutputCP(CP_UTF8);  
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
    CONSOLE_CURSOR_INFO cursorInfo;  
    cursorInfo.dwSize = 100;  
    cursorInfo.bVisible = FALSE;  
    SetConsoleCursorInfo(hConsole, &cursorInfo);  
    map1();  
    return 0;  
}