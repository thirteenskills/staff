#include "D:\c++\staffsystem\head\boss.h"
void boss::showinfo()
{
    cout << "职工编号" << this->m_id << "\t职工姓名: " << this->m_name << "\t岗位: " << this->showdepartment() << "\t岗位职责: 下发任务给经理" << endl;
};
string boss::showdepartment()
{
    return string("老板");
};
boss::boss(int id, string name, int depart)
{
    this->m_id = id;
    this->m_name = name;
    this->m_depart = depart;
}