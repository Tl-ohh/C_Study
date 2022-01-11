#include <stdio.h>
#include <stddef.h>

// int main()
// {
//     int a = 10;
//     int b = a + 1; // 1 a不变
//     int b = ++a;   // 2 a变了
//     return 0;
// }

// #define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
// int main()
// {
//     int a = 10;
//     int b = 11;
//     int Max = MAX(a++, b++); // 宏的参数是直接替换进去的，如下
//     //int Max = ((a++) > (b++) ? (a++) : (b++));
//     printf("%d\n", Max); // 12
//     printf("%d\n", a);   // 11
//     printf("%d\n", b);   // 13
//     return 0;
// }

// 宏和函数有点类似啊,还是需要看使用场景
// #define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
// int Max(int x, int y)
// {
//     return (x > y ? x : y);
// }
// int main()
// {
//     // int a = 10;
//     // int b = 11;
//     // int Max1 = Max(a, b);
//     // int Max2 = MAX(a, b);
//     // printf("Max1 = %d\n", Max1);// 11
//     // printf("Max2 = %d\n", Max2);// 11

//     float c = 3.0f;
//     float d = 4.00;
//     float Max1 = Max(c, d);
//     float Max2 = MAX(c, d);
//     printf("Max1 = %.1f\n", Max1); // 4.0
//     printf("Max2 = %.1f\n", Max2); // 4.0
//     return 0;
// }

// #undef 移除#define
// int main()
// {

//     return 0;
// }

// 命令行定义 gcc test22.c -D n=10 这样可以输入经常变化的值，预编译
// int main()
// {
//     int i;
//     int arr[n] = {0};
//     for (i = 0; i < n; i++)
//     {
//         arr[i] = i;
//     }
//     for (i = 0; i < n; i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }

// 条件编译:可以选择性的执行代码
//#define DEBUG // 满足条件编译指令，这里是 定义DEBUG 就会执行#ifdef DEBUG与#endif之间的语句
// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int i;
//     for (i = 0; i < 10; i++)
//     {
//         arr[i] = i;
// #ifdef DEBUG
//         printf("%d ", arr[i]);
// #endif
//     }

//     return 0;
// }

// 条件编译指令:

// 1
//#if 常量表达式
//...
//#endif
// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int i;
//     for (i = 0; i < 10; i++)
//     {
//         arr[i] = i;
// // #if 1
// #if 0
//         printf("%d ", arr[i]);
// #endif
//     }
// }

// 2 多分支的条件编译
//#if 常量表达式
//...
//#elif 常量表达式
//...
//  #else
//...
//  #endif
// int main()
// {
// #if 1 == 1
//     printf("haha");
// #elif 2 == 1
//     printf("hehe");
// #else
//     printf("heihei");
// #endif
// }

// 3 判断是否被定义
// #if defined(symbol)  或者 #ifdef symbol
// #endif

// #if !defined(symbol) 或者 #ifndef symbol
// #endif
// int main()
// {
// //#if defined(DEBUG)
// #ifdef
//     printf("hehe");
// #endif
// //#if !defined(symbol)
// #ifndef DEBUG
//     printf("haha");
// #endif
//     return 0;
// }

// 4 嵌套指令-如:头文件stdio.h
// #if defined(OS_UNIX)
//         #ifdef OPTION1
//             unix_version_option1();
//     #endif

//         #ifdef OPTION2
//             unix_version_option2();
//     #endif

// #elif defined(OS_MSDOS)
//         #ifdef OPTION2
//             msdos_version_option2();
//     #endif
// #endif


// 文件包含 
//1. #include <库文件名> 
//2. #include "本地文件名"
// 以上两种引用的区别：引用场景不同、查找策略不同

// 头文件重复引用会导致代码冗余
// 在头文件中输入 以下代码 可以消除代码冗余,假如头文件test.h
// #ifndef __TEST_H__
// #define __TEST_H__
// // 中间代码内容
// #endif

// 或者输入以下代码
// #pragma once
// // 中间代码内容

// offset 模式实现宏
struct S
{
    char c1;
    int a;
    char c2;
};
#define OffSETOF(struct_name,member_name) (int)&(((struct_name*)0)->member_name)
int main()
{
    //struct S s;
    // printf("%d\n",offsetof(struct S,c1)); //0
    // printf("%d\n",offsetof(struct S,a));  //4
    // printf("%d\n",offsetof(struct S,c2)); //8
    
    printf("%d\n",OffSETOF(struct S,c1)); //0
    printf("%d\n",OffSETOF(struct S,a)); //4
    printf("%d\n",OffSETOF(struct S,c2)); //8
    return 0;
}
