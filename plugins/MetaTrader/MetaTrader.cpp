#include "MetaTrader.hpp"

////////////////////////////////////////////////////////////////////
MetaTraderApplication:: MetaTraderApplication (void)
                     :  FixApplication        (    )
{
};

MetaTraderApplication::~MetaTraderApplication(void)
{
};

////////////////////////////////////////////////////////////////////
MetaTraderThread:: MetaTraderThread (QObject * parent)
                :  FixThread        (          parent)
{
};

MetaTraderThread::~MetaTraderThread(void)
{
};

////////////////////////////////////////////////////////////////////
MetaTraderConnection:: MetaTraderConnection (QObject * parent)
                    :  FixConnection        (          parent)
{
  setType(Currency);
};

MetaTraderConnection::~MetaTraderConnection(void)
{
};

QString MetaTraderConnection::name(void) const
{
  return "MetaTrader";
};
