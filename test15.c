#include <stdio.h>
#include <string.h>
#include <stddef.h>

// 结构体传参
// struct S
// {
//     char c;
//     int a;
//     double d;
// };
// void Init(struct S* tmp)
// {
//     tmp->a = 100;
//     tmp->c = 'w';
//     tmp->d = 3.14;
// }
// // 传值
// void print1(struct S tmp)
// {
//     printf("1 %d %c %lf\n",tmp.a,tmp.c,tmp.d);
// }
// // 传址 更好
// void print2(const struct S* ps)
// {
//     printf("2 %d %c %lf\n",ps->a,ps->c,ps->d);
// }
// int main()
// {
//     struct S s;
//     Init(&s);
//     // s.a = 100;
//     // s.c = 'w';
//     // s.d = 3.14;
//     print1(s); // 传值
//     print2(&s);// 传址 更好
//     return 0;
// }

// 位段
// 位段的声明和结构类似的，有2个不同：
// 1.位段的成员必须是int、unsigned int、signed int,基本上都是一样的
// 2.位段的成员后边有一个冒号和一个数字
// 位：二进制位
// 目的：节省空间
// struct S
// {
//     int a : 2;   // a 只占2个比特位
//     int b : 5;   // b 只占5个比特位
//     int c : 10;  // c 只占10个比特位
//     int d : 30;  // d 只占30个比特位
//     // 总共47个比特位，一个字节8个比特位
//     //     所以只需6个字节，但是打印为8字节
//     // 位段开辟内存空间是按照需要以4个字节(int)或1个字节(char)开辟
//     //

// };
// int main()
// {
//     struct S s;
//     printf("%d\n", sizeof(s));
//     return 0;
// }

// struct S
// {
//     char a : 3;
//     char b : 4;
//     char c : 5;
//     char d : 4;
// };
// int main()
// {
//     struct S s = {0};
//     s.a = 10; // 1010
//     s.b = 20; // 10100
//     s.c = 3; // 011
//     s.d = 4; // 100
//     printf("%d\n",s.a); // 010 - 2
//     printf("%d\n",s.b); // 0100 - 4
//     printf("%d\n",s.c); // 010 - 3
//     printf("%d\n",s.d); // 010 - 4
//     return 0;
// }

// 枚举 ---- 一一列举，是一种类型
// 定义一个枚举类型
// enum Sex
// {
//     // 枚举的可能取值
//     male = 1, // 赋值1
//     female = 2 // 赋值2
// };
// int main()
// {
//     // 定义一个枚举类型变量
//     enum Sex m = male;
//     enum Sex f = female;
//     //printf("%d %d",m,f);
//     printf("%d ",sizeof(m)); // 是一个整型的大小
// }
// 我们可以使用#define定义常量，为什么要用枚举？枚举的优点：
// 1. 增加代码的可读性和可维护性
// 2.和#define定义的标识符比较枚举有类型检查，更加严谨
// 3.防止命名污染（封装）
// 4.便于调试
// 5.使用方便，一次可以定义多个常量

// 联合（联合体），也叫共用体
// 是一种特殊的自定义类型，这种类型定义的变量也包含一系列的成员
//     特征是这些成员公用同一块空间
// 这个联合变量的大小，至少是最大成员的大小，因为联合至少得有能力保存最大那个成员
// 当最大成员大小不是自大对齐数的整数倍时，就要对齐到最大对齐数的整数倍
union Un
{
    //                 默认对齐数  最大对齐数
    char arr[5]; // 5    8          1(是char的大小，总共5个)
    int i;       // 4    8          4
};

int main()
{
    union Un u; 
    printf("%d\n", sizeof(u)); // 8

    // 共用同一块空间
    // printf("%p\n",&u);     // 0061FF1C
    // printf("%p\n",&(u.c)); // 0061FF1C
    // printf("%p\n",&(u.i)); // 0061FF1C
    return 0;
}

// 判断当前机器是大端存储，还是小端存储
// int check_sys()
// {
//     union Un
//     {
//         char c;
//         int i ;
//     }u;
//     u.i=1;
//     return u.c;
// }
// int main()
// {
//     //int a = 0x11223344;
//     //      低地址----------------高地址
//     // ...[][][11][22][33][44][][][][][]   大端字节序存储模式
//     // ...[][][44][33][22][11][][][][][]   小端字节序存储模式
//     // 讨论一个数据，放在内存中的存放字节顺序
//     int a = 1;
//     int ret = check_sys();
//     if(1 == ret)
//     {
//         printf("小端字节序存储模式\n");
//     }
//     else
//     {
//         printf("大端字节序存储模式\n");
//     }
// }
