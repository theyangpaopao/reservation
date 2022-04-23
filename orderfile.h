//
// Created by 杨浩 on 2022/4/18.
//

#ifndef RESERVATION_ORDERFILE_H
#define RESERVATION_ORDERFILE_H

#include <iostream>
using namespace std;
#include <map>
#include "globalFile.h"

class OrderFile
{
public:
    // 构造函数
    OrderFile();

    // 更新预约记录
    void updateOrder();

    // 记录的容器 key--记录的条数   value--具体记录的键值对信息
    map<int, map<string, string>> m_orderData;

    // 预约记录条数
    int m_Size;
};

#endif //RESERVATION_ORDERFILE_H
