#include <iostream>
#include "Displayable.h"
#include "ScoreCounter.h"

int main()
{
    Displayable* obj = new ScoreCounter();
    obj->display();
}