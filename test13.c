#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
// void *my_memmove(void *dest, const void *src, size_t count)
// {
//     assert(dest != NULL);
//     assert(src != NULL);
//     void* ret = dest;
//     // if (dest < src || dest > (char*)src+count)
//     // {
//     //     // 前->后
//     // }
//     // else
//     // {
//     //     // 后->前
//     // }
//     if (dest < src)
//     {
//         // 前->后
//         while (count--)
//         {
//             *(char *)dest = *(char *)src;
//             (*(char *)dest)++;
//             (*(char *)src)++;
//         }
//     }
//     else
//     {
//         // 后->前
//         while (count--)
//         {
//             *((char *)dest + count) = *((char *)src + count);
//         }
//     }
//     return ret;
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     // my_memmove(arr + 2, arr, 20);
//     // int i = 0;
//     // for(i = 0; i < 10;i++)
//     // {
//     //     printf("%d ",arr[i]);// 1 2 1 2 3 4 5 8 9 10
//     // }
//     my_memmove(arr, arr + 2, 20);
//     int i = 0;
//     for (i = 0; i < 10; i++)
//     {
//         printf("%d ", arr[i]); //
//     }
//     return 0;
// }

//memcmp 内存比较
// int main()
// {
//     // 01 00 00 00 02 00 00 00 03 00 00 …………
//     // 01 00 00 00 02 00 00 00 05 00 00 …………
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[] = {1, 2, 5, 4, 3};
//     //int ret = memcmp(arr1,arr2,8); // 0 说明前8个字节一样
//     int ret = memcmp(arr1,arr2,9); // -1  第九个字节上小于下
//     printf("%d\n",ret);
//     return 0;
// }

//memset 内存设置 改的单位是字节
int main()
{
    char arr[10] = "";
    memset(arr,'#',10);
    printf("%s ",arr);
    //system("pause"); 
    return 0;
}
