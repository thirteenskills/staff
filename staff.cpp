#include "D:\c++\staffsystem\head\staff.h"

void staff::showinfo()
{
    cout << "职工编号" << this->m_id << 
    "\t职工姓名: " << this->m_name <<
     "\t岗位: " << this->showdepartment() <<
      "\t岗位职责: 完成经理交给的任务" << endl;
};
string staff::showdepartment(){
    return string("职员");};
staff::staff(int id, string name, int depart)
{this->m_id=id;
this->m_name=name;
this->m_depart=depart;
}