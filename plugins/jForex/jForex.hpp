#ifndef JFOREX_HPP
#define JFOREX_HPP

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

class jForexApplication : public FixApplication
{
  public:

    explicit jForexApplication (void);
    virtual ~jForexApplication (void);

  protected:

  private:

};

class jForexThread : public FixThread
{
  Q_OBJECT
  public:

    explicit jForexThread     (QObject * parent = 0);
    virtual ~jForexThread     (void                );

  protected:

  private:

  public slots:

  private slots:

  signals:

};

class jForexConnection : public FixConnection
{
  Q_OBJECT
  public:

    explicit jForexConnection     (QObject * parent = 0);
    virtual ~jForexConnection     (void                );

    QString name                  (void) const;

  protected:

  private:

  public slots:

  private slots:

  signals:

};

#endif // TOKYOSE_HPP
