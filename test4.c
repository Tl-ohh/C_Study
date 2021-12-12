#include<stdio.h>
#include <string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>

//头文件函数定义
// #ifndef __TEST_H__
// #define __TEST_H__
// 函数的声明，如：
// int Add(int x, int y);
// #endif

// 汉诺塔问题
// void move(int n,char x,char y,char z) {
//     // n代表盘子数，x是起始位置，y是中转位置
//     // z是目的位置
//     if (n==1) {
//         printf("%c--->%c\n",x,z);
//     }else {
//         move(n-1,x,z,y);
//         printf("%c--->%c\n",x,z);
//         move(n-1,y,x,z);
//     }
// }
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     move(n,'X','Y','Z');
//     return 0;
// }

// 青蛙跳台阶
// int Frog(int n){
// 	if (n <= 2 && n >= 0)
// 	{
// 		return n;
// 	}
// 	else if (n < 0)
// 	{
// 		printf("您的输入错误\n");
// 		return n;
// 	}else
// 	{
// 		return Frog(n - 1) + Frog(n - 2);
// 	}
// }
// int main(){
// 		int n;
// 		printf("请输入有几级台阶:\n");
// 		scanf("%d", &n);
// 		int result = Frog(n);
// 		if(n >= 0){ 
// 			printf("青蛙有%d种跳法\n", result);
// 		}
// 		system("pause");
// 		return 0;
// }

// int main(){
//     char arr[] = "abc"; // a,b,c,\0
//     char arr1[] = {'a','b','c'}; // a,b,c
//     printf("%d\n",sizeof(arr)); // 4
//     printf("%d\n",sizeof(arr1)); // 3
//     // sizeof 计算变量、数组、类型、的所占内存的空间大小，
//     // 单位是字节，是操作符
//     printf("%d\n",strlen(arr)); // 3
//     printf("%d\n",strlen(arr1)); // 大于3的随机数
//     // strlen 是求字符串长度，只能针对字符串，
//     // 是库函数，得引入头文件
//     return 0;
// }

// <------数组在内存中是连续存放的---->
// int main(){
//     int arr[2][2] = {{1,2},{2,3}};
//     int i = 0;
//     for(i = 0; i < 2 ; i++){
//         int j;
//         for(j = 0; j<2;j++){
//             printf("&arr[%d][%d] = %p\n",i,j,&arr[i][j]);
//         }
//     }
//     return 0;
// }

// 数组实现冒泡排序
// void bubble_sort(int arr[],int sz){
//     int i;
//     for(i = 0;i<sz-1;i++){
//         int j = 0;
//         int flag = 1;// 假定已经有序
//         for(j = 0; j <sz-i-1;j++){
//             if(arr[j] > arr[j+1]){
//                 int tmp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = tmp;
//                 flag = 0; // 这次乱序
//             }
//         }
//         if(flag == 1){
//             break;
//         }
//     }
// }
// int main(){
//     int arr[] = {3,1,2,9,4,5,6,0,8,7};
//     int sz= sizeof(arr)/sizeof(arr[0]);
//     bubble_sort(arr,sz);
//     for(int i=0; i<sz;i++){
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }

// 数组名
// int main(){
//     int arr[] = {0,1,2,3,4,5,6,7,8,9};

//     // <----通常数组名就是首元素地址，有2个例外----->
//     // printf("%p\n",arr); // 0061FEF8
//     // printf("%p\n",&arr[0]); // 0061FEF8
//     // printf("%d\n",*arr); // 0

//     // 例外1
//     // int sz = sizeof(arr)/sizeof(arr[0]);
//     // sizeof(数组名)，数组名表示整个数组，
//     // sizeof(数组名)计算的是整个数组的大小

//     // 例外2
//     printf("%p\n",arr); // 0061FEF8 -> 首元素地址
//     printf("%p\n",arr+1); // 0061FEFC -> 首元素地址

//     printf("%p\n",&arr[0]); // 0061FEF8 -> 首元素地址
//     printf("%p\n",&arr[0]+1); // 0061FEFC -> 首元素地址

//     printf("%p\n",&arr); // 0061FEF8 -> 整个数组的地址
//     printf("%p\n",&arr+1); // 0061FF20 -> 整个数组的地址
//     // &数组名，去除的是数组的地址，&数组名，表示整个数组
//     return 0;
// }


// #define ROW 3;
// #define COL 3;
// void InitBoard(char board[ROW][COL],int row,int col){
//     int i = 0;
//     int j = 0;
//     for(i = 0; i < row; i++){
//        for(j = 0; j< col; j++){
//            board[i][j] = ' ';
//        } 
//     }
// }
// void DisplayBoard(char board[ROW][COL],int row,int col){
//     int i = 0;
//     for(i = 0; i < row; i++){
//         printf(" %c | %c | %c \n");
//         printf("---|---|---|\n");
//     }
// }
// void game(){
//     char board[ROW][COL] = {0};
//     // 初始化
//     InitBoard(board,ROW,COL);
//     // 打印棋盘
//     DisplayBoard(board,ROW,COL);
// }
// void menu(){
//     printf("********************\n");
//     printf("***1.play  0.exit***\n");
//     printf("********************\n");
// }
// void test(){
//     int input = 0;
//     do
//     {
//         menu();
//         printf("请输入>:");
//         scanf("%d",&input);
//         switch(input){
//             case 1 :
//             game();
//             break;
//             case 0 :
//             printf("退出游戏\n");
//             break;
//             default:
//             printf("选择错误，请重新输入!\n");
//             break;
//         }
//     } while (input); 
// }
// int main(){
//     test();
//     return 0;
// }

// int main(){
//     int a = 3;
//     int b = 5;
//     // printf("交换前:a=%d b=%d\n",a,b);
//     // a = a + b; //  8
//     // b = a - b; //  3
//     // a = a - b; //  5
//     printf("交换前:a=%d b=%d\n",a,b);
//     // ^为(二进制)按位异或,同为0，异为1 
//     // 3=011,5=101
//     a = a^b; // 110 = 6
//     b = a^b; // 011 = 3
//     a = a^b; // 101 = 5
//     printf("交换后:a=%d b=%d\n",a,b);
//     return 0;
// }

// 移位操作符
// int main(){
//     int a = -2;
//     // 注意：不要移动负数位
//     // 左移操作符：左边抛弃，右边补0 乘上2
//     int b = a << 1;
//     printf("%d\n",b);
//     // 右移操作符：1.右边抛弃，左边补原符号位:算术右移 √
//     // 右移操作符：2.右边抛弃，左边补0:逻辑右移
//     int c = a >> 1;
//     printf("%d\n",c);
//     return 0;
// }

// 求二进制中1的个数
int main(){
    int num = 0;
    int count = 0;
    scanf("%d",&num);
    int i = 0;
    for(i = 0;i<32;i++){
        if(1 == ((num >> i ) & 1)){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}

