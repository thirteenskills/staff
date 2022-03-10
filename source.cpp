
#include "D:\c++\staffsystem\head\head.h"
#include "D:\c++\staffsystem\head\boss.h"
#include "D:\c++\staffsystem\head\manager.h"
#include "D:\c++\staffsystem\head\staff.h"
//////////构造函数/////////
workermanager::workermanager()
{
    ifstream ifs;
    char ch;
    ifs.open(filename, ios::in);
    if (!ifs.is_open())
    {
        // cout << "文件不存在\n";
        this->m_workernum = 0;
        this->m_workerarr = NULL;
        this->fileisempty = true;
        ifs.close();
        return;
    }
    ifs >> ch;
    if (ifs.eof())
    {
        // std::cout << "文件为空" << endl;
        this->m_workernum = 0;
        this->m_workerarr = NULL;
        this->fileisempty = true;
        ifs.close();
        return;
    }

    int num = this->getfilenum();
    this->m_workernum = num;

    this->m_workerarr = new worker *[num];
    this->initiworker();
};
/////////析构函数////////
workermanager::~workermanager()
{
    if (this->m_workerarr != NULL)
    {
        for (int i = 0; i < m_workernum; i++)
        {
            delete m_workerarr[i];
            m_workerarr[i]=NULL;
        }
        delete[] this->m_workerarr;
        this->m_workerarr = NULL;
    }
}
///////////初始化员工（读取文件并生成堆数据）/////////
void workermanager::initiworker()
{
    ifstream ifs;
    ifs.open(filename, ios::in);

    int id, index = 0;
    string name;
    int depart;
    while (ifs >> id && ifs >> name && ifs >> depart)
    {
        worker *workern = NULL;
        switch (depart)
        {
        case 1:
        {
            workern = new staff(id, name, depart);
            break;
        }
        case 2:
        {
            workern = new manager(id, name, depart);
            break;
        }
        case 3:
        {
            workern = new boss(id, name, depart);
            break;
        }
        }

        this->m_workerarr[index] = workern;
        index++;
    }
    ifs.close();
}
//////////显示菜单//////////
void workermanager::mainsys()
{
    cout << string(41, '*') << endl
         << string(8, '*') << " 欢迎使用职工管理系统！ " << string(9, '*') << endl
         << string(13, '*') << "1、添加职工信息" << string(13, '*') << endl
         << string(13, '*') << "2、显示职工信息" << string(13, '*') << endl
         << string(13, '*') << "3、删除职工信息" << string(13, '*') << endl
         << string(13, '*') << "4、修改职工信息" << string(13, '*') << endl
         << string(13, '*') << "5、查找职工信息" << string(13, '*') << endl
         << string(13, '*') << "6、按照编号排序" << string(13, '*') << endl
         << string(13, '*') << "7、清空职工信息" << string(13, '*') << endl
         << string(13, '*') << "0、退出操作系统" << string(13, '*') << endl
         << string(41, '*') << endl;
}
////////添加员工//////////
void workermanager::appe()
{
flag:
    cout << "请输入添加员工数量：";
    int num = 0;
    cin >> num;
    if (num > 0)
    {
        int newsize = this->m_workernum + num;
        worker **newspace = new worker *[newsize];
        if (this->m_workerarr != NULL)
        {
            for (int i = 0; i < this->m_workernum; i++)
            {
                newspace[i] = this->m_workerarr[i];
            }
        }
        for (int i = 0; i < num; i++)
        {
            int id;
            string name;
            int depart;
            cout << "请输入第" << i + 1 << "位员工信息\n";
        scan_id:
            cout << "请输入员工id:  ";
            cin >> id;
            /////////////防止编号重复/////////
            for (int j = 0; j < m_workernum; j++)
            {
                if (m_workerarr[j]->m_id == id)
                {
                    cout << "编号重复！！请重新输入" << endl;
                    goto scan_id;
                }
            }
            for (int j = 0; j < i; j++)
            {
                if (newspace[this->m_workernum + j]->m_id == id)
                {
                    cout << "编号重复！！请重新输入" << endl;
                    goto scan_id;
                }
            }
            ////////////////////////////////////
            cout << "请输入员工姓名:  ";
            cin >> name;
            cout << "请输入员工岗位: \n职员————1\n经理————2\n老板————3\n";
            cin >> depart;

            worker *workern = NULL;
            switch (depart)
            {
            case 1:
            {
                workern = new staff(id, name, depart);
                break;
            }
            case 2:
            {
                workern = new manager(id, name, depart);
                break;
            }
            default:
            {
                workern = new boss(id, name, depart);
                break;
            }
            }
            newspace[this->m_workernum + i] = workern;
        }
        delete[] this->m_workerarr;
        this->m_workerarr = newspace;
        this->m_workernum = newsize;
        this->fileisempty = false;
        cout << "成功添加" << num << "位员工" << endl;
        this->save();
        cout << "成功保存员工列表" << endl;
    }
    else
    {
        cout << "请重新输入正确数值" << endl;
        system("pause");
        system("cls");
        goto flag;
    }
    system("pause");
    system("cls");
};
//////////////存储员工数据///////////
void workermanager::save()
{
    ofstream ofs;
    ofs.open(filename, ios::out);

    for (int i = 0; i < this->m_workernum; i++)
    {
        ofs << this->m_workerarr[i]->m_id << "  "
            << this->m_workerarr[i]->m_name << "  "
            << this->m_workerarr[i]->m_depart << endl;
    }
    ofs.close();
}
////////////读取文件员工数///////////
int workermanager::getfilenum()
{
    ifstream ifs;
    ifs.open(filename, ios::in);

    int id, num = 0;
    string name;
    int depart;
    while (ifs >> id && ifs >> name && ifs >> depart)
    {
        num++;
    }
    return num;
}
////////显示所有职工///////
void workermanager::show()
{
    if (this->fileisempty)
    {
        cout << "员工不存在" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_workernum; i++)
        {
            this->m_workerarr[i]->showinfo();
        }
    }

    cout << "输出结束" << endl;
    system("pause");
    system("cls");
}
///////////判断职工存在////////////
int workermanager::findis(int id)
{
    for (int i = 0; i < m_workernum; i++)
    {
        if (m_workerarr[i]->m_id == id)
        {
            return i;
        }
    }
    return -1;
}
///////////删除职工//////////
void workermanager::dele()
{

    if (fileisempty)
    {
        cout << "文件为空" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "请输入您想删除的员工编号: ";
    int id;
    cin >> id;
    int index = findis(id);
    if (index == -1)
    {
        cout << "查无此人" << endl;
    }
    else
    {
        delete m_workerarr[index];
        for (int i = index; i < m_workernum; i++)
        {
            m_workerarr[i] = m_workerarr[i + 1];
        }
        cout << "删除结束" << endl;

        m_workernum--;
        this->save();
        if (m_workernum == 0)
            fileisempty = 1;
    }

    system("pause");
    system("cls");
}
////////修改职工//////////
void workermanager::change()
{
    if (fileisempty)
    {
        cout << "文件为空" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "请输入您想修改的员工编号: ";
    int id;
    cin >> id;
    int index = findis(id);
    if (index == -1)
    {
        cout << "查无此人" << endl;
    }
    else
    {
        cout << "您想修改\nid————1\n姓名————2\n岗位————3\n";
        int choo;
        cin >> choo;
        cout << "请输入修改后的结果:  ";
        switch (choo)
        {
        case 1:
        {
            int id;
            cin >> id;
            m_workerarr[index]->m_id = id;
            break;
        }
        case 2:
        {
            string name;
            cin >> name;
            m_workerarr[index]->m_name = name;
            break;
        }
        case 3:
        {
            int depart;
            cout << "请输入员工岗位: \n职员————1\n经理————2\n老板————3\n";
            cin >> depart;

            worker *workern = NULL;
            switch (depart)
            {
            case 1:
            {
                workern = new staff(m_workerarr[index]->m_id, m_workerarr[index]->m_name, depart);
                break;
            }
            case 2:
            {
                workern = new manager(m_workerarr[index]->m_id, m_workerarr[index]->m_name, depart);
                break;
            }
            default:
            {
                workern = new boss(m_workerarr[index]->m_id, m_workerarr[index]->m_name, depart);
                break;
            }
            }
            delete m_workerarr[index];
            m_workerarr[index] = workern;
        }
            cout << "修改成功" << endl;
            save();
        }
        system("pause");
        system("cls");
    }
}
////////查找职工信息/////////
void workermanager::find()
{
    if (fileisempty)
    {
        cout << "文件为空" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "查找员工编号————1\n查找员工姓名————2\n";
    int a;
    cin >> a;
    if (a == 1)
    {
        cout << "请输入您想查找的员工编号: ";
        int id;
        cin >> id;
        int index = findis(id);
        if (index == -1)
        {
            cout << "查无此人" << endl;
        }
        else
        {
            m_workerarr[index]->showinfo();
        }
    }
    else
    {
        cout << "请输入您想查找的员工姓名: ";
        string name;
        int a = 0;
        cin >> name;
        for (int i = 0; i < m_workernum; i++)
        {
            if (m_workerarr[i]->m_name == name)
            {
                m_workerarr[i]->showinfo();
                a = 1;
            }
        }
        if (a == 0)
        {
            cout << "查无此人" << endl;
        }
    }

    cout << "查找结束" << endl;
    system("pause");
    system("cls");
}
////////排序////////////////
void workermanager::sort()
{
    if (fileisempty)
    {
        cout << "文件为空" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "请选择排序方式\n升序————1\n降序————2\n";
    int a;
    cin >> a;
    if (a == 1)
    {
        for (int i = 0; i < m_workernum - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < m_workernum; j++)
                if (m_workerarr[j]->m_id < m_workerarr[min]->m_id)
                    min = j;
            std::swap(m_workerarr[i], m_workerarr[min]);
        }
    }
    else
    {
        for (int i = 0; i < m_workernum - 1; i++)
        {
            int max = i;
            for (int j = i + 1; j < m_workernum; j++)
                if (m_workerarr[j]->m_id > m_workerarr[max]->m_id)
                    max = j;
            std::swap(m_workerarr[i], m_workerarr[max]);
        }
    }
    cout << "排序完毕,结果如下" << endl;
    save();
    show();
}
////////////清空///////////
void workermanager::clear()
{
    cout << "您确定要清空吗？\n是————1\n否————2\n";
    int choo;
    cin >> choo;
    if (choo == 1)
    {
        for (int i = 0; i < m_workernum; i++)
        {
            delete m_workerarr[i];
            m_workerarr[i]=NULL;
        }

        delete[] m_workerarr;
        m_workerarr = NULL;
        m_workernum = 0;
        fileisempty = 1;
        save();
        cout << "已清空" << endl;
    }
    else
    {
        cout << "已取消" << endl;
    }
    system("pause");
    system("cls");
}
