#include "Queue.hh"
#include <iostream>
template<> void Priority_Queue<int,string>::insert(int new_key, string new_data){
    Node *new_node, *temp;
    new_node = new Node;
    new_node->data=new_data;
    new_node->key=new_key;
    if((*this).is_empty()||this->first->key>new_key)
    {
        new_node->next = this->first;
        this->first = new_node;
    }
    else
    {
        temp = this->first;
        while (temp->next!=nullptr&&temp->next->key<=new_key)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    
    
}
template<class KEY_TYPE, class VALUE_TYPE>
void Priority_Queue<KEY_TYPE,VALUE_TYPE>::insert(KEY_TYPE new_key, VALUE_TYPE new_data){}
template<class KEY_TYPE, class VALUE_TYPE>
VALUE_TYPE Priority_Queue<KEY_TYPE,VALUE_TYPE>::remove_min(){
    if((*this).is_empty())
    {
        throw std::runtime_error("Kolejka jest pusta");
    }
    else
    {
        Node *temp;
        VALUE_TYPE data = this->first->data;
        temp = this->first;
        this->first = temp->next;
        free(temp);
        return data;
    }
}
template<class KEY_TYPE, class VALUE_TYPE>
const VALUE_TYPE & Priority_Queue<KEY_TYPE,VALUE_TYPE>::min() const {
    if (!((*this).is_empty()))
    {
        return this->first->data;
    }
    else
    {
        throw std::runtime_error("Kolejka jest pusta");
    }
    
}
template<class KEY_TYPE, class VALUE_TYPE>
bool Priority_Queue<KEY_TYPE,VALUE_TYPE>::is_empty() const{
    if(this->first==nullptr){
        return true;
    }
    return false;
}
template<class KEY_TYPE, class VALUE_TYPE>
int Priority_Queue<KEY_TYPE,VALUE_TYPE>::size() const{
    int size=0;
    Node *temp;
    temp = this->first;
    while (temp!=nullptr)
    {
        size++;
        temp=temp->next;
    }
    if (temp==nullptr)
    {
        return size;
    }
    return 0;
}