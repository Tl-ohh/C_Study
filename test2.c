#include<stdio.h>
#include <string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
// <------if语句----->
// int main(){
//     int a = 1;
//     int b = 2;
//     if (a == 1){
//        if(b == 2){
//           printf("hhhh\n"); 
//        }
//      else
//      printf("haha\n"); 
//     }   
//     return 0;    
// }

// int main(){
//     // int a;
//     // scanf("%d",&a);
//     // if(a%2 == 1){
//     //     printf("a为奇数\n");
//     // }
//     // else{
//     //     printf("a为偶数\n");
//     // }

//     // for(a = 1; a<= 100; a++){
//     //     if(a%2 == 1){
//     //         printf("a=%d\n",a);
//     //     }
//     // } 
//     return 0;
// }

// int main(){
//     int day = 0;
//     int n = 1;
//     scanf("%d",&day);
//     switch (day)
//     {
//     case 1:
//     case 2:
//     case 3:
//     case 4:
//     case 5:
//     printf("工作日\n");
//         break;
//     case 6:
//     case 7:
//     printf("休息日\n");
//         break;
//     default:
//     printf("输入错误\n");
//         break;
//     }
//     return 0;
// }

// int main(){
//     int i = 0;
//     while (i <= 10)
//     {
//         i++;
//         if(i == 5)
//             continue;//终止本次循环, continue条件跳
//             //break; while中break直接永久终止循环，break全跳
//             printf("%d ",i);
            
//     }
    
//     return 0;
// }

// int main(){
//     int ret = 0;
//     int ch = 0;
//     char password[20] = {0};
//     printf("请输入密码:>");
//     scanf("%s",password);
//     while ((ch = getchar()) != '\n') 
//     {
//         ;
//     }   
//     printf("请确认(Y/N):>");
//     ret = getchar();
//     if(ret == 'Y'){
//         printf("确认成功\n");
//     }
//     else{
//         printf("放弃确认\n");
//     }
//     return 0;
// }

// int main(){
//     int ch = 0; //只判断0~9之外的
//     while ((ch = getchar()) != EOF)
//     { // getchar获取字符，putchar打印字符
//        if(ch < '0' || ch > '9')
//            continue;
//            putchar(ch);
//     }  
//     return 0;
// }

// int main(){
//     int i = 0;
//     for(i=1; i<=10; i++){
//         if(i == 5)
//         continue;// 1 2 3 4 6 7 8 9 10 
//         //break; // 1 2 3 4 
//         printf("%d ",i);
//     }
//     return 0;
// }

// int main(){
//     int i = 0;
//     int j = 0;
//     for (; i < 10; i++)
//     {
//         for ( ; j < 10; j++)
//         {
//             printf("i=%d j=%d haha\n",i,j);
//         }  
//     }
//     return 0;
// }

// int main(){
//     int i =0;
//     int k =0;
//     for(i = 0,k = 0;k = 0; i++,k++)
// k=0为k是假，则不进入判断；k为真是进入循环，且是死循环
//     k++;
//     return 0;
// }

//n的阶乘
// int main(){
//     int i = 0;
//     int n = 0;
//     int jc = 1;
//     scanf("%d",&n);
//         for(i=1;i<=n;i++){
//             jc = jc*i;
//         }
//     printf("jc= %d\n",jc);
//     return 0;
// }

// 阶乘之和
// int main(){
//     int i = 0;
//     int n = 0;
//     int jc = 1;
//     int t = 1;
//     long long sum = 0;
//     scanf("%d",&t);
//     for(n=1;n<=t;n++){
//         for(i=1,jc=1;i<=n;i++){
//             jc = jc*i;
//         }
//         sum = sum + jc;
//     }
//     printf("sum= %d\n",sum);
//     return 0;
// }

//在有序数组中找到某一个数字的下标
// int main(){
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int k;
//     scanf("%d",&k);
//     int sz = sizeof(arr)/sizeof(arr[0]);// 计算元素个数
//     int left = 0; //左下标
//     int right = sz - 1; //右下标
//     while (left <= right) // 下标不能交叉，说明中间有元素
//     {
//         int mid = (left + right) /2;
//         if(arr[mid] > k){
//         right = mid - 1;
//         }
//         else if(arr[mid] < k) {
//             left = mid + 1; 
//             }
//             else {
//                 printf("找到了，下标是：%d\n",mid);
//                 break;//找到了需要跳出去
//             }
//     }
//     if(left > right){
//         printf("找不到\n");
//     }
//     return 0;
// }

