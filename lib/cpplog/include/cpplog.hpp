#pragma once

#include <iostream>
#include <map>
#include <ostream>
#include <iomanip>

class CPPLog {
   public:
    enum Level { NONE, FATAL, ERROR, WARNING, INFO, DEBUG };
    
    static constexpr Level DEFAULT_MIN_LEVEL = Level::INFO;
    static constexpr std::ostream &DEFAULT_OSTREAM = std::cout;

    static const std::map<Level, std::string> LEVEL_NAMES;

    CPPLog();
	CPPLog(Level minLevel);

	CPPLog(std::ostream &ostream);
	CPPLog(Level minLevel, std::ostream &ostream);

	CPPLog(const std::map<Level, std::ostream &> ostreams);
    CPPLog(Level minLevel, const std::map<Level, std::ostream &> ostreams);

    void log(Level level, const std::string &message) const;
    void logFatal(const std::string &message) const;
    void logError(const std::string &message) const;
    void logWarning(const std::string &message) const;
    void logInfo(const std::string &message) const;
    void logDebug(const std::string &message) const;

   private:
    Level _minLevel;
    const std::map<Level, std::ostream &> _ostreams;

    std::ostream &ostream(Level level) const;

};

std::ostream &operator<<(std::ostream &ostream, CPPLog::Level level);

/* ---------------- IMPLEMENTATION ---------------- */



inline void CPPLog::log(Level level, std::string const &message) const {
    if (level > _minLevel)
        return;
    std::string const &levelName = std::string("[ ") + LEVEL_NAMES.at(level) + " ]";
    ostream(level) << std::setw(11) << std::left << levelName << " " << message << std::endl;
}

inline std::ostream &CPPLog::ostream(Level level) const {
    if (_ostreams.find(level) == _ostreams.end()) {
        return DEFAULT_OSTREAM;
    }
    return _ostreams.at(level);
}

/* ---------------- BORING STUFF ---------------- */

inline const std::map<CPPLog::Level, std::string> CPPLog::LEVEL_NAMES = {{Level::NONE, "NONE"}, {Level::FATAL, "FATAL"}, {Level::ERROR, "ERROR"}, {Level::WARNING, "WARNING"}, {Level::INFO, "INFO"}, {Level::DEBUG, "DEBUG"}};

inline CPPLog::CPPLog() : CPPLog(DEFAULT_MIN_LEVEL) {}
inline CPPLog::CPPLog(Level minLevel) : _minLevel(minLevel) {}

inline CPPLog::CPPLog(std::ostream &ostream) : CPPLog(DEFAULT_MIN_LEVEL, ostream) {}
inline CPPLog::CPPLog(Level minLevel, std::ostream &ostream) : CPPLog(minLevel, {{Level::FATAL, ostream}, {Level::ERROR, ostream}, {Level::WARNING, ostream}, {Level::INFO, ostream}, {Level::DEBUG, ostream}}) {}

inline CPPLog::CPPLog(const std::map<Level, std::ostream &> ostreams) : CPPLog(DEFAULT_MIN_LEVEL, ostreams) {}
inline CPPLog::CPPLog(Level minLevel, const std::map<Level, std::ostream &> ostreams) : _minLevel(minLevel), _ostreams(ostreams) {}

inline std::ostream &operator<<(std::ostream &ostream, CPPLog::Level level) {
    ostream << CPPLog::LEVEL_NAMES.at(level);
    return ostream;
}

inline void CPPLog::logFatal(const std::string &message) const { log(Level::FATAL, message); }
inline void CPPLog::logError(const std::string &message) const { log(Level::ERROR, message); }
inline void CPPLog::logWarning(const std::string &message) const { log(Level::WARNING, message); }
inline void CPPLog::logInfo(const std::string &message) const { log(Level::INFO, message); }
inline void CPPLog::logDebug(const std::string &message) const { log(Level::DEBUG, message); }
