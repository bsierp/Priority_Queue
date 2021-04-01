#ifndef QUEUE_HH
#define QUEUE_HH
#include <string>
#include <stdexcept>
// #include "Node.hh"

using std::string;

template<class KEY_TYPE, class VALUE_TYPE>
class Priority_Queue {
    struct Node{
    KEY_TYPE key;
    VALUE_TYPE data;
    Node *next;
};
    Node *first;
    public:
    Priority_Queue(){this->first=nullptr;}
    void insert(KEY_TYPE new_key, VALUE_TYPE new_data);
    VALUE_TYPE remove_min();
    const VALUE_TYPE & min() const;
    bool is_empty() const;
    int size() const;
};

template<> void Priority_Queue<int,string>::insert(int new_key, string new_data);
#endif