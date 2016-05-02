/*
 * Title:       SinglyLinkedList
 * Author:      Victor Yuen
 * Description: An implemenation of the singly linked list data structure.
 *              Note that cycles are not possible in this implementation.
 */

#ifndef SINGLY_LINKED_LIST_IPP
#define SINGLY_LINKED_LIST_IPP

template <class T> SinglyLinkedList<T>::SinglyLinkedList() : head(NULL), tail(NULL), sll_size(0) {}
template <class T> SinglyLinkedList<T>::SinglyLinkedList(size_t sll_size, const T &value) {
  head = NULL;
  tail = NULL;
  this->sll_size = 0;

  // Push on N elements
  for(size_t i = 0; i < sll_size; ++i) {
    push_back(value);
  }
}
template <class T> SinglyLinkedList<T>::~SinglyLinkedList() {
  SinglyLinkedListNode<T> *curr = head, *next;

  // Delete all nodes
  while(curr) {
    next = curr->next;
    delete curr;
    curr = next;
  }
}

template <class T> T& SinglyLinkedList<T>::at(size_t index) {
  // If out of bounds, print error and throw
  if(index < 0 || index >= sll_size) {
    std::cerr << "ERROR: Index " << index << " is out of bounds." << std::endl;
    throw;
  }

  // Use [] operator to find the nth element and return its data
  return (*this)[index];
}
template <class T> T& SinglyLinkedList<T>::operator[](size_t index) {
  // Find the nth element and return its data
  SinglyLinkedListNode<T> *curr = head;
  for(size_t i = 0; i < index; ++i) {
    curr = curr->next;
  }

  return curr->data;
}

template <class T> bool SinglyLinkedList<T>::hasElement(const T& value) {
  // Search entire list for the element
  SinglyLinkedListNode<T> *curr = head;
  for(size_t i = 0; i < sll_size; ++i, curr = curr->next) {
    if(curr->data == value) {
      return true;
    }
  }

  return false;
}

template <class T> void SinglyLinkedList<T>::insert(size_t index, const T &value) {
  // Print error and throw if index is out of range
  if(index < 0 || index > sll_size) {
    std::cerr << "ERROR: Index " << index << " is out of bounds." << std::endl;
    throw;
  }

  // Create new  node to add to list
  SinglyLinkedListNode<T> *new_node = new SinglyLinkedListNode<T>;
  new_node->data = value;
  new_node->next = NULL;

  // If list is empty add to list
  if(sll_size == 0) {
    head = new_node;
    tail = new_node;
  }
  // If index == 0, add to front
  else if(index == 0) {
    new_node->next = head;
    head = new_node;
  }
  // If index == sll_size, add to end
  else if(index == sll_size) {
    tail->next = new_node;
    tail = new_node;
  }
  // Otherwise, find location and add new node
  else {
    SinglyLinkedListNode<T> *prev = head, *curr = head->next;
    for(size_t i = 1; i < index; ++i, prev = curr, curr = curr->next);
    prev->next = new_node;
    new_node->next = curr;
  }

  ++sll_size;
}
template <class T> void SinglyLinkedList<T>::push_back(const T &value) {
  return insert(sll_size, value);
}
template <class T> void SinglyLinkedList<T>::push_front(const T &value) {
  return insert(0, value);
}
template <class T> void SinglyLinkedList<T>::erase(size_t index) {
  // Print error and throw if index is out of range
  if(index < 0 || index >= sll_size) {
    std::cerr << "ERROR: Index " << index << " is out of range." << std::endl;
    throw;
  }

  SinglyLinkedListNode<T> *curr = head, *prev = NULL;

  // If list has only one element, delete element and set head and tail to NULL
  if(sll_size == 1) {
    delete head;
    head = NULL;
    tail = NULL;
  }
  // If index == 0, delete head and move one over
  else if (index == 0) {
    curr = head->next;
    delete head;
    head = curr;
  }
  // Otherwise, find node at index and remove
  else {
    for(size_t i = 0; i < index; ++i, prev = curr, curr = curr->next);
    prev->next = curr->next;
    delete curr;
  }

  --sll_size;
}

template <class T> size_t SinglyLinkedList<T>::size() {
  return sll_size;
}
template <class T> void SinglyLinkedList<T>::printList() {
  std::cout << "[";

  SinglyLinkedListNode<T> *curr = head;
  for(size_t i = 0; i < sll_size; ++i, curr = curr->next) {
    std::cout << curr->data << ((i != sll_size - 1) ? ", " : "");
  }

  std::cout << "]" << std::endl;
}


#endif
