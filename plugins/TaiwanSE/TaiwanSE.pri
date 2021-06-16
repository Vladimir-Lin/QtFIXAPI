INCLUDEPATH += $$PWD
DEFINES     += 

HEADERS     += $$PWD/TaiwanSE.hpp
SOURCES     += $$PWD/TaiwanSE.cpp

win32 {
  DEFINES += 
}

macx {
  DEFINES += 
}

unix:!macx {
  DEFINES += 
}
