#include "FXCM.hpp"

////////////////////////////////////////////////////////////////////
FxcmApplication:: FxcmApplication (void)
               :  FixApplication  (    )
{
};

FxcmApplication::~FxcmApplication(void)
{
};

////////////////////////////////////////////////////////////////////
FxcmThread:: FxcmThread (QObject * parent)
          :  FixThread  (          parent)
{
};

FxcmThread::~FxcmThread(void)
{
};

////////////////////////////////////////////////////////////////////
FxcmConnection:: FxcmConnection (QObject * parent)
              :  FixConnection  (          parent)
{
  setType(Currency);
};

FxcmConnection::~FxcmConnection(void)
{
};

QString FxcmConnection::name(void) const
{
  return "FXCM";
};
