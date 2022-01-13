#include "game.h"
void menu()
{
    printf("*****************************\n");
    printf("*********   1.paly   ********\n");
    printf("*********   0.exit   ********\n");
    printf("*****************************\n");
}
void game()
{
    // 存储雷的信息
    // 1.布置好的雷的信息
    char mine[ROWS][COLS] = {0};
    // 2.排查好的雷的信息
    char show[ROWS][COLS] = {0};
    // 初始化
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    // 打印棋盘
    // Displayboard(mine, ROW, COL);
    Displayboard(show, ROW, COL);
    // 布雷
    SetMine(mine, ROW, COL);
    // Displayboard(mine, ROW, COL);
    // 扫雷
    FindMine(mine, show, ROW, COL);
    // Displayboard(mine, ROW, COL);
}
void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    } while (input);
}
int main()
{
    test();
    return 0;
}