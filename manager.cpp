#include "D:\c++\staffsystem\head\manager.h"

void manager::showinfo()
{
    cout << "ְ�����" << this->m_id << 
    "\tְ������: " << this->m_name <<
     "\t��λ: " << this->showdepartment() <<
      "\t��λְ��: ����ϰ彻��������,���·������Ա��" << endl;
};
string manager::showdepartment(){
    return string("����");};

manager::manager(int id, string name, int depart)
{this->m_id=id;
this->m_name=name;
this->m_depart=depart;
}