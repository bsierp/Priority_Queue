/**
 * @file Queue.cpp
 * @brief Plik zawiera definicje metod klasy PriorityQueue.
 * 
 */
#include "Queue.hh"
#include <iostream>


template<> void PriorityQueue<int,string>::insert(int new_key, string new_data){
    Node *new_node;//węzeł, który zostanie dodany do kolejki
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
        Node *temp = this->first; //pomocniczy węzeł do przeszukiwania kolejki
        while (temp->next!=nullptr&&temp->next->key<=new_key)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    
    
}
template<class KEY_TYPE, class VALUE_TYPE>
void PriorityQueue<KEY_TYPE,VALUE_TYPE>::insert(KEY_TYPE new_key, VALUE_TYPE new_data){}
template<class KEY_TYPE, class VALUE_TYPE>
VALUE_TYPE PriorityQueue<KEY_TYPE,VALUE_TYPE>::remove_min(){
    if((*this).is_empty())
    {
        throw std::underflow_error("Kolejka jest pusta");
    }
    else
    {
        Node *temp;//węzeł pomocniczy do przechowania elementu o najmniejszym priorytecie
        VALUE_TYPE data = this->first->data;
        temp = this->first;
        this->first = temp->next;
        delete temp;
        return data;
    }
}
template<class KEY_TYPE, class VALUE_TYPE>
const VALUE_TYPE & PriorityQueue<KEY_TYPE,VALUE_TYPE>::min() const {
    if ((*this).is_empty())
    {
        throw std::underflow_error("Kolejka jest pusta");
    }
    else
    {
        return this->first->data;
    }
    
}
template<class KEY_TYPE, class VALUE_TYPE>
bool PriorityQueue<KEY_TYPE,VALUE_TYPE>::is_empty() const{
    if(this->first==nullptr){
        return true;
    }
    else
    {
    return false;
    }
}
template<class KEY_TYPE, class VALUE_TYPE>
int PriorityQueue<KEY_TYPE,VALUE_TYPE>::size() const{
    int size=0;// liczba elementów kolejki
    Node *temp;//węzeł pomocniczy do sprawdzania ilości elementów kolejki
    temp = this->first;
    
    while (temp!=nullptr)
    {
        size++;
        temp=temp->next;
    }
    return size;
}