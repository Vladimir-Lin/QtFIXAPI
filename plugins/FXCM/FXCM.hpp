#ifndef FXCM_HPP
#define FXCM_HPP

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

class FxcmApplication : public FixApplication
{
  public:

    explicit FxcmApplication (void);
    virtual ~FxcmApplication (void);

  protected:

  private:

};

class FxcmThread : public FixThread
{
  Q_OBJECT
  public:

    explicit FxcmThread     (QObject * parent = 0);
    virtual ~FxcmThread     (void                );

  protected:

  private:

  public slots:

  private slots:

  signals:

};

class FxcmConnection : public FixConnection
{
  Q_OBJECT
  public:

    explicit FxcmConnection     (QObject * parent = 0);
    virtual ~FxcmConnection     (void                );

    QString name                  (void) const;

  protected:

  private:

  public slots:

  private slots:

  signals:

};

#endif // FXCM_HPP
