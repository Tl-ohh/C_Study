#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���̳�ʼ������������
void InitBoard(char board[ROW][COL], int row, int col);

// ���̴�ӡ����������
void DisplayBoard(char board[ROW][COL], int row, int col);

// ������庯��������
void PlayerMove(char board[ROW][COL], int row, int col);

// �������庯��������
void ComputerMove(char board[ROW][COL], int row, int col);

// ��������������Ϸ״̬
// 1.���Ӯ '*'
// 2.����Ӯ '#'
// 3.ƽ��   'p'
// 4.����   'c'
char IsWin(char board[ROW][COL], int row, int col);
