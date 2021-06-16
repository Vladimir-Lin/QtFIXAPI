#include "Dukascopy.hpp"

////////////////////////////////////////////////////////////////////
DukascopyApplication:: DukascopyApplication (void)
                    :  FixApplication    (    )
{
};

DukascopyApplication::~DukascopyApplication(void)
{
};

////////////////////////////////////////////////////////////////////
DukascopyThread:: DukascopyThread (QObject * parent)
               :  FixThread       (          parent)
{
};

DukascopyThread::~DukascopyThread(void)
{
};

////////////////////////////////////////////////////////////////////
DukascopyConnection:: DukascopyConnection (QObject * parent)
                   :  FixConnection       (          parent)
{
  setType(Currency);
};

DukascopyConnection::~DukascopyConnection(void)
{
};

QString DukascopyConnection::name(void) const
{
  return "Dukascopy";
};
