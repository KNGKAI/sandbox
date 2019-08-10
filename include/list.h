#ifndef LIST_H
#define LIST_H

#include <exception>
#include <string>

template <typename T>
struct ListNode
{
    T value;
    ListNode<T> *next;
};

template <typename T>
class List 
{
    private:
        ListNode<T>     *_nodes;
        int             _length;

    public:
        List();
        ~List();
        T           get(int index);   
        int         length() const;
        void        add(T val);
        void        remove(int index);
        bool        contains(T val);
        void        clear();
        T           to_array() const;
        std::string to_string() const;

    struct IndexOutOfRange : public std::exception { virtual const char *what() const throw() { return ("Index out of range"); } };
    struct EmptyList : public std::exception { virtual const char *what() const throw() { return ("List is empty"); } };
};

template <typename T>
List<T>::List()
{
    this->_length = 0;
    this->_nodes = NULL;
    return;
}

template <typename T>
List<T>::~List()
{
    ListNode<T> *node;
    ListNode<T> *temp;

    if (this->_length == 0) { return; }
    node = this->_nodes;
    while (node != NULL)
    {
        temp = node->next;
        delete node;
        node = temp;
    }
    return;
}

template <typename T>
T List<T>::get(int index)
{
    ListNode<T> *node;

    if (index < 0) { throw List::IndexOutOfRange(); }
    if (index >= this->_length) { throw List::IndexOutOfRange(); }
    node = this->_nodes;
    while (index > 0)
    {
        node = node->next;
        index--;
    }
    return (node->value);
}

template <typename T>
int List<T>::length() const { return (this->_length); }

template <typename T>
void List<T>::add(T val)
{
    ListNode<T> *node;

    node = new ListNode<T>();
    node->value = val;
    node->next = this->_nodes;
    this->_nodes = node;
    this->_length++;
}

template <typename T>
void List<T>::remove(int index)
{
    ListNode<T> *node;
    ListNode<T> *prev;

    if (index < 0) { throw List::IndexOutOfRange(); }
    if (this->_length <= index) { throw List::IndexOutOfRange(); }
    if (index == 0)
    {
        node = this->_nodes;
        this->_nodes = node->next;
        this->_length--;
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
    this->_length--;
    delete node;
}

template <typename T>
bool List<T>::contains(T val)
{
    for (int i = 0; i < this->length(); i++)
    {
        if (this->get(i) == val) { return (true); }
    }
    return (false);
}

template <typename T>
void List<T>::clear()
{
    while (this->length() > 0)
    {
        this->remove(this->length() - 1);
    }
}

template <typename T>
std::string List<T>::to_string() const
{
    std::string str;

    if (this->_length <= 0) { return (str); }
    for (int i = 0; i < this->_length; i++)
    {
        str += std::to_string(this->get(i)) + "\n";
    }
    return (str);
}

#endif