#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// 文本行输入输出函数到标准流
// int main()
// {
//     // 从键盘读取一行文本信息
//     char buf[1024] = {0};
//     // fgets(buf, 1024, stdin);// 从标准输入流读取
//     // fputs(buf,stdout); // 输出到标准输出流

//     // 等价于这样写
//     gets(buf);
//     puts(buf);
//     return 0;
// }

// 格式化输入输出函数
// struct S
// {
//     int n;
//     float score;
//     char arr[10];
// };
// int main()
// {
//     struct S s = {100, 3.14, "hello"};
//     FILE *pf = fopen("text.txt", "w");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     // 格式化的形式写文件
//     fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// struct S
// {
//     int n;
//     float score;
//     char arr[10];
// };
// int main()
// {
//     struct S s = {0};

//     FILE *pf = fopen("text.txt", "r");
//     if (pf == NULL)
//     {
//         return 0;
//     }

//     // 格式化的形式输入数据
//     fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);
//     printf("%d %f %s\n", s.n, s.score, s.arr);

//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// struct S
// {
//     int n;
//     float score;
//     char arr[10];
// };
// int main()
// {
//     struct S s = {0};

//     // 格式化的形式输入数据
//     fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr);
//     fprintf(stdout,"%d %.2f %s\n", s.n, s.score, s.arr);
//     // %.2f 小数点后2位
//     return 0;
// }

// scanf /printf   是针对 标准 输入流 / 标准 输出流 的格式化 输入/输出 语句
// fscanf/fprintf  是针对 所有 输入流 / 所有 输出流 的格式化 输入/输出 语句
// sscanf          是从字符串中读取格式化的数据
// sprintf         是把格式化数据输出成(输出到)字符串

// struct S
// {
//     int n;
//     float score;
//     char arr[10];
// };
// int main()
// {
//     struct S s = {100, 3.14, "hello"};
//     struct S tmp = {0};
//     char buf[1024] = {0};
//     // 把格式化的数据转换成字符串存储到buf
//     sprintf(buf, "%d %f %s\n", s.n, s.score, s.arr);
//     //printf("%s\n", buf);
//     // 从buf中读取格式化的数据到tmp
//     sscanf(buf, "%d %f %s\n", &(tmp.n), &(tmp.score), tmp.arr);

//     printf("%d %f %s \n",tmp.n,tmp.score,tmp.arr);
//     return 0;
// }

// 二进制输入输出
// struct S
// {
//     char name[20];
//     int age;
//     double score;
// };

// int main()
// {
//     struct S s = {"张三",20,55.6};
//     FILE* pf = fopen("test.txt","wb");
//     if(pf == NULL)
//     {
//         return;
//     }
//     // 二进制的形式写文件
//     fwrite(&s,sizeof(struct S),1,pf);

//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// struct S
// {
//     char name[20];
//     int age;
//     double score;
// };

// int main()
// {
//     //struct S s = {"张三",20,55.6};
//     struct S tmp = {0};
//     FILE *pf = fopen("test.txt", "rb");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     // 二进制的形式读文件
//     fread(&tmp, sizeof(struct S), 1, pf);
//     printf("%s %d %lf\n",tmp.name,tmp.age,tmp.score);

//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// 文件的随机读写
int main()
{
    FILE *pf = fopen("text.txt", "r");
    if (pf == NULL)
    {
        return 0;
    }
    // text.txt: a b c d e f

    // 1.定位文件指针
    // int fseek(pf,(偏移量,单位:字节)，(文件指针的起始位置:SEEK_CUR(文件指针的当前位置)、SEEK_END(文件的末尾位置)、SEEK_SET(文件的起始位置)))
    // fseek(pf,2,SEEK_CUR); // 从文件指针的当前位置，默认为文件的起始位置   打印结果: c
     fseek(pf,-4,SEEK_END); // 从文件的末尾位置，   打印结果: c
    // fseek(pf,2,SEEK_SET); // 从文件的起始位置   打印结果: c
    // 2.读取文件
    int ch = fgetc(pf);
    printf("%c\n",ch); 
    // 关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
}
