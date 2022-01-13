#include "game.h"

// 初始化的实现
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

// 打印棋盘
void Displayboard(char board[ROWS][COLS], int row, int col)
{
    int i, j;
    // 打印列号
    for (i = 0; i <= col; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i);
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// 布雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        // 布雷生成随机坐标
        int x = rand() % row + 1; // 1-9
        int y = rand() % col + 1; // 1-9
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

// 字符1减去字符0就是数字1,其他字符也是一样
// 获取雷的个数
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    return mine[x - 1][y] +
           mine[x - 1][y - 1] +
           mine[x][y - 1] +
           mine[x + 1][y - 1] +
           mine[x + 1][y] +
           mine[x + 1][y + 1] +
           mine[x][y + 1] +
           mine[x - 1][y + 1] - 8 * '0';
}
// 扫雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    while (win < row * col - EASY_COUNT)
    {
        printf("请输入所排查雷的坐标:>");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
        {
            // 是雷
            if (mine[x][y] == '1')
            {
                printf("很遗憾,你被炸屎了!!!\n");
                Displayboard(mine, row, col);
                break;
            }
            // 不是雷
            else
            {
                // 计算x,y坐标周围有几个雷
                int count = get_mine_count(mine, x, y);
                show[x][y] = count + '0';
                Displayboard(show, row, col);
                win++;
            }
        }
        else
        {
            printf("输入的坐标非法,请输入合法坐标!\n");
        }
    }
    if (win == row * col - EASY_COUNT)
    {
        printf("恭喜你,排雷成功! 下面是地雷分布!\n");
        Displayboard(mine, row, col);
    }
}