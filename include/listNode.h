#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
struct ListNode
{
    T value;
    ListNode<T> *next;
};

#endif