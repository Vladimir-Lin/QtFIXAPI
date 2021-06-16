#ifndef DUKASCOPY_HPP
#define DUKASCOPY_HPP

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

class DukascopyApplication : public FixApplication
{
  public:

    explicit DukascopyApplication (void);
    virtual ~DukascopyApplication (void);

  protected:

  private:

};

class DukascopyThread : public FixThread
{
  Q_OBJECT
  public:

    explicit DukascopyThread     (QObject * parent = 0);
    virtual ~DukascopyThread     (void                );

  protected:

  private:

  public slots:

  private slots:

  signals:

};

class DukascopyConnection : public FixConnection
{
  Q_OBJECT
  public:

    explicit DukascopyConnection     (QObject * parent = 0);
    virtual ~DukascopyConnection     (void                );

    QString name                  (void) const;

  protected:

  private:

  public slots:

  private slots:

  signals:

};

#endif // DUKASCOPY_HPP
