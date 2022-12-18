#include "Log.hpp"

int main()
{
    Log log;
    log.SetLevel(Log::LevelERROR);
    log.Error("ERROR");
    log.Warn("WARNING");
    log.Info("INFO");
    log.SetLevel(Log::LevelWARNING);
    log.Error("ERROR");
    log.Warn("WARNING");
    log.Info("INFO");
    log.SetLevel(Log::LevelINFO);
    log.Error("ERROR");
    log.Warn("WARNING");
    log.Info("INFO");
}