#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;

class worker
{
public:
    virtual void showinfo() = 0;
    virtual string showdepartment() = 0;

    int m_id;
    string m_name;
    int m_depart;
};