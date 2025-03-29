#include "teacher.h"

TeacherManager::TeacherManager() {
    initialLinkList(&teacherList);
}

TeacherManager::~TeacherManager() {
    freeLinkList(teacherList);
}

void TeacherManager::addTeacher(int id, std::string name, std::string department) {
    Teacher teacher = {id, name, department};
    insertLinkList(teacherList, 1, teacher.id);
}

void TeacherManager::deleteTeacher(int id) {
    int pos = findLinkList(teacherList, id);
    if (pos != -1) {
        deleteLinkList(teacherList, pos + 1);
    }
}

void TeacherManager::updateTeacher(int id, std::string name, std::string department) {
    int pos = findLinkList(teacherList, id);
    if (pos != -1) {
        deleteLinkList(teacherList, pos + 1);
        Teacher teacher = {id, name, department};
        insertLinkList(teacherList, pos + 1, teacher.id);
    }
}

Teacher* TeacherManager::searchTeacherById(int id) {
    int pos = findLinkList(teacherList, id);
    if (pos != -1) {
        return &teacherList[pos];
    }
    return nullptr;
}

Teacher* TeacherManager::searchTeacherByName(std::string name) {
    int_node* p = teacherList->next;
    while (p != nullptr) {
        if (p->data == name) {
            return &p->data;
        }
        p = p->next;
    }
    return nullptr;
}

void TeacherManager::displayAllTeachers() {
    printLinkList(teacherList);
}

void TeacherManager::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件进行写入: " << filename << std::endl;
        return;
    }
    int_node* p = teacherList->next;
    while (p != nullptr) {
        file << p->data << std::endl;
        p = p->next;
    }
    file.close();
}

void TeacherManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件进行读取: " << filename << std::endl;
        return;
    }
    int id;
    while (file >> id) {
        addTeacher(id, "", "");
    }
    file.close();
}

