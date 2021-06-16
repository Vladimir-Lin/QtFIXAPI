#ifndef OANDA_HPP
#define OANDA_HPP

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

class OandaApplication : public FixApplication
{
  public:

    explicit OandaApplication (void);
    virtual ~OandaApplication (void);

  protected:

  private:

};

class OandaThread : public FixThread
{
  Q_OBJECT
  public:

    explicit OandaThread     (QObject * parent = 0);
    virtual ~OandaThread     (void                );

  protected:

  private:

  public slots:

  private slots:

  signals:

};

class OandaConnection : public FixConnection
{
  Q_OBJECT
  public:

    explicit OandaConnection     (QObject * parent = 0);
    virtual ~OandaConnection     (void                );

    QString name                  (void) const;

  protected:

  private:

  public slots:

  private slots:

  signals:

};

#endif // TOKYOSE_HPP
