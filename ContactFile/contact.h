
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
// ͨѶ¼����
struct Contact
{
    int capacity;         // ��ǰͨѶ¼���������
    int size;             // ��¼��ǰ���е�Ԫ�ظ���
    struct PeoInfo *data; // ���һ����Ϣ
};

// ��������
void InitContact(struct Contact *ps);

// ����һ����Ϣ��ͨѶ¼
void AddContact(struct Contact *ps);

// ��ӡͨѶ¼�е���Ϣ
void ShowContact(const struct Contact *ps);

// ɾ��ָ������ϵ��
void DelContact(struct Contact *ps);

// ����ָ�����ֵ���ϵ��
void SearchContact(const struct Contact *ps);

// �޸�ָ�����ֵ���ϵ�˵�ʵ��
void ModifyContact(struct Contact *ps);

// ����ͨѶ¼-�ͷŶ�̬���ٵ��ڴ�
void DestroyContact(struct Contact *ps);

// ����ͨѶ¼��ϢΪ�ļ�
void SaveContact(struct Contact *ps);

// �������
void CheckCapacity(struct Contact *ps);

// �����ļ��е���Ϣ��ͨѶ¼
void LoadContact(struct Contact *ps);