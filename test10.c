#include<stdio.h>
#include <string.h>

// int main()
// {
//     // char* p = "abcdef";
    
//     // printf("1 %d\n",sizeof(p));// 4/8 -计算指针变量，所以是4/8
//     // printf("2 %d\n",sizeof(p+1));// 4/8 - 计算字符b的地址，所以是4/8
//     // printf("3 %d\n",sizeof(*p));// 1 -*p是字符a,所以是一个字符为1
//     // printf("4 %d\n",sizeof(p[0]));// 1 -p[0]是字符a,所以是一个字符为1
//     // printf("5 %d\n",sizeof(&p));// 4/8 - 计算p的地址，所以是4/8
//     // printf("6 %d\n",sizeof(&p+1));// 4/8 - 计算的是地址，所以是4/8
//     // printf("7 %d\n",sizeof(&p[0]+1)); //4/8 - 计算字符b的地址，所以是4/8
    
//     // a b c d e f \0 
//     // strlen要找到 \0才会停止
//     // printf("1 %d\n",strlen(p));// 6 -p是a的地址，算了6个字符
//     // printf("2 %d\n",strlen(p+1));// 5 -p+1是b的地址，算了5个字符
//     //printf("3 %d\n",strlen(*p));// error
//     //printf("4 %d\n",strlen(p[0]));// error
//     // printf("5 %d\n",strlen(&p));// 随机值 -取出的是p的地址，p后面不知道\0在哪
//     // printf("6 %d\n",strlen(&p+1));// 随机值 -取出的是p后面一个空间的地址，也不知道\0在哪
//     // printf("7 %d\n",strlen(&p[0]+1));//5 -从b之后的大小
    

//     int a[3][4] = {0};
//     printf("1 %d\n",sizeof(a)); //48 -计算数组总大小
//     printf("2 %d\n",sizeof(a[0][0]));//4 - 计算第1个元素大小
//     printf("3 %d\n",sizeof(a[0]));//16 -计算第一行的元素总大小
//     printf("4 %d\n",sizeof(a[0]+1));//4 -计算的是第1行第2个元素地址的大小
//     printf("5 %d\n",sizeof(*(a[0]+1)));//4 -计算的是第1行第2个元素的大小
//     printf("6 %d\n",sizeof(a+1));//4 -第二行首元素的地址
//     printf("7 %d\n",sizeof(*(a+1)));//16 -计算第2行的元素总大小
//     printf("8 %d\n",sizeof(&a[0]+1));//4 -计算第2行的元素的地址大小
//     printf("9 %d\n",sizeof(*(&a[0]+1)));//16 -计算第2行的元素总大小
//     printf("10 %d\n",sizeof(*a));//16 -计算第一行的元素总大小
//     printf("12 %d\n",sizeof(a[3]));//16 
//     return 0;
// }

// int main()
// {
//     int a[5] = {1,2,3,4,5};
//     int*ptr = (int*) (&a+1);
//     // a是首元素地址，a+1是第2个元素2的地址
//     printf("%d,%d\n",*(a+1),*(ptr-1));//2,5
//     //&a是整个数组地址,+1直接越界,
//     //但ptr是int*类型,他-1只能往回扣一个地址长度,所以是5
//     return 0;
// }

// struct Test
// {
//     int num;
//     char *pcName;
//     short sData;
//     char cha[2];
//     short sBa[4];
// }*p;

// int main()
// {
//     // 假设p为0x100000
//     // 已知 结构体Test类型的变量的大小是20字节
//     p = (struct Test*)0x100000;
//     printf("%p\n",p+0x1);//00100014 
//     printf("%p\n",(unsigned long)p+0x1);// 00100001
//     printf("%p\n",(unsigned int*)p+0x1);// 00100004
//     return 0;
// }

// int main(){
//     // 小端存储模式
//     // 01 00 00 00 / 02 00 00 00 / 03 00 00 00 / 04 00 00 00
//     //  1  2  3  4    5  6  7  8   9  10  11 12  13  14 15 16
//     int a[4] = {1,2,3,4};
//     int* ptr1 = (int*)(&a+1);
//     int* ptr2 = (int*)((int)a+1); 
//     // ptr2为2那个00的地址，解引用之后又是整型，所以从2开始向后倒着读4个，即从5向前读到2： 00 00 00 / 02 倒着读
//     printf("%x,%x",ptr1[-1],*ptr2);//4,2000000
// }

