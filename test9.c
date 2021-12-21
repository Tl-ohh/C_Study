#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>

// void Swap(char* buf1,char* buf2, int width)
// {
//     int i = 0;
//     for(i = 0; i< width;i++)
//     {
//         char tmp = *buf1;
//         *buf1 = *buf2;
//         *buf2 = tmp;
//         buf1++;
//         buf2++;
//     }
// }
// //         qsort(void* base, size_t num, size_t width, int(*cmp)(const void* e1,const void* e2));
// void bubble_sort(void* base, int sz ,    int width,    int(*cmp)(const void* e1,const void* e2))
// {
//     int i = 0; // 趟数
//     for(i=0;i<sz-1;i++){
//         // 每一趟比较的对儿数
//         int j = 0;
//         for(j = 0;j<sz-i-1;j++){
//             // 两个元素的比较
//             if(cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)
//             {
//                 // 交换
//                 Swap((char*)base+j*width,(char*)base+(j+1)*width,width);
//             }
//         }
//     }
// }
// int cmp_int(const void* e1, const void* e2)
// {
//     // 相等返回0、e1<e2返回小于0的数、e1>e2返回大于0的数
//     return *(int*)e1 - *(int*)e2;
// }
// void test_int()
// {
//    int arr[] = {3,5,9,4,1,0,6,8,7,2};
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);
//    int i = 0;
//     for( i = 0;i < sz; i++)
//     {
//         printf("%d ",arr[i]);
//     }
// }
// // int cmp_Stu_by_age(const void* e1, const void* e2)
// // {
// //     return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
// // }
// int cmp_Stu_by_name(const void* e1, const void* e2)
// {
//     // 比较名字字符串不能直接比较
//     // 要使用 strcmp
//     // 字符串比大小比的是比较首个字符的大小，换成ASCII码比
//     return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);
// }
// typedef struct Stu
// {
//     char name[20];
//     int age;
// } Stu;

// // void test_Stu_by_age()
// // {
// //     Stu s[] = {{"zhangsan",20},{"lisi",10},{"wangwu",20}};
// //     int sz = sizeof(s) / sizeof(s[0]);
// //     bubble_sort(s,sz,sizeof(s[0]),cmp_Stu_by_age);
// // //     int i = 0;
// // //     for(i = 0; i<3;i++)
// // //     {
// // //         printf("%d\n",*s->age);
// // //     }
// // }

// void test_Stu_by_name()
// {
//     Stu s[] = {{"zhangsan",20},{"lisi",10},{"wangwu",20}};
//     int sz = sizeof(s) / sizeof(s[0]);
//     bubble_sort(s,sz,sizeof(s[0]),cmp_Stu_by_name);
// //     int i ,j;
// //     for(i = 0; i<3;++)
// //     {
// //         for(j=0;j<3;j++)
// //         {
// //             printf("%C%d\n",s[i][j]);
// //         }
// //     }
// // }
// int main()
// {
//     // test_int();
//     // test_Stu_by_age(); // 结构体Stu中年龄的qsort排序
//     test_Stu_by_name(); // 结构体Stu中名字的qsort排序
//     return 0;
// }

// // 交换
// void Swap(char*buf1,char*buf2,int width)
// {
//     char tmp = *buf1;
//     *buf1 = *buf2;
//     *buf2 = tmp;
//     buf1++;
//     buf2++;
// }
// // 排序
// void bubble_sort(void*base,int sz,int width, int(*cmp)(const void* e1,const void* e2))
// {
//     int i;
//     for(i = 0;i<sz;i++)
//     {
//         int j;
//         for(j = 0 ;j<sz-i-1;j++)
//         {
//             if(cmp((char*)base+j*width,(char*)base+(j+1)*width) > 0) // ">"为升序，"<"为降序
//             {
//                 Swap((char*)base+j*width,(char*)base+(j+1)*width,width);
//             }
//         }
//     }
// }
// // 比较方法
// int cmp_int(const void* e1,const void* e2)
// {
//     return *(int*)e1 - *(int*)e2;
// }
// // 声明
// void test()
// {
//     int arr[] = {3,6,9,8,5,2,1,4,7,0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);
//     int i;
//     for(i = 0;i<sz;i++)
//     {
//         printf("%d ",arr[i]);
//     }
// }
// int main(){
//    test();// 调用
//    return 0;
// }

// int main()
// {
//     // 数组名是首元素地址
//     // 1.sizeof(数组名)-数组名表示整个数组
//     // 2.&数组名---数组名表示整个数组

