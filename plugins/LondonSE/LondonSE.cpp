#include "LondonSE.hpp"

////////////////////////////////////////////////////////////////////
LondonApplication:: LondonApplication (void)
                 :  FixApplication    (    )
{
};

LondonApplication::~LondonApplication(void)
{
};

////////////////////////////////////////////////////////////////////
LondonThread:: LondonThread (QObject * parent)
            :  FixThread       (          parent)
{
};

LondonThread::~LondonThread(void)
{
};

////////////////////////////////////////////////////////////////////
LondonConnection:: LondonConnection (QObject * parent)
                :  FixConnection    (          parent)
{
  setType(Currency);
};

LondonConnection::~LondonConnection(void)
{
};

QString LondonConnection::name(void) const
{
  return "London";
};
