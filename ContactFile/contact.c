#include "contact.h"

// 初始化通讯录
void InitContact(struct Contact *ps)
{
    ps->data = (struct PeoInfo *)malloc(3 * sizeof(struct PeoInfo));
    if (ps->data == NULL)
    {
        return;
    }
    ps->size = 0;
    ps->capacity = DEFAULT_SZ;
    // 把文件中已经存放的通讯录的信息加载到通讯录里
    LoadContact(ps);
}

// 检测容量
void CheckCapacity(struct Contact *ps)
{
    if (ps->size == ps->capacity)
    {
        // 增容
        struct PeoInfo *ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
        if (ptr != NULL)
        {
            ps->data = ptr;
            ps->capacity += 2;
            printf("增容成功\n");
        }
        else
        {
            printf("增容失败\n");
        }
    }
}

// 加载文件中的信息到通讯录
void LoadContact(struct Contact *ps)
{
    struct PeoInfo tmp = {0};
    FILE *pfRead = fopen("contact.dat", "rb");
    if (pfRead == NULL)
    {
        printf("LoadContact::%s\n", strerror(errno));
        return;
    }
    // 读取文件,放到通讯录中
    while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead))
    {
        CheckCapacity(ps);
        ps->data[ps->size] = tmp;
        ps->size++;
    }
    // 关闭文件
    fclose(pfRead);
    pfRead = NULL;
}

// 增加一个信息到通讯录的实现
void AddContact(struct Contact *ps)
{
    // 检测当前通讯录的容量，如果满了，增减空间；如果不满，无操作
    CheckCapacity(ps);
    // 增加数据
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
    if (pos == -1)
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
    if (pos == -1)
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

// 销毁通讯录-释放动态开辟的内存
void DestroyContact(struct Contact *ps)
{
    free(ps->data);
    ps->data = NULL;
}

// 保存通讯录信息为文件
void SaveContact(struct Contact *ps)
{
    FILE *pfwrite = fopen("contact.dat", "wb");
    if (pfwrite == NULL)
    {
        printf("SaveContact::%s\n", strerror(errno));
        return;
    }
    // 写通讯录中的数据到文件中
    int i = 0;
    for (i = 0; i < ps->size; i++)
    {
        fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfwrite);
        printf("保存成功!!\n");
    }

    // 关闭文件
    fclose(pfwrite);
    pfwrite = NULL;
}