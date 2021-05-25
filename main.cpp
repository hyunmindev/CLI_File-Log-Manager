#include "log_manager.h"

void LogTest() {
  OutputLog(LogLevel::ERROR, "error debug test 1")
  OutputLog(LogLevel::WARN, "warn debug test 2")
  OutputLog(LogLevel::INFO, "info debug test 3")
  OutputLog(LogLevel::DEBUG, "debug debug test 4")
  LogManager::SetOutputTargetAble(OutputTarget::COMMAND);
  LogManager::SetOutputTargetDisable(OutputTarget::FILE);
  OutputLog(LogLevel::ERROR, "error debug test 5")
  OutputLog(LogLevel::WARN, "warn debug test 6")
  OutputLog(LogLevel::INFO, "info debug test 7")
  OutputLog(LogLevel::DEBUG, "debug debug test 8")
}

int main() {
  FileManager::CleanUpFile(); // clean up old file
  OutputLog(LogLevel::ERROR, "error debug test 1")
  OutputLog(LogLevel::WARN, "warn debug test 2")
  OutputLog(LogLevel::INFO, "info debug test 3")
  OutputLog(LogLevel::DEBUG, "debug debug test 4")
  LogManager::SetOutputTargetDisable(OutputTarget::COMMAND);
  LogManager::SetLogLevelDisable(LogLevel::ERROR);
  LogManager::SetLogLevelDisable(LogLevel::WARN);
  LogManager::SetLogLevelDisable(LogLevel::INFO);
  LogManager::SetLogLevelDisable(LogLevel::DEBUG);
  OutputLog(LogLevel::ERROR, "error debug test 5")
  OutputLog(LogLevel::WARN, "warn debug test 6")
  OutputLog(LogLevel::INFO, "info debug test 7")
  OutputLog(LogLevel::DEBUG, "debug debug test 8")
  OutputLog(LogLevel::ERROR, "error debug test 9")
  OutputLog(LogLevel::WARN, "warn debug test 10")
  OutputLog(LogLevel::INFO, "info debug test 11")
  OutputLog(LogLevel::DEBUG, "debug debug test 12")
  LogManager::SetLogLevelAble(LogLevel::ERROR);
  LogManager::SetLogLevelAble(LogLevel::WARN);
  LogManager::SetLogLevelAble(LogLevel::INFO);
  LogManager::SetLogLevelAble(LogLevel::DEBUG);
  LogTest();
  return 0;
}
