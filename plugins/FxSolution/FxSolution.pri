INCLUDEPATH += $$PWD
DEFINES     += 

HEADERS     += $$PWD/FxSolution.hpp
SOURCES     += $$PWD/FxSolution.cpp

win32 {
  DEFINES += 
}

macx {
  DEFINES += 
}

unix:!macx {
  DEFINES += 
}
