#include "game.h"
void menu()
{
    printf("*******************************\n");
    printf("*******1.play        0.exit****\n");
    printf("*******************************\n");
}
void game()
{
    char ret = 0;
    // 数组-存放走出的棋盘信息
    char board[ROW][COL] = {0};
    //初始化棋盘
    InitBoard(board, ROW, COL);
    // 打印棋盘
    DisplayBoard(board, ROW, COL);
    // 下棋
    while (1)
    {
        // 玩家下棋
        PlayerMove(board, ROW, COL);
        // 打印棋盘
        DisplayBoard(board, ROW, COL);
        // 判断玩家是否赢了
        ret = IsWin(board, ROW, COL);
        if (ret != 'c')
        {
            break;
        }
        // 电脑下棋
        ComputerMove(board, ROW, COL);
        // 打印棋盘
        DisplayBoard(board, ROW, COL);
        // 判断电脑是否赢了
        ret = IsWin(board, ROW, COL);
        if (ret != 'c')
        {
            break;
        }
    }
    if (ret == '*')
    {
        printf("玩家赢了\n");
    }
    else if (ret == '#')
    {
        printf("电脑赢了\n");
    }
    else
    {
        printf("平局\n");
    }
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
            printf("退出游戏");
            break;
        default:
            printf("选择错误，请重新选择");
            break;
        }
    } while (input);
}
int main()
{
    test();
    return 0;
}