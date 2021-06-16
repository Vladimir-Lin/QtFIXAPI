#include "FxSolution.hpp"

////////////////////////////////////////////////////////////////////
FxSolutionApplication:: FxSolutionApplication (void)
                     :  FixApplication        (    )
{
};

FxSolutionApplication::~FxSolutionApplication(void)
{
};

////////////////////////////////////////////////////////////////////
FxSolutionThread:: FxSolutionThread (QObject * parent)
                :  FixThread        (          parent)
{
};

FxSolutionThread::~FxSolutionThread(void)
{
};

////////////////////////////////////////////////////////////////////
FxSolutionConnection:: FxSolutionConnection (QObject * parent)
                    :  FixConnection        (          parent)
{
  setType(Currency);
};

FxSolutionConnection::~FxSolutionConnection(void)
{
};

QString FxSolutionConnection::name(void) const
{
  return "FxSolution";
};
