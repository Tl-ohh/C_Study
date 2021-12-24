#include<stdio.h>
#include <string.h>
#include <assert.h>

// 长度不受限制的字符串函数：strcpy、strcat、strcmp,以\0为结束
// strlen 字符串长度
// int main()
// {
//     // 3 - 6 = -3 但是strlen返回的是无符号数，所以一定大于0
//     if(strlen("abc")-strlen("abcdef")>0)
//     {
//         printf("haha\n");
//     }
//     else{
//         printf("hehe");
//     }
// }

// strcpy 字符串拷贝
// 源字符串(src)必须以'\0'结束
// 会将源字符串中的'\0'拷贝到目标空间
// 目标空间必须足够大，以确保能存放源字符串
// 目标空间必须可修改

// char* my_strcpy(char* dest, const char* src)
// {
//     assert(dest != NULL);
//     assert(src != NULL);
//     char* ret = dest;
//     // 拷贝src指向的字符串带dest指向的空间,包含\0
//     while (*dest++ =*src++)
//     {
//         ;
//     }
//     // 返回目的空间的起始地址
//     return ret;
// }
// int main()
// {
//     char arr1[] = "abcdef";
//     // char *arr1 = "abcdef"; // 错误示范：目标空间为常量字符串，不可变
//     // char arr1[] = "a"; 错误示范：目标空间不够大
//     char arr2[] = "lop";
//     // char arr2[] = {'b','i','t'}; 错误示范：没有以\0结束
//     my_strcpy(arr1,arr2);
//     printf("%s\n",arr1);
// }

// strcat 字符串追加
// 源字符串必须以'\0'结束
// 目标空间必须足够大，以确保能存放源字符串
// 目标空间必须可修改
// char* my_strcat(char* dest,const char* src)
// {
//     assert(dest && src);
//     char* ret = dest;
//     // 1.找到目标字符串的\0
//     while (*dest != '\0')
//     {
//         dest++;
//     }
//     // 2. 追加或者说拷贝
//     while (*dest++ =*src++)
//     {
//         ;
//     }
//     // 返回目的空间的起始地址
//     return ret;  
// }
// int main()
// {
//     // char arr1[] = "hello"; 错误示范,目标空间要足够大
//     char arr1[30] = "hello";
//     char arr2[] = " world"; // 追加在\0的后面，因此目标空间必须含有\0
//     // strcat(arr1,arr2);
//     my_strcat(arr1,arr2);
//     printf("%s\n",arr1);
//     return 0;
// }

// strcmp 字符串比较
// 比较的是首字符的ASCII值大小，相等则往后比
// int main()
// {
//     char* p1 = "a";
//     char* p2 = "x";
//     char* p3 = "x";
//     // 字符串1<字符串2 返回<0的数字  -1
//     // 字符串1=字符串2 返回0         0 
//     // 字符串1>字符串2 返回>0的数字   1
//     printf("%d\n",strcmp(p1,p2)); //a<x -1
//     printf("%d\n",strcmp(p2,p1)); //x>a  1
//     printf("%d\n",strcmp(p3,p2)); //x=x  0
//     return 0;
// }
// int my_strcmp(const char* str1, const char* str2)
// {
//     assert(str1 && str2);
//     while (*str1 == *str2)
//     {
//         if(*str1 == '\0'){
//             return 0;
//         }
//         str1++;
//         str2++;
//     }
//     // 返回 1 -1
//     // if(*str1 > * str2)
//     // {
//     //     return 1;
//     // }
//     // else
//     // {
//     //     return -1;
//     // } 
    
//     // 返回大于0、小于0
//     return(*str1 -*str2);
// }
// int main()
// {
//     char* p1 = "a";
//     char* p2 = "x";
//     char* p3 = "x";
//     printf("%d\n",my_strcmp(p1,p2)); //a<x -1  -23
//     printf("%d\n",my_strcmp(p2,p1)); //x>a  1   23
//     printf("%d\n",my_strcmp(p3,p2)); //x=x  0    0
//     return 0;
// }

// 长度受限制的字符串函数：strncpy、strncat、strncmp
// strncpy
// int main()
// {
//     char arr1[10] = "abcdef";
//     char arr2[] = "xyz";
//     //printf("%s\n",strcpy(arr1,arr2));
//     //printf("%s\n",strncpy(arr1,arr2,0)); // abcdef
//     //printf("%s\n",strncpy(arr1,arr2,1)); // xbcdef
//     //printf("%s\n",strncpy(arr1,arr2,2)); // xycdef
//     //printf("%s\n",strncpy(arr1,arr2,3)); // xyzdef
//     //printf("%s\n",strncpy(arr1,arr2,4)); // xyz
//     //printf("%s\n",strncpy(arr1,arr2,5)); // xyz
// }

// strncat
// int main()
// {
//     char arr1[30] = "hello\0xxxxxxx";
//     char arr2[] = " world";
//     //printf("%s\n",strncat(arr1,arr2,2)); // hello w
//     //printf("%s\n",strncat(arr1,arr2,3)); // hello wo
    
//     printf("%s\n",strncat(arr1,arr2,8)); // hello world
//     // 说明追加之后补了\0
// }

// strncmp
// int main()
// {
//     char* p1 = "abc";
//     char* p2 = "abz";
//     // 限制比较几个字符
//     printf("%d\n",strncmp(p1,p2,1));// 0
//     printf("%d\n",strncmp(p1,p2,2));// 0
//     printf("%d\n",strncmp(p1,p2,3));// -23
//     return 0;
// }


// NULL --空指针
// NUL或Null --'\0'

// strstr 查找子字符串
// int main()
// {
//     char* p1 = "abcdefg";
//     char* p4 = "abcdefgabcdefg";
//     char* p2 = "def";
//     char* p3 = "defh";
//     char* ret1 = strstr(p1,p2);
//     char* ret2 = strstr(p1,p3); 
//     char* ret3 = strstr(p4,p2); 
//     // if(ret1 == NULL)
//     // {
//     //     printf("子字符串不存在");
//     // }
//     // else
//     // {
//     //    printf("%s\n",ret1); // defg  
//     // }
//     // if(ret2 == NULL)
//     // {
//     //     printf("子字符串不存在");
//     // }
//     // else
//     // {
//     //    printf("%s\n",ret2); 
      
//     // }
//     if(ret3 == NULL)
//     {
//         printf("子字符串不存在");
//     }
//     else
//     {
//        printf("%s\n",ret3); // defgabcdefg
//        // 说明找的是第一次出现的位置
//     }
//     return 0;
// }
char* my_strstr(const char* p1,const char* p2)
{
    assert(p1 && p2);
    char* s1 = NULL;
    char* s2 = NULL;
    char* cur = (char*) p1;
    if(*p2 == '\0')
    {
        // 为空字符串返回p1
        return (char*) p1;
    }
    while (*cur)
    {
        s1 = cur;
        s2 = (char*) p2;
        while(*s1 && *s2 && !(*s1 -*s2)) // 更简洁的写法
       // while((*s1 == *s2) && (*s2 != '\0') && (*s1 != '\0'))
        {
            s1++;
            s2++;
        }
        if(*s2 == '\0')
        {
            return cur; // 找到了
        }
        if(*s1 == '\0')
        {
            return NULL;
        }
        cur++;
    }
    return NULL; // 找不到
}
int main()
{
    char* p1 = "abcddddefghi";
    char* p2 = "ddef";
    char* ret1 = my_strstr(p1,p2);
    if(ret1 == NULL)
    {
        printf("子字符串不存在");
    }
    else
    {
       printf("%s\n",ret1); // defg  
    }       
    return 0;
}
