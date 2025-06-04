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

    if (lists.find(date) == lists.end()) {
        std::cout << RED << "List not found." << RESET << std::endl;
        system("pause");
        return 1;
    }

    if (command == "mark_complete" && argc == 4) {
        int index = std::stoi(argv[3]);
        lists[date].markComplete(index);
        std::cout << GREEN << "Task marked as completed." << RESET << std::endl;

        if (lists[date].isComplete()) {
            lists.erase(date);
            std::cout << YELLOW << "All tasks completed. List deleted." << RESET << std::endl;
        }

    } else if (command == "show_list") {
        std::cout << BLUE << lists[date].toString() << RESET;

    } else if (command == "delete_list") {
        lists.erase(date);
        std::cout << GREEN << "List deleted." << RESET << std::endl;

    } else {
        std::cout << RED << "Invalid command." << RESET << std::endl;
        system("pause");
        return 1;
    }

    FileHandler::writeToFile("tasks.txt", lists);
    return 0;
}
