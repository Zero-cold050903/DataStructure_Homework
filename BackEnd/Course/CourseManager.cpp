#include "course.h"

CourseManager::CourseManager() {
    initialLinkList(&courseList);
}

CourseManager::~CourseManager() {
    freeLinkList(courseList);
}

void CourseManager::addCourse(int id, std::string name, int credits) {
    Course course = {id, name, credits};
    insertLinkList(courseList, 1, course.id);
}

void CourseManager::deleteCourse(int id) {
    int pos = findLinkList(courseList, id);
    if (pos != -1) {
        deleteLinkList(courseList, pos + 1);
    }
}

void CourseManager::updateCourse(int id, std::string name, int credits) {
    int pos = findLinkList(courseList, id);
    if (pos != -1) {
        deleteLinkList(courseList, pos + 1);
        Course course = {id, name, credits};
        insertLinkList(courseList, pos + 1, course.id);
    }
}

Course* CourseManager::searchCourseById(int id) {
    int pos = findLinkList(courseList, id);
    if (pos != -1) {
        return &courseList[pos];
    }
    return nullptr;
}

Course* CourseManager::searchCourseByName(std::string name) {
    int_node* p = courseList->next;
    while (p != nullptr) {
        if (p->data == name) {
            return &p->data;
        }
        p = p->next;
    }
    return nullptr;
}

void CourseManager::displayAllCourses() {
    printLinkList(courseList);
}

void CourseManager::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件进行写入: " << filename << std::endl;
        return;
    }
    int_node* p = courseList->next;
    while (p != nullptr) {
        file << p->data << std::endl;
        p = p->next;
    }
    file.close();
}

void CourseManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件进行读取: " << filename << std::endl;
        return;
    }
    int id;
    while (file >> id) {
        addCourse(id, "", 0);
    }
    file.close();
}

