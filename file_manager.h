//
// Created by 정현민 on 2021/05/24.
//

#ifndef PROJECT__FILE_MANAGER_H_
#define PROJECT__FILE_MANAGER_H_

#include <fstream>

#include "log_level.h"

class FileManager {
 public:
  static void Write(const std::string &log_level,
                    const std::string &current_time,
                    const std::string &file_name,
                    const std::string &function,
                    int line,
                    const std::string &log,
                    const std::string &current_date);

 private:
  FileManager() = default;

};

#endif //PROJECT__FILE_MANAGER_H_
