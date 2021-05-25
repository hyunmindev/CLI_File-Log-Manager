//
// Created by 정현민 on 2021/05/25.
//

#include "moment.h"

std::string Moment::GetCurrentTime() {
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

std::string Moment::GetCurrentDate(int day_offset) {
  auto now = std::time(nullptr) + 86400 * day_offset;
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
