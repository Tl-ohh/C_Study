#include <stdio.h>
#include <string.h>
#include <stddef.h>
// 自定义数据类型----结构体、枚举、联合体

// 结构体声明
// struct Stu
// {
//     // 结构体的成员变量
//     char name[20];
//     char tele[12];
//     char sex[10];
//     int age;
// }s4,s5,s6; //变量列表---全局变量
// struct Stu s3; // ---全局变量
// int main()
// {
//     // 创建结构体变量--局部变量
//     struct Stu s1;
//     struct Stu s2;
// }

// 结构体自引用
// struct Node
// {
//     int data; // ----数据域
//     // struct Node n; // 错误示范

//     // 存放下一个节点的地址
//     struct Node* next; // ----指针域
// };
// int main()
// {
//     return 0;
// }

// 结构体重命名
// typedef struct Node // Node不建议省略
// {
//     int data; // ----数据域
//     // struct Node n; // 错误示范

//     // 存放下一个节点的地址
//     struct Node *next; // ----指针域
// } Node;
// int main()
// {
//     Node n1;
//     return 0;
// }

// 结构体变量的定义和初始化
// struct T
// {
//     double weight;
//     short age;
// };

// struct S
// {
//     char c;
//     struct T st;
//     int a;
//     double d;
//     char arr[20];
// };
// int main()
// {
//     struct S s = {'c',{55.6,30}, 100, 3.14, "hello world"};
//     // printf("%c %d %lf %s \n", s.c, s.a, s.d, s.arr);
//     // printf(" %lf \n", s.st.weight);
//     return 0;
// }

// 结构体内存对齐
// 结构体对齐规则：
// 1.第一个成员放在与结构体变量偏移量为0的地址处
// 2.其他承运要对齐到对齐数的整数倍的地址处
// 3. 对齐数=编译器默认对齐数与该成员的较小值，
// -----------gcc没有默认对齐数，所以对齐数为该成员本身大小
// 4.结构体总大小为所有成员中最大的对齐数的整数倍
// 5如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处
// ----------结构体的整体大小就是所有最大对齐数的整数倍
// 内存对齐目的：空间换时间
// struct S1
// {
//     //     最大对齐数
//     char c1;// 1
//     int a;  // 4
//     char c2;// 1
// };
// struct S2
// {
//     //      最大对齐数
//     char c1;// 1
//     char c2;// 1
//     int a;  // 4

// };
// struct S3
// {
//     //        最大对齐数
//     double d; // 8
//     char c3;  // 1
//     int a;    // 4

// };
// struct S4
// {
//     //           最大对齐数
//     char c4;       // 1
//     struct S3 S3;  // 8
//     double f;      // 8

// };

// #pragma pack(4) // 修改默认对齐数 为4
// struct S5
// {
//     //           最大对齐数
//     char a;     // 1
//     double d;   // 4
// };
// #pragma pack() // 取消设置默认对齐数
// struct S6
// {
//     //           最大对齐数
//     char a;      // 1
//     double d;    // 8
// };
// int main()
// {
//     // struct S1 s1 = { 0 };
//     // printf("%d\n",sizeof(s1));// 12

//     // struct S2 s2 = { 0 };
//     // printf("%d\n",sizeof(s2));// 8

//     // struct S3 s3 = { 0 };
//     // printf("%d\n",sizeof(s3));// 16

//     // struct S4 s4 = { 0 };
//     // printf("%d\n",sizeof(s4));// 32

//     struct S5 s5 = { 0 };
//     printf("%d\n",sizeof(s5));// 12
//      struct S6 s6 = { 0 };
//     printf("%d\n",sizeof(s6));// 16
//     return 0;
// }

// offsetof
//计算结构体成员相对于结构体起始位置的偏移量，是宏
struct S
{
    char c;
    int i;
    double d;
};

int main()
{
    //offsetof 
    //#define  offsetof(TYPE, MEMBER) __builtin_offsetof (TYPE, MEMBER)
    printf("%d\n",offsetof(struct S,c)); // 0
    printf("%d\n",offsetof(struct S,i)); // 4
    printf("%d\n",offsetof(struct S,d)); // 8
    return 0;
}
