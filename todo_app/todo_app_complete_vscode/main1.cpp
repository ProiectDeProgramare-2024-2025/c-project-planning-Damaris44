#include "include/ToDoList.h"
#include "include/FileHandler.h"
#include "include/Color.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << RED << "Not enough arguments." << RESET << std::endl;
        system("pause");
        return 1;
    }

    std::string command = argv[1];
    std::string date = argv[2];
    auto lists = FileHandler::readFromFile("tasks.txt");

    if (command == "add_list") {
        lists[date] = ToDoList(date);
        std::cout << GREEN << "List added." << RESET << std::endl;

    } else if (command == "add_task" && argc >= 4) {
        std::string desc;
        for (int i = 3; i < argc; ++i) {
            desc += argv[i];
            if (i != argc - 1) desc += " ";
        }
        lists[date].addTask(desc);
        std::cout << GREEN << "Task added." << RESET << std::endl;

    } else if (command == "delete_task" && argc == 4) {
        int index = std::stoi(argv[3]);
        lists[date].deleteTask(index);
        std::cout << GREEN << "Task deleted." << RESET << std::endl;

    } else {
        std::cout << RED << "Invalid command." << RESET << std::endl;
        system("pause");
        return 1;
    }

    FileHandler::writeToFile("tasks.txt", lists);
    return 0;
}
