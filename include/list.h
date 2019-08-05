#ifndef LIST_H
#define LIST_H

template <class T>
class ListNode {
    T value;
    ListNode<T> *next;
    ListNode<T> *previous;  
};

template <class T>
class List {
    private:
        ListNode<T> _nodes;
    public:
        List();
        ~List();

        void push_back(T val);
 };

#endif