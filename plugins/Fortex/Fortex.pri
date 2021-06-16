INCLUDEPATH += $$PWD
DEFINES     += 

HEADERS     += $$PWD/Fortex.hpp
SOURCES     += $$PWD/Fortex.cpp

win32 {
  DEFINES += 
}

macx {
  DEFINES += 
}

unix:!macx {
  DEFINES += 
}
