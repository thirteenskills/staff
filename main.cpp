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
        cout << "���������ѡ��  ";
        cin >> select;
        switch (select)
        {
        case 1: //���ְ����Ϣ
        {
            wm.appe();
            break;
        }
        case 2: //��ʾְ����Ϣ
        {
            wm.show();
            break;
        }
        case 3: //ɾ��ְ����Ϣ
        {
            wm.dele();
            break;
        }
        case 4: //�޸�ְ����Ϣ
        {
            wm.change();
            break;
        }
        case 5: //����ְ����Ϣ
        {
            wm.find();
            break;
        }
        case 6: //���ձ������
        {
            wm.sort();
            break;
        }
        case 7: //���ְ����Ϣ
        {
            wm.clear();
            break;
        }
        case 0: //�˳�����ϵͳ
        {
            cout << "�����˳�ְ������ϵͳ" << endl;
            system("pause");
            return 0;
        }
        }
    }

    system("pause");
    return 0;
}