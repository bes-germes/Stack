#include "LinkedListStack.h"


void LinkedListStack::pushStack(const ValueType &value){
    this->pushFront(value);
}

void LinkedListStack::popStack(){
    this->removeFront();
}

const ValueType &LinkedListStack::topStack() const{
    return getNode(0)->value;
}

// проверка на пустоту
bool LinkedListStack::isEmptyStack() const{
    return this->size() == 0;
}

// размер
size_t LinkedListStack::sizeStack() const{
    return this->size();
}

