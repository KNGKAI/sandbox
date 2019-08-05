#include "list.h"
#include <iostream>

template <typename T>
List<T>::List()
{
    this->_lenght = 0;
    this->_nodes = NULL;
    return;
}

template <typename T>
List<T>::~List()
{
    ListNode<T> *node;
    ListNode<T> *temp;

    if (this->lenght == 0) { return; }
    node = this->_nodes;
    while (this->node != NULL)
    {
        temp = node->next;
        delete node;
        node = temp;
    }
    return;
}

template <typename T>
T List<T>::get(int index) const
{
    ListNode<T> *node;

    if (index < 0) { throw List::IndexOutOfRange(); }
    if (index >= this->_lenght) { throw List::IndexOutOfRange(); }
    node = this->_nodes;
    while (index > 0)
    {
        node = node->next;
        index--;
    }
    return (node->value);
}

template <typename T>
int List<T>::lenght() const { return (this->lenght); }

template <typename T>
void List<T>::add(T val)
{
    ListNode<T> *node;

    node = new ListNode<T>();
    node->value = val;
    node->next = this->_nodes;
    this->_nodes = node;
    this->_lenght++;
}

template <typename T>
void List<T>::remove(int index)
{
    ListNode<T> *node;
    ListNode<T> *prev;

    if (index < 0) { return; }
    if (this->_lenght <= 0) { return; }
    if (index == 0)
    {
        node = this->_nodes;
        this->_nodes = node->next;
        this->_lenght--;
        delete node;
        return;
    }
    prev = NULL;
    node = this->_nodes;
    while (index > 0)
    {
        prev = node;
        node = node->next;
        index--;
    }
    prev->next = node->next;
    this->_lenght--;
    delete node;
}