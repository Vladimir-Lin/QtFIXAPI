#include "qtfixapi.h"

QT_BEGIN_NAMESPACE

QtFixSettings:: QtFixSettings ( void  )
              : name          ( ""    )
              , uuid          ( 0     )
              , ExternalId    ( false )
              , QuoteStyle    ( 0     )
{
}

QtFixSettings::~QtFixSettings(void)
{
}

QT_END_NAMESPACE
