#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
// strtok 分隔符
// 第一个参数不为NULL时，函数找到
// int main()
// {
//     char arr[] = "xyz@bigc.edu";
//     char* p = "@.";
//     char buf[1024] = {0};
//     strcpy(buf,arr);
    
//     char* ret = NULL;
//     for(ret = strtok(arr,p);ret != NULL;ret = strtok(NULL,p))
//     {
//         printf("%s\n",ret);
//     }
    
//     // ret = strtok(NULL,p);
//     // printf("%s\n",ret);
//     // ret = strtok(NULL,p);
//     // printf("%s\n",ret);
//     // ret = strtok(NULL,p);
// }

// strerror 返回错误码，所对应的错误信息
// int main()
// {
//     // char* str = strerror(0);// No error
//     // char* str = strerror(1);// Operation not permitted
//     // char* str = strerror(2);// No such file or directory
//     // ………………………………………………………………
    
//     // errno 是一个全局的错误码的变量
//     // 当C语言的库函数在执行过程中，发生了错误，就会把对应的错误码，赋值到errno中  
//     // char* str = strerror(errno);

//     FILE* pf = fopen("test13.c","r");
//     if(pf == NULL)
//     {
//         printf("%s\n",strerror(errno));
//     }
//     else
//     {
//         printf("open file success\n");
//     }
// }

// 字符分类函数
// int main()
// {
//     char ch = '7';
//     //int ret = islower(ch);
//     //int ret = isdigit(ch);
//     printf("%d\n",ret);
//     return 0;
//     // 1. iscntrl 任何控制字符
//     // 2. isspace 空白字符：空格、换页'\f'、换行'\n'、回车'\r'、制表符'\t'或垂直制表符'\v'
//     // 3. isdigit 十进制数字0~9
//     // 4. isxdigit 十六进制数字,包括所有十进制，小写字母a~f,大写字母A~Z
//     // 5. islower  小写字母a~z
//     // 6. isupper  大写字母A~Z
//     // 7. isalpha 字母a~z或者A~Z
//     // 8. isalnum 字母或者数字，a~z,A~Z,0~9
//     // 9. ispunct 标点符号，任何不属于字母或数字的图形字符(可打印)
//     // 10. ispraph 任何图形字符
//     // 11. isprint 任何可打印字符，包括图形字符和空白字符
// }

// 字符转换函数
// tolower 转小写字母
// toupper 转大写字母
// int main()
// {
//     // tolower 转小写字母
//     // char ch = tolower('Q');
    
//     // toupper 转大写字母
//     // char ch = toupper('q');
//     // putchar(ch);

//     char arr[] = "I AM a StuDent";
//     int i = 0;
//     while(arr[i])
//     {
//         if(isupper(arr[i]))
//         {
//             arr[i] = tolower(arr[i]);
//         } 
//         i++;
//     }
//     printf("%s\n",arr);
// }

// 内存函数: memcpy memmove memcmp memset

// memcpy
// int main()
// {
//     // void *memcpy (void *, const void *, size_t);
//     int arr1[3] = {1,2,3};
//     int arr2[3] = {4,5,6};
//     memcpy(arr2,arr1,3);
//     return 0;
// }

// typedef struct Stu
// {
//     char name[20];
//     int age;
// } Stu;

// void* my_memcpy(void* dest, const void* src, size_t num)
// {
//     void* ret = dest;
//     assert(dest && src);
//     while(num--)
//     {
//         *(char*)dest = *(char*)src;
//         ++(char*)dest;
//         ++(char*)src;
//     }
//     return ret;
// }
// int main()
// {
//     // Stu s1 = {"张三",10};
//     // Stu s2 = {};
//     char c = 'abc';
//     char d = 'xyz';
//     //my_memcpy(s2,s1,sizeof(s1));
//     // printf("%s\n",*(s2).name); 
//     // printf("%s\n",*(s2).age); 
//     my_memcpy(d,c,sizeof(c));
//     printf("%d",d);
//     return 0;
// }

// memmove 处理内存重叠拷贝
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    // memcpy(arr+2,arr,20); // 1 2 1 2 3 4 5 8 9 10 
    // memmove(arr+2,arr,20); // 1 2 1 2 3 4 5 8 9 10 
    for(i = 0; i<10; i++)
    {
        printf("%d ",arr[i]);
    }
}
