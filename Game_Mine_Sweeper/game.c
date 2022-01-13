#include "game.h"

// ��ʼ����ʵ��
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

// ��ӡ����
void Displayboard(char board[ROWS][COLS], int row, int col)
{
    int i, j;
    // ��ӡ�к�
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

// ����
void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        // ���������������
        int x = rand() % row + 1; // 1-9
        int y = rand() % col + 1; // 1-9
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

// �ַ�1��ȥ�ַ�0��������1,�����ַ�Ҳ��һ��
// ��ȡ�׵ĸ���
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
// ɨ��
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    while (win < row * col - EASY_COUNT)
    {
        printf("���������Ų��׵�����:>");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
        {
            // ����
            if (mine[x][y] == '1')
            {
                printf("���ź�,�㱻ըʺ��!!!\n");
                Displayboard(mine, row, col);
                break;
            }
            // ������
            else
            {
                // ����x,y������Χ�м�����
                int count = get_mine_count(mine, x, y);
                show[x][y] = count + '0';
                Displayboard(show, row, col);
                win++;
            }
        }
        else
        {
            printf("���������Ƿ�,������Ϸ�����!\n");
        }
    }
    if (win == row * col - EASY_COUNT)
    {
        printf("��ϲ��,���׳ɹ�! �����ǵ��׷ֲ�!\n");
        Displayboard(mine, row, col);
    }
}