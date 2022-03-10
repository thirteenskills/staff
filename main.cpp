#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "D:\c++\staffsystem\head\head.h"

using namespace std;

int main()
{
    int select;
    workermanager wm;
    while (1)
    {
        wm.mainsys();
        cout << "请输入你的选择：  ";
        cin >> select;
        switch (select)
        {
        case 1: //添加职工信息
        {
            wm.appe();
            break;
        }
        case 2: //显示职工信息
        {
            wm.show();
            break;
        }
        case 3: //删除职工信息
        {
            wm.dele();
            break;
        }
        case 4: //修改职工信息
        {
            wm.change();
            break;
        }
        case 5: //查找职工信息
        {
            wm.find();
            break;
        }
        case 6: //按照编号排序
        {
            wm.sort();
            break;
        }
        case 7: //清空职工信息
        {
            wm.clear();
            break;
        }
        case 0: //退出操作系统
        {
            cout << "您已退出职工管理系统" << endl;
            system("pause");
            return 0;
        }
        }
    }

    system("pause");
    return 0;
}