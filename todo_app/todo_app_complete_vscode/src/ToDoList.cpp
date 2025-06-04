#include "../include/ToDoList.h"
#include <sstream>

ToDoList::ToDoList(const std::string& date) : date(date) {}

void ToDoList::addTask(const std::string& description) {
    tasks.emplace_back(description, false);
}

void ToDoList::deleteTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

void ToDoList::markComplete(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].second = true;
    }
}

bool ToDoList::isComplete() const {
    for (const auto& task : tasks) {
        if (!task.second) return false;
    }
    return true;
}

std::string ToDoList::toString() const {
    std::ostringstream oss;
    oss << "-= Tasks " << date << " =-" << std::endl;
    for (int i = 0; i < tasks.size(); ++i) {
        oss << i << ". [" << (tasks[i].second ? 'x' : ' ') << "] " << tasks[i].first << std::endl;
    }
    return oss.str();
}

void ToDoList::addTask(const std::string& description, bool completed) {
    tasks.emplace_back(description, completed);
}