#include "qtfixapi.h"

QT_BEGIN_NAMESPACE

QtFixAppConf:: QtFixAppConf   ( void              )
             : FixMode        ( FIXAPI::Both      )
             , SocketMode     ( FIXAPI::Initiator )
             , UseLogin       ( true              )
             , KeepConnection ( true              )
             , IniFile        ( ""                )
             , username       ( ""                )
             , password       ( ""                )
             , targetSubID    ( ""                )
{
}

QtFixAppConf::~QtFixAppConf(void)
{
}

QT_END_NAMESPACE
