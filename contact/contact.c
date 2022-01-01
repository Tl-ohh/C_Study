#include "contact.h"

// 初始化通讯录
void InitContact(struct Contact *ps)
{
    memset(ps->data, 0, sizeof(ps->data));
    ps->size = 0; //设置通讯录最初只有0个元素
}

// 增加一个信息到通讯录的实现
void AddContact(struct Contact *ps)
{
    if (ps->size == MAX)
    {
        printf("通讯录已满,无法增加\n");
    }
    else
    {
        printf("请输入名字:>");
        scanf("%s", ps->data[ps->size].name);
        // 因为其他都是数组所以不用取地址，年龄是整型需要取地址
        printf("请输入年龄:>");
        scanf("%d", &(ps->data[ps->size].age));
        printf("请输入性别:>");
        scanf("%s", ps->data[ps->size].sex);
        printf("请输入电话:>");
        scanf("%s", ps->data[ps->size].tele);
        printf("请输入地址:>");
        scanf("%s", ps->data[ps->size].addr);

        ps->size++;
        printf("添加成功!!\n");
    }
}

// 打印通讯录中的信息的实现
void ShowContact(const struct Contact *ps)
{
    if (ps->size == 0)
    {
        printf("通讯录为空\n");
    }
    else
    {
        int i;
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
        for (i = 0; i < ps->size; i++)
        {
            printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                   ps->data[i].name,
                   ps->data[i].age,
                   ps->data[i].sex,
                   ps->data[i].tele,
                   ps->data[i].addr);
        }
    }
}

// 通过名字查找返回下标 加static就只能在本文件使用
static int FindByName(const struct Contact *ps, char name[MAX_NAME])
{
    int i = 0;
    for (i = 0; i < ps->size; i++)
    {
        if (0 == strcmp(ps->data[i].name, name))
        {
            return i;
        }
    }
    return -1;
}

// 删除指定练习人的实现
void DelContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要删除人的名字:>\n");
    scanf("%s", name);
    // 1.查找，是否存在，在什么位置
    // 找到返回名字所在元素的下标，找不到返回-1
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("要删除的人不存在!!!\n");
    }
    // 2.删除
    else
    {
        // 删除数据
        int j = 0;
        for (j = pos; j < ps->size - 1; j++)
        {
            ps->data[j] = ps->data[j + 1];
        }
        ps->size--;
        printf("删除成功!!\n");
    }
}

// 查找指定名字的联系人的实现
void SearchContact(const struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要查找人的名字:>\n");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if(pos == -1)
    {
        printf("通讯录里面没有这个人\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", 
        "名字", "年龄", "性别", "电话", "地址");
        printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                   ps->data[pos].name,
                   ps->data[pos].age,
                   ps->data[pos].sex,
                   ps->data[pos].tele,
                   ps->data[pos].addr);
    }  
}

// 修改指定名字的联系人的实现
void ModifyContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要删除人的名字:>\n");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if(pos == -1)
    {
        printf("通讯录里面没有这个人\n");
    }
    else
    {
        printf("请输入名字:>");
        scanf("%s", ps->data[pos].name);
        printf("请输入年龄:>");
        scanf("%d", &(ps->data[pos].age));
        printf("请输入性别:>");
        scanf("%s", ps->data[pos].sex);
        printf("请输入电话:>");
        scanf("%s", ps->data[pos].tele);
        printf("请输入地址:>");
        scanf("%s", ps->data[pos].addr);
        printf("修改成功!!\n");
    }  
}