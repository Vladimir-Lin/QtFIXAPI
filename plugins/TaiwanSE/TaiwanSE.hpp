#ifndef TAIWANSE_HPP
#define TAIWANSE_HPP

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

class TaiwanApplication : public FixApplication
{
  public:

    explicit TaiwanApplication (void);
    virtual ~TaiwanApplication (void);

  protected:

  private:

};

class TaiwanThread : public FixThread
{
  Q_OBJECT
  public:

    explicit TaiwanThread     (QObject * parent = 0);
    virtual ~TaiwanThread     (void                );

  protected:

  private:

  public slots:

  private slots:

  signals:

};

class TaiwanConnection : public FixConnection
{
  Q_OBJECT
  public:

    explicit TaiwanConnection     (QObject * parent = 0);
    virtual ~TaiwanConnection     (void                );

    QString name                  (void) const;

  protected:

  private:

  public slots:

  private slots:

  signals:

};

#endif // DUKASCOPY_HPP
