## Feed the Hungry Brothers!

BIG THANK YOU to [@j84guo](https://github.com/j84guo) for coming up with this adorable question!

### Setup
There was once a group of brothers named Udon, Bun, Xiao Xiong, Toaster and Dou
Bao. The brothers worked as fire fighters and spent all day saving people from
fires.

By night time, they would always be hungry and would go home to eat. They had a
private chef called Meow, who would cook their favourite dishes. The chef had
an assistent called Weng, who would take dishes from the chef and place them on
the table.

Their table at home was small and only had room for 5 plates at a time. The
plates were of a magical bottomless variety bought from Home Sense, meaning
five different dishes could be stored on the table at one time, and none of the
ccould ever run out.

However, if a brother requested a dish which was not on the table at the time,
the chef's assistant would have to choose a dish from the table to eject, take
it off the table and replace it with the requested dish, brought from the
kitchen.

### Algorithm
The algorithm used by the chef's assistant to choose which dish on the table to
remove is called least frequently used (LFU) which is used in computers to
determine which blocks of memory should be stored in the CPU cache.

https://en.wikipedia.org/wiki/Least_frequently_used

In our scenario, each dish has a usage count associated with it, i.e. the
number of times it was requested. When a request comes in for a dish and that
dish does not currently exist on the table, the chef's assistant must choose
the dish with the least uses to replace, i.e. the least popular so far. This is
a reasonably good caching algorithm as it ensures that frequently used "things"
are kept in the cache for fast access.

### Task:
Write a program which reads integers from stdin, where each
integers represents a request for a particular "dish". You have an array of
size 5 in memory which represents your "table". For every dish request, if
<b>(1)</b> the dish alread exists on the table, you can considered the request
satisfied (recall the plates are botomless!!). If <b>(2)</b> it does not exist
but there is space on the table, you can simply add the dish to the table.
Otherwise, <b>(3)</b> choose the dish with the least uses and remove it, 
replacing it with the requested dish.

For any given set of inputs, your program should return the number of times the
assistant had to swap a dish off the table and replace it with a new one (i.e.
cache misses).

### To run:

```
g++ -o lfu_exercise -std=c++11 -Wall lfu_exercise.cpp

./lfu_exercise < test1.txt
```