//     int a[] = {1,2,3,4};
//     printf("1 %d\n",sizeof(a)); // 16 -sizeof(数组名)-计算的是数组总大小-单位字节
//     printf("2 %d\n",sizeof(a+0)); // 4/8 -数组名这里表示的是首元素的值，a+0还是首元素
//     printf("3 %d\n",sizeof(*a)); // 4 -数组名表比表示首元素地址 *a还是首元素，sizeof(*a)为4
//     printf("4 %d\n",sizeof(a+1)); // 4/8 -数组名表比表示首元素地址，a+1是第二个元素的地址，地址大小就是4/8
//     printf("5 %d\n",sizeof(a[1]));//4 -第二个元素的大小
//     printf("6 %d\n",sizeof(&a));// 4/8 -&a取出的是数组的地址，数组的地址也是地址，所以是4/8字节
//     printf("7 %d\n",sizeof(*&a)); // 16 -*&相互抵消，所以还是a,大小即为16字节
//     printf("8 %d\n",sizeof(&a+1)); // 4/8 -为地址，所以是4/8字节
//     printf("9 %d\n",sizeof(&a[0])); // 4/8 -为地址，所以是4/8字节
//     printf("10 %d\n",sizeof(&a[0]+1)); // 4/8 -为地址，所以是4/8字节
// }

// int main()
// {
//     char arr[] = {'a','b','c','d','e','f'};
//     // printf("1 %d\n",sizeof(arr));// 6 -数组总大小
//     // printf("2 %d\n",sizeof(arr+0));// 4/8 -首元素的地址
//     // printf("3 %d\n",sizeof(*arr));// 1 -首元素地址解引用为首元素，首元素是字符为1字节
//     // printf("4 %d\n",sizeof(arr[1]));// 1 -
//     // printf("5 %d\n",sizeof(&arr));// 4/8 -为地址，所以是4/8字节
//     // printf("6 %d\n",sizeof(&arr+1));// 4/8 -为地址，所以是4/8字节
//     // printf("7 %d\n",sizeof(&arr[0]+1));// 4/8 -为地址，所以是4/8字节
    
//     // strlen要找到 \0才会停止
//     printf("1 %d\n",strlen(arr));// 随机值--- \0的位置不确定
//     printf("2 %d\n",strlen(arr+0));// 随机值--- \0的位置不确定
//     //printf("3 %d\n",strlen(*arr));// 非法访问---error
//     //printf("4 %d\n",strlen(arr[1]));// 非法访问---error
//     printf("5 %d\n",strlen(&arr));// 随机值--- \0的位置不确定
//     printf("6 %d\n",strlen(&arr+1));// 随机值--- \0的位置不确定
//     printf("7 %d\n",strlen(&arr[0]+1));// 随机值--- \0的位置不确定
// } 

int main()
{
    // a b c d e f \0
    char arr[] = "abcdef";
    // printf("1 %d\n",sizeof(arr));// 7 -a b c d e f \0,sizeof计算的是所占空间大小-单位字节
    // printf("2 %d\n",sizeof(arr+0));// 4/8 -为地址，所以是4/8字节
    // printf("3 %d\n",sizeof(*arr));// 1- *arr是首元素，sizeof计算的是首元素大小
    // printf("4 %d\n",sizeof(arr[1]));// 1 -arr[1]第2个元素，sizeof计算的是第2个元素大小
    // printf("5 %d\n",sizeof(&arr));// 4/8 -为地址，所以是4/8字节
    // printf("6 %d\n",sizeof(&arr+1));// 4/8 -为地址，所以是4/8字节
    // printf("7 %d\n",sizeof(&arr[0]+1));// 4/8 -为地址，所以是4/8字节 

    // a b c d e f \0 
    // strlen要找到 \0才会停止
    printf("1 %d\n",strlen(arr));// 6 -从首元素地址开始算
    printf("2 %d\n",strlen(arr+0));// 6 -从首元素地址开始算
    //printf("3 %d\n",strlen(*arr));// 非法访问---error
    //printf("4 %d\n",strlen(arr[1]));//  非法访问---error
    printf("5 %d\n",strlen(&arr));// 6 -从首元素地址开始算
    printf("6 %d\n",strlen(&arr+1));// 随机值
    printf("7 %d\n",strlen(&arr[0]+1));// 5 -从第2个元素地址开始算
}
