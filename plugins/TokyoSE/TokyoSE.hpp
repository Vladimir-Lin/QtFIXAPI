#ifndef TOKYOSE_HPP
#define TOKYOSE_HPP

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

class TokyoApplication : public FixApplication
{
  public:

    explicit TokyoApplication (void);
    virtual ~TokyoApplication (void);

  protected:

  private:

};

class TokyoThread : public FixThread
{
  Q_OBJECT
  public:

    explicit TokyoThread     (QObject * parent = 0);
    virtual ~TokyoThread     (void                );

  protected:

  private:

  public slots:

  private slots:

  signals:

};

class TokyoConnection : public FixConnection
{
  Q_OBJECT
  public:

    explicit TokyoConnection     (QObject * parent = 0);
    virtual ~TokyoConnection     (void                );

    QString name                  (void) const;

  protected:

  private:

  public slots:

  private slots:

  signals:

};

#endif // TOKYOSE_HPP
