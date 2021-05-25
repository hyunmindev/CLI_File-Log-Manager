//
// Created by 정현민 on 2021/05/24.
//

#include "log_manager.h"

std::map<LogLevel, bool> LogManager::is_log_level_disable_map_;
std::map<OutputTarget, bool> LogManager::is_output_target_disable_map_;

void LogManager::Output(LogLevel log_level,
                        const std::string &file_name,
                        const std::string &function,
                        int line,
                        const std::string &log) {
  if (LogManager::is_log_level_disable_map_[log_level]) {
    return;
  }
  if (!is_output_target_disable_map_[OutputTarget::COMMAND]) {
    LogManager::OutputToCommand(log_level, file_name, function, line, log);
  }
  if (!is_output_target_disable_map_[OutputTarget::FILE]) {
    LogManager::OutputToFile(log_level, file_name, function, line, log);
  }
}

void LogManager::SetLogLevelDisable(LogLevel log_level) {
  is_log_level_disable_map_[log_level] = true;
}

void LogManager::SetLogLevelAble(LogLevel log_level) {
  is_log_level_disable_map_[log_level] = false;
}

void LogManager::SetOutputTargetDisable(OutputTarget output_target) {
  is_output_target_disable_map_[output_target] = true;
}

void LogManager::SetOutputTargetAble(OutputTarget output_target) {
  is_output_target_disable_map_[output_target] = false;
}

std::string LogManager::ConvertLogLevelToString(LogLevel log_level) {
  switch (log_level) {
    case LogLevel::ERROR: return "ERROR";
    case LogLevel::WARN: return "WARN";
    case LogLevel::INFO: return "INFO";
    case LogLevel::DEBUG: return "DEBUG";
  }
}

void LogManager::OutputToCommand(LogLevel log_level,
                                 const std::string &file_name,
                                 const std::string &function,
                                 int line,
                                 const std::string &log) {
  std::cout << LogManager::ConvertLogLevelToString(log_level) << " :: ";
  std::cout << Moment::GetCurrentTime();
  std::cout << "[" << file_name << "]";
  std::cout << "[" << function << "]";
  std::cout << "[" << line << "] :: ";
  std::cout << log << std::endl;
}

void LogManager::OutputToFile(LogLevel log_level,
                              const std::string &file_name,
                              const std::string &function,
                              const int line,
                              const std::string &log) {
  FileManager::Write(LogManager::ConvertLogLevelToString(log_level),
                     file_name,
                     function,
                     line,
                     log);
}
