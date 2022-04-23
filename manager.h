//
// Created by 杨浩 on 2022/4/18.
//

#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include <iostream>
#include <vector>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computerroom.h"

using namespace std;


class Manager : public Identity {

public:
    //默认构造
    Manager();

    //有参构造（姓名，密码）
    Manager(string name, string password);

    //选择菜单
    virtual void operMenu();


    // 初始化容器
    void initVector();

    //读取机房信息
    void InitComputer();

    //添加账号
    void addAccount();

    //查看账号
    void checkAccount();

    //清空预约记录
    void clearReservation();

    //查看机房信息
    void showRoomInfo();

    // 检测重复  参数：（传入id, 传入类型）  返回值：（true 代表有重复, false 代表没有重复）
    bool checkRepeat(int id, int type);

//学生容器
    vector<Student> vStu;

    //老师容器
    vector<Teacher> vTea;

    //机房容器
    vector<ComputerRoom> vCom;
};


#endif //RESERVATION_MANAGER_H
