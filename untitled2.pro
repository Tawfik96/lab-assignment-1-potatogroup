QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customer.cpp \
    main.cpp \
    home.cpp \
    product.cpp \
    registercust.cpp \
    registerseller.cpp \
    seller.cpp

HEADERS += \
    CartExceptions.h \
    Market.h \
    customer.h \
    home.h \
    product.h \
    registercust.h \
    registerseller.h \
    seller.h

FORMS += \
    customer.ui \
    home.ui \
    registercust.ui \
    registerseller.ui \
    seller.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
