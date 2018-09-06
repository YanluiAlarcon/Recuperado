TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Descargas/NTL/lib/release/ -lntl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Descargas/NTL/lib/debug/ -lntl
else:unix: LIBS += -L$$PWD/../../../Descargas/NTL/lib/ -lntl

INCLUDEPATH += $$PWD/../../../Descargas/NTL/include
DEPENDPATH += $$PWD/../../../Descargas/NTL/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/release/libntl.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/debug/libntl.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/release/ntl.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/debug/ntl.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/libntl.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Descargas/NTL/lib/release/ -lgmp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Descargas/NTL/lib/debug/ -lgmp
else:unix: LIBS += -L$$PWD/../../../Descargas/NTL/lib/ -lgmp

INCLUDEPATH += $$PWD/../../../Descargas/NTL/include
DEPENDPATH += $$PWD/../../../Descargas/NTL/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/release/libgmp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/debug/libgmp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/release/gmp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/debug/gmp.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/libgmp.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Descargas/NTL/lib/release/ -lgmpxx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Descargas/NTL/lib/debug/ -lgmpxx
else:unix: LIBS += -L$$PWD/../../../Descargas/NTL/lib/ -lgmpxx

INCLUDEPATH += $$PWD/../../../Descargas/NTL/include
DEPENDPATH += $$PWD/../../../Descargas/NTL/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/release/libgmpxx.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/debug/libgmpxx.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/release/gmpxx.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/debug/gmpxx.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../Descargas/NTL/lib/libgmpxx.a

unix|win32: LIBS += -lntl
