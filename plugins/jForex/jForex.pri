INCLUDEPATH += $$PWD
DEFINES     += 

HEADERS     += $$PWD/jForex.hpp
SOURCES     += $$PWD/jForex.cpp

win32 {
  DEFINES += 
}

macx {
  DEFINES += 
}

unix:!macx {
  DEFINES += 
}
