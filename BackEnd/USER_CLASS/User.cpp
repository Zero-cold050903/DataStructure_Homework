// TS_Operating_System.cpp
#include "User.h"
#include <algorithm>

// Student类实现 ======================================
Student::Student(std::string name, std::string sex, int age,
               std::string studentId, std::string className, int grade)
    : User(name, sex, age),
      studentId(studentId),
      className(className),
      grade(grade),
      earnedCredits(0) {}

// 基类方法实现
std::string Student::getName() const { return name; }
std::string Student::getSex() const { return sex; }
int Student::getAge() const { return age; }

// 选课逻辑（简化版）
bool Student::selectCourse(const std::string& course) {
    if (course.empty()) return false;
    
    // 检查是否已选
    auto it = std::find(selectedCourses.begin(), 
                       selectedCourses.end(), course);
    if (it != selectedCourses.end()) return false;

    // 假设每门课程3学分（实际应根据课程信息设置）
    selectedCourses.push_back(course);
    earnedCredits += 3;
    return true;
}

bool Student::dropCourse(const std::string& course) {
    auto it = std::find(selectedCourses.begin(),
                       selectedCourses.end(), course);
    if (it == selectedCourses.end()) return false;

    selectedCourses.erase(it);
    earnedCredits -= 3; // 实际应根据课程实际学分调整
    return true;
}

// 访问方法
std::string Student::getStudentId() const { return studentId; }
std::vector<std::string> Student::getSelectedCourses() const {
    return selectedCourses; 
}
int Student::getCredits() const { return earnedCredits; }
std::string Student::getClassName() const { return className; }
int Student::getGrade() const { return grade; }
Student::Permission Student::getPermission() const { return permission; }

// Teacher类实现 ======================================
Teacher::Teacher(std::string name, std::string sex, int age,
               std::string teacherId, 
               std::vector<std::string> teachingClasses,
               double salary, std::string hireDate, 
               Permission permission)
    : User(name, sex, age),
      teacherId(teacherId),
      teachingClasses(teachingClasses),
      salary(salary),
      hireDate(hireDate),
      permission(permission) {}

// 基类方法实现
std::string Teacher::getName() const { return name; }
std::string Teacher::getSex() const { return sex; }
int Teacher::getAge() const { return age; }

// 访问方法
std::string Teacher::getTeacherId() const { return teacherId; }
std::vector<std::string> Teacher::getTeachingClasses() const {
    return teachingClasses;
}
double Teacher::getSalary() const { return salary; }
std::string Teacher::getHireDate() const { return hireDate; }
Teacher::Permission Teacher::getPermission() const { return permission; }

// 原people类已废弃，建议删除