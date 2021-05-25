//
// Created by 정현민 on 2021/05/25.
//

#ifndef PROJECT__MOMENT_H_
#define PROJECT__MOMENT_H_

#include <string>

class Moment {
 public:
  static std::string GetCurrentTime();
  static std::string GetCurrentDate(int day_offset = 0);

 private:
  Moment() = default;
};

#endif //PROJECT__MOMENT_H_
