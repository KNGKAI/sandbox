#ifndef LIST_H
#define LIST_H

#include <exception>

template <typename T>
class ListNode
{
    public:
        T value;
        ListNode<T> *next;
};

template <typename T>
class List 
{
    private:
        ListNode<T>     *_nodes;
        int             _lenght;
    public:
        List();
        ~List();

        T       get(int index) const;   
        int     lenght() const;
        void    add(T val);
        void    remove(int index);

        struct IndexOutOfRange : public std::exception { virtual const char *what() const throw() { return ("Index out of range"); } };
 };

#endif