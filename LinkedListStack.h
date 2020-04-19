#pragma once
#include "StackImplementation.h"
#include "LinkedList.h"

// вариант с использованием ранее написанного вектора и множественного наследования
// если бы вектор не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию
class LinkedListStack : public StackImplementation, public LinkedList{
    // вот тут вы вступаете в дело
public:

    void pushStack(const ValueType &value);

    // удаление с хвоста
    void popStack();

    const ValueType &topStack() const;

    // проверка на пустоту
    bool isEmptyStack() const;

    // размер
    size_t sizeStack() const;

};