//从两端向中间移动
// int main(){
//     char arr1[] = "welcome to bit!!!!!!";
//     char arr2[] = "                    ";
//     int left = 0;
//     int right = strlen(arr1)-1;
//     while (left <= right)
//     {
//        arr2[left] = arr1[left];
//        arr2[right] = arr1[right];
//        printf("%s\n",arr2);
//        Sleep(1000); //休息1秒
//        //system("cls");//system为执行系统命令的函数,cls为清空屏幕
//        left++;
//        right--;
//     }  
//     return 0;
// }

// int main(){
//     int i = 0;
//     char password[20] = {0};
//     for ( i = 0; i < 3; i++)
//     {
//         printf("请输入密码:>");
//         scanf("%s",&password);
//         if(strcmp(password,"123456") == 0){
//            printf("登陆成功\n"); 
//            break;
//         }
//         else
//         {
//             printf("密码错误\n");
//         }
        
//     }
//     if(i == 3){
//         printf("三次机会用完，请退出\n");
//     }
//     //strcmp用于比较两个字符串并根据比较结果返回整数。
//     //基本形式为strcmp(str1,str2)，若str1=str2，则返回零；
//     //若str1<str2，则返回负数；若str1>str2，则返回正数
//     return 0;
// }

//排序
// int main(){
//     int a = 0;
//     int b = 0;
//     int c = 0;
//     scanf("%d%d%d",&a,&b,&c);
//     // a最大，b中间,c最小
//     if(a < b){
//         int tmp = a;
//         a = b;
//         b = tmp;
//     }   
//     if(a < c){
//         int tmp = a;
//         a = c;
//         c = tmp;
//     }
//     if(b < c){
//         int tmp = b;
//         b = c;
//         c = tmp;
//     }
//     printf("%d %d %d\n",a,b,c);
//     return 0;
// }

//求被3整除
// int main(){
//     int i = 0;
//     for(i=1;i<100;i++){
//         if(i%3 == 0){
//             printf("%d ",i);
//         }
//     }
//     return 0;
// }

//求公约数
// int main(){
//     int m = 0;
//     int n = 0;
//     int r = 0;
//     scanf("%d%d",&m,&n);
//     if(m == 0 || n == 0){
//         printf("m或n不能为0");
//     }
//     else{
//         if(m < n){
//             int tmp = n;
//             n = m;
//             m = tmp;
//         }
//         while(r = m%n){
//             m = n;
//             n = r;
//         }
//         printf("公约数是%d",n);
//     }
//     return 0;
// }

//求闰年
// int main(){
//     int i = 1000;
//     int count = 0;
//     for(i;i<=2000;i++){
//         if((i%4 == 0 && i%100 != 0) || (i%400 == 0)){
//             printf("%d ",i); 
//             count++;
//         }
//     }
//     printf("\n有%d个闰年",count);
//     return 0;
// }

//求素数
// int main(){
//     int i = 0;
//     int j = 0;
//     int count = 0;
//     for(i=101;i<=200;i+=2){
//         for(j=2;j<=sqrt(i);j++){
//             if(i%j == 0){
//                 break;
//             }
//         }
//         if(j > sqrt(i)){
//             count++;
//             printf(" %d",i);
//         }
//     }
//     printf("\n有%d个素数",count);
//     return 0;
// }

// 数9的个数
// int main(){
//     int i = 0;
//     int count = 0;
//     for(i=1;i<=100;i++){
//         if(i%10 == 9){
//             count++;
//             printf("%d ",i);
//         }
//         if(i/10 == 9){
//             count++;
//             printf("%d ",i);
//         }
//     }
//     printf("\n有%d个",count);
//     return 0;
// }

int main(){
    int i =0;
    double sum = 0.0;
    int f = 1;
    for(i = 1;i<=100;i++){
        sum += f*1.0/i;
        f = -f;
    }
    printf("%lf\n",sum);
    return 0;
}
