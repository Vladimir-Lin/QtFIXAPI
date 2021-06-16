INCLUDEPATH += $$PWD
DEFINES     += 

HEADERS     += $$PWD/NASDAQ.hpp
SOURCES     += $$PWD/NASDAQ.cpp

win32 {
  DEFINES += 
}

macx {
  DEFINES += 
}

unix:!macx {
  DEFINES += 
}
