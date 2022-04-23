#include <iostream>
#include "globalFile.h"

using namespace std;

void LoginIn(string fileName, int type);

int main() {
    int select = 0;
    while (1) {
        cout << "============预约系统============" << endl;
        cout << endl << "请输入您的身份：" << endl;
        cout << "\t\t----------------------------\n";
        cout << "\t\t         1.学生             \n";
        cout << "\t\t         2.教师             \n";
        cout << "\t\t         3.管理员           \n";
        cout << "\t\t         3.退出             \n";
        cout << "\t\t----------------------------\n";
        cout << "请输入您的选择：";
        cin >> select;

        //根据选择实现不同的接口
        switch (select) {
            case 1:
                LoginIn(STUDENT_FILE, 1);
                break;
            case 2:
                LoginIn(TEACHER_FILE, 2);
                break;
            case 3:
                LoginIn(ADMIN_FILE, 3);
                break;
            case 0:
                cout << "您选择了退出，欢迎下次使用！" << endl;
                return 0;
            default:
                cout << "输入错误，请重新输入！" << endl;
                break;

        }
    }

    return 0;
}
