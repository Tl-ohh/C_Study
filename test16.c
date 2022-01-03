#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
// 动态内存 malloc free calloc realloc
// struct S
// {
//     char name[20];
//     int age;
// };
// int main()
// {
//     struct S arr[50];
//     return 0;
// }

// malloc
// 开辟空间的内部存放随机值 -不用初始化
// 如果开辟成功，则返回有个指向开辟好的空间的指针
// 如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要检查
// 返回值的类型是void*,所以malloc函数并不是知道开辟空间的类型，具体在使用的使用者自己决定
// 如果参数size为0，malloc的行为是标准是未定义的，取决于编译器
// free
// free函数用来释放动态开辟的内存
// 1.如果参数 ptr 指向的空间不是动态开辟的那free函数的行为是未定义的
// 2.如果参数 ptr 是NUUL指针，则函数什么事都不做
// int main()
// {
//     // 向内存申请10个整型的空间,malloc放的是总大小
//     int *p = (int *)malloc(10 * sizeof(int)); //需要决定开辟空间的类型，所以要强制转换
//     if (p == NULL)
//     {
//         printf("%s\n", strerror(errno));
//     }
//     else
//     {
//         int i = 0;
//         for (i = 0; i < 10; i++)
//         {
//             *(p + i) = i;
//         }
//         for (i = 0; i < 10; i++)
//         {
//             printf("%d ", *(p + i));
//         }
//     }
//     // 当动态申请的空间不再使用的时候
//     // 释放该空间，还给内存
//     free(p);
//     p = NULL;
//     return 0;
// }

// calloc
// 开辟空间的内部初始化为0
// int main()
// {
//     // calloc放的是(元素个数，每个元素的大小)
//     int *p = (int *)calloc(10, sizeof(int));
//     if(p == NULL)
//     {
//         printf("%s\n", strerror(errno));
//     }
//     else
//     {
//         int i = 0;
//         // for (i = 0; i < 10; i++)
//         // {
//         //     *(p + i) = i;
//         // }
//         for (i = 0; i < 10; i++)
//         {
//             printf("%d ", *(p + i));
//         }
//     }
//     // free函数用来释放动态开辟的内存
//     free(p);
//     p = NULL;
//     return 0;
// }

// realloc 调整动态开辟的内存空间的大小，
// int main()
// {
//     int *p = (int *)malloc(20);
//     if (p == NULL)
//     {
//         printf("%s\n", strerror(errno));
//     }
//     else
//     {
//         int i = 0;
//         for (i = 0; i < 5; i++)
//         {
//             *(p + i) = i;
//         }
//     }
//     // 就是在使用malloc开辟的20个字节空间
//     // 假设20个字节空间不够使用
//     // 希望能够有40个字节空间的大小
//     // 这里就可以使用realloc来调整已开辟空间的大小
//     // realloc使用注意事项:
//     // 1.如果p指向的空间之后有足够的内存空间可以追加，则直接追加，后返回p
//     // 2.如果p指向的空间之后没有足够的内存空间可以追加，则realloc函数会重新找一个新的内存区域
//     //      开辟一块满足的空间，并且把内存中的数据拷贝回来，释放旧的内存空间，最后返回新开辟的内存空间地址
//     // 3.realloc成功后会自动释放原空间
//     // realloc(已开辟空间的地址,调整之后空间的大小)
//     int *ptr = (int *)realloc(p, 40);
//     if (ptr != NULL)
//     {
//         p = ptr;
//         int i;
//         for (i = 5; i < 10; i++)
//         {
//             *(p + i);
//         }
//         for (i = 0; i < 10; i++)
//         {
//             printf("%d ", *(p + i));
//         }
//     }
//     // 释放内存
//     free(p);
//     p = NULL;
//     return 0;
// }

int main()
{
    // 1.对空指针解引用
    // 开辟新空间首先判断空间是否开辟成功,还要返回开辟信息
    // int *p = (int *)malloc(40);
    // if (p == NULL)
    // {
    //     printf("%s\n", strerror(errno));
    // }

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
    
    return 0;
}
