//
// Created by 정현민 on 2021/05/24.
//

#include "file_manager.h"

void FileManager::Write(const std::string &log_level,
                        const std::string &current_time,
                        const std::string &file_name,
                        const std::string &function,
                        const int line,
                        const std::string &log,
                        const std::string &current_date) {
  std::ofstream fout(current_date + ".log", std::ios::app);
  if (fout.fail()) {
    return;
  }

  fout << "[" << log_level << "]::";
  fout << current_time << "::";
  fout << "[" << file_name << "]";
  fout << "[" << function << "]";
  fout << "[" << line << "]";
  fout << "::";
  fout << log << std::endl;
  fout.close();
}
