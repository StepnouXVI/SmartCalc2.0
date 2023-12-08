#pragma once

namespace Ui {
class Settings {
  struct Cell {
    int W = 0;
    int H = 0;
  };

 private:
  Cell _cell;

 public:
  static Settings &Instance();

  Cell &CellSetting();

 private:
  Settings();   // Private constructor to prevent instantiation
  ~Settings();  // Private destructor to prevent deletion
  Settings(const Settings &) = delete;  // Delete copy constructor
  Settings &operator=(const Settings &) =
      delete;  // Delete copy assignment operator
};
}  // namespace Ui
