/*
CH08-320143
a2 p3.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <bits/stdc++.h>

#ifndef _QUEUE_H
#define _QUEUE_H

template <class T>
class Queue{

    T *ptr;
    int size;
    int curr;

public:

    /* Constructors and desctructors */

    /**
     * Default constructor. Sets the size of the Queue to 10
    */
    Queue(){
        this->size = 10;
        this->ptr = new T[this->size];
        this->curr = 0;
    }

    /**
     * Copy constructor. Initializes a new Queue exactly the same
     * as the parameter q
     * @param q the Queue which is copied
    */
    Queue(const Queue& q){
        this->size = q.size;
        this->ptr = new T[this->size];
        for(int i = 0; i < this->size; i++){
            this->ptr[i] = q.ptr[i];
        }
        this->curr = q.curr;
    }

    /**
     * Parametrized constructor. Sets the size to the parameter size
     * @param size the size of the new Queue
    */
    Queue(int size){
        this->size = size;
        this->ptr = new T[size];
        this->curr = 0;
    }

    /**
     * Default destructor
    */
    ~Queue(){
        delete [] this->ptr;
        this->size = this->curr = 0;
    }

    /* Service methods */

    /**
     * Pushesh a new element in the back of the Queue
     * @param elem the new element pushed in the Queue
     * @return true if succesfully done, false otherwise
    */
    bool push(T elem){
        if(this->curr == this->size){
            return false;
        }
        this->ptr[this->curr++] = elem;
        return true;
    }

    /**
     * Pushesh an element from the front of the Queue
     * @param out passed by reference: the popped value is stored there
     * @return true if succesfully done, false otherwise
    */
    bool pop(T& out){
        if(this->curr == 0){
            return false;
        }
        out = this->ptr[0];
        for(int i = 0; i < this->curr; i++){
            this->ptr[i] = this->ptr[i+1];
        }
        this->curr--;
        return true;
    }

    /**
     * @return the element in the back of the Queue
    */
    T back(){
        assert(this->curr > 0);
        return this->ptr[this->curr-1];
    }

    /**
     * @return the element in the front of the Queue
    */
    T front(){
        assert(this->curr > 0);
        return this->ptr[0];
    }

    /**
     * @return the number of entries in the Queue
    */
    int getNumEntries(){
        return this->curr;
    }

    /**
     * Method which resizes the Queue to have maximum element
     * of parameter size. If the current number of elements is more than
     * the new size, then those elements are lost
     * @param size the new size of the Queue
    */
    void resize(int size){
        T *newptr = new T[size];
        for(int i = 0; i < std::min(this->curr, size); i++){
            newptr[i] = this->ptr[i];
        }
        delete [] this->ptr;
        this->ptr = newptr;
        this->size = size;
        this->curr = std::min(this->curr, size);
    }

    /**
     * @return the size of the Queue. In other words, the maximum number
     *         of entries the Queue can have
    */
    int getSize(){
        return this->size;
    }
};

#endif