#include <iostream>
#include "student.h"
#include "teacher.h"
#include "course.h"
#include "data.h"

void displayMenu() {
    std::cout << "====================" << std::endl;
    std::cout << "1. ѧ������" << std::endl;
    std::cout << "2. ��ʦ����" << std::endl;
    std::cout << "3. �γ̹���" << std::endl;
    std::cout << "4. �˳�" << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "��ѡ��һ��ѡ��: ";
}

void studentMenu(StudentManager& studentManager) {
    int choice;
    do {
        std::cout << "====================" << std::endl;
        std::cout << "1. ���ѧ��" << std::endl;
        std::cout << "2. ɾ��ѧ��" << std::endl;
        std::cout << "3. ����ѧ��" << std::endl;
        std::cout << "4. ����ѧ��" << std::endl;
        std::cout << "5. ��ʾ����ѧ��" << std::endl;
        std::cout << "6. �������˵�" << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << "��ѡ��һ��ѡ��: ";
        std::cin >> choice;

        int id, age;
        std::string name, major;

        switch (choice) {
            case 1:
                std::cout << "����ѧ��ID: ";
                std::cin >> id;
                std::cout << "����ѧ������: ";
                std::cin >> name;
                std::cout << "����ѧ������: ";
                std::cin >> age;
                std::cout << "����ѧ��רҵ: ";
                std::cin >> major;
                studentManager.addStudent(id, name, age, major);
                break;
            case 2:
                std::cout << "����Ҫɾ����ѧ��ID: ";
                std::cin >> id;
                studentManager.deleteStudent(id);
                break;
            case 3:
                std::cout << "����ѧ��ID: ";
                std::cin >> id;
                std::cout << "�����µ�ѧ������: ";
                std::cin >> name;
                std::cout << "�����µ�ѧ������: ";
                std::cin >> age;
                std::cout << "�����µ�ѧ��רҵ: ";
                std::cin >> major;
                studentManager.updateStudent(id, name, age, major);
                break;
            case 4:
                std::cout << "����Ҫ���ҵ�ѧ��ID: ";
                std::cin >> id;
                if (Student* student = studentManager.searchStudentById(id)) {
                    std::cout << "ID: " << student->id << ", ����: " << student->name
                              << ", ����: " << student->age << ", רҵ: " << student->major << std::endl;
                } else {
                    std::cout << "δ�ҵ�ѧ��" << std::endl;
                }
                break;
            case 5:
                studentManager.displayAllStudents();
                break;
            case 6:
                return;
            default:
                std::cout << "��Чѡ�������ѡ��" << std::endl;
        }
    } while (choice != 6);
}

void teacherMenu(TeacherManager& teacherManager) {
    int choice;
    do {
        std::cout << "====================" << std::endl;
        std::cout << "1. ��ӽ�ʦ" << std::endl;
        std::cout << "2. ɾ����ʦ" << std::endl;
        std::cout << "3. ���½�ʦ" << std::endl;
        std::cout << "4. ���ҽ�ʦ" << std::endl;
        std::cout << "5. ��ʾ���н�ʦ" << std::endl;
        std::cout << "6. �������˵�" << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << "��ѡ��һ��ѡ��: ";
        std::cin >> choice;

        int id;
        std::string name, department;

        switch (choice) {
            case 1:
                std::cout << "�����ʦID: ";
                std::cin >> id;
                std::cout << "�����ʦ����: ";
                std::cin >> name;
                std::cout << "�����ʦ����: ";
                std::cin >> department;
                teacherManager.addTeacher(id, name, department);
                break;
            case 2:
                std::cout << "����Ҫɾ���Ľ�ʦID: ";
                std::cin >> id;
                teacherManager.deleteTeacher(id);
                break;
            case 3:
                std::cout << "�����ʦID: ";
                std::cin >> id;
                std::cout << "�����µĽ�ʦ����: ";
                std::cin >> name;
                std::cout << "�����µĽ�ʦ����: ";
                std::cin >> department;
                teacherManager.updateTeacher(id, name, department);
                break;
            case 4:
                std::cout << "����Ҫ���ҵĽ�ʦID: ";
                std::cin >> id;
                if (Teacher* teacher = teacherManager.searchTeacherById(id)) {
                    std::cout << "ID: " << teacher->id << ", ����: " << teacher->name
                              << ", ����: " << teacher->department << std::endl;
                } else {
                    std::cout << "δ�ҵ���ʦ" << std::endl;
                }
                break;
            case 5:
                teacherManager.displayAllTeachers();
                break;
            case 6:
                return;
            default:
                std::cout << "��Чѡ�������ѡ��" << std::endl;
        }
    } while (choice != 6);
}

void courseMenu(CourseManager& courseManager) {
    int choice;
    do {
        std::cout << "====================" << std::endl;
        std::cout << "1. ��ӿγ�" << std::endl;
        std::cout << "2. ɾ���γ�" << std::endl;
        std::cout << "3. ���¿γ�" << std::endl;
        std::cout << "4. ���ҿγ�" << std::endl;
        std::cout << "5. ��ʾ���пγ�" << std::endl;
        std::cout << "6. �������˵�" << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << "��ѡ��һ��ѡ��: ";
        std::cin >> choice;

        int id, credits;
        std::string name;

        switch (choice) {
            case 1:
                std::cout << "����γ�ID: ";
                std::cin >> id;
                std::cout << "����γ�����: ";
                std::cin >> name;
                std::cout << "����γ�ѧ��: ";
                std::cin >> credits;
                courseManager.addCourse(id, name, credits);
                break;
            case 2:
                std::cout << "����Ҫɾ���Ŀγ�ID: ";
                std::cin >> id;
                courseManager.deleteCourse(id);
                break;
            case 3:
                std::cout << "����γ�ID: ";
                std::cin >> id;
                std::cout << "�����µĿγ�����: ";
                std::cin >> name;
                std::cout << "�����µĿγ�ѧ��: ";
                std::cin >> credits;
                courseManager.updateCourse(id, name, credits);
                break;
            case 4:
                std::cout << "����Ҫ���ҵĿγ�ID: ";
                std::cin >> id;
                if (Course* course = courseManager.searchCourseById(id)) {
                    std::cout << "ID: " << course->id << ", ����: " << course->name
                              << ", ѧ��: " << course->credits << std::endl;
                } else {
                    std::cout << "δ�ҵ��γ�" << std::endl;
                }
                break;
            case 5:
                courseManager.displayAllCourses();
                break;
            case 6:
                return;
            default:
                std::cout << "��Чѡ�������ѡ��" << std::endl;
        }
    } while (choice != 6);
}

int main() {
    StudentManager studentManager;
    TeacherManager teacherManager;
    CourseManager courseManager;

    // ��������
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