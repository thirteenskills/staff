#include "D:\c++\staffsystem\head\boss.h"
void boss::showinfo()
{
    cout << "ְ�����" << this->m_id << "\tְ������: " << this->m_name << "\t��λ: " << this->showdepartment() << "\t��λְ��: �·����������" << endl;
};
string boss::showdepartment()
{
    return string("�ϰ�");
};
boss::boss(int id, string name, int depart)
{
    this->m_id = id;
    this->m_name = name;
    this->m_depart = depart;
}