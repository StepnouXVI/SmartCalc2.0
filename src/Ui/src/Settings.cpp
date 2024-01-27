#include<Ui/Settings>

namespace Ui
{
Settings::Settings()
{
    // Constructor implementation
}

Settings::~Settings()
{
    // Destructor implementation
}

Settings::Cell &Settings::CellSetting()
{
    return _cell;
}

Settings &Settings::Instance()
{
    static Settings instance;
    return instance;
}
} // namespace Ui
