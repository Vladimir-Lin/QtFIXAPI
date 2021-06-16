INCLUDEPATH += $$PWD
DEFINES     += 

HEADERS     += $$PWD/FXCM.hpp
SOURCES     += $$PWD/FXCM.cpp

win32 {
  DEFINES += 
}

macx {
  DEFINES += 
}

unix:!macx {
  DEFINES += 
}
