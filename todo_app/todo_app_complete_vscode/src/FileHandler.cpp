#include "../include/FileHandler.h"
#include <fstream>
#include <sstream>

std::map<std::string, ToDoList> FileHandler::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::map<std::string, ToDoList> lists;
    std::string line, currentDate;

    while (std::getline(file, line)) {
        if (line.find("-= Tasks") != std::string::npos) {
            size_t start = line.find("Tasks ") + 6;
            size_t end = line.find(" =-");
            currentDate = line.substr(start, end - start);
            lists[currentDate] = ToDoList(currentDate);
        } else if (!line.empty() && !currentDate.empty()) {
            size_t dotPos = line.find(". ");
            if (dotPos != std::string::npos && dotPos + 3 < line.length()) {
                char status = line[dotPos + 3];
                std::string desc = line.substr(dotPos + 6);
                bool completed = (line[dotPos + 3] == 'x');
                desc = line.substr(dotPos + 6);
                lists[currentDate].addTask(desc, completed);
            }
        }
    }

    return lists;
}

void FileHandler::writeToFile(const std::string& filename, const std::map<std::string, ToDoList>& lists) {
    std::ofstream file(filename);
    for (const auto& pair : lists) {
        file << pair.second.toString() << std::endl;
    }
}
