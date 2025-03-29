#pragma once
#include <string>
#include <iostream>
#include "LinkList.c"

struct Course {
    int id;
    std::string name;
    int credits;
};

class CourseManager {
public:
    CourseManager();
    ~CourseManager();

    void addCourse(int id, std::string name, int credits);
    void deleteCourse(int id);
    void updateCourse(int id, std::string name, int credits);
    Course* searchCourseById(int id);
    Course* searchCourseByName(std::string name);
    void displayAllCourses();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);

private:
    int_LinkList courseList;
};

