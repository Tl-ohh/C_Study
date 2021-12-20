#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>

// 二级指针
// void test(int** ptr){
//     printf("num = %d\n",**ptr);
// }
// int main(){
//     int n = 10;
//     int* p = &n;
//     int** pp = &p;
//     test(pp); // 二级指针
//     test(&p); // 一级指针的地址
//     // 形参是二级指针，主函数可以传二级指针、一级指针的地址、一级指针数组的数组名(指针数组)
//     return 0;
// }

// 函数指针----指向函数的指针/存放函数地址的指针
// int Add(int x,int y){
//     return x+y;
// }
// int main(){
//     int a = 10;
//     int b = 20;
//     // &函数名 和 函数名都是函数的地址
//     // printf("%d\n",Add(a,b));
//     // printf("%p",&Add); // 00401410
//     // printf("%p",Add); // 00401410
//     int (*pa)(int,int) = Add; // 函数指针
//     printf("%d\n",Add(a,b)); // 30
//     printf("%d\n",pa(a,b)); // 30
//     printf("%d\n",(*pa)(a,b)); // 30
//     // 说明*没什么用
// }

// void Print(char* str){
//     printf("%s\n",str);
// }
// int main(){
//     void (*p)(char*) = Print;
//     (*p)("hello world!");
//     return 0;
// }

// (*  (void (*)()  )  0)();
// 1.  ()0，是把0强制类型转换
// 2.  void (*)()是函数指针类型
// 通过1和2，则是 (void (*)())0，把0强制类型转换成函数指针类型，0则是函数地址
// *(void (*)())0 () 则是解引用，因为0是函数地址，解引用就是调用函数,传参则是()

// void (*signal(int,void(*)(int))) (int)
// void (*)(int) 函数指针
// signal(int,void(*)(int)) 中 void(*)(int)是函数指针类型
// signal是一个函数声明
// signal函数的参数有2个，第一个是int，第二个是函数指针，该函数指针指向的函数的参数是int，返回类型是void，
// signal函数的返回类型也是一个函数指针，该函数指针的函数参数是int，返回类型是void

// 函数指针数组
// int Add(int x,int y){
//     return x + y;
// }
// int Sub(int x,int y){
//     return x - y;
// }
// int Mul(int x,int y){
//     return x * y;
// }
// int Div(int x,int y){
//     return x / y;
// }
// int main(){
//     // 需要一个数组，这个数组可以存放4个函数的地址--函数指针的数组
//     int (*parr[4])(int,int) = {Add,Sub,Mul,Div}; // 函数指针的数组
//     for(int i = 0;i<4;i++)
//     {
//         printf("%d\n",parr[i](2,3));
//     }
// }

// char* my_strcpy(char* dest,const char* src)
// // 写一个函数指针 pf 能够指向my_strcpy
// char* (*pf)(char*,const char*)
// // 写一个函数指针数组 pfarr 能够存放4个my_strcpy函数的地址
// char* (*pfarr[4])(char*,const char*) = {my_strcpy,my_strcpy,my_strcpy,my_strcpy}

// void menu(){
//     printf("********************\n");
//     printf("***1.add    2.sub***\n");
//     printf("***3.mul    4.div***\n");
//     printf("***5.XOR   0.exit***\n");
//     printf("********************\n");
// }
// int Add(int x,int y){
//     return x + y;
// }
// int Sub(int x,int y){
//     return x - y;
// }
// int Mul(int x,int y){
//     return x * y;
// }
// int Div(int x,int y){
//     return x / y;
// }
// int XOR(int x,int y){
//     return x ^ y;
// }

// int main(){
//     int input = 0;
//     int x = 0;
//     int y = 0;
//     int (*pfArr[])(int,int) = {0,Add,Sub,Mul,Div,XOR};
//     do
//     {
//         menu();
//         printf("请选择:>");
//         scanf("%d",&input); 
//         if(input >= 1 && input <= 5)
//         {
//             printf("请选择输入两个操作数:>");
//             scanf("%d%d",&x,&y);
//             int ret = pfArr[input](x,y);
//             printf("%d\n",ret);
//         }
//         else if(input == 0)
//         {
//             printf("退出\n");
//         }
//         else
//         {
//             printf("选择错误\n");
//         }   
//     } while (input);    
// }
// int main(){
//     int input = 0;
//     int x = 0;
//     int y = 0;
//     do
//     {
//         menu();
//         printf("请选择:>");
//         scanf("%d",&input);
//         switch (input)
//         {
//         case 1:
//             printf("请选择输入两个操作数:>");
//             scanf("%d%d",&x,&y);
//             printf("%d\n",Add(x,y));
//             break;
//         case 2:
//             printf("请选择输入两个操作数:>");
//             scanf("%d%d",&x,&y);
//             printf("%d\n",Sub(x,y));
//             break;
//         case 3:
//             printf("请选择输入两个操作数:>");
//             scanf("%d%d",&x,&y);
//             printf("%d\n",Mul(x,y));
//             break;
//         case 4:
//             printf("请选择输入两个操作数:>");
//             scanf("%d%d",&x,&y);
//             printf("%d\n",Div(x,y));
//             break;
//         case 0:
//             printf("退出\n");
//             break;
//         default:
//             printf("选择错误\n");
//             break;
//         }
//     } while (input);   
// }


