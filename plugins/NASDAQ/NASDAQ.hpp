#ifndef NASDAQ_HPP
#define NASDAQ_HPP

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

class NasdaqApplication : public FixApplication
{
  public:

    explicit NasdaqApplication (void);
    virtual ~NasdaqApplication (void);

  protected:

  private:

};

class NasdaqThread : public FixThread
{
  Q_OBJECT
  public:

    explicit NasdaqThread     (QObject * parent = 0);
    virtual ~NasdaqThread     (void                );

  protected:

  private:

  public slots:

  private slots:

  signals:

};

class NasdaqConnection : public FixConnection
{
  Q_OBJECT
  public:

    explicit NasdaqConnection     (QObject * parent = 0);
    virtual ~NasdaqConnection     (void                );

    QString name                  (void) const;

  protected:

  private:

  public slots:

  private slots:

  signals:

};

#endif // NASDAQ_HPP
