#include "game.h"

// 棋盘初始化函数的实现
void InitBoard(char board[ROW][COL], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// 棋盘打印函数的实现
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
        {
            // 1.打印一行数据
            printf(" %c ", board[i][j]);
            if (j < col - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        // 2.打印分割行
        if (i < row - 1)
        {
            for (j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}

// 玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("玩家走:>");
    while (1)
    {
        printf("请输入要下的坐标:>");
        scanf("%d%d", &x, &y);
        // 判断x,y的合法性
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("该坐标被占用!\n");
            }
        }
        else
        {
            printf("坐标合法,请重新输入!\n");
        }
    }
}

// 电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x, y;
    printf("电脑这样下:\n");
    while (1)
    {
        x = rand() % row;
        y = rand() % col;
        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

// 返回1 表示棋盘满了
// 返回0 表示棋盘没满
int IsFull(char board[ROW][COL], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0; // 没满
            }
        }
    }
    return 1;// 满了
}

// 告诉我们四种游戏状态
char IsWin(char board[ROW][COL], int row, int col)
{
    int i;
    // 横三行
    for (i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return board[i][1];
        }
    }
    // 竖三列
    for (i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
        {
            return board[1][i];
        }
    }
    // 对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    // 对角线
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }

    // 判断是否平局
    if (1 == IsFull(board, ROW, COL))
    {
        return 'p';
    }
    return 'c';
}