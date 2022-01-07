#include "contact.h"

// ��ʼ��ͨѶ¼
void InitContact(struct Contact *ps)
{
    ps->data = (struct PeoInfo *)malloc(3 * sizeof(struct PeoInfo));
    if (ps->data == NULL)
    {
        return;
    }
    ps->size = 0;
    ps->capacity = DEFAULT_SZ;
    // ���ļ����Ѿ���ŵ�ͨѶ¼����Ϣ���ص�ͨѶ¼��
    LoadContact(ps);
}

// �������
void CheckCapacity(struct Contact *ps)
{
    if (ps->size == ps->capacity)
    {
        // ����
        struct PeoInfo *ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
        if (ptr != NULL)
        {
            ps->data = ptr;
            ps->capacity += 2;
            printf("���ݳɹ�\n");
        }
        else
        {
            printf("����ʧ��\n");
        }
    }
}

// �����ļ��е���Ϣ��ͨѶ¼
void LoadContact(struct Contact *ps)
{
    struct PeoInfo tmp = {0};
    FILE *pfRead = fopen("contact.dat", "rb");
    if (pfRead == NULL)
    {
        printf("LoadContact::%s\n", strerror(errno));
        return;
    }
    // ��ȡ�ļ�,�ŵ�ͨѶ¼��
    while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead))
    {
        CheckCapacity(ps);
        ps->data[ps->size] = tmp;
        ps->size++;
    }
    // �ر��ļ�
    fclose(pfRead);
    pfRead = NULL;
}

// ����һ����Ϣ��ͨѶ¼��ʵ��
void AddContact(struct Contact *ps)
{
    // ��⵱ǰͨѶ¼��������������ˣ������ռ䣻����������޲���
    CheckCapacity(ps);
    // ��������
    printf("����������:>");
    scanf("%s", ps->data[ps->size].name);
    // ��Ϊ���������������Բ���ȡ��ַ��������������Ҫȡ��ַ
    printf("����������:>");
    scanf("%d", &(ps->data[ps->size].age));
    printf("�������Ա�:>");
    scanf("%s", ps->data[ps->size].sex);
    printf("������绰:>");
    scanf("%s", ps->data[ps->size].tele);
    printf("�������ַ:>");
    scanf("%s", ps->data[ps->size].addr);

    ps->size++;
    printf("��ӳɹ�!!\n");
}

// ��ӡͨѶ¼�е���Ϣ��ʵ��
void ShowContact(const struct Contact *ps)
{
    if (ps->size == 0)
    {
        printf("ͨѶ¼Ϊ��\n");
    }
    else
    {
        int i;
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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

// ͨ�����ֲ��ҷ����±� ��static��ֻ���ڱ��ļ�ʹ��
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

// ɾ��ָ����ϰ�˵�ʵ��
void DelContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("������Ҫɾ���˵�����:>\n");
    scanf("%s", name);
    // 1.���ң��Ƿ���ڣ���ʲôλ��
    // �ҵ�������������Ԫ�ص��±꣬�Ҳ�������-1
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("Ҫɾ�����˲�����!!!\n");
    }
    // 2.ɾ��
    else
    {
        // ɾ������
        int j = 0;
        for (j = pos; j < ps->size - 1; j++)
        {
            ps->data[j] = ps->data[j + 1];
        }
        ps->size--;
        printf("ɾ���ɹ�!!\n");
    }
}

// ����ָ�����ֵ���ϵ�˵�ʵ��
void SearchContact(const struct Contact *ps)
{
    char name[MAX_NAME];
    printf("������Ҫ�����˵�����:>\n");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("ͨѶ¼����û�������\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n",
               "����", "����", "�Ա�", "�绰", "��ַ");
        printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
               ps->data[pos].name,
               ps->data[pos].age,
               ps->data[pos].sex,
               ps->data[pos].tele,
               ps->data[pos].addr);
    }
}

// �޸�ָ�����ֵ���ϵ�˵�ʵ��
void ModifyContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("������Ҫɾ���˵�����:>\n");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("ͨѶ¼����û�������\n");
    }
    else
    {
        printf("����������:>");
        scanf("%s", ps->data[pos].name);
        printf("����������:>");
        scanf("%d", &(ps->data[pos].age));
        printf("�������Ա�:>");
        scanf("%s", ps->data[pos].sex);
        printf("������绰:>");
        scanf("%s", ps->data[pos].tele);
        printf("�������ַ:>");
        scanf("%s", ps->data[pos].addr);
        printf("�޸ĳɹ�!!\n");
    }
}

// ����ͨѶ¼-�ͷŶ�̬���ٵ��ڴ�
void DestroyContact(struct Contact *ps)
{
    free(ps->data);
    ps->data = NULL;
}

// ����ͨѶ¼��ϢΪ�ļ�
void SaveContact(struct Contact *ps)
{
    FILE *pfwrite = fopen("contact.dat", "wb");
    if (pfwrite == NULL)
    {
        printf("SaveContact::%s\n", strerror(errno));
        return;
    }
    // дͨѶ¼�е����ݵ��ļ���
    int i = 0;
    for (i = 0; i < ps->size; i++)
    {
        fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfwrite);
        printf("����ɹ�!!\n");
    }

    // �ر��ļ�
    fclose(pfwrite);
    pfwrite = NULL;
}