//
// Created by 杨浩 on 2022/4/18.
//
//不同身份可能会用到不同的文件操作，所以将所有文件名定义到一个全局的文件中
//
//和当前文件目录下 globalFile文件夹中的文件对应

#ifndef RESERVATION_GLOBALFILE_H
#define RESERVATION_GLOBALFILE_H

//管理员文件
#define ADMIN_FILE "admin.txt"

//学生文件
#define STUDENT_FILE "student.txt"

//教师文件
#define TEACHER_FILE "teacher.txt"

//机房信息文件
#define ROOM_FILE "computerRoom.txt"

//订单文件
#define ORDER_FILE "order.txt"

#endif //RESERVATION_GLOBALFILE_H
