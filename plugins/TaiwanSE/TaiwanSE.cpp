#include "TaiwanSE.hpp"

////////////////////////////////////////////////////////////////////
TaiwanApplication:: TaiwanApplication (void)
                 :  FixApplication    (    )
{
};

TaiwanApplication::~TaiwanApplication(void)
{
};

////////////////////////////////////////////////////////////////////
TaiwanThread:: TaiwanThread (QObject * parent)
            :  FixThread       (          parent)
{
};

TaiwanThread::~TaiwanThread(void)
{
};

////////////////////////////////////////////////////////////////////
TaiwanConnection:: TaiwanConnection (QObject * parent)
                :  FixConnection    (          parent)
{
  setType(Currency);
};

TaiwanConnection::~TaiwanConnection(void)
{
};

QString TaiwanConnection::name(void) const
{
  return "Taiwan";
};
