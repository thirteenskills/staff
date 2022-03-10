#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "D:\c++\staffsystem\head\worker.h"
using namespace std;

class manager : public worker
{public:
    manager(int id, string name, int depart);
    virtual void showinfo();
    virtual string showdepartment();
};