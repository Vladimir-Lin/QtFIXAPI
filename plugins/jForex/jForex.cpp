#include "jForex.hpp"

////////////////////////////////////////////////////////////////////
jForexApplication:: jForexApplication (void)
                 :  FixApplication    (    )
{
};

jForexApplication::~jForexApplication(void)
{
};

////////////////////////////////////////////////////////////////////
jForexThread:: jForexThread (QObject * parent)
            :  FixThread    (          parent)
{
};

jForexThread::~jForexThread(void)
{
};

////////////////////////////////////////////////////////////////////
jForexConnection:: jForexConnection (QObject * parent)
                :  FixConnection    (          parent)
{
  setType(Currency);
};

jForexConnection::~jForexConnection(void)
{
};

QString jForexConnection::name(void) const
{
  return "jForex";
};
