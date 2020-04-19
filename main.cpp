#include <iostream>
#include "Stack.h"

int main() {
    Stack s(StackContainer::List);
    s.pushStack(549);
    std::cout << s.topStack() << std::endl;
    Stack c;
    c = s;
    c.pushStack(1);
    std::cout << c.topStack() << std::endl;
}
