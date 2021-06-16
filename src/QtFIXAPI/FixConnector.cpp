#include "qtfixapi.h"

QT_BEGIN_NAMESPACE

QtFixConnector:: QtFixConnector ( QObject * parent )
               : QObject        (           parent )
               , uuid           ( 0                )
               , messageType    ( FIXAPI::Detail   )
               , Type           ( None             )
               , feeding        ( NULL             )
               , trade          ( NULL             )
{
}

QtFixConnector::~QtFixConnector(void)
{
}

QtFixThread * QtFixConnector::Trade(void)
{
  return trade ;
}

QtFixThread * QtFixConnector::Feeding(void)
{
  return feeding ;
}

QtFixConnector::TradeType QtFixConnector::type(void)
{
  return Type ;
}

void QtFixConnector::setType(TradeType type)
{
  Type = type ;
}

void QtFixConnector::setMessageType(FIXAPI::MessageType msgType)
{
  messageType = msgType ;
}

QT_END_NAMESPACE
