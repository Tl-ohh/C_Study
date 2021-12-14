#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>

// int main(){
//     short s = 0;
//     int a = 10;
//     printf("%d\n",sizeof(s = a + 5)); 
//     // 为2，是因为short只存2个字节大小
//     printf("%d\n",s);
//      // 为0，是因为sizeof里面的表达式不参与运算
// }

// void test1(int arr[]){
//     printf("%d\n",sizeof(arr)); // 4
//     // 传过来的是指针，因此是4个字节
// }
// void test2(char ch[]){
//     printf("%d\n",sizeof(ch)); // 4
// }

// int main(){
//     int arr[10] = {0};
//     char ch[10] = {0};
//     printf("%d\n",sizeof(arr)); // 40
//     printf("%d\n",sizeof(ch)); // 10
//     test1(arr);
//     test2(ch);
//     return 0;
// }

// int main(){
//     int a = 3;
//     int b = 5;
//     int d = 0;
//     int e = 0;
//     int c = a && b;
//     int f = a && d;
//     int g = a || d;
//     int h = e || d;
//     printf("%d\n",c);// 1 真 && 真 = 1
//     printf("%d\n",f);// 0 真 && 假 = 0
//     printf("%d\n",g);// 1 真 || 假 = 1
//     printf("%d\n",h);// 0 假 || 假 = 0
//     return 0;
// }

// int main(){
//     int i = 0,a=1,b=2,c=3,d=4;
//     // &&遇到0后面不看 ||遇到1后面不看
//     // i = a++ && ++b && d++;
//     i = a++ || ++b || d++;
//     printf("a = %d\nb = %d\nc = %d\nd = %d\n",a,b,c,d);
//     return 0;
// }

// int main(){
//     int a = 10;
//     int b = 20;
//     // b = (a>5?3:-3);
//     // printf("%d\n",b);
//     int max = (a>b?a:b);
//     printf("%d\n",max);
// }

// int main(){
//     char a = 3;
//     // char 存储8个比特位，因此从右往左数8个再截断
//     // 00000000000000000000000000000011
//                             // 00000011 ---->a
//     char b = 127;
//     // 00000000000000000000000001111111
//                             // 01111111 ---->b

//     // a,b如何相加
//     // 00000000000000000000000000000011
//     // 00000000000000000000000001111111
//     // 00000000000000000000000010000010
//     char c = a + b;
//                             // 10000010 ---->c
//     // 11111111111111111111111110000010 补码
//     // 11111111111111111111111110000001 反码=补码-1
//     // 10000000000000000000000001111110 原码=补码的符号位(第一位)不变，其他取反
//     // - 1111110 = -126 (符号位为1，为负。为0，则为正)
//     printf("%d\n",c);// %d:打印整型 -126
//     return 0;
// }

// int main(){
//     char c = 1; 
//     // %u是无符号的十进制整数
//     printf("%u\n",sizeof(c));
//     printf("%u\n",sizeof(+c));// +c是表达式，要整型提升
//     printf("%u\n",sizeof(!c)); // !为取反
//     return 0;
// }

// int main(){
//     int i = 1;
//     int a = (i++) + (i++) +(i++);
//     printf("%d",a);
// }

// int main(){
//     int a = 10;
//     int b = &a;
//     int* c = &a;
//     printf("%p\n",b);
//     return 0;
// }

// <---------指针--------->

// 指针解引用
// 指针类型决定了指针进行解引用操作的时候，
// 能够访问的空间大小
// int* p; *p能够访问4个字节
// char* p; *p能够访问1个字节
// double* p; *p能够访问8个字节

// 指针的类型决定的指针的步长
// int main(){
//     int a = 0x11223344;
//     int* pa = &a;
//     char* pc = &a;

//     printf("%p\n",pa);   // 0061FF14
//     printf("%p\n",pa+1); // 0061FF18 = 0061FF14 + 4
//     printf("%p\n",pc);   // 0061FF14
//     printf("%p\n",pc+1); // 0061FF15 = 0061FF14 + 1
// }

// <-----避免野指针---->
// 1.指针初始化 
// 2.小心指针越界
// 3.指针空间释放后就使之置为NULL
// 4.指针使用之前检查有效性

// <-----指针运算--->
int main(){
    // 指针±整数
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    // int i = 0;
    // int sz = sizeof(arr)/ sizeof(arr[0]);
    // int* p = arr;
    // for(i = 0; i<5; i++){
    //     printf("%d ",*p);
    //     p+=2;
    // }

    // 指针-指针 为指针和指针之间的元素个数
    printf("%d\n",&arr[9] - &arr[0]);
    return 0;
}
