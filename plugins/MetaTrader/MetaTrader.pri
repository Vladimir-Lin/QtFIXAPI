INCLUDEPATH += $$PWD
DEFINES     += 

HEADERS     += $$PWD/MetaTrader.hpp
SOURCES     += $$PWD/MetaTrader.cpp

win32 {
  DEFINES += 
}

macx {
  DEFINES += 
}

unix:!macx {
  DEFINES += 
}
