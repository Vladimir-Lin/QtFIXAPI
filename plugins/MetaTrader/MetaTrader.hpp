#ifndef METATRADER_HPP
#define METATRADER_HPP

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

class MetaTraderApplication : public FixApplication
{
  public:

    explicit MetaTraderApplication (void);
    virtual ~MetaTraderApplication (void);

  protected:

  private:

};

class MetaTraderThread : public FixThread
{
  Q_OBJECT
  public:

    explicit MetaTraderThread     (QObject * parent = 0);
    virtual ~MetaTraderThread     (void                );

  protected:

  private:

  public slots:

  private slots:

  signals:

};

class MetaTraderConnection : public FixConnection
{
  Q_OBJECT
  public:

    explicit MetaTraderConnection (QObject * parent = 0);
    virtual ~MetaTraderConnection (void                );

    QString name                  (void) const;

  protected:

  private:

  public slots:

  private slots:

  signals:

};

#endif // METATRADER_HPP
