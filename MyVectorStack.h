#pragma once
#include "StackImplementation.h"
#include "MyVector.h" // меняете на include вашего вектора

// вариант с использованием ранее написанного вектора и множественного наследования
// если бы вектор не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию
class MyVectorStack : public StackImplementation, public MyVector{

    void pushStack(const ValueType &value);

    void popStack();

    const ValueType &topStack() const;

    bool isEmptyStack() const;

    size_t sizeStack() const;
};
