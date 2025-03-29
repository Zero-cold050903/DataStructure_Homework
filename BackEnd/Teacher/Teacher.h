#pragma once
#include <string>
#include <iostream>
#include "LinkList.c"

struct Teacher {
    int id;
    std::string name;
    std::string department;
};

class TeacherManager {
public:
    TeacherManager();
    ~TeacherManager();

    void addTeacher(int id, std::string name, std::string department);
    void deleteTeacher(int id);
    void updateTeacher(int id, std::string name, std::string department);
    Teacher* searchTeacherById(int id);
    Teacher* searchTeacherByName(std::string name);
    void displayAllTeachers();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);

private:
    int_LinkList teacherList;
};

