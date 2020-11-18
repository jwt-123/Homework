//一开始用英语。。居然还出了些错。。。还是改成中文debug了23333

#include <iostream>
#include<malloc.h>
typedef int Datatype;
using namespace std;

typedef struct linknode
{
    int data;
    struct linknode* next;
}Linknode;

Linknode* InitList()//初始化
{
    Linknode* head;
    head = (Linknode*)malloc(sizeof(Linknode));
    head->next = NULL;
    return head;
}

void CreateListH(Linknode* head, int n)//头插法
{
    Linknode* s;
    cout << "plz input", n, "number";
    for (int i = 0; i < n; i++)
    {
        s = (linknode*)malloc(sizeof(linknode));
        cin >> s->data;
        s->next = head->next;
        head->next = s;
    }
    cout << "成功建立" << endl;
}

void CreateListL(Linknode* head, int n)
{
    Linknode* s, * last;
    last = head;
    cout << "plz input", n, "number";
    for (int i = 0; i < n; i++)
    {
        s = (linknode*)malloc(sizeof(linknode));
        cin >> s->data;
        s->next = NULL;
        last->next = s;
        last = s;
    }
    cout << "succeed built Linklist";
}

int lengthlist(Linknode* head)
{
    Linknode* p = head->next;
    int i = 0;
    while (p != NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}

void locate(linknode* head, Datatype x)
{
    int i = 1;
    linknode* p;
    p = head->next;
    while (p != NULL && p->data != x)
    {
        p = p->next;
        i++;
    }

    if (p != NULL)
    {
        cout << "locate", i, "find the", x;
    }
    else
    {
        cout << "fail to find" << endl;
    }
}

void searchlist(linknode* head, int i)
{
    linknode* p;
    int j = 0;
    p = head;
    if (i > lengthlist(head))
    {
        while (p->next != NULL && j < i)
        {
            p = p->next;
            j++;
        }
        if (j == i)
        {
            cout << "the value is", p->data, "at", i;
        }
    }
}

void Inslist(linknode* head, int i, Datatype x)
{
    int j = 0;
    linknode* p, * s;
    p = head;
    while (p->next != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p != NULL)
    {
        s = (linknode*)malloc(sizeof(linknode));
        s->data = x;
        s->next = p->next;
        p->next = s;
        cout << "成功插入" << endl;
    }
    else
    {
        cout << "未成功插入" << endl;
    }
}

void delllist(linknode* head, int i)
{
    int j = 0;
    Datatype x;
    linknode* p = head, * s;
    while (p->next != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p->next != NULL && j == i - 1)
    {
        s = p->next;
        x = s->data;
        p->next = s->next;
        free(s);
        cout << "dell", x, "at the", i;
    }
    else
    {
        cout << "失败 ,请再次尝试" << endl;
    }
}

void displist(linknode* head)
{
    linknode* p;
    p = head->next;
    while (p != NULL)
    {
        cout << p->data<<endl;
        p = p->next;
    }
}

void menuline()
{
    cout << "单链表" << endl;
    cout << "===================" << endl;
    cout << "1,建立" << endl;
    cout << "2,插入" << endl;
    cout << "3,位置查找" << endl;
    cout << "4,值查找" << endl;
    cout << "5，计算长度" << endl;
    cout << "6, 返回" << endl;
    cout << "7,查看" << endl;
    cout << "请输入" << endl;
}


int main()
{
    linknode* head;
    Datatype x;
    int i, n;
    char ch1, ch2, a;
    ch1 = 'y';
    while (ch1 == 'y' || ch1 == 'Y')
    {
        menuline();
        cin >> ch2;
        switch (ch2)
        {
        case '1':
            head = InitList();
            cout << "输入长度\n";
            cin >> n;
            CreateListL(head, n);
            cout << "成功建立\n";
            displist(head);
            break;
        case '2':
            cout << "plz input the number location" << endl;
            cin >> i;
            cout << "plz input the value" << endl;
            cin >> x;
            Inslist(head, i, x);
            displist(head);
            break;
        case '3':
            cout << "plz input the location";
            cin >> i;
            delllist(head, i);
            cout << "the menu is" << endl;
            displist(head);
            break;
        case '4':
            cout << "plz input the value you wanna search";
            cin >> i;
            searchlist(head, i);
            displist(head);
            break;
        case '5':
            cout << "plz input the integer you search";
            cin >> x;
            locate(head, x);
            break;
        case '6':
            cout << "the length is";
            cout << lengthlist(head);
            break;
        case '0':
            ch1 = 'n';
            break;
        case'7':
            displist(head);
        default:
            break;
        }
    }
}
