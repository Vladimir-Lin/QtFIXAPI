#ifndef LONDONSE_HPP
#define LONDONSE_HPP

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

class LondonApplication : public FixApplication
{
  public:

    explicit LondonApplication (void);
    virtual ~LondonApplication (void);

  protected:

  private:

};

class LondonThread : public FixThread
{
  Q_OBJECT
  public:

    explicit LondonThread     (QObject * parent = 0);
    virtual ~LondonThread     (void                );

  protected:

  private:

  public slots:

  private slots:

  signals:

};

class LondonConnection : public FixConnection
{
  Q_OBJECT
  public:

    explicit LondonConnection     (QObject * parent = 0);
    virtual ~LondonConnection     (void                );

    QString name                  (void) const;

  protected:

  private:

  public slots:

  private slots:

  signals:

};

#endif // LONDONSE_HPP
