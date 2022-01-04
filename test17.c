#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <windows.h>
// 使用realloc开辟空间
// int main()
// {
//     int* p = realloc(NULL,40); // 等价于用malloc(40)
//     return 0;
// }

// 动态内存常见使用错误
// int main()
// {
// 1.对NULL指针解引用操作
// int *p = malloc(40);
// *p = 10; // 这里存在风险：malloc开辟空间失败时，就会对NULL进行解引用
// // 因此需要对p进行相关的判断

// 2.对动态开辟的内存越界访问
//                     20字节
// int *p = (int *)malloc(5 * sizeof(int));
// if (p == NULL)
// {
//     printf("%s\n", strerror(errno));
// }
// else
// {
//     int i;
//     //                  40字节
//     for (i = 0; i < 10; i++)
//     {
//         *(p + i) = i;
//     }
// }
// free(p);
// p = NULL;

// 3.对非动态开辟空间使用free
// int a = 10;
// int *p = &a;
// *p = 20;
// free(p);
// p = NULL;

// 4.使用free释放动态开辟内存的一部分
// int *p = (int *)malloc(40);
// if (p == NULL)
// {
//     return 0;
// }
// int i = 0;
// for (i = 0; i < 10; i++)
// {
//     *p++ = i;  // 起始位p已经改变 建议这样使用 *(p+i)=i
// }
// free(p);
// p = NULL;

// 5.对同一块动态开辟的内存多次释放
// int* p = (int*) malloc(40);
// if (p == NULL)
// {
//     return 0;
// }
// // 使用
// // 释放
// free(p); // 建议后面把p变成空指针，即p = NULL
// // …………
// free(p);

// 6.对动态开辟的内存空间忘记释放，(内存泄漏)
// while (1)
// {
//     malloc(1);
//     Sleep(1000);
// }

//     return 0;
// }

// 1.运行代码程序会出现崩溃
// 2.程序存在内存泄漏现象：str以值传递的形式传给p，p是GetMemory
// 只能函数内部有效，等GetMemory函数返回之后，动态开辟内存
// 尚未释放，并且无法找到，所以会造成内存泄漏
// void GetMemory(char *p)
// {
//     p = (char *)malloc(1000); // 形参，出了函数p就无用了，且没有释放
// }
// void Test(void)
// {
//     char *str = NULL;
//     GetMemory(str);
//     strcpy(str, "hello world"); // 这里程序崩溃
//     printf(str); // 可以这样打印
// }
// int main()
// {
//     // Test();
//     return 0;
// }

// // 改正 1
// void GetMemory(char **p) // 改成二级指针
// {
//     *p = (char *)malloc(1000);  // 改成解引用
// }
// void Test(void)
// {
//     char *str = NULL;
//     GetMemory(&str); // 改成取地址
//     strcpy(str, "hello world");
//     printf(str);

//     // 加上释放空间
//     free(str);
//     str = NULL;
// }
// int main()
// {
//     Test();
//     return 0;
// }
// 改正 2
// char *GetMemory(char *p)
// {
//     p = (char *)malloc(1000);
//     return p; // 返回p
// }
// void Test(void)
// {
//     char *str = NULL;
//     str = GetMemory(str); // 接收返回值
//     strcpy(str, "hello world");
//     printf(str);
//     // 加上释放空间
//     free(str);
//     str = NULL;
// }
// int main()
// {
//     Test();
//     return 0;
// }

// 返回栈空间的地址的问题
// char *GetMemory(void)
// {
//     char p[] = "hellow world";
//     return p; // 函数返回局部变量的地址,只能在函数内部使用，返回没用
// }
// void Test(void)
// {
//     char *str = NULL;
//     str = GetMemory(); // 接收返回值，是随机值
//     printf(str);
// }
// int main()
// {
//     Test();
//     return 0;
// }

// void* Test()
// {
//     //int a = 10; // a在栈区
//     static int a = 10; // 加了static ，a 就在静态区了
//     return &a; // 函数返回局部变量的地址
// }
// int main()
// {
//     int* a = Test();
//     printf("%d ",*a);
//     return 0;
// }

// int* test()
// {
//     int* ptr = malloc(100); // 堆区，可以返回
//     return ptr;
// }
// int main()
// {
//     int* p = test();
//     return 0;
// }

// int *f2(void)
// {
//     int *ptr; // 没有初始化，也没有指向对象，野指针
//     *ptr = 10; // 野指针ptr里面是随机值，再解引用，存在非法访问
//     return ptr;
// }

