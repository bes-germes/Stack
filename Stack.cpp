#include "Stack.h"
#include "LinkedListStack.h"
#include "MyVectorStack.h"
#include "StackImplementation.h"

#include <stdexcept>

Stack::Stack(StackContainer container)
        : _containerType(container)
        {
    switch (container)
    {
        case StackContainer::List:
            {
            _pimpl = new LinkedListStack();// конкретизируйте под ваши конструкторы, если надо
            break;
        }
        case StackContainer::Vector:
            {
            _pimpl = new MyVectorStack();// конкретизируйте под ваши конструкторы, если надо
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container)
        : _containerType(container)
        {
    // принцип тот же, что и в прошлом конструкторе
    switch (container){
        case StackContainer::List:
            {
            _pimpl = new LinkedListStack();
            for (int i = 0; i < arraySize; ++i)
            {
                _pimpl->pushStack(valueArray[i]);
            }
            break;
        }
        case StackContainer::Vector:
            {
            _pimpl = new MyVectorStack();
            for (int i = 0; i < arraySize; ++i)
            {
                _pimpl->pushStack(valueArray[i]);
            }
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Stack::Stack(const Stack& copyStack)
    {
        switch (copyStack._containerType){
            case StackContainer::List:
            {
                _pimpl = new LinkedListStack();    // конкретизируйте под ваши конструкторы, если надо
                break;
            }
            case StackContainer::Vector:
            {
                _pimpl = new MyVectorStack();    // конкретизируйте под ваши конструкторы, если надо
                break;
            }
            default:
                throw std::runtime_error("Неизвестный тип контейнера");
        }
        int copySize = copyStack.sizeStack();
        ValueType *newArray = new ValueType[copySize];
        for (int i = 0; i < copySize; ++i) {
            newArray[i] = copyStack._pimpl->topStack();
            copyStack._pimpl->popStack();
        }
        for (int i = 0; i < copySize; ++i) {
            _pimpl->pushStack(newArray[i]);
            copyStack._pimpl->pushStack(newArray[i]);
        }
        delete [] newArray;
}

Stack& Stack::operator=(const Stack& copyStack)
        {
    switch (copyStack._containerType){
        case StackContainer::List:
            {
            _pimpl = new LinkedListStack();    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
        case StackContainer::Vector:
            {
            _pimpl = new MyVectorStack();  // конкретизируйте под ваши конструкторы, если надо
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
    int copySize = copyStack.sizeStack();
    ValueType *newArray = new ValueType[copySize];
    for (int i = 0; i < copySize; ++i) {
        newArray[i] = copyStack._pimpl->topStack();
        copyStack._pimpl->popStack();
    }
    for (int i = 0; i < copySize; ++i) {
        _pimpl->pushStack(newArray[i]);
        copyStack._pimpl->pushStack(newArray[i]);
    }
    delete [] newArray;
    return *this;
    // TODO: вставьте здесь оператор return
}

Stack::~Stack()
{
    delete _pimpl;		// композиция!
}

void Stack::pushStack(const ValueType& value)
{
    _pimpl->pushStack(value);
}

void Stack::popStack()
{
    _pimpl->popStack();
}

const ValueType& Stack::topStack() const
{
    return _pimpl->topStack();
}


bool Stack::isEmptyStack() const
{
    return _pimpl->isEmptyStack();
}


size_t Stack::sizeStack() const
{
    return _pimpl->sizeStack();
}

