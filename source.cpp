
#include "D:\c++\staffsystem\head\head.h"
#include "D:\c++\staffsystem\head\boss.h"
#include "D:\c++\staffsystem\head\manager.h"
#include "D:\c++\staffsystem\head\staff.h"
//////////���캯��/////////
workermanager::workermanager()
{
    ifstream ifs;
    char ch;
    ifs.open(filename, ios::in);
    if (!ifs.is_open())
    {
        // cout << "�ļ�������\n";
        this->m_workernum = 0;
        this->m_workerarr = NULL;
        this->fileisempty = true;
        ifs.close();
        return;
    }
    ifs >> ch;
    if (ifs.eof())
    {
        // std::cout << "�ļ�Ϊ��" << endl;
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
/////////��������////////
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
///////////��ʼ��Ա������ȡ�ļ������ɶ����ݣ�/////////
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
//////////��ʾ�˵�//////////
void workermanager::mainsys()
{
    cout << string(41, '*') << endl
         << string(8, '*') << " ��ӭʹ��ְ������ϵͳ�� " << string(9, '*') << endl
         << string(13, '*') << "1�����ְ����Ϣ" << string(13, '*') << endl
         << string(13, '*') << "2����ʾְ����Ϣ" << string(13, '*') << endl
         << string(13, '*') << "3��ɾ��ְ����Ϣ" << string(13, '*') << endl
         << string(13, '*') << "4���޸�ְ����Ϣ" << string(13, '*') << endl
         << string(13, '*') << "5������ְ����Ϣ" << string(13, '*') << endl
         << string(13, '*') << "6�����ձ������" << string(13, '*') << endl
         << string(13, '*') << "7�����ְ����Ϣ" << string(13, '*') << endl
         << string(13, '*') << "0���˳�����ϵͳ" << string(13, '*') << endl
         << string(41, '*') << endl;
}
////////���Ա��//////////
void workermanager::appe()
{
flag:
    cout << "���������Ա��������";
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
            cout << "�������" << i + 1 << "λԱ����Ϣ\n";
        scan_id:
            cout << "������Ա��id:  ";
            cin >> id;
            /////////////��ֹ����ظ�/////////
            for (int j = 0; j < m_workernum; j++)
            {
                if (m_workerarr[j]->m_id == id)
                {
                    cout << "����ظ���������������" << endl;
                    goto scan_id;
                }
            }
            for (int j = 0; j < i; j++)
            {
                if (newspace[this->m_workernum + j]->m_id == id)
                {
                    cout << "����ظ���������������" << endl;
                    goto scan_id;
                }
            }
            ////////////////////////////////////
            cout << "������Ա������:  ";
            cin >> name;
            cout << "������Ա����λ: \nְԱ��������1\n����������2\n�ϰ塪������3\n";
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
        cout << "�ɹ����" << num << "λԱ��" << endl;
        this->save();
        cout << "�ɹ�����Ա���б�" << endl;
    }
    else
    {
        cout << "������������ȷ��ֵ" << endl;
        system("pause");
        system("cls");
        goto flag;
    }
    system("pause");
    system("cls");
};
//////////////�洢Ա������///////////
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
////////////��ȡ�ļ�Ա����///////////
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
////////��ʾ����ְ��///////
void workermanager::show()
{
    if (this->fileisempty)
    {
        cout << "Ա��������" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_workernum; i++)
        {
            this->m_workerarr[i]->showinfo();
        }
    }

    cout << "�������" << endl;
    system("pause");
    system("cls");
}
///////////�ж�ְ������////////////
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
///////////ɾ��ְ��//////////
void workermanager::dele()
{

    if (fileisempty)
    {
        cout << "�ļ�Ϊ��" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "����������ɾ����Ա�����: ";
    int id;
    cin >> id;
    int index = findis(id);
    if (index == -1)
    {
        cout << "���޴���" << endl;
    }
    else
    {
        delete m_workerarr[index];
        for (int i = index; i < m_workernum; i++)
        {
            m_workerarr[i] = m_workerarr[i + 1];
        }
        cout << "ɾ������" << endl;

        m_workernum--;
        this->save();
        if (m_workernum == 0)
            fileisempty = 1;
    }

    system("pause");
    system("cls");
}
////////�޸�ְ��//////////
void workermanager::change()
{
    if (fileisempty)
    {
        cout << "�ļ�Ϊ��" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "�����������޸ĵ�Ա�����: ";
    int id;
    cin >> id;
    int index = findis(id);
    if (index == -1)
    {
        cout << "���޴���" << endl;
    }
    else
    {
        cout << "�����޸�\nid��������1\n������������2\n��λ��������3\n";
        int choo;
        cin >> choo;
        cout << "�������޸ĺ�Ľ��:  ";
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
            cout << "������Ա����λ: \nְԱ��������1\n����������2\n�ϰ塪������3\n";
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
            cout << "�޸ĳɹ�" << endl;
            save();
        }
        system("pause");
        system("cls");
    }
}
////////����ְ����Ϣ/////////
void workermanager::find()
{
    if (fileisempty)
    {
        cout << "�ļ�Ϊ��" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "����Ա����š�������1\n����Ա��������������2\n";
    int a;
    cin >> a;
    if (a == 1)
    {
        cout << "������������ҵ�Ա�����: ";
        int id;
        cin >> id;
        int index = findis(id);
        if (index == -1)
        {
            cout << "���޴���" << endl;
        }
        else
        {
            m_workerarr[index]->showinfo();
        }
    }
    else
    {
        cout << "������������ҵ�Ա������: ";
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
            cout << "���޴���" << endl;
        }
    }

    cout << "���ҽ���" << endl;
    system("pause");
    system("cls");
}
////////����////////////////
void workermanager::sort()
{
    if (fileisempty)
    {
        cout << "�ļ�Ϊ��" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "��ѡ������ʽ\n���򡪡�����1\n���򡪡�����2\n";
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
    cout << "�������,�������" << endl;
    save();
    show();
}
////////////���///////////
void workermanager::clear()
{
    cout << "��ȷ��Ҫ�����\n�ǡ�������1\n�񡪡�����2\n";
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
        cout << "�����" << endl;
    }
    else
    {
        cout << "��ȡ��" << endl;
    }
    system("pause");
    system("cls");
}
