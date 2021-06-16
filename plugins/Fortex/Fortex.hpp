#ifndef FORTEX_HPP
#define FORTEX_HPP

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

class FortexApplication : public FixApplication
{
  public:

    explicit FortexApplication (void);
    virtual ~FortexApplication (void);

  protected:

  private:

};

class FortexThread : public FixThread
{
  Q_OBJECT
  public:

    explicit FortexThread     (QObject * parent = 0);
    virtual ~FortexThread     (void                );

  protected:

  private:

  public slots:

  private slots:

  signals:

};

class FortexConnection : public FixConnection
{
  Q_OBJECT
  public:

    explicit FortexConnection     (QObject * parent = 0);
    virtual ~FortexConnection     (void                );

    QString name                  (void) const;

  protected:

  private:

  public slots:

  private slots:

  signals:

};

#endif // FORTEX_HPP
