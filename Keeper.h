// Keeper.h
#pragma once
#include "Base.h"

class Keeper {
private:
    Base** items;     // Динамический массив указателей на базовый класс
    int count;        // Текущее количество объектов
    int capacity;     // Текущая емкость массива

public:
    Keeper();
    ~Keeper();
    
    void printAll() const;
    // Методы добавления/удаления/сохранения добавим в следующие дни
};