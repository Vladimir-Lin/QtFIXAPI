/****************************************************************************
 *
 * Copyright (C) 2015 Neutrino International Inc.
 *
 * Author : Brian Lin <lin.foxman@gmail.com>, Skype: wolfram_lin
 *
 * QtFIXAPI acts as an interface between Qt and QuickFIX library.
 * Please keep QtFIXAPI as simple as possible.
 *
 ****************************************************************************/

#ifndef QT_FIXAPI_H
#define QT_FIXAPI_H

#include <QtCore>
#include <QtNetwork>

#include <quickfix/Application.h>
#include <quickfix/MessageCracker.h>
#include <quickfix/Values.h>
#include <quickfix/Mutex.h>

#include <quickfix/fix40/NewOrderSingle.h>
#include <quickfix/fix40/ExecutionReport.h>
#include <quickfix/fix40/OrderCancelRequest.h>
#include <quickfix/fix40/OrderCancelReject.h>
#include <quickfix/fix40/OrderCancelReplaceRequest.h>

#include <quickfix/fix41/NewOrderSingle.h>
#include <quickfix/fix41/ExecutionReport.h>
#include <quickfix/fix41/OrderCancelRequest.h>
#include <quickfix/fix41/OrderCancelReject.h>
#include <quickfix/fix41/OrderCancelReplaceRequest.h>

#include <quickfix/fix42/NewOrderSingle.h>
#include <quickfix/fix42/ExecutionReport.h>
#include <quickfix/fix42/OrderCancelRequest.h>
#include <quickfix/fix42/OrderCancelReject.h>
#include <quickfix/fix42/OrderCancelReplaceRequest.h>

#include <quickfix/fix43/NewOrderSingle.h>
#include <quickfix/fix43/ExecutionReport.h>
#include <quickfix/fix43/OrderCancelRequest.h>
#include <quickfix/fix43/OrderCancelReject.h>
#include <quickfix/fix43/OrderCancelReplaceRequest.h>
#include <quickfix/fix43/MarketDataRequest.h>

#include <quickfix/fix44/NewOrderSingle.h>
#include <quickfix/fix44/ExecutionReport.h>
#include <quickfix/fix44/OrderCancelRequest.h>
#include <quickfix/fix44/OrderCancelReject.h>
#include <quickfix/fix44/OrderCancelReplaceRequest.h>
#include <quickfix/fix44/MarketDataRequest.h>

#include <quickfix/fix50/NewOrderSingle.h>
#include <quickfix/fix50/ExecutionReport.h>
#include <quickfix/fix50/OrderCancelRequest.h>
#include <quickfix/fix50/OrderCancelReject.h>
#include <quickfix/fix50/OrderCancelReplaceRequest.h>
#include <quickfix/fix50/MarketDataRequest.h>

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#    if defined(QT_BUILD_QTFIXAPI_LIB)
#      define Q_FIXAPI_EXPORT Q_DECL_EXPORT
#    else
#      define Q_FIXAPI_EXPORT Q_DECL_IMPORT
#    endif
#else
#    define Q_FIXAPI_EXPORT
#endif

namespace FIXAPI
{

  typedef enum   {
    NoEngine     ,
    Trade        ,
    Feeding      ,
    Both         }
    EngineMode   ;

  typedef enum   {
    Initiator    ,
    Acceptor     }
    Acting       ;

  typedef enum   {
    Silence      ,
    Compact      ,
    Detail       }
    MessageType  ;

  typedef enum   {
    FixNone      ,
    FixCompact   ,
    FixDetail    ,
    FixCreate    ,
    FixLogon     ,
    FixLogout    ,
    FixToAdmin   ,
    FixFromAdmin ,
    FixToApp     ,
    FixFromApp   }
    SessionMode  ;

