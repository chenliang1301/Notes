
#include <stdio.h>

#include <stdlib.h>

/* ¶ÓÁÐ */
typedef struct node {
    int num;
    struct node* pt_next;
}T_node;

typedef struct {
    T_node t_head;
    T_node t_tail;
}T_queue;

int init_queue(T_queue* pt_queue)
{
    if (pt_queue == NULL) return -1;
    pt_queue->t_head.pt_next = &(pt_queue->t_tail);
    pt_queue->t_tail.pt_next = NULL;
    return 0;
}

int push_queue_tail(T_queue* pt_queue, int newNum)
{
    if (pt_queue == NULL)    return -1;
    T_node* pt_newNode = (T_node*)malloc(sizeof(T_node));
    pt_newNode->num = newNum;
    pt_newNode->pt_next = NULL;

    T_node* pt_first;
    T_node* pt_mid;
    T_node* pt_last;
    T_node* pt_tmp;
    for (pt_tmp = &(pt_queue->t_head); pt_tmp != &(pt_queue->t_tail); pt_tmp = pt_tmp->pt_next)
    {
        pt_first = pt_tmp;
        pt_mid = pt_first->pt_next;
        pt_last = pt_mid->pt_next;
        if (pt_mid == &(pt_queue->t_tail))
        {
            pt_first->pt_next = pt_newNode;
            pt_newNode->pt_next = pt_mid;
        }
    }
    return 0;
}

int pop_queue_head(T_queue* pt_queue)
{
    if (pt_queue == NULL && (pt_queue->t_head.pt_next == &(pt_queue->t_tail))) return -1;
    T_node* pt_first = &(pt_queue->t_head);
    T_node* pt_mid = pt_first->pt_next;
    T_node* pt_last = pt_mid->pt_next;
    pt_first->pt_next = pt_last;
    free(pt_mid);
    pt_mid = NULL;
    return 0;
}

int traverse_queue(T_queue* pt_queue)
{
    if (pt_queue == NULL && pt_queue->t_head.pt_next == &(pt_queue->t_tail)) return -1;
    T_node* pt_first;
    T_node* pt_mid;
    T_node* pt_last;
    T_node* pt_tmp;
    for (pt_tmp = &(pt_queue->t_head); pt_tmp != &(pt_queue->t_tail); pt_tmp = pt_tmp->pt_next)
    {
        pt_first = pt_tmp;
        pt_mid = pt_first->pt_next;
        pt_last = pt_mid->pt_next;
        if (pt_mid != &(pt_queue->t_tail))
            printf("%d\t", pt_mid->num);
    }
    printf("\n");
    return 0;
}

int main()
{
    T_queue pt_queue = { 0 };
    init_queue(&pt_queue);
    push_queue_tail(&pt_queue, 1);
    push_queue_tail(&pt_queue, 2);
    push_queue_tail(&pt_queue, 3);
    push_queue_tail(&pt_queue, 4);
    push_queue_tail(&pt_queue, 5);
    traverse_queue(&pt_queue);
    pop_queue_head(&pt_queue); traverse_queue(&pt_queue);
    pop_queue_head(&pt_queue); traverse_queue(&pt_queue);
    pop_queue_head(&pt_queue); traverse_queue(&pt_queue);
    pop_queue_head(&pt_queue); traverse_queue(&pt_queue);
    pop_queue_head(&pt_queue); traverse_queue(&pt_queue);
    pop_queue_head(&pt_queue); traverse_queue(&pt_queue);
    pop_queue_head(&pt_queue); traverse_queue(&pt_queue);
    system("pause");
    return 0;
}