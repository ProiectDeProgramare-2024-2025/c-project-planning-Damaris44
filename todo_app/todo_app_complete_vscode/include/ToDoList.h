#ifndef TODOLIST_H
#define TODOLIST_H

#include <string>
#include <vector>

class ToDoList {
private:
    std::string date;
    std::vector<std::pair<std::string, bool>> tasks;

public:
    ToDoList() = default;
    ToDoList(const std::string& date);
    void addTask(const std::string& description);
    void addTask(const std::string& description, bool completed);
    void deleteTask(int index);
    void markComplete(int index);
    bool isComplete() const;
    std::string toString() const;
};

#endif
