#include "MyVectorStack.h"

void MyVectorStack::pushStack(const ValueType &value){
    this->pushFront(value);
}

void MyVectorStack::popStack(){
    this->erase(0);
}

const ValueType &MyVectorStack::topStack() const{
    return this->top();
}

// проверка на пустоту
bool MyVectorStack::isEmptyStack() const{
    return this->size() == 0;
}

// размер
size_t MyVectorStack::sizeStack() const{
    return this->size();
}