  typedef enum {
    HEARTBEAT                  =   0 ,
    TEST                       =   1 ,
    RESEND                     =   2 ,
    REJECT                     =   3 ,
    SEQUENCE                   =   4 ,
    LOGOUT                     =   5 ,
    IOI                        =   6 ,
    ADVERTISE                  =   7 ,
    EXECUTION                  =   8 ,
    CANCELREJECT               =   9 ,
    QUOTESTATUS                =  10 ,
    LOGON                      =  11 ,
    DERIVATIVESECURITYLIST     =  12 ,
    NEWMULTILEG                =  13 ,
    MULTILEGCANCELREPLACE      =  14 ,
    TRADECAPTUREREQUEST        =  15 ,
    TRADECAPTUREREPORT         =  16 ,
    ORDERMASSREQUEST           =  17 ,
    QUOTEREQUESTREJECT         =  18 ,
    RFQREQUEST                 =  19 ,
    QUOTESTATUSREPORT          =  20 ,
    QUOTERESPONSE              =  21 ,
    CONFIRMATION               =  22 ,
    POSITIONMAINTENANCEREQUEST =  23 ,
    POSITIONMAINTENANCEREPORT  =  24 ,
    REQUESTPOSITION            =  25 ,
    REQUESTPOSITIONACK         =  26 ,
    POSITIONREPORT             =  27 ,
    TRADEREPORTREQUESTACK      =  28 ,
    TRADEREPORTREPORTACK       =  29 ,
    ALLOCATIONREPORT           =  30 ,
    ALLOCATIONREPORTACK        =  31 ,
    CONFIRMATIONACK            =  32 ,
    SETTLEMENTREQUEST          =  33 ,
    ASSIGNMENTREPORT           =  34 ,
    COLLATERALREQUEST          =  35 ,
    COLLATERALASSIGNMENT       =  36 ,
    COLLATERALRESPONSE         =  37 ,
    NEWS                       =  38 ,
    MASSQUOTEACK               =  39 ,
    COLLATERALREPORT           =  40 ,
    COLLATERALINQUIRY          =  41 ,
    NETWORKSTATUSREQUEST       =  42 ,
    NETWORKSTATUSRESPONSE      =  43 ,
    USERREQUEST                =  44 ,
    USERRESPONSE               =  45 ,
    COLLATERALINQUIRYACK       =  46 ,
    CONFIRMATIONREQUEST        =  47 ,
    EMAIL                      =  48 ,
    SECURITYDEFINITIONREQUEST  =  49 ,
    SECURITYDEFINITION         =  50 ,
    NEWORDERSINGLE             =  51 ,
    SECURITYSTATUSREQUEST      =  52 ,
    NEWORDERLIST               =  53 ,
    ORDERCANCELREQUEST         =  54 ,
    SECURITYSTATUS             =  55 ,
    ORDERREPLACEREQUEST        =  56 ,
    TRADINGSTATUSREQUEST       =  57 ,
    ORDERSTATUSREQUEST         =  58 ,
    TRADINGSESSIONSTATUS       =  59 ,
    MASSQUOTE                  =  60 ,
    BUSINESSREJECT             =  61 ,
    ALLOCATIONINSTRUCTION      =  62 ,
    BIDREQUEST                 =  63 ,
    LISTCANCELREQUEST          =  64 ,
    BIDRESPONSE                =  65 ,
    LISTEXECUTE                =  66 ,
    LISTSTRIKEPRICE            =  67 ,
    LISTSTATUSREQUEST          =  68 ,
    XMLNONFIX                  =  69 ,
    LISTSTATUS                 =  70 ,
    REGISTRATIONINSTRUCTIONS   =  71 ,
    REGISTRATIONRESPONSE       =  72 ,
    ALLOCATIONACK              =  73 ,
    ORDERMASSCANCELREQUEST     =  74 ,
    DONTKNOWTRADE              =  75 ,
    QUOTEREQUEST               =  76 ,
    ORDERMASSCANCELREPORT      =  77 ,
    QUOTE                      =  78 ,
    NEWORDERCROSS              =  79 ,
    SETTLEMENTINSTRUNCTIONS    =  80 ,
    CROSSORDERREPLACEREQUEST   =  81 ,
    CROSSORDERCANCELREQUEST    =  82 ,
    MARKETDATAREQUEST          =  83 ,
    SECURITYTYPEREQUEST        =  84 ,
    SECURITYTYPES              =  85 ,
    MARKETDATAFULLREFRESH      =  86 ,
    SECURITYLISTREQUEST        =  87 ,
    MARKETDATAINCREMENTAL      =  88 ,
    MARKETDATAREQUESTREJECT    =  89 ,
    SECURITYLIST               =  90 ,
    QUOTECANCEL                =  91 ,
    NOTIFICATION               =  92 ,
    ACCOUNTINFO                =  93 ,
    INSTRUMENTPOSITIONINFO     =  94 ,
    ACTIVATIONREQUEST          =  95 ,
    ACTIVATIONRESPONSE         =  96 ,
    ACCOUNTINFOREQUEST         =  97 ,
    MAXCOUNT                   =  98 ,
    NONE                       =  -1 }
    TypeNumbers                      ;

}

