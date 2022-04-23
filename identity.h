//
// Created by 杨浩 on 2022/4/18.
//
//学生、教师、管理员身份父类
//
//在登录时，根据身份类型，调用不同的构造函数

#ifndef RESERVATION_IDENTITY_H
#define RESERVATION_IDENTITY_H

#include <iostream>

using namespace std;

//身份抽象类
class Identity {
public:
    //操作菜单
    virtual void operMenu() = 0;
    string m_Name;
    string mPwd;
};

#endif //RESERVATION_IDENTITY_H

