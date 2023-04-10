#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*top= NULL;

void push(int i)
{
    struct Node *t;
    t = (struct Node*) malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Stack is full \nStack Overflow");
    }
    else
    {
        t->data = i;
        t-> next = top;
        top = t;
    }
}

void display()
{
    struct Node* p;
    p= top ;
    while(p!=NULL)
    {
        printf("data : %d", p->data);
        p=p->next;
        printf("\n");
    }
}

int pop()
{
    int x=-1;
    if(top == NULL)
    {
        printf("Stack is empty");
    }
    else{
        struct Node *t;
        t = top;
        top = top->next;
        x = t-> data;
        free(t);

    }
    return x;
}
void test_display() {
    push(40);
    push(50);
    push(60);
    printf("Expected: 60\n50\n40\n");
    display();
    pop();
    printf("Expected: 50\n40\n");
    display();
}


int main()
{
    test_display();
    push(101);
    push(102);
    push(103);
    push(104);
    push(105);
    push(106);
    push(107);
    display();
    pop();
    printf("hello");
    display();
    return 0;

}