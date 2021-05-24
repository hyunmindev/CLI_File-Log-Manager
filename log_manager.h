//
// Created by 정현민 on 2021/05/24.
//

#ifndef PROJECT__LOG_MANAGER_H_
#define PROJECT__LOG_MANAGER_H_

#include <iostream>
#include <chrono>
#include <ctime>
#include <map>

#include "file_manager.h"
#include "log_level.h"
#include "output_target.h"

#define OutputLog(log_level, log) \
  LogManager::Output(log_level, __FILE_NAME__, __FUNCTION__, __LINE__, log);

class LogManager {
 public:
  static void Output(LogLevel log_level,
                     const std::string &file_name,
                     const std::string &function,
                     int line,
                     const std::string &log);
  static void SetLogLevelDisable(LogLevel log_level);
  static void SetLogLevelAble(LogLevel log_level);
  static void SetOutputTargetDisable(OutputTarget output_target);
  static void SetOutputTargetAble(OutputTarget output_target);

 public:
  static std::map<LogLevel, bool> is_log_level_disable_map_;
  static std::map<OutputTarget, bool> is_output_target_disable_map_;

 private:
  LogManager() = default;
  static std::string ConvertLogLevelToString(LogLevel log_level);
  static std::string GetCurrentTime();
  static std::string GetCurrentDate();
  static void OutputToCommand(LogLevel log_level,
                              const std::string &file_name,
                              const std::string &function,
                              int line,
                              const std::string &log);
  static void OutputToFile(LogLevel log_level,
                           const std::string &file_name,
                           const std::string &function,
                           int line,
                           const std::string &log);
};

#endif //PROJECT__LOG_MANAGER_H_
