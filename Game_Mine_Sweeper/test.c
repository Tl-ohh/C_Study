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
    // �洢�׵���Ϣ
    // 1.���úõ��׵���Ϣ
    char mine[ROWS][COLS] = {0};
    // 2.�Ų�õ��׵���Ϣ
    char show[ROWS][COLS] = {0};
    // ��ʼ��
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    // ��ӡ����
    // Displayboard(mine, ROW, COL);
    Displayboard(show, ROW, COL);
    // ����
    SetMine(mine, ROW, COL);
    // Displayboard(mine, ROW, COL);
    // ɨ��
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
        printf("��ѡ��:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("�˳���Ϸ\n");
            break;
        default:
            printf("ѡ�����\n");
            break;
        }
    } while (input);
}
int main()
{
    test();
    return 0;
}