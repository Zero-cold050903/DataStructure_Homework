#include <iostream>
#include "student.h"
#include "teacher.h"
#include "course.h"
#include "data.h"

void displayMenu() {
    std::cout << "====================" << std::endl;
    std::cout << "1. 学生管理" << std::endl;
    std::cout << "2. 教师管理" << std::endl;
    std::cout << "3. 课程管理" << std::endl;
    std::cout << "4. 退出" << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "请选择一个选项: ";
}

void studentMenu(StudentManager& studentManager) {
    int choice;
    do {
        std::cout << "====================" << std::endl;
        std::cout << "1. 添加学生" << std::endl;
        std::cout << "2. 删除学生" << std::endl;
        std::cout << "3. 更新学生" << std::endl;
        std::cout << "4. 查找学生" << std::endl;
        std::cout << "5. 显示所有学生" << std::endl;
        std::cout << "6. 返回主菜单" << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << "请选择一个选项: ";
        std::cin >> choice;

        int id, age;
        std::string name, major;

        switch (choice) {
            case 1:
                std::cout << "输入学生ID: ";
                std::cin >> id;
                std::cout << "输入学生姓名: ";
                std::cin >> name;
                std::cout << "输入学生年龄: ";
                std::cin >> age;
                std::cout << "输入学生专业: ";
                std::cin >> major;
                studentManager.addStudent(id, name, age, major);
                break;
            case 2:
                std::cout << "输入要删除的学生ID: ";
                std::cin >> id;
                studentManager.deleteStudent(id);
                break;
            case 3:
                std::cout << "输入学生ID: ";
                std::cin >> id;
                std::cout << "输入新的学生姓名: ";
                std::cin >> name;
                std::cout << "输入新的学生年龄: ";
                std::cin >> age;
                std::cout << "输入新的学生专业: ";
                std::cin >> major;
                studentManager.updateStudent(id, name, age, major);
                break;
            case 4:
                std::cout << "输入要查找的学生ID: ";
                std::cin >> id;
                if (Student* student = studentManager.searchStudentById(id)) {
                    std::cout << "ID: " << student->id << ", 姓名: " << student->name
                              << ", 年龄: " << student->age << ", 专业: " << student->major << std::endl;
                } else {
                    std::cout << "未找到学生" << std::endl;
                }
                break;
            case 5:
                studentManager.displayAllStudents();
                break;
            case 6:
                return;
            default:
                std::cout << "无效选项，请重新选择" << std::endl;
        }
    } while (choice != 6);
}

void teacherMenu(TeacherManager& teacherManager) {
    int choice;
    do {
        std::cout << "====================" << std::endl;
        std::cout << "1. 添加教师" << std::endl;
        std::cout << "2. 删除教师" << std::endl;
        std::cout << "3. 更新教师" << std::endl;
        std::cout << "4. 查找教师" << std::endl;
        std::cout << "5. 显示所有教师" << std::endl;
        std::cout << "6. 返回主菜单" << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << "请选择一个选项: ";
        std::cin >> choice;

        int id;
        std::string name, department;

        switch (choice) {
            case 1:
                std::cout << "输入教师ID: ";
                std::cin >> id;
                std::cout << "输入教师姓名: ";
                std::cin >> name;
                std::cout << "输入教师部门: ";
                std::cin >> department;
                teacherManager.addTeacher(id, name, department);
                break;
            case 2:
                std::cout << "输入要删除的教师ID: ";
                std::cin >> id;
                teacherManager.deleteTeacher(id);
                break;
            case 3:
                std::cout << "输入教师ID: ";
                std::cin >> id;
                std::cout << "输入新的教师姓名: ";
                std::cin >> name;
                std::cout << "输入新的教师部门: ";
                std::cin >> department;
                teacherManager.updateTeacher(id, name, department);
                break;
            case 4:
                std::cout << "输入要查找的教师ID: ";
                std::cin >> id;
                if (Teacher* teacher = teacherManager.searchTeacherById(id)) {
                    std::cout << "ID: " << teacher->id << ", 姓名: " << teacher->name
                              << ", 部门: " << teacher->department << std::endl;
                } else {
                    std::cout << "未找到教师" << std::endl;
                }
                break;
            case 5:
                teacherManager.displayAllTeachers();
                break;
            case 6:
                return;
            default:
                std::cout << "无效选项，请重新选择" << std::endl;
        }
    } while (choice != 6);
}

void courseMenu(CourseManager& courseManager) {
    int choice;
    do {
        std::cout << "====================" << std::endl;
        std::cout << "1. 添加课程" << std::endl;
        std::cout << "2. 删除课程" << std::endl;
        std::cout << "3. 更新课程" << std::endl;
        std::cout << "4. 查找课程" << std::endl;
        std::cout << "5. 显示所有课程" << std::endl;
        std::cout << "6. 返回主菜单" << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << "请选择一个选项: ";
        std::cin >> choice;

        int id, credits;
        std::string name;

        switch (choice) {
            case 1:
                std::cout << "输入课程ID: ";
                std::cin >> id;
                std::cout << "输入课程名称: ";
                std::cin >> name;
                std::cout << "输入课程学分: ";
                std::cin >> credits;
                courseManager.addCourse(id, name, credits);
                break;
            case 2:
                std::cout << "输入要删除的课程ID: ";
                std::cin >> id;
                courseManager.deleteCourse(id);
                break;
            case 3:
                std::cout << "输入课程ID: ";
                std::cin >> id;
                std::cout << "输入新的课程名称: ";
                std::cin >> name;
                std::cout << "输入新的课程学分: ";
                std::cin >> credits;
                courseManager.updateCourse(id, name, credits);
                break;
            case 4:
                std::cout << "输入要查找的课程ID: ";
                std::cin >> id;
                if (Course* course = courseManager.searchCourseById(id)) {
                    std::cout << "ID: " << course->id << ", 名称: " << course->name
                              << ", 学分: " << course->credits << std::endl;
                } else {
                    std::cout << "未找到课程" << std::endl;
                }
                break;
            case 5:
                courseManager.displayAllCourses();
                break;
            case 6:
                return;
            default:
                std::cout << "无效选项，请重新选择" << std::endl;
        }
    } while (choice != 6);
}

int main() {
    StudentManager studentManager;
    TeacherManager teacherManager;
    CourseManager courseManager;

    // 加载数据
    studentManager.loadFromFile("students.txt");
    teacherManager.loadFromFile("teachers.txt");
    courseManager.loadFromFile("courses.txt");

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                studentMenu