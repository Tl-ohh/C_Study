
//#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
enum Option
{
    EXIT, // 0
    ADD,  // 1
    DEL,  // 2
    SEARCH,
    MODIFY,
    SHOW,
    SORT,
    SAVE
};
struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};
// 通讯录类型
struct Contact
{
    int capacity;         // 当前通讯录的最大容量
    int size;             // 记录当前已有的元素个数
    struct PeoInfo *data; // 存放一个信息
};

// 声明函数
void InitContact(struct Contact *ps);

// 增加一个信息到通讯录
void AddContact(struct Contact *ps);

// 打印通讯录中的信息
void ShowContact(const struct Contact *ps);

// 删除指定的联系人
void DelContact(struct Contact *ps);

// 查找指定名字的联系人
void SearchContact(const struct Contact *ps);

// 修改指定名字的联系人的实现
void ModifyContact(struct Contact *ps);

// 销毁通讯录-释放动态开辟的内存
void DestroyContact(struct Contact *ps);

// 保存通讯录信息为文件
void SaveContact(struct Contact *ps);

// 检测容量
void CheckCapacity(struct Contact *ps);

// 加载文件中的信息到通讯录
void LoadContact(struct Contact *ps);