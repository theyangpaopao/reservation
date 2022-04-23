//
// Created by 杨浩 on 2022/4/18.
//
#include <iostream>
#include <string>
#include "identity.h"
#include <fstream>
#include "student.h"
#include "teacher.h"
#include "manager.h"


void StudentMenu(Identity* &student);
void ManagerMenu(Identity* &manager);
void TeacherMenu(Identity* &teacher);
//登录函数封装，根据用户的选择，进入不同的身份登录
void LoginIn(string filename, int type) {

    //用父类创建指针
    Identity *person = NULL;

    //读文件
    ifstream ifs;
    filename = "../globalFile/" + filename;
    ifs.open(filename);

    if (!ifs.is_open()) {
        cout << "文件打开失败！" << endl;
        ifs.close();
        return;
    }

    //准备接收用户信息
    int id = 0;
    string name;
    string password;
    //普通用户
    if (type == 1) {
        cout << "请输入学生的学号：";
        cin >> id;
    } else if (type == 2) {
        cout << "请输入教师的工号：";
        cin >> id;
    }

    cout << "请输入用户名：";
    cin >> name;
    cout << "请输入密码：";
    cin >> password;

    if (type == 1) {
        //学生登录
        // 学生登录验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (id == fId && name == fName && password == fPwd) {
                cout << "学生验证登录成功！" << endl;
                person = new Student(id, name, password);
                StudentMenu(person);
                return;
            }
        }


    } else if (type == 2) {
        //教师登录
        // 教师登录验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (id == fId && name == fName && password == fPwd) {
                cout << "教师验证登录成功！" << endl;
                person = new Teacher(id, name, password);
                // 进入教师子菜单
               TeacherMenu(person);

                return;
            }
        }

    } else {
        // 管理员登录验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd)
        {
            if (name == fName && password == fPwd)
            {
                cout << "验证登录成功！" << endl;
                // 登录成功后，按任意键进入管理员界面
                // 创建管理员对象
                person = new Manager(name, password);
                ManagerMenu(person);
                return;
            }
        }

    }
    cout << "验证登录失败！" << endl;
    return;
}