class Q_FIXAPI_EXPORT QtFixAppConf   ;
class Q_FIXAPI_EXPORT QtFixSettings  ;
class Q_FIXAPI_EXPORT QtFIXAPI       ;
class Q_FIXAPI_EXPORT QtFixThread    ;
class Q_FIXAPI_EXPORT QtFixConnector ;

class Q_FIXAPI_EXPORT QtFixAppConf
{
  public:

    FIXAPI::EngineMode FixMode          ;
    FIXAPI::Acting     SocketMode       ;
    bool               UseLogin         ;
    bool               KeepConnection   ;

    std::string        IniFile          ;
    std::string        username         ;
    std::string        password         ;
    std::string        targetSubID      ;

    QStringList        CurrencyExchange ;

    explicit QtFixAppConf (void) ;
    virtual ~QtFixAppConf (void) ;

  protected:

  private:

};

class Q_FIXAPI_EXPORT QtFixSettings
{
  public:

    QString             name            ;
    unsigned long long  uuid            ;
    QStringList         CurrencyMonitor ;
    bool                ExternalId      ;
    int                 QuoteStyle      ;
    QList<QtFixAppConf> Settings        ;

    explicit QtFixSettings (void) ;
    virtual ~QtFixSettings (void) ;

};

class Q_FIXAPI_EXPORT QtFIXAPI : public FIX::Application
                               , public FIX::MessageCracker
{
  public:

    unsigned long long   uuid           ;

    bool                 working        ;
    bool                 useLogin       ;
    int                  isLogin        ;
    QtFixThread *        fixThread      ;

    FIXAPI::EngineMode   Mode           ;
    FIXAPI::Acting       Acting         ;
    FIXAPI::MessageType  messageType    ;

    FIX::SessionSettings settings       ;
    FIX::SessionID       DefaultSession ;

    QtFixAppConf         Conf           ;

    explicit            QtFIXAPI      (void) ;
    virtual            ~QtFIXAPI      (void) ;

    virtual void        run            (void);

  protected:

    void                Message        (std::string & message ) ;
    QDateTime           stdToDateTime  (std::string   datetime) ;
    FIXAPI::SessionMode DispatchType   (void) ;
    virtual int         MessageId      (std::string msg) ;
    std::string         TypeName       (int TypeId) ;
    bool                sendMessage    (FIX::Message & message) ;

    virtual void        Dispatch       (FIX::Message         & message ,
                                        const FIX::SessionID & session ,
                                        FIXAPI::SessionMode    mode  ) ;

    virtual void        showMessage    (FIX::Message      & message   ,
                                        FIXAPI::MessageType msgType ) ;

    virtual void        doCreate       (void) ;
    virtual void        doLogon        (void) ;
    virtual void        doLogout       (void) ;

    virtual void        WaitLogin      (void) ;
    virtual void        LoginStuffs    (void) ;
    virtual void        doLoop         (void) ;
    virtual void        LogoutStuffs   (void) ;

  private:

    virtual void        onCreate       (const FIX::SessionID &) ;
    virtual void        onLogon        (const FIX::SessionID & sessionID) ;
    virtual void        onLogout       (const FIX::SessionID & sessionID) ;
    virtual void        toAdmin        (FIX::Message         &         ,
                                        const FIX::SessionID &       ) ;
    virtual void        toApp          (FIX::Message         &         ,
                                        const FIX::SessionID &         )
                        throw          (FIX::DoNotSend               ) ;
    virtual void        fromAdmin      (const FIX::Message   &         ,
                                        const FIX::SessionID &         )
                        throw          (FIX::FieldNotFound             ,
                                        FIX::IncorrectDataFormat       ,
                                        FIX::IncorrectTagValue         ,
                                        FIX::RejectLogon             ) ;
    virtual void        fromApp        (const FIX::Message   & message ,
                                        const FIX::SessionID & session )
                        throw          (FIX::FieldNotFound             ,
                                        FIX::IncorrectDataFormat       ,
                                        FIX::IncorrectTagValue         ,
                                        FIX::UnsupportedMessageType  ) ;

};

