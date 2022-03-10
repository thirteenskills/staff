#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "D:\c++\staffsystem\head\worker.h"

using namespace std;

#define filename "D:\\c++\\staffsystem\\workers.txt"

class workermanager
{
public:
    int m_workernum;
    bool fileisempty;
    worker **m_workerarr;

    workermanager();
    ~workermanager();

    void mainsys();
    void appe();
    void save();
    void initiworker();  
    void show();
    void dele();
    int findis(int id);
    void find();
    void change();
    void sort();
    void clear();
    int getfilenum();
};
