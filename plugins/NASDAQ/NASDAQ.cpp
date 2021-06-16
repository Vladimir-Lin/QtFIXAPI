#include "NASDAQ.hpp"

////////////////////////////////////////////////////////////////////
NasdaqApplication:: NasdaqApplication (void)
                 :  FixApplication    (    )
{
};

NasdaqApplication::~NasdaqApplication(void)
{
};

////////////////////////////////////////////////////////////////////
NasdaqThread:: NasdaqThread (QObject * parent)
            :  FixThread       (          parent)
{
};

NasdaqThread::~NasdaqThread(void)
{
};

////////////////////////////////////////////////////////////////////
NasdaqConnection:: NasdaqConnection (QObject * parent)
                :  FixConnection    (          parent)
{
  setType(Currency);
};

NasdaqConnection::~NasdaqConnection(void)
{
};

QString NasdaqConnection::name(void) const
{
  return "NASDAQ";
};
