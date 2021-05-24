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

std::string LogManager::GetCurrentTime() {
  const auto now = std::chrono::system_clock::now();
  const auto
      milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
  const auto current_time_milliseconds = milliseconds.count();
  const auto current_time = (long) current_time_milliseconds / 1000;
  const auto *local_time = std::localtime(&current_time);
  std::string year = std::to_string(local_time->tm_year + 1900);
  std::string month = std::to_string(local_time->tm_mon + 1);
  if (stoi(month) < 10) {
    month = "0" + month;
  }
  std::string day = std::to_string(local_time->tm_mday);
  if (stoi(day) < 10) {
    day = "0" + day;
  }
  std::string hour = std::to_string(local_time->tm_hour);
  if (stoi(hour) < 10) {
    hour = "0" + hour;
  }
  std::string minute = std::to_string(local_time->tm_min);
  if (stoi(minute) < 10) {
    minute = "0" + minute;
  }
  std::string second = std::to_string(local_time->tm_sec);
  if (stoi(second) < 10) {
    second = "0" + second;
  }
  std::string millisecond = std::to_string(current_time_milliseconds % 1000);
  if (stoi(millisecond) < 100) {
    millisecond = "0" + millisecond;
  }
  if (stoi(millisecond) < 10) {
    millisecond = "0" + millisecond;
  }
  return year + month + day + hour + minute + second + millisecond;
}

std::string LogManager::GetCurrentDate() {
  auto now = std::time(nullptr);
  auto local_time = std::localtime(&now);
  std::string year = std::to_string(local_time->tm_year + 1900);
  std::string month = std::to_string(local_time->tm_mon + 1);
  if (stoi(month) < 10) {
    month = "0" + month;
  }
  std::string day = std::to_string(local_time->tm_mday);
  if (stoi(day) < 10) {
    day = "0" + day;
  }
  return year + month + day;
}

void LogManager::OutputToCommand(LogLevel log_level,
                                 const std::string &file_name,
                                 const std::string &function,
                                 int line,
                                 const std::string &log) {
  std::cout << "[" << LogManager::ConvertLogLevelToString(log_level) << "]::";
  std::cout << LogManager::GetCurrentTime() << "::";
  std::cout << "[" << file_name << "]";
  std::cout << "[" << function << "]";
  std::cout << "[" << line << "]";
  std::cout << "::";
  std::cout << log << std::endl;
}

void LogManager::OutputToFile(LogLevel log_level,
                              const std::string &file_name,
                              const std::string &function,
                              const int line,
                              const std::string &log) {
  FileManager::Write(LogManager::ConvertLogLevelToString(log_level),
                     LogManager::GetCurrentTime(),
                     file_name,
                     function,
                     line,
                     log,
                     LogManager::GetCurrentDate());
}
