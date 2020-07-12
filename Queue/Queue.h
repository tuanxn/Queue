// Student ID: 20274909

#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

#ifndef Queue_h
#define Queue_h

// TODO: Fill in as necessary
template <typename T>
class Queue {
private:
   std::vector<T> _data;
   size_t _head, _tail;
   static T _sentinel;
public:
   static const int MAX_DISP_ELEMS = 100;
   Queue(size_t size);
   static void set_sentinel(const T& elem) { _sentinel = elem; }
   static T get_sentinel() { return _sentinel; }
   bool is_empty() const;
   size_t size() const { return _tail - _head; }
   void resize(size_t size);
   const T& peek() const;
   bool dequeue();
   bool enqueue(const T& elem);
   std::string to_string(size_t limit = MAX_DISP_ELEMS) const;
   friend class Tests; // Don't remove this line
};
template <typename T> T Queue<T>::_sentinel = T();
template <typename T>
Queue<T>::Queue(size_t size) {
   _data.resize(size + 1);
   _head = 0;
   _tail = _head;
   // TODO
}

template <typename T>
bool Queue<T>::enqueue(const T& elem) {
   if (_head == ((_tail + 1) % _data.size())) {
      return false;
   }
   _data[_tail % _data.size()] = elem;
   _tail++;
   return true;
}

template <typename T>
bool Queue<T>::dequeue() {
   if (is_empty()) {
      return false;
   }
   _data[_head % _data.size()] = get_sentinel(); // TODO check to see if this is true
   _head++;
   return true;
}

template <typename T> 
const T& Queue<T>::peek() const {
   if (is_empty()) {
      return _sentinel;
   }
   return _data[_head % _data.size()]; // TODO check if this is byval or byref. Need to be a copy
}

template <typename T> 
bool Queue<T>::is_empty() const {
   if (_head == _tail) {
      return true;
   }
   return false;
}

template <typename T> 
void Queue<T>::resize(size_t size) {

   Queue newQueue = Queue(size);
   size_t max_size;
   if (size < this->size()) {
      max_size = size;
   }
   else {
      max_size = this->size();
   }
   for (size_t i = 0; i < max_size; i++) {
      newQueue.enqueue(this->peek());
      this->dequeue();
   }

   *this = newQueue;
}

template <typename T>
void popalot(Queue<T>& q) {
   while (q.dequeue());
}

template <typename T> 
string Queue<T>::to_string(size_t lim) const {
   stringstream s_size;
   s_size << this->size();
   string output = "# Queue - size = " + s_size.str() + "\n";
   output += "data :";

   for (size_t i = _head; i < _tail; i++) {
      stringstream i_str;
      i_str << _data[i % _data.size()];
      output += i_str.str() + " ";
      if ((i+1) == lim) {
         output += "...";
         break;
      }
   }

   output += "\n";
   return output;
}

// TODO - Fill in the missing implementations. Experiment with the aesthetics by moving
// some of these implementations inline (into your class def above). See which gives
// you more readable code.
#endif /* Queue_h */