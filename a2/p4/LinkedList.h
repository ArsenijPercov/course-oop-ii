/*
CH08-320143
a2 p4.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <bits/stdc++.h>

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

template <class T>
class LinkedList{

    class Link{
        public: 
        T val;
        Link *next;
        Link *prev;
    };
    Link *start;

    int size;

public: 

    /* Constructors and destructors */

    /**
     * Default constructor
    */
    LinkedList(){
        this->start = NULL;
        this->size = 0;
    }

    /**
     * Copy constructor
     * @param list makes a copy of new list exactly as this parameter
    */
    LinkedList(const LinkedList& list){
        this->start = list.start;
        this->size = list.size;
    }

    /**
     * Destructor
    */
    ~LinkedList(){
        delete this->start;
        this->size = 0;
    }

    /* Service methods */

    /**
     * Pushesh an element at the end of the linked list
     * @param elem the element which is inserted
    */
    void push_back(T elem){
        if(this->start == NULL){
            this->start = new Link();
            this->start->prev = NULL;
            this->start->next = NULL;
            this->start->val = elem;
            this->start++;
            return;
        }

        Link *curr = this->start;
        while(curr->next != NULL) curr = curr->next;
        curr->next = new Link();
        curr->next->prev = curr;
        curr->next->next = NULL;
        curr->next->val = elem;
        this->size++;
    }

    /**
     * Pushesh an element at the start of the linked list
     * @param elem the element which is inserted
    */
    void push_front(T elem){
        if(this->start == NULL){
            this->start = new Link();
            this->start->prev = NULL;
            this->start->next = NULL;
            this->start->val = elem;
            this->size++;
            return;
        }

        Link *newlink = new Link();
        newlink->next = this->start;
        newlink->prev = NULL;
        newlink->val = elem;
        this->start = newlink;
        this->size++;
    }

    /**
     * @return element at the begining of the list
    */
    T front(){
        assert(this->start != NULL);
        return this->start->val;
    }

    /**
     * @return element at the end of the list
    */
    T back(){
        assert(this->start != NULL);
        Link *curr = this->start;
        while(curr->next != NULL) curr = curr->next;
        return curr->val;
    }

    /**
     * Returns an element at the start of the list and delets it
     * from the list
     * @return the element at the start of the list
    */
    T pop_front(){
        assert(this->start != NULL);
        T ret = this->start->val;
        Link *tmp = this->start;
        this->start = this->start->next;
        delete tmp;
        this->size--;
        if(this->size == 0){
            this->start = NULL;
        }
        return ret;
    }

    /**
     * Returns an element at the end of the list and deletes it
     * from the list
     * @return the element at the end of the list
    */
    T pop_back(){
        assert(this->start != NULL);
        Link *curr = this->start;
        while(curr->next != NULL) curr = curr->next;
        T ret = curr->val;
        Link *tmp = curr;
        this->size--;
        if(this->size == 0){
            this->start = NULL;
        } else {
            Link *prev = curr->prev;
            prev->next = NULL;
            delete tmp;
        }
        return ret;
    }

    /**
     * @return the current size of the linked list
    */
    int getSize(){
        return this->size;
    }
};

#endif // !_LINKEDLIST_H