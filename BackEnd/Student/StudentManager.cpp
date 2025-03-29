#include "student.h"

StudentManager::StudentManager() {
    initialLinkList(&studentList);
}

StudentManager::~StudentManager() {
    freeLinkList(studentList);
}

void StudentManager::addStudent(int id, std::string name, int age, std::string major) {
    Student student = {id, name, age, major};
    insertLinkList(studentList, 1, student.id);
}

void StudentManager::deleteStudent(int id) {
    int pos = findLinkList(studentList, id);
    if (pos != -1) {
        deleteLinkList(studentList, pos + 1);
    }
}

void StudentManager::updateStudent(int id, std::string name, int age, std::string major) {
    int pos = findLinkList(studentList, id);
    if (pos != -1) {
        deleteLinkList(studentList, pos + 1);
        Student student = {id, name, age, major};
        insertLinkList(studentList, pos + 1, student.id);
    }
}

Student* StudentManager::searchStudentById(int id) {
    int pos = findLinkList(studentList, id);
    if (pos != -1) {
        return &studentList[pos];
    }
    return nullptr;
}

Student* StudentManager::searchStudentByName(std::string name) {
    int_node* p = studentList->next;
    while (p != nullptr) {
        if (p->data == name) {
            return &p->data;
        }
        p = p->next;
    }
    return nullptr;
}

void StudentManager::displayAllStudents() {
    printLinkList(studentList);
}

void StudentManager::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件进行写入: " << filename << std::endl;
        return;
    }
    int_node* p = studentList->next;
    while (p != nullptr) {
        file << p->data << std::endl;
        p = p->next;
    }
    file.close();
}

void StudentManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件进行读取: " << filename << std::endl;
        return;
    }
    int id;
    while (file >> id) {
        addStudent(id, "", 0, "");
    }
    file.close();
}

