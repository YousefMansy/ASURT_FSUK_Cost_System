#!/bin/sh
QT_VERSION=0.3.0
export QT_VERSION
QT_VER=0.3
export QT_VER
QT_VERSION_TAG=030
export QT_VERSION_TAG
QT_INSTALL_DOCS=/usr/share/doc/qt5
export QT_INSTALL_DOCS
exec /usr/lib64/qt5/bin/qdoc "$@"
