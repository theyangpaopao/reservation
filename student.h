//
// Created by 杨浩 on 2022/4/18.
//

#ifndef RESERVATION_STUDENT_H
#define RESERVATION_STUDENT_H

#include <iostream>
#include <vector>
#include "identity.h"
#include "computerroom.h"

void StudentMenu(Identity*& manager);

//学生类作为派生类，继承父类identity
class Student : public Identity {
public:
    //默认构造
    Student();

    //有参构造
    Student(int id, string name, string pwd);

    //菜单界面
    virtual void operMenu();

    //申请预约
    void applyOrder();

    //查看预约情况
    void checkOrder();

    //查看所有预约
    void checkAllOrder();

    //取消预约
    void cancelOrder();

    //创建机房信息容器
    vector<ComputerRoom> vCom;

    //初始化机房信息

    void InitComputer();

    //学生学号
    int studentId;


};


#endif //RESERVATION_STUDENT_H
