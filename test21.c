#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// 预定义符号
// int main()
// {
//     // printf("%s\n",__FILE__); // 当前文件的相对路径+文件全称
//     // printf("%d",__LINE__); // 此句代码在当前文件的所在行的行号
//     // printf("%s\n",__DATE__); // 打印日期
//     // printf("%s\n",__TIME__); // 打印时间

//     // 写日志文件
//     int i;
//     int arr[10] = {0};
//     FILE *pf = fopen("log.txt","w");
//     for (i = 0; i < 10; i++)
//     {
//         arr[i] = i;
//         fprintf(pf,"file:%s line:%d data:%s time:%s i=%d\n",
//         __FILE__,__LINE__,__DATE__,__TIME__,i);
//     }
//     fclose(pf);
//     pf = NULL;
//     for (i = 0; i < 10; i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     return 0 ;
// }

// int main()
// {
//     printf("%d\n", __STDC__);
//     return 0;
// }

// 预处理指令:#define #include #pragma #if #end  #endif #ifdef #line等
// #define 定义标识符 可以是代码  不要加分号
// #define MAX 100
// #define STR "hehe"
// #define do_forever for(;;)
// int main()
// {
//     // printf("%d\n",MAX);
//     // printf("%s\n",STR);

//     return 0;
// }
// #define SQUARE(x) x * x //
// #define SQUARE(x) (x) * (x) // 宏 是完成参数替换
// int main()
// {
//     //printf("%d", SQUARE(5)); // 25
//     //printf("%d", SQUARE(5+1)); // 11 是替换不是赋值 5+1 * 5+1 = 11
//     printf("%d", SQUARE(5 + 1)); // 36 = (5+1)*(5+1),即把x替换为(5+1)
//     return 0;
// }

//#define DOUBLE(x) x + x
// #define DOUBLE(x) ((x) + (x))
// int main()
// {
//     int a = 5;
//     int ret = 10 * DOUBLE(a);
//     // 宏不加括号: int ret = 10* a+a 即:10*5+5
//     //printf("%d", ret);// 55
//     printf("%d", ret);// 100
//     return 0;
//     //所以用于对数值表达式进行求职宏定义都应该用这种方式加上括号，
//     //避免在使用宏时由于参数中的操作法或邻近操作符之间不可预料的相互作用
// }

// #define 的替换规则
// 1. 在调用宏时，首先对参数进行检查，看看是否包含任何由#define定义的符号，如果是，它们首先被替换
// 2. 替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被它们的值替换
// 3. 最后，在此对结果文件进行扫描，看看它是否包含任何由#define定义的符号。如果是，就重复上述过程。
// 注意:宏参数和#define定义中可以传其他#define定义的符号，但是对于宏，不能出现递归
//      当预处理器搜索#define定义的符号的时候，字符串常量的内容不能被搜索
// #define MAX 100
// #define DOUBLE(x) ((x) + (x))

// int main()
// {
//     int a = 5;
//     int ret = 10* DOUBLE(MAX);
//     printf("%d\n",ret);
//     return 0;
// }

//  #和##
//  #
// void print(int a)
// {
//     printf("the value of a is %d\n",a);
// }
// int main()
// {
//     int a = 10;
//     int b = 20;
//     //printf("the value of a is %d\n",a);
//     print(a);
//     print(b);
//     return 0;
// }
// 如何把参数插入到字符串中
// #define PRINT(X) printf("the value of "#X" is %d\n",X)
// int main()
// {
//     // printf("hello world\n");
//     // printf("hello " "world\n");
//     // printf("he""llo"  "world\n"); // 字符串插入双引号不会影响打印内容
    
//     int a = 10;
//     int b = 20;
//     PRINT(a);
//     // 变成 printf("the value of ""a"" is %d\n",a)
//     PRINT(b);
//     // 变成 printf("the value of ""b"" is %d\n",b)
//     return 0;
// }

// ##可以把位于它两边的符号合成一个符号，它允许宏定义从分离的文本片段创建标识符
#define CAT(X,Y) X##Y
int main()
{
    int Class20 = 2019;
    printf("%d\n",CAT(Class,20)); // 2019
    // 等价于 printf("%d\n",Class##20);
    // 等价于 printf("%d\n",Class20);
    return 0;
}
