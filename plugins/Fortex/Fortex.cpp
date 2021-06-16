#include "Fortex.hpp"

////////////////////////////////////////////////////////////////////
FortexApplication:: FortexApplication (void)
                 :  FixApplication    (    )
{
};

FortexApplication::~FortexApplication(void)
{
};

////////////////////////////////////////////////////////////////////
FortexThread:: FortexThread (QObject * parent)
            :  FixThread    (          parent)
{
};

FortexThread::~FortexThread(void)
{
};

////////////////////////////////////////////////////////////////////
FortexConnection:: FortexConnection (QObject * parent)
                :  FixConnection    (          parent)
{
  setType(Currency);
};

FortexConnection::~FortexConnection(void)
{
};

QString FortexConnection::name(void) const
{
  return "Fortex";
};
