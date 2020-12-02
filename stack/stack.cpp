#include <iostream>
typedef int DataType;
#define  MAXSIZE  100
using namespace std;

typedef struct stacknode
{
    int data;
    struct stacknode* next;
}LinkStack;

LinkStack* InitList()
{
    LinkStack* head;
    head = (LinkStack*)malloc(sizeof(LinkStack));
    head->next = NULL;
    return head;//判断栈是不是空的
}

int EmptyStack(LinkStack* S)
{
    if (S == NULL)
        return 1;
    else
    {
        return 0;
    }
}

LinkStack* Push(LinkStack* S, int x)
{
    LinkStack* p;
    p = (LinkStack*)malloc(sizeof(LinkStack));
    p->data = x;
    p->next = S;
    S = p;
    return S;
}

LinkStack* Pop(LinkStack* S, DataType* x)
{ 
    LinkStack* p;
    if (EmptyStack(S))    
    {
        printf("");
        return NULL;         
    }
    else                     
    {
        *x = S->data;           
        p = S;                 
        S = S->next;            
        free(p);              
        return S;             
    }
}

int GetTop(LinkStack* S, DataType* x)
{ 
    if (EmptyStack(S))      
    {
        printf("Stack is empty");
        return 0;
    }
    else                 
    {
        *x = S->data;      
        return 1;
    }
}

void ShowStack(LinkStack* S)
{
    LinkStack* p = S;
    if (p == NULL)
        printf("栈空");
    else
    {
        printf("从栈顶起栈 各元素为");
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    }
}

void D_B(LinkStack* S, DataType x)
{
    while (x)
    {
        S = Push(S, x % 2);      
        x /= 2;             
    }
    printf("转换后的二进制是");
    while (!EmptyStack(S))
    {
        S = Pop(S, &x);      
        printf("%d", x);
    }
}

void trans(char* exp, char* postexp)
{   
    struct
    {
        char data[MAXSIZE];
        int top;
    } op;    
    int i = 0;
    op.top = -1;
    while (*exp != '#')   
    {
        switch (*exp)    
        {
        case '(':   
            op.top++; op.data[op.top] = *exp;   
            exp++;   
            break;
        case ')':   
            while (op.data[op.top] != '(')   
            {
                postexp[i++] = op.data[op.top];  
                op.top--;  
            }
            op.top--; exp++; 
            break;
        case '+':
        case '-':
            while (op.top != -1 && op.data[op.top] != '(')  
            {
                postexp[i++] = op.data[op.top];  
                op.top--;   
            }
            op.top++;  
            op.data[op.top] = *exp;  
            exp++; 
            break;
        case '*':
        case '/':
            while (op.data[op.top] == '*' || op.data[op.top] == '/') 
            {
                postexp[i++] = op.data[op.top]; 
                op.top--;  
            }
            op.top++;
            op.data[op.top] = *exp; 
            exp++; 
            break;
        case ' ':break;
        default:
            while (*exp >= '0' && *exp <= '9') 
            {
                postexp[i++] = *exp;   
                exp++;  
            }
            postexp[i++] = '#';  
        }
    }
    while (op.top != -1)  
    {
        postexp[i++] = op.data[op.top];  
        op.top--;   
    }
    postexp[i] = '\0';  
}

float compvalue(char* postexp)
{  
    struct
    {
        float data[MAXSIZE];
        int top;
    } st; 
    float a, b, c, d;
    st.top = -1;   
    while (*postexp != '\0') 
    {
        switch (*postexp)
        {
        case '+':
            a = st.data[st.top]; 
            st.top--;          
            b = st.data[st.top]; 
            st.top--;          
            c = b + a;             
            st.top++;          
            st.data[st.top] = c; 
            break;
        case '-':
            a = st.data[st.top];
            st.top--;
            b = st.data[st.top];
            st.top--;
            c = b - a;
            st.top++;
            st.data[st.top] = c;
            break;
        case '*':
            a = st.data[st.top];
            st.top--;
            b = st.data[st.top];
            st.top--;
            c = b * a;
            st.top++;
            st.data[st.top] = c;
            break;
        case '/':
            a = st.data[st.top];
            st.top--;
            b = st.data[st.top];
            st.top--;
            if (a != 0)
            {
                c = b / a;
                st.top++;
                st.data[st.top] = c;
            }
            else
                cout << "\n\t�������!\n";
            break;
        default: 
            d = 0;
            while (*postexp >= '0' && *postexp <= '9')
            {
                d = 10 * d + *postexp - '0';
                postexp++;
            }
            st.top++;
            st.data[st.top] = d;  
            break;
        }
        postexp++;
    }
    return st.data[st.top];  
}

void  MenuStack()
{  
    printf("\n                     栈子系统");
    printf("\n==================================================");
    printf("\n|               1初始化栈                    |");
    printf("\n|               2入栈操作                    |");
    printf("\n|               3出栈操作                    |");
    printf("\n|               4求栈顶元素                  |");
    printf("\n|               5显示栈中元素                |");
    printf("\n|               6十,十二进制转换            |");
    printf("\n|               7表达式转换 求值            |");
    printf("\n|               0返回                        |");
    printf("\n==================================================");
    printf("\n请输入菜单号");
}

main()
{
    int i, n, flag;
    LinkStack* S;
    DataType x;
    char  ch1, ch2, a;
    char exp[MAXSIZE], postexp[MAXSIZE];  /*�����ʽֵ����������*/
    ch1 = 'y';
    while (ch1 == 'y' || ch1 == 'Y')
    {
        MenuStack();
        cin >> ch2;
        getchar();
        switch (ch2)
        {
        case  '1':
            S = InitList();
            printf("栈的初始化完成");
            break;
        case  '2':
            printf("请输入要入栈的元素个数");
            scanf("%d", &n);
            printf("请输入%d个整数进行入栈", n);
            for (i = 0; i < n; i++)
            {
                cin >> x;
                S = Push(S, x);
            }
            printf("入栈成功");
            break;
        case  '3':
            printf("");
            scanf("%d", &n);
            printf("��ջ��Ԫ��Ϊ��");
            for (i = 0; i < n; i++)
            {
                S = Pop(S, &x);
                if (S != NULL)
                    printf("%5d", x);
            }
            break;
        case  '4':
            if (flag = GetTop(S, &x))
                printf("��ǰ��ջ��Ԫ��ֵΪ��%d", x);
            break;
        case  '5':
            ShowStack(S);
            break;
        case  '6':
            S = InitStack();
            printf("������ʮ����������Ϊ:");
            scanf("%d", &x);     /*����ʮ����������*/
            D_B(S, x);          /*���ý���ת������*/
            break;
        case  '7':
            printf("��������������ʽ��ֻ��+��-��*��/���������������'#'������");
            scanf("%s", &exp);
            trans(exp, postexp);
            printf("��ñ���ʽ����׺����ʽΪ��%s\n", exp);
            printf("ת��֮��ĺ�׺����ʽΪ��ÿ���������á�#���ָ�����%s\n", postexp);
            printf("����ʽ��ֵΪ:%.2f\n", compvalue(postexp));
            break;
        case  '0':
            ch1 = 'n'; break;
        default:
            printf("��������������0-5����ѡ��");
        }
        if (ch2 != '0')
        {
            printf("\n���س�����������������������˵���\n");
            a = getchar();
            if (a != '\xA')
            {
                getchar(); ch1 = 'n';
            }
        }
    }
}
