#include <iostream>
class Log
{
  public:
    enum Level
    {
        LevelERROR = 0,
        LevelWARNING,
        LevelINFO
    };

  public:
    Level m_LogLevel = LevelINFO;

  public:
    void SetLevel(Level level)
    {
        m_LogLevel = level;
    };
    void Error(const char *message)
    {
        if (m_LogLevel >= LevelERROR)
            std::cout << "[ERROR]: " << message << std::endl;
    };
    void Warn(const char *message)
    {
        if (m_LogLevel >= LevelWARNING)
            std::cout << "[WARNING]: " << message << std::endl;
    };
    void Info(const char *message)
    {
        if (m_LogLevel >= LevelINFO)
            std::cout << "[INFO]: " << message << std::endl;
    };
};