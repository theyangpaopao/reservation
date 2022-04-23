//
// Created by 杨浩 on 2022/4/18.
//
#include <fstream>
#include "globalFile.h"
#include "manager.h"
#include "teacher.h"
#include "student.h"
#include "identity.h"
#include "computerroom.h"

//默认构造
Manager::Manager() {}

//有参构造（姓名，密码）
Manager::Manager(string name, string password) {
    this->m_Name = name;
    this->mPwd = password;
    // 调用初始化容器函数
    this->initVector();
    //初始化机房信息
    void InitComputer();
}

// 管理员菜单
void ManagerMenu(Identity* &manager)
{
    while (true)
    {
        // 管理员菜单
        manager->operMenu();

        Manager* man = (Manager*)manager;
        int select = 0;

        cin >> select;

        if (select == 1) // 添加账号
        {
            cout << "添加账号" << endl;
            man->addAccount();
        }
        else if (select == 2) // 查看账号
        {
            cout << "查看账号" << endl;
            man->checkAccount();
        }
        else if (select == 3) // 查看机房
        {
            cout << "查看机房" << endl;
            man->showRoomInfo();
        }
        else if (select == 4) // 清空预约
        {
            cout << "清空预约" << endl;
            man->clearReservation();
        }
        else
        {
            //delete manager;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}


void Manager::initVector() {
    // 确保容器清空状态
    vStu.clear();
    vTea.clear();

    // 获取学生文件中信息
    ifstream ifs;

    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件读取失败" << endl;
        return;
    }

    ComputerRoom c;
    while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
        vCom.push_back(c);
    }
    cout << "当前机房数量为：" << vCom.size() << endl;

    Student s;
    while (ifs >> s.studentId && ifs >> s.m_Name && ifs >> s.mPwd) {
        vStu.push_back(s);
    }
    cout << "当前学生数量为：" << vStu.size() << endl;
    ifs.close(); // 学生初始化

    // 读取老师文件信息
    ifs.open(TEACHER_FILE, ios::in);

    Teacher t;
    while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.mPwd) {
        vTea.push_back(t);
    }
    cout << "当前教师数量为：" << vTea.size() << endl;

    ifs.close();
}


void printStudent(Student &s) {
    cout << "学号：" << s.studentId << " 姓名：" << s.m_Name << " 密码：" << s.mPwd << endl;
}


void printTeacher(Teacher &t) {
    cout << "职工号：" << t.m_EmpId << " 姓名：" << t.m_Name << " 密码：" << t.m_EmpId << endl;
}






bool Manager::checkRepeat(int id, int type) {
    if (type == 1) {
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
            if (id == it->studentId) {
                return true;
            }
            {
                return true;
            }
            {
                return true;
            }
        }
    } else {
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
            if (id == it->m_EmpId) {
                return true;
            }
        }
    }
    return false;
}

//选择菜单
void Manager::operMenu() {
    cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
    cout << "\t\t -----------------------------------\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|             1.添加账号           |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|             2.查看账号           |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|             3.查看机房           |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|             4.清空预约           |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|             0.注销登录           |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t -----------------------------------\n";
    cout << "请选择您的操作：" << endl;
}

//查看账号
void Manager::checkAccount() {
    cout << "请选择查看内容：" << endl;
    cout << "1、查看所有学生" << endl;
    cout << "2、查看所有老师" << endl;

    int select = 0;

    cin >> select;

    if (select == 1) {
        cout << "所有学生信息如下：" << endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    } else {
        cout << "所有老师信息如下：" << endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }
}

//清空预约记录
void Manager::clearReservation() {

    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "清空成功！" << endl;
}

//查看机房信息
void Manager::showRoomInfo() {
    cout << "机房信息如下：" << endl;
    for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
        cout << "机房编号：" << it->m_ComId << " 机房最大容量：" << it->m_MaxNum << endl;
    }
}

// 管理员菜单
void managerMenu(Identity *&manager) {
    while (true) {
        // 管理员菜单
        manager->operMenu();

        Manager *man = (Manager *) manager;
        int select = 0;

        cin >> select;

        if (select == 1) // 添加账号
        {
            cout << "添加账号" << endl;
            man->addAccount();
        } else if (select == 2) // 查看账号
        {
            cout << "查看账号" << endl;
            man->checkAccount();
        } else if (select == 3) // 查看机房
        {
            cout << "查看机房" << endl;
            man->showRoomInfo();
        } else if (select == 4) // 清空预约
        {
            cout << "清空预约" << endl;
            man->clearReservation();
        } else {
            //delete manager;
            cout << "注销成功" << endl;
            return;
        }
    }
}

//添加账号
void Manager::addAccount() {
    cout << "请输入添加账号的类型" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

    string fileName;
    string tip;
    ofstream ofs;

    int select = 0;
    string errorTip; // 重复错误提示
    cin >> select;

    if (select == 1) {
        fileName = STUDENT_FILE;
        tip = "请输入学号：";
        errorTip = "学号重复，请重新输入";
    } else {
        fileName = TEACHER_FILE;
        tip = "请输入职工编号：";
        errorTip = "职工号重复，请重新输入";

    }

    ofs.open(fileName, ios::out | ios::app);
    int id;
    string name;
    string pwd;
    cout << tip << endl;

    while (true) {
        cin >> id;

        bool ret = this->checkRepeat(id, select);
        if (ret) // 有重复
        {
            cout << errorTip << endl;
        } else {
            break;
        }
    }
    cin >> id;
    cout << "请输入姓名：" << endl;
    cin >> name;

    cout << "请输入密码：" << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;

    ofs.close();
}

// 学生菜单
void studentMenu(Identity* &student)
{
    while (true)
    {
        // 学生菜单
        student->operMenu();

        Student* stu = (Student*)student;
        int select = 0;

        cin >> select;

        if (select == 1) // 申请预约
        {
            stu->applyOrder();
        }
        else if (select == 2) // 查看自身预约
        {
            stu->checkOrder();
        }
        else if (select == 3) // 查看所有预约
        {
            stu->checkAllOrder();
        }
        else if (select == 4) // 取消预约
        {
            stu->cancelOrder();
        }
        else
        {
            cout << "注销成功" << endl;
            return;
        }
    }
}

//读取机房信息
void Manager::InitComputer()
{
    vCom.clear();
    ifstream ifs;
    ifs.open(ROOM_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "机房文件无法打开！" << endl;
        return;
    }
    ComputerRoom c;
    while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
    {
        vCom.push_back(c);
    }
    ifs.close();
}



