#ifndef STACK_H
#define STACK_H
#include <iostream>
template <typename Item>
class Stack
{
    private:
        Item * arr;
        int size;
        int top;
    public:
        Stack(int s)
        {
            arr = new Item[s];
            size = s;
            top = 0;
        }
        void push(Item item)
        {
            if (!isfull())
                arr[top++] = item;
            else
                std::cout << "Full." << std::endl;
        }
        Item pop()
        {
            if (!isempty())
            {
                Item temp = arr[--top];
                return temp;
            }
            else
                return Item();
        }
        Item peek() 
        {
            if (!isempty()) {
                return arr[top - 1];
            } else {
                std::cout << "Stack is empty." << std::endl;
                return Item();
            }
        }
        void print() 
        {
            std::cout << "Stack contents: ";
            for (int i = 0; i < top; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
        ~Stack() {delete [] arr;}
        bool isempty() {return top == 0;}
        bool isfull() {return top >= size;} 
};
#endif