#pragma once
#include <string>
#include <iostream>
#include "LinkList.c"

struct Student {
    int id;
    std::string name;
    int age;
    std::string major;
};

class StudentManager {
public:
    StudentManager();
    ~StudentManager();

    void addStudent(int id, std::string name, int age, std::string major);
    void deleteStudent(int id);
    void updateStudent(int id, std::string name, int age, std::string major);
    Student* searchStudentById(int id);
    Student* searchStudentByName(std::string name);
    void displayAllStudents();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);

private:
    int_LinkList studentList;
};

