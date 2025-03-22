// User.h
#pragma once
#include <string>
#include <vector>
#include <memory>

class User {
public:
    virtual ~User() = default;
    
    // 纯虚函数
    virtual std::string getName() const = 0;
    virtual std::string getSex() const = 0;
    virtual int getAge() const = 0;

protected:
    User(std::string name, std::string sex, int age)
        : name(name), sex(sex), age(age) {}

private:
    std::string name;
    std::string sex;
    int age;
};

class Student : public User {
public:
    enum class Permission { STUDENT };

    Student(std::string name, std::string sex, int age, 
           std::string studentId, std::string className, int grade);

    // 实现基类方法
    std::string getName() const override;
    std::string getSex() const override;
    int getAge() const override;

    // 选课/退课方法
    bool selectCourse(const std::string& course);
    bool dropCourse(const std::string& course);

    // 新增访问方法
    std::string getStudentId() const;
    std::vector<std::string> getSelectedCourses() const;
    int getCredits() const;
    std::string getClassName() const;
    int getGrade() const;
    Permission getPermission() const;

private:
    std::string studentId;
    std::vector<std::string> selectedCourses;
    int earnedCredits;
    std::string className;
    int grade;
    const Permission permission = Permission::STUDENT;
};

class Teacher : public User {
public:
    enum class Permission { TEACHER, ADMIN };

    Teacher(std::string name, std::string sex, int age,
          std::string teacherId, std::vector<std::string> teachingClasses,
          double salary, std::string hireDate, Permission permission);

    // 实现基类方法
    std::string getName() const override;
    std::string getSex() const override;
    int getAge() const override;

    // 新增访问方法
    std::string getTeacherId() const;
    std::vector<std::string> getTeachingClasses() const;
    double getSalary() const;
    std::string getHireDate() const;
    Permission getPermission() const;

    // 查看学生信息（暂留空实现）
    void viewClassStudents() {}

private:
    std::string teacherId;
    std::vector<std::string> teachingClasses;
    double salary;
    std::string hireDate;
    Permission permission;
};
	  