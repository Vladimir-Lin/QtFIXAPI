#include "qtfixapi.h"

QT_BEGIN_NAMESPACE

QtFixThread:: QtFixThread ( QObject * parent  )
            : QObject     (           parent  )
            , uuid        ( 0                 )
            , running     ( false             )
            , Mode        ( FIXAPI::NoEngine  )
            , Acting      ( FIXAPI::Initiator )
            , messageType ( FIXAPI::Detail    )
            , application ( NULL              )
{
}

QtFixThread::~QtFixThread(void)
{
}

void QtFixThread::LOGIN(FIXAPI::EngineMode mode)
{
  emit Login  (             ) ;
  emit Login  ( uuid , mode ) ;
}

void QtFixThread::LOGOUT(FIXAPI::EngineMode mode)
{
  emit Logout (             ) ;
  emit Logout ( uuid , mode ) ;
}

void QtFixThread::FixMessage(QString message)
{
  emit Message ( message ) ;
}

void QtFixThread::FixMessage(std::string message)
{
  if ( message . size ( ) <= 0 ) return            ;
  emit Message ( QString::fromStdString(message) ) ;
}

QT_END_NAMESPACE
