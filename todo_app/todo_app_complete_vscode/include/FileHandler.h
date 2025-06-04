#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "ToDoList.h"
#include <string>
#include <map>

class FileHandler {
public:
    static std::map<std::string, ToDoList> readFromFile(const std::string& filename);
    static void writeToFile(const std::string& filename, const std::map<std::string, ToDoList>& lists);
};

#endif
