INCLUDEPATH += $$PWD
DEFINES     += 

HEADERS     += $$PWD/OANDA.hpp
SOURCES     += $$PWD/OANDA.cpp

win32 {
  DEFINES += 
}

macx {
  DEFINES += 
}

unix:!macx {
  DEFINES += 
}
