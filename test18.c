#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
// 柔性数组
// struct S
// {
//     int n;
//     int arr[0]; // 柔性数组成员
// };
// int main()
// {
//     struct S *p = (struct S *)malloc(sizeof(struct S) + 10 * sizeof(int));
//     p->n = 100;
//     int i;
//     for (i = 0; i < 10; i++)
//     {
//         p->arr[i] = i;
//     }
//     for (i = 0; i < 10; i++)
//     {
//         printf("%d ", p->arr[i]);
//     }
//     free(p);
//     p = NULL;
//     return 0;
// }

// 文件操作，包括:程序文件(源程序文件、目标文件、可执行文件)，数据文件；
// 文件类型：文本文件、二进制文件

// int main()
// {
//     int a = 10000;
//     FILE* pf = fopen("test.txt","wb"); // FILE* pf文件指针变量
//     fwrite(&a,4,1,pf); // 二进制形式写入文件中
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// 文件缓冲区 https://blog.csdn.net/weixin_43202635/article/details/97928825

// 文件指针 https://www.cnblogs.com/liang-chen/p/11397558.html

// 文件的打开和关闭
//              文件名                 打开模式
// FILE *fopen(const char* filename,const char* mode);
// int fclose(FILE *stream) // 关闭文件

// 文件使用方式                    含义                       如果文件不存在
//   "r"只读      为了输入数据，打开一个已经存在的文本文件       出错

//   "w"只写      为了输出数据，打开一个文本文件                建立一个新的文件

//   "a"追加      向文本文件尾添加数据                          出错

//   "rb"只读     为了输入数据，打开一个二进制文本文件           出错

//   "wb"只写     为了输出数据，打开一个二进制文本文件          建立一个新的文件

//   "ab"追加     向二进制文件尾添加数据                       出错

//   "r+"读写     为了读和写，打开一个文本文件                 出错

//   "w+"读写     为了读和写, 建立一个新的文件                 建立一个新的文件

//   "a+"读写     打开一个文件，在文件尾进行读写               建立一个新的文件

//   "rb+"读写    为了读和写，打开一个二进制文件                 出错

//   "wb+"读写    为了读和写, 建立一个新的二进制文件            建立一个新的文件

//   "ab+"读写    打开一个二进制文件，在文件尾进行读和写        建立一个新的文件

// int main()
// {
//     // 打开文件test.txt
//     // 相对路径
//     //fopen("test.txt","r");
//     // 绝对路径
//     //fopen("E:\\Project\\C\\TEST\\test.txt","r");

//     FILE *pf = fopen("test.txt", "w");
//     if(pf == NULL)
//     {
//         printf("%s\n",strerror(errno));
//         return 0;
//     }
//     // 打开成功
//     // 读文件

//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// 文件顺序读写
//        功能              函数名               适用于
// 字符输入函数              fgetc              所有输入流
// 字符输出函数              fputc              所有输出流
// 文本行输入函数            fgets              所有输入流
// 文本行输出函数            fputs              所有输出流
// 格式化输入函数            fscanf             所有输入流
// 格式化输出函数            fprintf            所有输出流
// 二进制输入                fread              文件
// 二进制输出                fwrite             文件

// 写文件
// int main()
// {
//     FILE *pfWrite = fopen("test.txt", "w");
//     if (pfWrite == NULL)
//     {
//         printf("%s\n", strerror(errno));
//         return 0;
//     }
//     // 写文件
//     fputc('o', pfWrite);
//     fputc('h', pfWrite);
//     fputc('h', pfWrite);
//     fputc('h', pfWrite);

//     // 关闭文件
//     fclose(pfWrite);
//     pfWrite = NULL;
//     return 0;
// }

// 读文件
// int main()
// {
//     FILE *pfRead = fopen("test.txt", "r");
//     if (pfRead == NULL)
//     {
//         printf("%s\n", strerror(errno));
//         return 0;
//     }
//     // 读文件
//     printf("%c", fgetc(pfRead)); // o
//     printf("%c", fgetc(pfRead)); // h
//     printf("%c", fgetc(pfRead)); // h
//     printf("%c", fgetc(pfRead)); // h

//     // 关闭文件
//     fclose(pfRead);
//     pfRead = NULL;
//     return 0;
// }

// 从键盘输入
// 输出到屏幕
// 键盘和屏幕都是外部设备
// 键盘-标准输入设备  stdin
// 屏幕-标准输出设备  stdout
// 是一个程序默认打开的两个流设备
// stdin---类型： FILE *
// stdout---类型： FILE *
// stderr---类型： FILE *

// int main()
// {
//     int ch = fgetc(stdin);
//     fputc(ch,stdout);
//     return 0;
// }

// int main()
// {
//     char buf[1024] = {0};
//     FILE *pfRead = fopen("test.txt", "r");
//     if (pfRead == NULL)
//     {
//         printf("%s\n", strerror(errno));
//         return 0;
//     }

//     // 读文件  fgets---行输入函数，只读行
//     // fgets(buf, 1024, pfRead);
//     // //printf("%s\n", buf);
//     // printf("%s", buf); // hello   注：buf 里面本来就有一个换行，所以不用加\n

//     // fgets(buf, 1024, pfRead);
//     // printf("%s", buf);  // world

//     puts(buf);
//     fgets(buf, 1024, pfRead);
//     //printf("%s\n", buf);
//     puts(buf); // hello \n \n

//     fgets(buf, 1024, pfRead);
//     puts(buf); // world

//     // 关闭文件
//     fclose(pfRead);
//     pfRead = NULL;
//     return 0;
// }

int main()
{
    char buf[1024] = {0};
    FILE *pfRead = fopen("test.txt", "w");
    if (pfRead == NULL)
    {
        printf("%s\n", strerror(errno));
        return 0;
    }

    // 写文件  fputs---行输入函数，只写一行，不加\n
    // fputs("hello",pfRead);
    // fputs("world",pfRead); 
    // // 输出 helloworld  没有换行，要换行需主动加\n

    fputs("hello\n",pfRead);
    fputs("world",pfRead); 
    // 输出 hello
    //      world 

    // 关闭文件
    fclose(pfRead);
    pfRead = NULL;
    return 0;
}
