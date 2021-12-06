#include<stdio.h>
#include <string.h>
// int main() {  
//     // int是整型 main前面的int表示main函数调用返回一个整型值
//     // printf("helloWord!\n");
//     // printf("哈哈哈哈哈哈\n");
//     // return 0;
// }

// int main() {  
//     //<------数据类型------>
//     // char ch = 'A'; //内存
//     // printf("%c\n",ch);  // %c--------打印字符格式的数据

//     //  int age = 20;
//     // printf("%d\n",age); // %d--------打印整型|进制数据

//     // float f = 5.0;
//     // printf("%f\n",f);   // %f--------打印单精度浮点数字

//     // double d = 3.14;
//     // printf("%lf\n",d);  // %lf-------打印双精度浮点数字 

//     // char 字符数据类型
//     // short 短整型
//     // int 整型
//     // long 长整型
//     // long long 更长的整型
//     // float 单精度浮点数
//     // double 双精度浮点数
//     // %d--------打印整型
//     // %c--------打印字符
//     // %f--------打印浮点数字-打印小数
//     // %p--------以地址形式打印
//     // %x--------打印16进制数字
//     // %o--------打印。。。
//     // return 0;
// }

// int main() {  
//     //<------数据类型大小------>
//     // printf("%d\n",sizeof(char));       // 1 字节 = 8 bit
//     // printf("%d\n",sizeof(short));      // 2 字节
//     // printf("%d\n",sizeof(int));        // 4 字节
//     // printf("%d\n",sizeof(long));       // 4/8 字节
//     // printf("%d\n",sizeof(long long));  // 8 字节
//     // printf("%d\n",sizeof(float));      // 4 字节
//     // printf("%d\n",sizeof(double));     // 8 字节
//     //  bit(比特位)->byte(字节)->kb->mb->gb->tb->pb
//     // return 0;
// }

// int main() {  
//     //<------变量：局部、全局------>
//     // int num1 = 0;
//     // int num2 = 0;
//     // scanf("%d%d",&num1,&num2);  // 输入数据---使用输入函数scanf / &为取地址符号
//     // int sum = 0;
//     // sum = num1 + num2;
//     // printf("sum = %d\n",sum);
//     // return 0;
// }

// int main() {  
//     //<------代码作用域------>
//     // extern int g_val;
//     // printf("g_val = %d\n",g_val);
//     // 局部变量的作用域是变量所在的局部范围
//     // 全局变量的作用域是整个工程


//     //<------生命周期------>
//     // 局部变量的生命周期在进去作用域开始，出去结束
//     // 全局变量是整个程序的生命周期
//     // return 0;
// }

// enum Sex {male,female};
// int main() {  
//     //<------常量------>
//     // 1.字面常量

//     // 2.const修饰的常变量
//     // // const int num = 8; // const 常属性
//     // // printf("%d\n",num);
//     // const int n = 10; 
//     // int arr[n] = {0};

//     // 3.#define定义的标识符常量

//     // 4.枚举常量：性别(男、女)等
//     // enum Sex {male,female};
//     printf("%d\n",male);   // 0
//     printf("%d\n",female); // 1
//     return 0;
// }

// int main() {  
//     char arr1[] = "abc"; // "abc" --'a','b',;'c','\0'
//     char arr2[] = {'a','b','c'}; // "abcabc"
//     char arr3[] = {'a','b','c','\0'}; // "abc", '\0'是字符串的结束标志
//     // printf("%s\n",arr1); 
//     // printf("%s\n",arr2); //在arr2的基础上变成arr3，arr2输出才能和arr1一样
//     // printf("%s\n",arr3);
//     // \0是字符串结束的标志，不算字符串长度
//     printf("%d\n",strlen(arr1));// 3
//     printf("%d\n",strlen(arr2));// 6
//     printf("%d\n",strlen(arr3));// 3
//     return 0;
// }

// int main() {
    // // printf("(are you ok \?\?)");
    // printf("%d\n",strlen("c:\test\32\test.c")); 
    // // \3 2是2个8进制数字 3*8^1+2*8^0=26
    // // 32作为8进制代表的那个十进制数字，作为ASCII码值，对应的字符
    // printf("%c\n",'\32'); 
    // // 32 ---->10进制为26--->作为ASCII码值代表的字符是→这个符号

    // // <----移位操作符-------->
    // int a = 1;
    // int b = a<<4; // 左移
    // printf("%d\n",b);

    // <----位操作------->
    // &：(按位与)，|：(按位或),^：(按位异或)，~：(按位取反)
    // int a = 0;
    // int b = ~a;
    // printf("%d\n",b); // -1  源码、补码、反码

    // <----操作符------->
    // int a = 10;
    // int b = a++; //  后置++，先使用，再++
    // printf("a = %d b = %d\n",a,b); // a = 11 b = 10
    // int c = ++a; // 前置++，先++，再使用
    // printf("a = %d c = %d\n",a,c); // a = 11 c = 11
    // int d = a--; //  后置--，先使用，再--
    // printf("a = %d d = %d\n",a,d); // a = 9 d = 10
    // int e = --a; //  前置--，先--，再使用
    // printf("a = %d e = %d\n",a,e); // a = 9 e = 9

    // int a = 100;
    // int b = 200;
    // int max = 0;
    // max = (a>b?a:b); // 三目操作符
    // printf("%d\n",max);

//     return 0;
// }

// void test()
// {
//     static int a = 1; 
//     // 当static修饰局部变量时，使得局部变量的生命周期变长
//     // 当static修饰全局变量时，使得静态的全局变量只能在自己所在的源文件内部使用
//     // static 能使外部连接属性变为内部链接属性
//     int b = 1;
//     a++; // 23456
//     b++; // 22222
//     printf("a= %d b= %d\n",a,b);
// }
// int main(){
//     int i = 0;
//     while (i < 5)
//     {
//         test();
//         i++;
//     }
//     return 0;
// }

// <---------不能执行----->
// 声明外部函数 
// extern int Add(int，int);
// int main(){
//     int a = 10;
//     int b = 20;
//     int sum = Add(a,b);
//     printf("sum= %d\n",sum);
//     return 0;
// }

// <--------指针------>
// int main() {
//     int a = 10;
//     //printf("%p\n",&a); // 0061FF1C &a为取a的地址
//     int* p = &a;
//     //printf("%p\n",&a); // 0061FF18
//     //printf("%p\n",p);  // 0061FF18
//     *p = 20; // * 为解引用操作符
//     printf("a= %d\n",a);
//     return 0;
// }

// <--------构造体------>
struct book
{
    char name[20];
    short price;
    char author[20];
};
int main(){
    struct book b1 = {"三国演义",110,"罗贯中"};
    // printf("书名:《%s》\n",b1.name);
    // printf("价格:%d元\n",b1.price);
    // printf("作者:%s\n",b1.author);

    // 利用指针打印出书名、作者、价格
    struct book* pb = &b1;
    // printf("%s\n",(*pb).name);   // . 为结构体变量.成员
    // printf("%d\n",(*pb).price);  // . 为结构体变量.成员
    // printf("%s\n",(*pb).author); // . 为结构体变量.成员
    
    printf("%s\n",pb->name);   // -> 为结构体指针->成员
    printf("%d\n",pb->price);  // -> 为结构体指针->成员
    printf("%s\n",pb->author); // -> 为结构体指针->成员
    return 0;
}
