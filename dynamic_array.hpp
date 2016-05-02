/*
 * Title:       DynamicArray
 * Author:      Victor Yuen
 * Description: An interface for a dynamic array, similar to the vector
 *              class found in the standard C++ library.
 */

#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <cstddef>
#include <iostream>

template <class T> class DynamicArray {
  public:
    DynamicArray();
    DynamicArray(size_t arr_size, const T &value = T());
    ~DynamicArray();

    // // Basic Array Functions
    T& at(size_t index);                          // Index Method
    T& operator[](size_t index);
    bool hasElement(const T &value);              // Find Method
    void insert(size_t index, const T &value);    // Insert Method
    void push_back(const T &value);
    void erase(size_t index);                     // Delete Method

    // Array Properties
    size_t size() const;
    size_t max_size() const;

    // Array Test Methods, Will Be Removed
    T* getArray();
    void printArray();

  private:
    T *array;
    size_t arr_size;
    size_t max_arr_size;

    // // Resize Methods
    void resize(size_t new_size);
    void increaseSize();
    void decreaseSize();
};

#include "dynamic_array.ipp"

#endif
