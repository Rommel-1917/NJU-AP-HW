#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct Node {
    char val;
    Node* next;
}Node;
typedef struct Node* CharList;
CharList init()
{
    CharList top = new Node;
    top->next = NULL;
    return top;
}
bool insert(CharList& top, int i, char val)
{
    CharList p = top;
    int index = 0;
    if (i == 0)
    {
        CharList char0 = new Node;
        char0->val = val;
        p->next = char0;
        char0->next = NULL;
        return true;
    }
    else
    {
        p = p->next;
        for (index = 0; index < i - 1; index++, p = p->next)
        {
        };
        if (0 < i )
        {
            CharList char1 = new Node;
            char1->next = NULL;
            char1->next = p->next;
            p->next = char1;
            char1->val = val;
            return true;
        }
        
        
    }
}
void show(CharList& top)
{
    int index = 0;
    CharList char0 = top->next;
    if (char0 == NULL)
    {
        cout << endl;
    }
    if (char0 != NULL)
    {
        while (0 < 4)
        {
            if (char0->next == NULL)
            {
                cout << char0->val << endl;
                return;
            }
            else
            {
                cout << char0->val << " ";
                char0 = char0->next;
            }
            index++;
        }
    }
}
bool erase(CharList& top, int i)
{
    if (i < 0)
        return false;
    if (top->next == NULL)
        return false;
    CharList p = top->next;
    int index = 0;
    int num = i + 1;
    if (i == 0)
    {
        top->next = top->next->next;
        return true;
    }
    else
    {
        for (index = 0; index < i - 1; index++, p = p->next)
        {
        };
        if (p->next == NULL)
            return false;
        p->next = p->next->next;
        return  true;
    }
}
bool change(CharList& top, int i, char val)
{
    if ( i < 0)
        return false;
    CharList p = top->next;
    int index = 0;
    if (top->next == NULL)
        return false;
    for (index = 0; index < i; index++, p = p->next)
    {
        if (p == NULL)
        {
            return false;
        }
    }
    p->val = val;
    return  true;
}
void clear(CharList& top) {
    return;
}
int main()
{
    int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
    int i = 0;
    cout <<i++ + ++i<< endl;
  
}
