#
# Copyright (C) 2018-2019 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

!isEmpty(INSTALL_REFIX_PRI_INCLUDED):error("install_prefix.pri already included")
INSTALL_REFIX_PRI_INCLUDED = 1

unix:libfiletype=*.so*
win32:libfiletype=*.dll
unix:runfiletype=*
win32:runfiletype=*.exe


isEmpty(PREFIX) {
    message(install target not complited if you want added install rules use PREFIX)
} else {
    message(install target  (use install_data): $$PREFIX)

    install_data.path = $$PREFIX
#    install_data.CONFIG += no_check_exist
    INSTALLS += install_data
}