// int main()
// {
//     //               1     3     5    0    0     0
//     int a[3][2] = {(0,1),(2,3),(4,5)};
//     int* p; // p是地址
//     p = a[0]; // 把a[0]第一行的地址赋给p
//     // 打印p这个地址中的数据，逗号表达式一直算到最右边,所以是1
//     printf("%d\n",p[0]); // 1
//     printf("%d\n",p[1]); // 3
//     printf("%d\n",p[2]); // 5
//     printf("%d\n",p[3]); // 0
//     printf("%d\n",p[4]); // 0
//     printf("%d\n",p[5]); // 0
//     printf("%d\n",p[6]); // 0
//     return 0;
// }

// int main()
// {
// // □□□□□ □□□□□ □□□□□ □□□□□ □□□□□ 为a的存储情况，忽略空格
// //                           □   为a[4][2]的地址 
// // □----                         为p的地址
// //     □ ----                    为p+1的地址
// //          □- ---               为p+2的地址
// //               □-- --          为p+3的地址
// //                    □--- -     为p+4的地址，即p[4]的地址
// //                      □- ---   为p+4+2的地址，即p[4][2]的地址
// //       &p[4][2]-&a[4][2] = -4                      
//     int a[5][5];
//     int(*p)[4]; // 指向4个元素的数组指针
//     p = a;
//     // 10000000000000000000000000000100 -4的原码
//     // 11111111111111111111111111111011 -4的反码
//     // 11111111111111111111111111111100 -4的补码
//     // 1111 1111 1111 1111 1111 1111 1111 1100 -4的补码
//     //   f   f    f     f    f   f    f     c
//     printf("%p\n",&p[4][2]-&a[4][2]); // FFFFFFFC
//     printf("%d\n",&p[4][2]-&a[4][2]); // -4
// }

// int main()
// {
//     int aa[2][5] = {1,2,3,4,5,6,7,8,9,10};
//     int *ptr1 = (int*)(&aa+1);
//     int *ptr2 = (int*)(*(aa+1));
//     printf("%d,%d",*(ptr1 - 1),*(ptr2 - 1));  // 10,5
//     return  0;
// }

// int main()
// {
//     char *a[] = {"work","at","alibaba"};
//     char **pa = a;
//     pa++;
//     printf("%s\n",*pa);
//     return 0;
// }

// int main()
// {
//     //         ENTER NEW POINT FIRST
//     char *c[] = {"ENTER","NEW","POINT","FIRST"};
//     char** cp[] = {c+3,c+2,c+1,c}; // FIRST  POINT NEW ENTER
//     char***cpp =cp;
//     printf("1%s\n",**++cpp);// POINT
//     printf("2%s\n",*--*++cpp+3); // ER
//     printf("3%s\n",*cpp[-2]+3); // ST
//     printf("4%s\n",cpp[-1][-1]+1); // EW
//     return 0;
// }


// 杨氏矩阵
// 内容： 矩阵的每行从左到右递增，从上到下递增，
// 编写程序在矩阵中查找某个数字是否存在
// 时间复杂度小于O(n)，即不能遍历n次
int FindNum(int arr[3][3],int k,int* row,int* col)
{
    int x = 0;
    int y = *col - 1;
    while(x<=*row-1 && y>= 0)
    {
        if(arr[x][y] > k)
        {
            y--;
        }
        else if(arr[x][y] < k)
        {
            x++;
        }
        else
        {
            *row = x;
            *col = y;
            return 1;
        }   
    }
    return 0;
    
}
int main()
{
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 7;
    int x = 3;
    int y = 3;
    int ret = FindNum(arr,k,&x,&y);
    if(ret == 1)
    {
        printf("找到了,下标是%d,%d\n",x,y);
    }
    else
    {
        printf("找不到\n");
    }
    
    return 0;
}
