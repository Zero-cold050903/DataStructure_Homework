#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
class people
{
public:
    people(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    std::string name;
    int age;
private:
    std::string name;
    int age;
};
class student: public people
{
public:
    student(std::string name, int age) : people(name, age)
    std::string ChooseCourse(const std::string& course)
private:
    std::string StudentCode;
    std::string* courses_chosen;
};
class teacher: public people
{
public:
    teacher(std::string name, int age) : people(name, age)
    std::string* courses_taught;
private:
    std::string TeacherCode;
    std::string* courses_taught;
};
