#include "OANDA.hpp"

////////////////////////////////////////////////////////////////////
OandaApplication:: OandaApplication (void)
                :  FixApplication   (    )
{
};

OandaApplication::~OandaApplication(void)
{
};

////////////////////////////////////////////////////////////////////
OandaThread:: OandaThread (QObject * parent)
           :  FixThread   (          parent)
{
};

OandaThread::~OandaThread(void)
{
};

////////////////////////////////////////////////////////////////////
OandaConnection:: OandaConnection (QObject * parent)
               :  FixConnection   (          parent)
{
  setType(Currency);
};

OandaConnection::~OandaConnection(void)
{
};

QString OandaConnection::name(void) const
{
  return "OANDA";
};
