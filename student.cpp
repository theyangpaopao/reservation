//
// Created by 杨浩 on 2022/4/18.
//

#include "student.h"
#include <fstream>
#include "globalFile.h"
#include "orderfile.h"

#include "computerroom.h"
//默认构造
Student::Student() {

}

//有参构造
Student::Student(int id, string name, string pwd) {

    this->studentId = id;
    this->m_Name = name;
    this->mPwd = pwd;

    this->InitComputer();
}


void Student::InitComputer() {
    vCom.clear();
    ifstream ifs;
    ifs.open(ROOM_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "机房文件无法打开！" << endl;
        return;
    }
    ComputerRoom c;
    while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
        vCom.push_back(c);
    }
    ifs.close();
}

// 学生菜单
void StudentMenu(Identity *&student) {
    while (true) {
        // 学生菜单
        student->operMenu();

        Student *stu = (Student *) student;
        int select = 0;

        cin >> select;

        if (select == 1) // 申请预约
        {
            stu->applyOrder();
        } else if (select == 2) // 查看自身预约
        {
            stu->checkOrder();
        } else if (select == 3) // 查看所有预约
        {
            stu->checkAllOrder();
        } else if (select == 4) // 取消预约
        {
            stu->cancelOrder();
        } else {
            //delete student;
            cout << "注销成功" << endl;

            return;
        }
    }
}

//菜单界面
void Student::operMenu() {
    cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.申请预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.查看我的预约          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.查看所有预约          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4.取消预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作：" << endl;
}


//申请预约
void Student::applyOrder() {
    cout << "机房开放时间为周一至周五！" << endl;
    cout << "请输入申请预约的时间：" << endl;
    cout << "1、周一" << endl;
    cout << "2、周二" << endl;
    cout << "3、周三" << endl;
    cout << "4、周四" << endl;
    cout << "5、周五" << endl;
    int date = 0;
    int interval = 0;
    int room = 0;

    while (true) {
        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "请输入申请预约的时间段：" << endl;
    cout << "1、上午" << endl;
    cout << "2、下午" << endl;

    while (true) {
        cin >> interval;
        if (interval >= 1 && interval <= 2) {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "请选择机房：" << endl;
    cout << "1号机房容量：" << vCom[0].m_MaxNum << endl;
    cout << "2号机房容量：" << vCom[1].m_MaxNum << endl;
    cout << "3号机房容量：" << vCom[2].m_MaxNum << endl;

    while (true) {
        cin >> room;
        if (room >= 1 && room <= 3) {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "预约成功！审核中" << endl;

    ofstream ofs(ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->studentId << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;

    ofs.close();

    system("pause");
    system("cls");
}


//查看预约
void Student::checkOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < of.m_Size; i++) {
        // string 转 int
        // string 利用 .c_str() 转 const char*
        // 利用 atoi(const char*) 转 int
        if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->studentId) {
            cout << "预约日期： 周" << of.m_orderData[i]["date"];
            cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
            cout << " 机房：" << of.m_orderData[i]["roomId"];
            string status = " 状态："; // 0 取消的预约  1 审核中   2 已预约  -1 预约失败
            if (of.m_orderData[i]["status"] == "1") {
                status += "审核中";
            } else if (of.m_orderData[i]["status"] == "2") {
                status += "预约成功";
            } else if (of.m_orderData[i]["status"] == "-1") {
                status += "预约失败";
            } else {
                status += "预约已取消";
            }
            cout << status << endl;
        }
    }
}

//查看所有预约
void Student::checkAllOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }

    for (int i = 0; i < of.m_Size; i++) {
        cout << i + 1 << "、 ";

        cout << "预约日期：周" << of.m_orderData[i]["date"];
        cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
        cout << " 学号：" << of.m_orderData[i]["stuId"];
        cout << " 姓名：" << of.m_orderData[i]["stuName"];
        cout << " 机房：" << of.m_orderData[i]["roomId"];
        string status = " 状态："; // 0 取消的预约  1 审核中  2 已预约  -1 预约失败
        if (of.m_orderData[i]["status"] == "1") {
            status += "审核中";
        } else if (of.m_orderData[i]["status"] == "2") {
            status += "预约成功";
        } else if (of.m_orderData[i]["status"] == "-1") {
            status += "审核未通过，预约失败";
        } else {
            status += "预约已取消";
        }
        cout << status << endl;
    }
}

//取消预约
void Student::cancelOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "申请中或预约成功的记录可以取消，请输入取消的记录" << endl;

    vector<int> v;
    int index = 1;
    for (int i = 0; i < of.m_Size; i++) {
        if (atoi(of.m_orderData[i]["studentId"].c_str()) == this->studentId) {
            if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
                v.push_back(i);
                cout << index++ << "、 ";
                cout << "预约日期：周" << of.m_orderData[i]["date"];
                cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
                cout << " 机房：" << of.m_orderData[i]["roomId"];
                string status = " 状态：";
                if (of.m_orderData[i]["status"] == "1") {
                    status += "审核中";
                } else if (of.m_orderData[i]["status"] == "2") {
                    status += "预约成功";
                }
                cout << status << endl;
            }
        }
    }

    cout << "请输入取消的记录，0代表返回" << endl;
    int select = 0;
    while (true) {
        cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                break;
            } else {
                of.m_orderData[v[select - 1]]["status"] = "0";
                of.updateOrder();
                cout << "已取消预约" << endl;
                break;
            }
        }
        cout << "输入有误，请重新输入" << endl;
    }
}