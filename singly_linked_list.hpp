/*
 * Title:       SinglyLinkedList
 * Author:      Victor Yuen
 * Description: An interface of the singly linked list data structure.
 *              Note that cycles are not possible in this implementation.
 */

#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>
#include <cstddef>

template <class T> struct SinglyLinkedListNode {
  T data;
  SinglyLinkedListNode * next;
};

template <class T> class SinglyLinkedList {
  public:
    SinglyLinkedList();
    SinglyLinkedList(size_t sll_size, const T &value = T());
    ~SinglyLinkedList();

    // Default Data Structure Methods
    T& at(size_t index);                    // Indexing Method
    T& operator[](size_t index);
    bool hasElement(const T &value);              // Find Method
    void insert(size_t index, const T &value);    // Insert Method
    void push_back(const T &value);
    void push_front(const T &value);
    void erase(size_t index);              // Delete Method

    // Linked List Properties
    size_t size();

    // Test Methods
    void printList();

  private:
    SinglyLinkedListNode<T> *head, *tail;
    size_t sll_size;
};

#include "singly_linked_list.ipp"

#endif
