INCLUDEPATH += $$PWD
DEFINES     += 

HEADERS     += $$PWD/LondonSE.hpp
SOURCES     += $$PWD/LondonSE.cpp

win32 {
  DEFINES += 
}

macx {
  DEFINES += 
}

unix:!macx {
  DEFINES += 
}
