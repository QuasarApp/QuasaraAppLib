/*
 * Copyright (C) 2018-2021 QuasarApp.
 * Distributed under the lgplv3 software license, see the accompanying
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
*/

#ifndef PARAMS_H
#define PARAMS_H

#include <QMap>
#include <QVariant>
#include "quasarapp_global.h"
#include "helpdata.h"

namespace QuasarAppUtils {

/**
 * @brief The VerboseLvl enum uses for sets log level.
 */
enum VerboseLvl {
    /// Error message. This logs will marked as a **Error** and printing if the verbose lvl >= 1
    Error   = 0x0,
    /// Warning message. This logs will marked as a **Warning** and printing if the verbose lvl >= 2
    Warning = 0x1,
    /// General information. This logs will marked as a **Info** and printing always.
    Info    = 0x2,
    /// Debug message. This logs will marked as a **Debug** and printing if the verbose lvl >= 3
    Debug   = 0x3,

};

#ifdef RELEASE_BUILD
#define DEFAULT_VERBOSE_LVL "2"

#else
#define DEFAULT_VERBOSE_LVL "3"

#endif

/**
 * @brief The Params class Contains fonctions for working with input arguments and logs.
 * This Class support next comandline arguments.
 *  * **-verbose** (level 1 - 3) Shows debug log
 *  * **-fileLog** (path to file) Sets path of log file. Default it is path to executable file with suffix '.log'
 */
class QUASARAPPSHARED_EXPORT Params
{
public:
    Params() = delete;

    /**
     * @brief parseParams Parse input data of started application.
     * @param argc Count of arguments.
     * @param argv Array of arguments.
     * @return true if all arguments read successful else false.
     */
    static bool parseParams(const int argc, const char *argv[]);

    /**
     * @brief parseParams Parse input data of started application.
     * @param argc Count of arguments.
     * @param argv Array of arguments.
     * @return true if all arguments read successful else false.
     */
    static bool parseParams(int argc, char *argv[]);

    /**
     * @brief parseParams Parse input data of started application.
     * @param paramsArray Arguments.
     * @return true if all arguments read successful else false.
     */
    static bool parseParams(const QStringList& paramsArray);

    /**
     * @brief getArg return string value of a @a key if key is exits else return a @a def value.
     *  If a @a def value not defined retunr empty string.
     * @param key This is key of a console argument.
     * @param def This is Default value. If key not exits This function will return a default value.
     * @return a string value of argument.
     */
    static QString getArg(const QString& key, const QString &def = {});

    /**
     * @brief setArg sets a new value of a @a key.
     * @param key This is a name of sets option.
     * @param val This is a new value of the @a key.
     */
    static void setArg(const QString& key, const QString& val);

    /**
     * @brief setArg This method sets boolean value of key.
     * @param key This is name of the console option.
     * @param enable New value of key.
     * @note For check is enable @a key argument use the Params::isEndable method.
     */
    static void setEnable(const QString& key, bool enable);

    /**
     * @brief isEndable This method check if enable a @a key argument.
     * @param key This is name of the validate arguments
     * @return true if argument enabled.
     */
    static bool isEndable(const QString& key);

    /**
     * @brief log This method print @a log text on console.
     * @param log This is printed text message.
     * @param vLvl This is verbose level of message, for get more information see the QuasarAppUtils::VerboseLvl enum.
     * @note All messages will be printed according to the current verbose setting.
     * @note The verbose level sets by verbose option on console.
     */
    static void log(const QString& log, VerboseLvl vLvl = VerboseLvl::Debug);

    /**
     * @brief getParamsHelp This method return help object of the params class.
     * @note All Options from the Params class can be used on any application that incuded this library. So if you printing your own help do not forget print this help.
     * @return help object of default params.
     */
    static Help::Section getParamsHelp();

    /**
     * @brief getVerboseLvl This method return the verbose log level.
     * @return verbose log lvl.
     */
    static VerboseLvl getVerboseLvl();

    /**
     * @brief isDebug This method return true if the application verbose level >= VerboseLvl::Debug.
     * @return true if a verbose level >= VerboseLvl::Debug
     */
    static bool isDebug();

    /**
     * @brief isDebugBuild This method return true if the library buildet in debug mode.
     * @return true if this library buildet in debug mode.
     */
    static bool isDebugBuild();


    /**
     * @brief size This method return count of the all input arguments.
     * @return size of all params array.
     */
    static int size();

    /**
     * @brief showHelp This method shows help of the Params class of the QuasarAppLib.
     */
    static void showHelp();

    /**
     * @brief getUserParamsMap This method return const reference to the parsed arguments map.
     * @return A map object with parsed arguments.
     */
    static const QMap<QString, QString> &getUserParamsMap();

    /**
     * @brief clearParsedData This method clear all parsed data.
     */
    static void clearParsedData();

    /**
     * @brief getCurrentExecutable This method return path to the current executable.
     * @return path to current executable.
     */
    static QString getCurrentExecutable();

    /**
     * @brief getCurrentExecutableDir This method return a path to a folder with the current executable.
     * @return path of the folder with current executable.
     */
    static QString getCurrentExecutableDir();

    /**
     * @brief Traverse @a params and output its content (all the working
     *    options) to stdout in the form of option-value groups at the
     *    debug verbose level (-verbose 3).
     */
    static void printWorkingOptions();

private:
    static QString timeString();
    static std::string lvlToString(VerboseLvl vLvl);
    static bool writeLoginFile(const QString& log, VerboseLvl vLvl = VerboseLvl::Debug);




    static QMap<QString, QString> params;
    static QString appPath;
    static QString appName;

};
}

#endif // PARAMS_H