class Q_FIXAPI_EXPORT QtFixThread : public QObject
{
  Q_OBJECT
  public:

    unsigned long long  uuid        ;
    bool                running     ;
    FIXAPI::EngineMode  Mode        ;
    FIXAPI::Acting      Acting      ;
    FIXAPI::MessageType messageType ;

    explicit     QtFixThread (QObject * parent = 0) ;
    virtual     ~QtFixThread (void                ) ;

    virtual void LOGIN       (FIXAPI::EngineMode mode) ;
    virtual void LOGOUT      (FIXAPI::EngineMode mode) ;

  protected:

    QtFIXAPI * application ;

    virtual void Run         (void) = 0 ;

  private:

  public slots:

    virtual void FixMessage  (QString     message) ;
    virtual void FixMessage  (std::string message) ;

    virtual void Install     (QtFixAppConf & Conf) = 0 ;
    virtual void Start       (void) = 0 ;
    virtual void Stop        (void) = 0 ;

  private slots:

  signals:

    void Message             (QString message);
    void Login               (void);
    void Logout              (void);
    void Login               (unsigned long long uuid,FIXAPI::EngineMode mode) ;
    void Logout              (unsigned long long uuid,FIXAPI::EngineMode mode) ;

};

class QtFixConnector : public QObject
{
  Q_OBJECT
  Q_ENUMS(TradeType)
  Q_PROPERTY(TradeType Type READ type WRITE setType)
  public:

    typedef enum {
      None       ,
      Stock      ,
      Currency   }
      TradeType  ;

    unsigned long long  uuid        ;
    FIXAPI::MessageType messageType ;

    explicit QtFixConnector (QObject * parent = 0) ;
    virtual ~QtFixConnector (void                ) ;

    QtFixThread * Trade     (void) ;
    QtFixThread * Feeding   (void) ;

    TradeType type          (void) ;

    virtual QString name    (void) const = 0 ;

  protected:

    TradeType     Type    ;
    QtFixThread * feeding ;
    QtFixThread * trade   ;

  private:

  public slots:

    virtual void Initialize (void) = 0 ;
    virtual void Install    (QtFixSettings & engine) = 0 ;
    virtual void Start      (void) = 0 ;
    virtual void Stop       (void) = 0 ;

    void setType            (TradeType type) ;
    void setMessageType     (FIXAPI::MessageType messageType) ;

  private slots:

  signals:

    void Finished          (void) ;

};

Q_DECLARE_INTERFACE(QtFixThread    , "com.neutrino.forex.fixapi.thread"   )
Q_DECLARE_INTERFACE(QtFixConnector , "com.neutrino.forex.fixapi.connector")

QT_END_NAMESPACE

#endif
