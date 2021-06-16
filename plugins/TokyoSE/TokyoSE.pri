INCLUDEPATH += $$PWD
DEFINES     += 

HEADERS     += $$PWD/TokyoSE.hpp
SOURCES     += $$PWD/TokyoSE.cpp

win32 {
  DEFINES += 
}

macx {
  DEFINES += 
}

unix:!macx {
  DEFINES += 
}