// char *GetMemory(char **p, int num)
// {
//     *p = (char *)malloc(num);
//     // 没有free，即忘记释放动态开辟的内存，导致内存泄漏
// }
// void Test(void)
// {
//     char *str = NULL;
//     GetMemory(&str, 100); //
//     strcpy(str, "hello");
//     printf(str);

//     // 改进
//     free(str);
//     str = NULL;
// }
// int main()
// {
//     Test();
//     return 0;
// }

// void Test(void)
// {
//     char *str = (char*)malloc(100);
//     strcpy(str,"hello");
//     free(str);

//     // 非法访问内存
//     // 考点：free释放str指向的空间后，并不会把str置为空指针
//     str = NULL; // 应该这样改进，if判断才有意义

//     if(str != NULL)
//     {
//     strcpy(str,"world");
//     printf(str);
//     }
// }
// int main()
// {
//     Test();
//     return 0;
// }

// 柔性数组 即C99中结构中的最后一个元素允许是位置大小的数组
// 特点：
// 结构中的柔性数组成员前面至少有一个其他成员
// sizeof返回的这种结构体大小不包括柔性数组的内存
// 包含柔性数组成员用malloc()函数进行内存的董涛分配，摈弃分配
// 的内存应该大于结构体的大小，以适应柔性数组的预期大小

// 写法1 效率更高
// struct S
// {
//     int n;
//     int arr[];// 未知大小的
// };
// struct S
// {
//     int n;
//     int arr[0]; // 同上 ，数组成员大小是可以调整的
// };
// int main()
// {
//     // struct S s;
//     // printf("%d\n",sizeof(s)); // 4 ,没有包含数组大小
//     struct S *ps = (struct S *)malloc(sizeof(struct S) + 5 * sizeof(int));
//     ps->n = 100;
//     int i;
//     for (i = 0; i < 5; i++)
//     {
//         ps->arr[i] = i;
//     }
//     // for (i = 0; i < 5; i++)
//     // {
//     //     printf("%d ",ps->arr[i]);
//     // }

//     // 不够用时,重新开辟内存空间
//     struct S *ptr = realloc(ps, 44);
//     if (ptr != NULL)
//     {
//         ps = ptr;
//         int i ;
//         for (i = 5; i < 10; i++)
//         {
//             ps->arr[i] = i;
//         }
//         for (i = 0; i < 10; i++)
//         {
//             printf("%d ", ps->arr[i]);
//         }
//     }
//     free(ps);
//     ps = NULL;
//     return 0;
// }

// 写法2 效率低
// struct S
// {
//     int n;
//     int *arr;
// };
// int main()
// {
//     struct S *ps = (struct S *)malloc(sizeof(struct S));
//     ps->arr = malloc(5 * sizeof(int));
//     int i;
//     for (i = 0; i < 5; i++)
//     {
//         ps->arr[i] = i;
//     }
//     for (i = 0; i < 5; i++)
//     {
//         printf("%d ", ps->arr[i]);
//     }

//     // 调整大小
//     int *ptr = realloc(ps->arr, 10 * sizeof(int));
//     if (ptr != NULL)
//     {
//         ps->arr = ptr;
//     }
//     for (i = 5; i < 10; i++)
//     {
//         ps->arr[i] = i;
//     }
//     for (i = 0; i < 10; i++)
//     {
//         printf("%d ", ps->arr[i]);
//     }
//     //释放内存
//     free(ps->arr);
//     free(ps);
//     ps->arr = NULL;
//     ps = NULL;
//     return 0;
// }

// 对比使用指针和柔性数组会发现，使用柔性数组的优点：
// 由于结构体使用指针地址不连续（两次 malloc），
// 柔性数组地址连续，只需要一次 malloc，同样释放前者需要两次，
// 后者可以一起释放。在数据拷贝时，结构体使用指针时，必须拷贝它指向的内存，
// 内存不连续会存在问题，柔性数组可以直接拷贝。减少内存碎片，
// 由于结构体的柔性数组和结构体成员的地址是连续的，
// 即可一同申请内存，因此更大程度地避免了内存碎片。另外由于该成员本身不占结构体空间，
// 因此，整体而言，比普通的数组成员占用空间要会稍微小点。

// 缺点：对结构体格式有要求，必要放在最后，不是唯一成员。

#include <stdio.h>
struct str{
    int len;
    char s[0];
};

struct foo {
    struct str *a;
};

int main(int argc, char** argv) {
    struct foo f={0};
    if (f.a->s) {
        // printf(f.a->s); 为什么这样写死错误
        printf("%x\n",f.a->s); // 为什么打印输出4
    }
    return 0;
}