// void menu(){
//     printf("********************\n");
//     printf("***1.add    2.sub***\n");
//     printf("***3.mul    4.div***\n");
//     printf("***    0.exit    ***\n");
//     printf("********************\n");
// }
// int Add(int x,int y){
//     return x + y;
// }
// int Sub(int x,int y){
//     return x - y;
// }
// int Mul(int x,int y){
//     return x * y;
// }
// int Div(int x,int y){
//     return x / y;
// }
// // 回调函数：通过函数指针调用的函数
// void Calc(int (*pf)(int,int)){
//     int x = 0;
//     int y = 0;
//     printf("请选择输入两个操作数:>");
//     scanf("%d%d",&x,&y);
//     printf("%d\n",pf(x,y));
// }
// int main(){
//     int input = 0;
//     int x = 0;
//     int y = 0;
//     do
//     {
//         menu();
//         printf("请选择:>");
//         scanf("%d",&input);
//         switch (input)
//         {
//         case 1:
//             Calc(Add);
//             break;
//         case 2:
//             Calc(Sub);
//             break;
//         case 3:
//             Calc(Mul);
//             break;
//         case 4:
//             Calc(Div);
//             break;
//         case 0:
//             printf("退出\n");
//             break;
//         default:
//             printf("选择错误\n");
//             break;
//         }
//     } while (input);   
// }

//指向函数指针数组的指针
// int Add(int x,int y){
//     return x + y;
// }
// int main(){
//     int arr[10] = {0};
//     int (*p)[10] = &arr;
//     int (*pfArr[4])(int,int);
//     // ppfArr是一个数组指针，是指向函数指针数组的指针，
//     // 指向的数组有4个元素，指向的数组的每个元素的类型是一个函数指针-int(*)(int,int)
//     int (*(*ppfArr)[4])(int,int) = &pfArr;
//     return 0;
// }

// int main()
// {
//     // void* 类型的指针，可以接收任意类型的地址
//     // void* 类型的指针，不能解引用操作,不能加减整数的操作
//     int a = 10;
//     void* pa = &a;
//     // printf("%d", (int)*pa = 0);
//     return 0;
// }

// qsort 快速排序 
int cmp_int(const void* e1, const void* e2)
{
    // 相等返回0、e1<e2返回小于0的数、e1>e2返回大于0的数
    return *(int*)e1 - *(int*)e2;
}
void test_int()
{
    int arr[] = {3,5,9,4,1,0,6,8,7,2};
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort(arr,sz,sizeof(arr[0]),cmp_int);
    int i = 0;
    for( i = 0;i < sz; i++)
    {
        printf("%d ",arr[i]);
    }
}

int cmp_float(const void* e1, const void* e2)
{
    // if((*(float*)e1) == (*(float*)e2))
    // {
    //     return 0;
    // }
    // else if((*(float*)e1) > (*(float*)e2))
    // {
    //     return 1;
    // }
    // else 
    // {
    //     return -1;
    // }
    return ((int)(*(float*)e1 - *(float*)e2));
}
void test_float()
{
    float f[] = {3.1,4.1,1.0,0.9,2.1};
    int sz = sizeof(f) / sizeof(f[0]);
    qsort(f,sz,sizeof(f[0]),cmp_float);
    int j = 0;
    for( j = 0;j < sz; j++)
    {
        printf("%f ",f[j]);
    }
}

typedef struct Stu
{
    char name[20];
    int age;
} Stu;
void test_Stu_by_age(){
    Stu s[] = {{"zhangsan",20},{"lisi",10},{"wangwu",20}};
    int sz = sizeof(s) / sizeof(s[0]);
    qsort(s,sz,sizeof(s[0]),cmp_Stu_by_age);   
}
int cmp_Stu_by_age(const void* e1, const void* e2)
{
    return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age
}

void test_Stu_by_name(){
    Stu s[] = {{"zhangsan",20},{"lisi",10},{"wangwu",20}};
    int sz = sizeof(s) / sizeof(s[0]);
    qsort(s,sz,sizeof(s[0]),cmp_Stu_by_name);   
}
int cmp_Stu_by_name(const void* e1, const void* e2)
{
    // 比较名字字符串不能直接比较
    // 要使用 strcmp
    // 字符串比大小比的是比较首个字符的大小，换成ASCII码比
    return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name)
}
int main()
{
    // test_int(); // 整型数组的qsort排序
    // test_float(); // 浮点型数组的qsort排序
    // test_Stu_by_age(); // 结构体Stu中年龄的qsort排序
    test_Stu_by_name(); // 结构体Stu中名字的qsort排序
    return 0;
}
// qsort(s,sz,sizeof(s[0]),cmp_Stu_by_name);
// 第一个参数：待排序数组的首元素地址
// 第二个参数：待排序数组的元素个数
// 第三个参数：待排序数组的每个元素的大小-单位字节
// 第四个参数：是函数指针，比较两个元素的方法和函数的地址-函数是自己实现
//             函数指针的两个参数：待比较的两个元素的地址

// qsort 实现原理，用普遍的bubble_sort代替qsort
// typedef struct Stu
// {
//     char name[20];
//     int age;
// } Stu;

// int main()
// {
//     test_command();
//     return 0;
// }
