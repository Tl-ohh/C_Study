#include<stdio.h>
#include <string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
// int main(){
//     int i = 0;
//     for(i=1; i<=9;i++){
//         int j = 1;
//         for ( j = 1;j <= i ; j++)
//         {
//             printf("%d*%d=%-2d ",i,j,i*j);
//         }
//        printf("\n"); 
//     }
//     return 0;
// }

// 生成1-100之间的随机数，然后猜数字
// void menu(){
//     printf("***********************\n");
//     printf("***1.play     0.exit***\n");
//     printf("***********************\n");
// }
// // RAND_MAX 最大为32767
// void game(){
//     // 1.生成随机数
//     int ret = 0;
//     int guess = 0;
//     ret = rand()%100+1; // rand()为生成随机数的函数 
//     // printf("%d\n",ret);
//     // 2.猜数字
//     while(1){
//         printf("请输入所猜数字>:");
//         scanf("%d",&guess);
//         if(guess > ret){
//             printf("猜大了\n");
//         }
//         else if(guess < ret){
//             printf("猜小了\n");
//         }
//         else
//         {
//             printf("猜中了！！！\n");
//             break;
//         }       
//     }  
// }
// int main(){
//     int input = 0;
//     srand((unsigned int) time(NULL));// 引入时间戳
//     do
//     {
//         menu();
//         printf("请选择>:");
//         scanf("%d",&input);
//         switch (input)
//         {
//         case 1:
//             game();
//             break;
//         case 0:
//             printf("退出游戏\n");
//             break;
//         default:
//             printf("选择错误\n");
//             break;
//         }
//     } while (input);  
//     return 0;
// }

// goto 语句
// int main(){
//     char input[20] = {0};
//     system("shutdown -s -t 120");
//     again;
//     printf("请注意，你的电脑将会在2分钟以内关机，如果输入：我是猪，就取消关机\n请输入>:");
//     scanf("%s",input);
//     if(strcmp(input,"我是猪") == 0){
//         system("shutdown -a");
//     }
//     else {
//         goto again; //会直接跳转到上面那个again那里重新开始
//     }
//     return 0;
// }

// int main(){
//     char arr1[] = "bit bit";
//     // char arr2[10] = "########";
//     // strcpy(arr1,arr2);
//     // printf("%s\n",arr2);

//     memset(arr1,'!',3); //内存设置(目标，设置的内容，个数)
//     printf("%s\n",arr1);
//     return 0;
// }

// 构造函数交换数字
// void Swap2(int* x,int* y){ // 形参
// // 当实参传给形参的时候，形参其实是实参的一份临时拷贝
// // 对形参的修改是不会改变实参的
//     int tmp = 0;
//     tmp = *x;
//     *x = *y;
//     *y = tmp;
// }
// // void Swap1(int m, int n){
// //     int tmp1 = 0;
// //     tmp1 = n;
// //     n = m;
// //     m = tmp1; 
// // }
// // 不能直接交换，需要借助内存地址再去交换
// int main(){
//     int a = 10;
//     int b = 20;
//     printf("a=%d b=%d\n",a,b);
//     // Swap1(a,b);// 实参 // 传值调用
//     // 传值调用:函数的形参和实参分别战友
//     // 不同的内存块，对形参的修改不会影响实参
//     Swap2(&a,&b);// 实参 // 传址调用
//     // 传址调用:这种传参方式可以让函数和函数外边
//     // 的变量建立起真正的联系,也是内部函数可
//     // 以直接操作函数外部的变量
//     printf("a=%d b=%d",a,b);
//     return 0;
// }

// 用函数判断100-200之间的素数
// int is_prime(int n){
//     int j = 0;
//     for(j=2;j<sqrt(n);j++){
//         if(n%j == 0){
//             return 0;
//         }
//         return 1;
//     }
// }
// int main(){
//     int i = 0;
//     for(i = 100; i<=200;i++){
//         if(is_prime(i) == 1){
//             printf("%-d是素数 ",i);
//         }
//     }
//     return 0;
// }

// 二分查找
// 在一个有序数组中查找具体的某个数，找到返回下标，否则为-1
                // 这里传过来的是arr首元素的地址，本质是指针
// int binary_search(int arr[],int k,int sz){
//     int left = 0; // 左下标
//     int right = sz - 1; // 右下标
//     while(left <= right){
//         int mid = (left + right)/2;
//         if(arr[mid] < k){
//             left = mid + 1;
//             }
//         else if(arr[mid] > k){
//             right = mid - 1;
//             }   
//         else{
//             return mid;
//         }
//     }
//     return -1;
// }
// int main(){
//     int arr[]= {1,2,3,4,5,6,7,8,9,10};
//     int k = 5;
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     int ret = binary_search(arr,k,sz);
//     if(ret == -1){
//         printf("找不到指定的数字\n");
//     }
//     else{
//         printf("找到了，下标是: %d\n",ret);
//     }
//     return 0;
// }

// void Add(int* p){
//     (*p)++;
//     // ++*p;
// }
// int main(){
//     int num = 0;
//     Add(&num);
//     printf("num= %d\n",num);
//     Add(&num);
//     printf("num= %d\n",num);
//     Add(&num);
//     printf("num= %d\n",num);
//     Add(&num);
//     printf("num= %d\n",num);
//     return 0;
// }

// 函数的嵌套调用
// 函数的链式访问
// int main(){
//     printf("%d",printf("%d",printf("%d",100)));
//     //4321
//     return 0;
// }

// int main(){
//     int a = 10;
//     int b = 20;
//     int sum = 0;
//     sum = Add(a,b);
//     printf("%d",sum);
// }

// 递归 自身调用自身，把大型复杂问题层层转化为一个与
//原问题相似的规模较小的问题来求解
// 栈区：局部变量、函数形参
// 堆区：动态开辟的内存，malloc、calloc
// 静态区：全局变量、static修饰的变量
// 递归要找到限制条件，且每次调用都要逼近这个条件
// void print(int n){
//     if(n > 9){
//         print(n / 10);
//     }
//     printf("%d ",n%10);
// }
// int main(){
//     unsigned int num = 0;
//     printf("请输入>:");
//     scanf("%d",&num);
//     print(num);
//     return 0;
// }

// 用递归求字符串长度
// int my_strlen(char* n){
//     if(*n != '\0')
//     return 1 + my_strlen(n+1);
//     else
//     return 0;
// }
// int main(){
//     char arr[] = "bittt";
//     printf("字符串长度为%d\n",my_strlen(arr));
//     return 0;
// }

// 用递归求数的阶乘
// int Fac(int x){
//     if(x > 1)
//     return x * Fac(x-1);
//     else
//     return 1;
// }
// int main(){
//     int n = 0;
//     int ret = 0;
//     printf("请输入数字>:");
//     scanf("%d",&n);
//     ret = Fac(n);
//     printf("所输入数字的阶乘为%d",ret);
//     return 0;
// }

// 用递归求第n个菲波那切数
int Fib(int k){
    // 使用递归会重复大量计算，建议使用循环
    // if(k <= 2){
    //     return 1;
    // }
    // else
    // return Fib(k-1) + Fib(k-2);

    // 使用循环则很快
    int a = 1;
    int b = 1;
    int c = 1;
    while(k>2){
        c = a + b;
        a = b;
        b = c;
        k--;
    }
    return c;
}
int main(){
    int n = 0;
    int ret = 0;
    printf("请输入数字>:");
    scanf("%d",&n);
    ret = Fib(n);
    printf("所输入数字的斐波那契数为%d",ret);
    return 0;
}
