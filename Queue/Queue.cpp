// Student ID: 20274909

#include "Queue.h"

using namespace std;

int main()
{
   Queue<int> my_queue(5);
   Queue<int>::set_sentinel(0);

   for (int i = 1; i <= 4; i++) {
      my_queue.enqueue(i);
   }

   cout << my_queue.to_string(3);

   cout << my_queue.to_string();

   my_queue.dequeue();

   cout << my_queue.to_string();

   popalot(my_queue);

   cout << my_queue.to_string();

   my_queue.dequeue();

   cout << my_queue.to_string();

   for (int i = 1; i <= 6; i++) {
      my_queue.enqueue(i);
   }

   cout << my_queue.to_string();

   my_queue.resize(19);

   cout << my_queue.to_string();

   for (int i = 111; i <= 120; i++) {
      my_queue.enqueue(i);
   }

   cout << my_queue.to_string();

   my_queue.resize(7);

   cout << my_queue.to_string();

   my_queue.resize(20);

   cout << my_queue.to_string();

   my_queue.resize(30);

   cout << my_queue.to_string();
}