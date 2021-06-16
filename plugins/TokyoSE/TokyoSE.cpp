#include "TokyoSE.hpp"

////////////////////////////////////////////////////////////////////
TokyoApplication:: TokyoApplication (void)
                :  FixApplication   (    )
{
};

TokyoApplication::~TokyoApplication(void)
{
};

////////////////////////////////////////////////////////////////////
TokyoThread:: TokyoThread (QObject * parent)
           :  FixThread   (          parent)
{
};

TokyoThread::~TokyoThread(void)
{
};

////////////////////////////////////////////////////////////////////
TokyoConnection:: TokyoConnection (QObject * parent)
               :  FixConnection   (          parent)
{
  setType(Currency);
};

TokyoConnection::~TokyoConnection(void)
{
};

QString TokyoConnection::name(void) const
{
  return "Tokyo";
};
