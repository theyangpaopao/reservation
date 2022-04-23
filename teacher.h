//
// Created by 杨浩 on 2022/4/18.
//

#ifndef RESERVATION_TEACHER_H
#define RESERVATION_TEACHER_H

#include <iostream>
#include "identity.h"

using namespace std;

class Teacher : public Identity {
public:
    //默认构造
    Teacher();

    //有参构造（工号，姓名，密码）
    Teacher(int id, string name, string password);

    //菜单界面
    virtual void operMenu();

    //查看所有预约
    void showAllOrder();

    //审核预约
    void validOrder();

    //教师编号
    int m_EmpId;



};


#endif //RESERVATION_TEACHER_H
