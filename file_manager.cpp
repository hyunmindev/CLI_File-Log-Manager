//
// Created by 정현민 on 2021/05/24.
//

#include "file_manager.h"

void FileManager::Write(const std::string &log_level,
                        const std::string &file_name,
                        const std::string &function,
                        const int line,
                        const std::string &log) {
  std::ofstream fout(Moment::GetCurrentDate() + ".log", std::ios::app);
  if (fout.fail()) {
    return;
  }
  fout << log_level << " :: ";
  fout << Moment::GetCurrentTime();
  fout << "[" << file_name << "]";
  fout << "[" << function << "]";
  fout << "[" << line << "] :: ";
  fout << log << std::endl;
  fout.close();
}

void FileManager::CleanUpFile() {
  remove((Moment::GetCurrentDate(-7) + ".log").c_str());
}
