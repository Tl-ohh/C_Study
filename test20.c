#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// 文件的随机读写
// ftell 返回文件指针性对于起始位置的偏移量
// int main()
// {
//     FILE *pf = fopen("text.txt", "r");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     // 定位文件指针
//     //fseek(pf,-2,SEEK_END); // 4
//     fgetc(pf); // 1
//     int pos = ftell(pf);
//     printf("%d\n",pos);
//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// rewind 让文件指针的位置回到文件的起始位置
// int main()
// {
//     FILE *pf = fopen("text.txt", "r");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     int ch1 = fgetc(pf);
//     rewind(pf);
//     int ch2 = fgetc(pf);
//     printf("ch1=%c ch2=%c",ch1,ch2);// a a
//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// feof
// 1.文本文件读取是否结束：判断返回值是否为EOF(fgetc),或者NULL(fgets)
// 例如 fgetc判断是否为EOF  fgets判断返回值是否为NULL
// 2. 二进制文件的读取结束判断：判断返回值是否小于实际要读的个数
// 例如 fread判断返回值是否要实际小于要读的个数
// int main()
// {
//     //EOF - END OF FILE
//     // feof 在文件读取的过程中，不能用feof函数的返回值直接用来判断文件是否结束
//     // 而是应用于当文件读取结束时，判断是读取失败，还是遇到文件收尾结束
//     FILE *pf = fopen("text.txt", "r");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     int ch = fgetc(pf);
//     printf("%d", ch);
//     fclose(pf);
//     pf = NULL; // -1
//     return 0;
// }

// perror
// int main()
// {
//     FILE *pf = fopen("text2.txt", "r");
//     if (pf == NULL)
//     {
//         perror("open file text2.txt");
//         // open file text2.txt: No such file or directory
//     }
//     // 读文件

//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// feof 不是判断结束，而是判断结束的原因
// int main()
// {
//     FILE *pf = fopen("text.txt", "r");
//     if (pf == NULL)
//     {
//         perror("open file text.txt");
//         return 0;
//     }
//     // 读文件
//     int ch = 0;
//     while ((ch = fgetc(pf)) != EOF)
//     {
//         putchar(ch);
//     }
//     if (ferror(pf))
//     {
//         printf("error\n");
//     }
//     else if (feof(pf))
//     {
//         printf("end of file\n");
//     }
//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// 程序的环境和预处理
//        -----------翻译环境-----------                    ----运行环境------
// test.c -----> 编译(编译器) -----> 链接(连接器) -----> test.exe -------> 运行
// 编译：
int main()
{
    int arr[10] = {0};
    int i;
    for (i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0; 
}
