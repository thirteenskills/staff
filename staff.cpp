#include "D:\c++\staffsystem\head\staff.h"

void staff::showinfo()
{
    cout << "ְ�����" << this->m_id << 
    "\tְ������: " << this->m_name <<
     "\t��λ: " << this->showdepartment() <<
      "\t��λְ��: ��ɾ�����������" << endl;
};
string staff::showdepartment(){
    return string("ְԱ");};
staff::staff(int id, string name, int depart)
{this->m_id=id;
this->m_name=name;
this->m_depart=depart;
}