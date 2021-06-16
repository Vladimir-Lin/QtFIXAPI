INCLUDEPATH += $$PWD
DEFINES     += 

HEADERS     += $$PWD/Dukascopy.hpp
SOURCES     += $$PWD/Dukascopy.cpp

win32 {
  DEFINES += 
}

macx {
  DEFINES += 
}

unix:!macx {
  DEFINES += 
}
