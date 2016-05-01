/*
 * Filename:    DynamicArray.ipp
 * Author:      Victor Yuen
 * Description: An implemenation of a dynamic array, similar to the vector
 *              class found in the standard C++ library.
 *
 */

#ifndef DYNAMIC_ARRAY_IPP
#define DYNAMIC_ARRAY_IPP

// Constructors and Destructors
template <class T> DynamicArray<T>::DynamicArray() : array(NULL), arr_size(0), max_arr_size(0) {}
template <class T> DynamicArray<T>::DynamicArray(size_t arr_size, const T &value) : arr_size(arr_size), max_arr_size(arr_size) {
  // Intialize array to specific size with provided value
  array = new T[arr_size];
  for(size_t i = 0; i < arr_size; i++) {
    array[i] = value;
  }
}
template <class T> DynamicArray<T>::~DynamicArray() {
  delete[] array;
}

// Basic Array Functions
template <class T> T& DynamicArray<T>::at(size_t index) {
  if(index < 0 || index >= arr_size) {
    std::cerr << "ERROR: Index " << index << " is out of range" << std::endl;
    throw;
  }
  return array[index];
}
template <class T> T& DynamicArray<T>::operator[](size_t index) {
  return array[index];
}
template <class T> bool DynamicArray<T>::hasElement(const T &value) {
  for(int i = 0; i < arr_size; i++) {
    if(array[i] == value) {
      return true;
    }
  }
  return false;
}
template <class T> void DynamicArray<T>::insert(size_t index, const T &value) {
  // Resize Array If necessary
  if(arr_size >= max_arr_size) {
    increaseSize();
  }

  // Move elements over one if necessary
  for(int i = arr_size, j = i-1 ; i > index; --i, --j) {
    array[i] = array[j];
  }

  // Add Element to the array
  array[index] = value;
  ++arr_size;
}
template <class T> void DynamicArray<T>::push_back(const T &value) {
  insert(arr_size, value);
}
template <class T> void DynamicArray<T>::erase(size_t index) {
  // If there aren't any elements to delete, throw error
  if(arr_size == 0) {
    std::cerr << "ERROR: Array has no more elements to erase" << std::endl;
    throw;
  } else if(index >= arr_size) {
    std::cerr << "ERROR: Index " << index << " is out of range" << std::endl;
    throw;
  }

  // Move elements over one if necessary
  for(int i = index, j = index + 1; j < arr_size; ++i, ++j) {
    array[i] = array[j];
  }

  // Update Properties
  --arr_size;

  // Resize if necessary
  if(arr_size <= max_arr_size * 0.3) {
    decreaseSize();
  }
}

// Array Properties
template <class T> size_t DynamicArray<T>::size() const {
  return arr_size;
}
template <class T> size_t DynamicArray<T>::max_size() const {
  return max_arr_size;
}

// Resize Methods
template <class T> void DynamicArray<T>::resize(size_t new_size) {
  // Make new array with new_size and copy array over
  T *arr2 = new T[new_size];
  for(int i = 0; i < arr_size; ++i) {
    arr2[i] = array[i];
  }

  // Delete old array and reassign old array to new array
  delete[] array;
  array = arr2;
  max_arr_size = new_size;
}
template <class T> void DynamicArray<T>::increaseSize() {
  // Resize to double the array's original size
  resize(max_arr_size * 2);
}
template <class T> void DynamicArray<T>::decreaseSize() {
  // Resize to half the array's original size
  resize(max_arr_size / 2);
}


// Test Methods
template <class T> T* DynamicArray<T>::getArray() {
  return array;
}
template <class T> void DynamicArray<T>::printArray() {
  std::cout << "[";

  for(size_t i = 0; i < arr_size; i++) {
    std::cout << array[i]
              << ((i != arr_size-1) ? ", " : "");
  }

  std::cout << "]" << std::endl;
}

#endif
