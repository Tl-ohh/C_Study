#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 棋盘初始化函数的声明
void InitBoard(char board[ROW][COL], int row, int col);

// 棋盘打印函数的声明
void DisplayBoard(char board[ROW][COL], int row, int col);

// 玩家下棋函数的声明
void PlayerMove(char board[ROW][COL], int row, int col);

// 电脑下棋函数的声明
void ComputerMove(char board[ROW][COL], int row, int col);

// 告诉我们四种游戏状态
// 1.玩家赢 '*'
// 2.电脑赢 '#'
// 3.平局   'p'
// 4.继续   'c'
char IsWin(char board[ROW][COL], int row, int col);
