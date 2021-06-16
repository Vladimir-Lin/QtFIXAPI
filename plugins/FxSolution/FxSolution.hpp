#ifndef FXSOLUTION_HPP
#define FXSOLUTION_HPP

#ifdef QT_CORE_LIB
#include <QtCore>
#endif

#ifdef QT_GUI_LIB
#include <QtGui>
#endif

#ifdef QT_NETWORK_LIB
#include <QtNetwork>
#endif

#ifdef QT_SQL_LIB
#include <QtSql>
#endif

#include "nFixEngine.hpp"

class FxSolutionApplication : public FixApplication
{
  public:

    explicit FxSolutionApplication (void);
    virtual ~FxSolutionApplication (void);

  protected:

  private:

};

class FxSolutionThread : public FixThread
{
  Q_OBJECT
  public:

    explicit FxSolutionThread     (QObject * parent = 0);
    virtual ~FxSolutionThread     (void                );

  protected:

  private:

  public slots:

  private slots:

  signals:

};

class FxSolutionConnection : public FixConnection
{
  Q_OBJECT
  public:

    explicit FxSolutionConnection     (QObject * parent = 0);
    virtual ~FxSolutionConnection     (void                );

    QString name                  (void) const;

  protected:

  private:

  public slots:

  private slots:

  signals:

};

#endif // FXSOLUTION_HPP
