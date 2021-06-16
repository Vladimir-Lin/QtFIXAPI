#include "qtfixapi.h"

#define IsNull(item)      (NULL==(item))
#define NotNull(item)     (NULL!=(item))
#define NotEqual(a,b)     ((a)!=(b))
#define IsMask(a,b)       (((a) & (b))==(b))
#define nEqual(VAR,CONST) ((CONST)==(VAR))
#define nGreater(A,B)     ((A)>(B))
#define nLess(A,B)        ((A)<(B))

QT_BEGIN_NAMESPACE

struct FixTypeCast                  {
  const FIXAPI::TypeNumbers fixType ;
  const char *              msgType ;
  const char *              msgName ;
}                                   ;

static FixTypeCast FIXTYPES [ ] =                                                               {
  { FIXAPI::HEARTBEAT                  ,  "0" , "Heartbeat"                                   } ,
  { FIXAPI::TEST                       ,  "1" , "Test Request"                                } ,
  { FIXAPI::RESEND                     ,  "2" , "Resend Request"                              } ,
  { FIXAPI::REJECT                     ,  "3" , "Reject"                                      } ,
  { FIXAPI::SEQUENCE                   ,  "4" , "Sequence Reset"                              } ,
  { FIXAPI::LOGOUT                     ,  "5" , "Logout"                                      } ,
  { FIXAPI::IOI                        ,  "6" , "IOI"                                         } ,
  { FIXAPI::ADVERTISE                  ,  "7" , "Advertisement"                               } ,
  { FIXAPI::EXECUTION                  ,  "8" , "Execution Report"                            } ,
  { FIXAPI::CANCELREJECT               ,  "9" , "Order Cancel Reject"                         } ,
  { FIXAPI::QUOTESTATUS                ,  "a" , "Quote Status Request"                        } ,
  { FIXAPI::LOGON                      ,  "A" , "Logon"                                       } ,
  { FIXAPI::DERIVATIVESECURITYLIST     , "AA" , "Derivative Security List"                    } ,
  { FIXAPI::NEWMULTILEG                , "AB" , "New Order Multileg"                          } ,
  { FIXAPI::MULTILEGCANCELREPLACE      , "AC" , "Multileg Order Cancel Replace"               } ,
  { FIXAPI::TRADECAPTUREREQUEST        , "AD" , "Trade Capture Report Request"                } ,
  { FIXAPI::TRADECAPTUREREPORT         , "AE" , "Trade Capture Report"                        } ,
  { FIXAPI::ORDERMASSREQUEST           , "AF" , "Order Mass Status Request"                   } ,
  { FIXAPI::QUOTEREQUESTREJECT         , "AG" , "Quote Request Reject"                        } ,
  { FIXAPI::RFQREQUEST                 , "AH" , "RFQRequest"                                  } ,
  { FIXAPI::QUOTESTATUSREPORT          , "AI" , "QuoteStatusReport"                           } ,
  { FIXAPI::QUOTERESPONSE              , "AJ" , "QuoteResponse"                               } ,
  { FIXAPI::CONFIRMATION               , "AK" , "Confirmation"                                } ,
  { FIXAPI::POSITIONMAINTENANCEREQUEST , "AL" , "Position Maintenance Request"                } ,
  { FIXAPI::POSITIONMAINTENANCEREPORT  , "AM" , "Position Maintenance Report"                 } ,
  { FIXAPI::REQUESTPOSITION            , "AN" , "Request For Positions"                       } ,
  { FIXAPI::REQUESTPOSITIONACK         , "AO" , "Request For Positions Ack"                   } ,
  { FIXAPI::POSITIONREPORT             , "AP" , "Position Report"                             } ,
  { FIXAPI::TRADEREPORTREQUESTACK      , "AQ" , "Trade Capture Report Request Ack"            } ,
  { FIXAPI::TRADEREPORTREPORTACK       , "AR" , "Trade Capture Report Ack"                    } ,
  { FIXAPI::ALLOCATIONREPORT           , "AS" , "Allocation Report"                           } ,
  { FIXAPI::ALLOCATIONREPORTACK        , "AT" , "Allocation Report Ack"                       } ,
  { FIXAPI::CONFIRMATIONACK            , "AU" , "Confirmation Ack"                            } ,
  { FIXAPI::SETTLEMENTREQUEST          , "AV" , "Settlement Instruction Request"              } ,
  { FIXAPI::ASSIGNMENTREPORT           , "AW" , "Assignment Report"                           } ,
  { FIXAPI::COLLATERALREQUEST          , "AX" , "Collateral Request"                          } ,
  { FIXAPI::COLLATERALASSIGNMENT       , "AY" , "Collateral Assignment"                       } ,
  { FIXAPI::COLLATERALRESPONSE         , "AZ" , "Collateral Response"                         } ,
  { FIXAPI::NEWS                       ,  "B" , "News"                                        } ,
  { FIXAPI::MASSQUOTEACK               ,  "b" , "Mass Quote Acknowledgement"                  } ,
  { FIXAPI::COLLATERALREPORT           , "BA" , "Collateral Report"                           } ,
  { FIXAPI::COLLATERALINQUIRY          , "BB" , "Collateral Inquiry"                          } ,
  { FIXAPI::NETWORKSTATUSREQUEST       , "BC" , "Network Counter party System Status Request" } ,
  { FIXAPI::NETWORKSTATUSRESPONSE      , "BD" , "Network Counter party System Status Response"} ,
  { FIXAPI::USERREQUEST                , "BE" , "User Request"                                } ,
  { FIXAPI::USERRESPONSE               , "BF" , "User Response"                               } ,
  { FIXAPI::COLLATERALINQUIRYACK       , "BG" , "Collateral Inquiry Ack"                      } ,
  { FIXAPI::CONFIRMATIONREQUEST        , "BH" , "Confirmation Request"                        } ,
  { FIXAPI::EMAIL                      ,  "C" , "Email"                                       } ,
  { FIXAPI::SECURITYDEFINITIONREQUEST  ,  "c" , "Security Definition Request"                 } ,
  { FIXAPI::SECURITYDEFINITION         ,  "d" , "Security Definition"                         } ,
  { FIXAPI::NEWORDERSINGLE             ,  "D" , "New Order Single"                            } ,
  { FIXAPI::SECURITYSTATUSREQUEST      ,  "e" , "Security Status Request"                     } ,
  { FIXAPI::NEWORDERLIST               ,  "E" , "New Order List"                              } ,
  { FIXAPI::ORDERCANCELREQUEST         ,  "F" , "Order Cancel Request"                        } ,
  { FIXAPI::SECURITYSTATUS             ,  "f" , "Security Status"                             } ,
  { FIXAPI::ORDERREPLACEREQUEST        ,  "G" , "Order Cancel Replace Request"                } ,
  { FIXAPI::TRADINGSTATUSREQUEST       ,  "g" , "Trading Session Status Request"              } ,
  { FIXAPI::ORDERSTATUSREQUEST         ,  "H" , "Order Status Request"                        } ,
  { FIXAPI::TRADINGSESSIONSTATUS       ,  "h" , "Trading Session Status"                      } ,
  { FIXAPI::MASSQUOTE                  ,  "i" , "Mass Quote"                                  } ,
  { FIXAPI::BUSINESSREJECT             ,  "j" , "Business Message Reject"                     } ,
  { FIXAPI::ALLOCATIONINSTRUCTION      ,  "J" , "Allocation Instruction"                      } ,
  { FIXAPI::BIDREQUEST                 ,  "k" , "Bid Request"                                 } ,
  { FIXAPI::LISTCANCELREQUEST          ,  "K" , "List Cancel Request"                         } ,
  { FIXAPI::BIDRESPONSE                ,  "l" , "Bid Response"                                } ,
  { FIXAPI::LISTEXECUTE                ,  "L" , "List Execute"                                } ,
  { FIXAPI::LISTSTRIKEPRICE            ,  "m" , "List Strike Price"                           } ,
  { FIXAPI::LISTSTATUSREQUEST          ,  "M" , "List Status Request"                         } ,
  { FIXAPI::XMLNONFIX                  ,  "n" , "XML NonFIX"                                  } ,
  { FIXAPI::LISTSTATUS                 ,  "N" , "List Status"                                 } ,
  { FIXAPI::REGISTRATIONINSTRUCTIONS   ,  "o" , "Registration Instructions"                   } ,
  { FIXAPI::REGISTRATIONRESPONSE       ,  "p" , "Registration Instructions Response"          } ,
  { FIXAPI::ALLOCATIONACK              ,  "P" , "Allocation Instruction Ack"                  } ,
  { FIXAPI::ORDERMASSCANCELREQUEST     ,  "q" , "Order Mass Cancel Request"                   } ,
  { FIXAPI::DONTKNOWTRADE              ,  "Q" , "Dont Know Trade DK"                          } ,
  { FIXAPI::QUOTEREQUEST               ,  "R" , "Quote Request"                               } ,
  { FIXAPI::ORDERMASSCANCELREPORT      ,  "r" , "Order Mass Cancel Report"                    } ,
  { FIXAPI::QUOTE                      ,  "S" , "Quote"                                       } ,
  { FIXAPI::NEWORDERCROSS              ,  "s" , "New Order Cross"                             } ,
  { FIXAPI::SETTLEMENTINSTRUNCTIONS    ,  "T" , "Settlement Instructions"                     } ,
  { FIXAPI::CROSSORDERREPLACEREQUEST   ,  "t" , "Cross Order Cancel Replace Request"          } ,
  { FIXAPI::CROSSORDERCANCELREQUEST    ,  "u" , "Cross Order Cancel Request"                  } ,
  { FIXAPI::MARKETDATAREQUEST          ,  "V" , "Market Data Request"                         } ,
  { FIXAPI::SECURITYTYPEREQUEST        ,  "v" , "Security Type Request"                       } ,
  { FIXAPI::SECURITYTYPES              ,  "w" , "Security Types"                              } ,
  { FIXAPI::MARKETDATAFULLREFRESH      ,  "W" , "Market Data Snapshot Full Refresh"           } ,
  { FIXAPI::SECURITYLISTREQUEST        ,  "x" , "Security List Request"                       } ,
  { FIXAPI::MARKETDATAINCREMENTAL      ,  "X" , "Market Data Incremental Refresh"             } ,
  { FIXAPI::MARKETDATAREQUESTREJECT    ,  "Y" , "Market Data Request Reject"                  } ,
  { FIXAPI::SECURITYLIST               ,  "y" , "Security List"                               } ,
  { FIXAPI::QUOTECANCEL                ,  "Z" , "Quote Cancel"                                } ,
  { FIXAPI::SECURITYLISTREQUEST        ,  "z" , "Derivative Security List Request"            } ,
  { FIXAPI::NOTIFICATION               , "U1" , "Notification"                                } ,
  { FIXAPI::ACCOUNTINFO                , "U2" , "Account Info"                                } ,
  { FIXAPI::INSTRUMENTPOSITIONINFO     , "U3" , "Instrument Position Info"                    } ,
  { FIXAPI::ACTIVATIONREQUEST          , "U5" , "Activation Request"                          } ,
  { FIXAPI::ACTIVATIONRESPONSE         , "U6" , "Activation Response"                         } ,
  { FIXAPI::ACCOUNTINFOREQUEST         , "U7" , "Account Info Request"                        } ,
  { FIXAPI::MAXCOUNT                   , NULL , NULL                                          }
};

QtFIXAPI:: QtFIXAPI         (void               )
         : FIX::Application (                   )
         , uuid             ( 0                 )
         , working          ( false             )
         , useLogin         ( true              )
         , isLogin          ( false             )
         , fixThread        ( NULL              )
         , Mode             ( FIXAPI::NoEngine  )
         , Acting           ( FIXAPI::Initiator )
         , messageType      ( FIXAPI::Detail    )
{
}

QtFIXAPI::~QtFIXAPI(void)
{
}

QDateTime QtFIXAPI::stdToDateTime(std::string datetime)
{
  QString   DS                                                 ;
  QDateTime DT                                                 ;
  DS = QString::fromStdString ( datetime                     ) ;
  DT = QDateTime::fromString  ( DS , "yyyyMMdd-hh:mm:ss.zzz" ) ;
  return DT                                                    ;
}

FIXAPI::SessionMode QtFIXAPI::DispatchType(void)
{
  if ( FIXAPI::Compact == messageType ) return FIXAPI::FixCompact ; else
  if ( FIXAPI::Detail  == messageType ) return FIXAPI::FixDetail  ;
  return FIXAPI::FixNone                                          ;
}

void QtFIXAPI::Message(std::string & message)
{
  if ( NULL == fixThread ) return     ;
  fixThread -> FixMessage ( message ) ;
}

int QtFIXAPI::MessageId(std::string msg)
{
  for (int i=0;i<FIXAPI::MAXCOUNT;i++)     {
    if ( msg == FIXTYPES [ i ] . msgType ) {
      return FIXTYPES [ i ] . fixType      ;
    }                                      ;
  }                                        ;
  return FIXAPI::NONE                      ;
}

std::string QtFIXAPI::TypeName(int TypeId)
{
  for (int i=0;i<FIXAPI::MAXCOUNT;i++)        {
    if ( TypeId == FIXTYPES [ i ] . fixType ) {
      return FIXTYPES [ i ] . msgName         ;
    }                                         ;
  }                                           ;
  return ""                                   ;
}

bool QtFIXAPI::sendMessage(FIX::Message & message)
{
  bool sent = false                                           ;
  try                                                         {
    sent = FIX::Session::sendToTarget(message,DefaultSession) ;
  }
  catch ( FIX::SessionNotFound & s )                          {
    std::string msg                                           ;
    msg  = "Session Error"                                    ;
    msg += " : "                                              ;
    msg += s . what ( )                                       ;
    Message ( msg )                                           ;
  }                                                           ;
  return sent                                                 ;
}

void QtFIXAPI::onCreate(const FIX::SessionID & session)
{
  FIX::Message message                               ;
  Dispatch ( message , session , FIXAPI::FixCreate ) ;
}

void QtFIXAPI::onLogon(const FIX::SessionID & session)
{
  FIX::Message message                              ;
  Dispatch ( message , session , FIXAPI::FixLogon ) ;
}

void QtFIXAPI::onLogout(const FIX::SessionID & session)
{
  FIX::Message message                               ;
  Dispatch ( message , session , FIXAPI::FixLogout ) ;
}

void QtFIXAPI::toAdmin(FIX::Message & message,const FIX::SessionID & session)
{
  Dispatch ( message , session , DispatchType ( )   ) ;
  Dispatch ( message , session , FIXAPI::FixToAdmin ) ;
}

void QtFIXAPI::toApp(FIX::Message & message,const FIX::SessionID & session)
     throw (FIX::DoNotSend)
{
  Dispatch ( message , session , DispatchType ( ) ) ;
  Dispatch ( message , session , FIXAPI::FixToApp ) ;
}

////////////////////////////////////////////////////////////
void QtFIXAPI::fromAdmin              (
       const FIX::Message   & message ,
       const FIX::SessionID & session )
     throw ( FIX::FieldNotFound       ,
             FIX::IncorrectDataFormat ,
             FIX::IncorrectTagValue   ,
             FIX::RejectLogon         )
{
  Dispatch ( (FIX::Message)message , session , DispatchType ( )     ) ;
  Dispatch ( (FIX::Message)message , session , FIXAPI::FixFromAdmin ) ;
}

void QtFIXAPI::fromApp                   (
       const FIX::Message   & message    ,
       const FIX::SessionID & session    )
     throw ( FIX::FieldNotFound          ,
             FIX::IncorrectDataFormat    ,
             FIX::IncorrectTagValue      ,
             FIX::UnsupportedMessageType )
{
  Dispatch ( (FIX::Message)message , session , DispatchType ( )   ) ;
  Dispatch ( (FIX::Message)message , session , FIXAPI::FixFromApp ) ;
}

void QtFIXAPI::showMessage(FIX::Message & message,FIXAPI::MessageType mode)
{
  std::string msgType  = message.getHeader(         ) . getField ( 35 ) ;
  std::string msgTime  = message.getHeader(         ) . getField ( 52 ) ;
  int TypeId           = MessageId        ( msgType )                   ;
  std::string typeName = TypeName         ( TypeId  )                   ;
  std::string msg                                                       ;
  if ( mode == FIXAPI::Compact )                                        {
    msg  = msgTime                                                      ;
    msg += "@" + typeName + "\n"                                        ;
    msg += message.toString()                                           ;
    Message ( msg )                                                     ;
  } else
  if ( mode == FIXAPI::Detail  )                                        {
    msg  = msgTime                                                      ;
    msg += "@" + typeName + "\n"                                        ;
    msg += message.toXML()                                              ;
    Message ( msg )                                                     ;
  }                                                                     ;
}

void QtFIXAPI::Dispatch               (
       FIX::Message         & message ,
       const FIX::SessionID & session ,
       FIXAPI::SessionMode    mode    )
{
  if ( mode == FIXAPI::FixNone   )                                           {
    /* Do nothing */
  } else
  if ( mode == FIXAPI::FixCreate )                                           {
    std::string msg                                                          ;
    msg  = "Create Session"                                                  ;
    msg += " : "                                                             ;
    msg += session.toString()                                                ;
    Message  ( msg )                                                         ;
    doCreate (     )                                                         ;
  } else
  if ( mode == FIXAPI::FixLogon  )                                           {
    std::string msg                                                          ;
    msg  = "Logon FIX/API Server"                                            ;
    msg += " : "                                                             ;
    msg += session.toString()                                                ;
    Message ( msg )                                                          ;
    doLogon (     )                                                          ;
  } else
  if ( mode == FIXAPI::FixLogout)                                            {
    std::string msg                                                          ;
    msg  = "Logout FIX/API Server"                                           ;
    msg += " : "                                                             ;
    msg += session.toString()                                                ;
    Message  ( msg )                                                         ;
    doLogout (     )                                                         ;
  } else                                                                     {
    std::string msgType       = message.getHeader(       ) . getField ( 35 ) ;
    std::string msgTime       = message.getHeader(       ) . getField ( 52 ) ;
    std::string sessionString = session.toString (       )                   ;
    int TypeId                = MessageId        (msgType)                   ;
    std::string typeName      = TypeName         (TypeId )                   ;
    switch ( mode )                                                          {
      case FIXAPI::FixCompact                                              : {
        switch ( TypeId )                                                    {
          case FIXAPI::HEARTBEAT                                             :
            Message ( msgTime + "[" + sessionString + "]" + "@" + typeName ) ;
          break                                                              ;
          case FIXAPI::TEST                                                  :
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::RESEND                                                :
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::REJECT                                                :
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::SEQUENCE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::LOGOUT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::IOI:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ADVERTISE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::EXECUTION:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::CANCELREJECT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::QUOTESTATUS:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::LOGON:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::DERIVATIVESECURITYLIST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::NEWMULTILEG:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::MULTILEGCANCELREPLACE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::TRADECAPTUREREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::TRADECAPTUREREPORT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ORDERMASSREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::QUOTEREQUESTREJECT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::RFQREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::QUOTESTATUSREPORT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::QUOTERESPONSE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::CONFIRMATION:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::POSITIONMAINTENANCEREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::POSITIONMAINTENANCEREPORT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::REQUESTPOSITION:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::REQUESTPOSITIONACK:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::POSITIONREPORT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::TRADEREPORTREQUESTACK:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::TRADEREPORTREPORTACK:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ALLOCATIONREPORT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ALLOCATIONREPORTACK:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::CONFIRMATIONACK:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::SETTLEMENTREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ASSIGNMENTREPORT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::COLLATERALREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::COLLATERALASSIGNMENT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::COLLATERALRESPONSE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::NEWS:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::MASSQUOTEACK:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::COLLATERALREPORT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::COLLATERALINQUIRY:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::NETWORKSTATUSREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::NETWORKSTATUSRESPONSE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::USERREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::USERRESPONSE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::COLLATERALINQUIRYACK:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::CONFIRMATIONREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::EMAIL:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::SECURITYDEFINITIONREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::SECURITYDEFINITION:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::NEWORDERSINGLE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::SECURITYSTATUSREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::NEWORDERLIST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ORDERCANCELREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::SECURITYSTATUS:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ORDERREPLACEREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::TRADINGSTATUSREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ORDERSTATUSREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::TRADINGSESSIONSTATUS:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::MASSQUOTE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::BUSINESSREJECT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ALLOCATIONINSTRUCTION:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::BIDREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::LISTCANCELREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::BIDRESPONSE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::LISTEXECUTE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::LISTSTRIKEPRICE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::LISTSTATUSREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::XMLNONFIX:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::LISTSTATUS:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::REGISTRATIONINSTRUCTIONS:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::REGISTRATIONRESPONSE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ALLOCATIONACK:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ORDERMASSCANCELREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::DONTKNOWTRADE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::QUOTEREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ORDERMASSCANCELREPORT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::QUOTE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::NEWORDERCROSS:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::SETTLEMENTINSTRUNCTIONS:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::CROSSORDERREPLACEREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::CROSSORDERCANCELREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::MARKETDATAREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::SECURITYTYPEREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::SECURITYTYPES:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::MARKETDATAFULLREFRESH:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::SECURITYLISTREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::MARKETDATAINCREMENTAL:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::MARKETDATAREQUESTREJECT:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::SECURITYLIST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::QUOTECANCEL:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::NOTIFICATION:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ACCOUNTINFO:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::INSTRUMENTPOSITIONINFO:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ACTIVATIONREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ACTIVATIONRESPONSE:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          case FIXAPI::ACCOUNTINFOREQUEST:
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
          default                                                            :
            showMessage ( message , FIXAPI::Compact )                        ;
          break                                                              ;
        }                                                                    ;
      }                                                                      ;
      break                                                                  ;
      case FIXAPI::FixDetail                                               : {
        switch (TypeId)                                                      {
          case FIXAPI::HEARTBEAT                                             :
            Message ( msgTime + "[" + sessionString + "]" + "@" + typeName ) ;
          break                                                              ;
          case FIXAPI::TEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::RESEND:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::REJECT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::SEQUENCE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::LOGOUT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::IOI:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ADVERTISE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::EXECUTION:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::CANCELREJECT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::QUOTESTATUS:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::LOGON:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::DERIVATIVESECURITYLIST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::NEWMULTILEG:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::MULTILEGCANCELREPLACE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::TRADECAPTUREREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::TRADECAPTUREREPORT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ORDERMASSREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::QUOTEREQUESTREJECT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::RFQREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::QUOTESTATUSREPORT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::QUOTERESPONSE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::CONFIRMATION:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::POSITIONMAINTENANCEREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::POSITIONMAINTENANCEREPORT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::REQUESTPOSITION:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::REQUESTPOSITIONACK:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::POSITIONREPORT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::TRADEREPORTREQUESTACK:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::TRADEREPORTREPORTACK:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ALLOCATIONREPORT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ALLOCATIONREPORTACK:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::CONFIRMATIONACK:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::SETTLEMENTREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ASSIGNMENTREPORT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::COLLATERALREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::COLLATERALASSIGNMENT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::COLLATERALRESPONSE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::NEWS:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::MASSQUOTEACK:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::COLLATERALREPORT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::COLLATERALINQUIRY:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::NETWORKSTATUSREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::NETWORKSTATUSRESPONSE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::USERREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::USERRESPONSE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::COLLATERALINQUIRYACK:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::CONFIRMATIONREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::EMAIL:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::SECURITYDEFINITIONREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::SECURITYDEFINITION:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::NEWORDERSINGLE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::SECURITYSTATUSREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::NEWORDERLIST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ORDERCANCELREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::SECURITYSTATUS:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ORDERREPLACEREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::TRADINGSTATUSREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ORDERSTATUSREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::TRADINGSESSIONSTATUS:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::MASSQUOTE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::BUSINESSREJECT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ALLOCATIONINSTRUCTION:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::BIDREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::LISTCANCELREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::BIDRESPONSE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::LISTEXECUTE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::LISTSTRIKEPRICE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::LISTSTATUSREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::XMLNONFIX:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::LISTSTATUS:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::REGISTRATIONINSTRUCTIONS:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::REGISTRATIONRESPONSE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ALLOCATIONACK:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ORDERMASSCANCELREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::DONTKNOWTRADE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::QUOTEREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ORDERMASSCANCELREPORT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::QUOTE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::NEWORDERCROSS:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::SETTLEMENTINSTRUNCTIONS:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::CROSSORDERREPLACEREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::CROSSORDERCANCELREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::MARKETDATAREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::SECURITYTYPEREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::SECURITYTYPES:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::MARKETDATAFULLREFRESH:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::SECURITYLISTREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::MARKETDATAINCREMENTAL:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::MARKETDATAREQUESTREJECT:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::SECURITYLIST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::QUOTECANCEL:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::NOTIFICATION:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ACCOUNTINFO:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::INSTRUMENTPOSITIONINFO:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ACTIVATIONREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ACTIVATIONRESPONSE:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          case FIXAPI::ACCOUNTINFOREQUEST:
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
          default                                                            :
            showMessage ( message , FIXAPI::Detail )                         ;
          break                                                              ;
        }                                                                    ;
      }                                                                      ;
      break                                                                  ;
      case FIXAPI::FixToAdmin                                              : {
        switch (TypeId)                                                      {
          case FIXAPI::HEARTBEAT:
          break                                                              ;
          case FIXAPI::TEST:
          break                                                              ;
          case FIXAPI::RESEND:
          break                                                              ;
          case FIXAPI::REJECT:
          break                                                              ;
          case FIXAPI::SEQUENCE:
          break                                                              ;
          case FIXAPI::LOGOUT:
          break                                                              ;
          case FIXAPI::IOI:
          break                                                              ;
          case FIXAPI::ADVERTISE:
          break                                                              ;
          case FIXAPI::EXECUTION:
          break                                                              ;
          case FIXAPI::CANCELREJECT:
          break                                                              ;
          case FIXAPI::QUOTESTATUS:
          break                                                              ;
          case FIXAPI::LOGON:
          break                                                              ;
          case FIXAPI::DERIVATIVESECURITYLIST:
          break                                                              ;
          case FIXAPI::NEWMULTILEG:
          break                                                              ;
          case FIXAPI::MULTILEGCANCELREPLACE:
          break                                                              ;
          case FIXAPI::TRADECAPTUREREQUEST:
          break                                                              ;
          case FIXAPI::TRADECAPTUREREPORT:
          break                                                              ;
          case FIXAPI::ORDERMASSREQUEST:
          break                                                              ;
          case FIXAPI::QUOTEREQUESTREJECT:
          break                                                              ;
          case FIXAPI::RFQREQUEST:
          break                                                              ;
          case FIXAPI::QUOTESTATUSREPORT:
          break                                                              ;
          case FIXAPI::QUOTERESPONSE:
          break                                                              ;
          case FIXAPI::CONFIRMATION:
          break                                                              ;
          case FIXAPI::POSITIONMAINTENANCEREQUEST:
          break                                                              ;
          case FIXAPI::POSITIONMAINTENANCEREPORT:
          break                                                              ;
          case FIXAPI::REQUESTPOSITION:
          break                                                              ;
          case FIXAPI::REQUESTPOSITIONACK:
          break                                                              ;
          case FIXAPI::POSITIONREPORT:
          break                                                              ;
          case FIXAPI::TRADEREPORTREQUESTACK:
          break                                                              ;
          case FIXAPI::TRADEREPORTREPORTACK:
          break                                                              ;
          case FIXAPI::ALLOCATIONREPORT:
          break                                                              ;
          case FIXAPI::ALLOCATIONREPORTACK:
          break                                                              ;
          case FIXAPI::CONFIRMATIONACK:
          break                                                              ;
          case FIXAPI::SETTLEMENTREQUEST:
          break                                                              ;
          case FIXAPI::ASSIGNMENTREPORT:
          break                                                              ;
          case FIXAPI::COLLATERALREQUEST:
          break                                                              ;
          case FIXAPI::COLLATERALASSIGNMENT:
          break                                                              ;
          case FIXAPI::COLLATERALRESPONSE:
          break                                                              ;
          case FIXAPI::NEWS:
          break                                                              ;
          case FIXAPI::MASSQUOTEACK:
          break                                                              ;
          case FIXAPI::COLLATERALREPORT:
          break                                                              ;
          case FIXAPI::COLLATERALINQUIRY:
          break                                                              ;
          case FIXAPI::NETWORKSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::NETWORKSTATUSRESPONSE:
          break                                                              ;
          case FIXAPI::USERREQUEST:
          break                                                              ;
          case FIXAPI::USERRESPONSE:
          break                                                              ;
          case FIXAPI::COLLATERALINQUIRYACK:
          break                                                              ;
          case FIXAPI::CONFIRMATIONREQUEST:
          break                                                              ;
          case FIXAPI::EMAIL:
          break                                                              ;
          case FIXAPI::SECURITYDEFINITIONREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYDEFINITION:
          break                                                              ;
          case FIXAPI::NEWORDERSINGLE:
          break                                                              ;
          case FIXAPI::SECURITYSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::NEWORDERLIST:
          break                                                              ;
          case FIXAPI::ORDERCANCELREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYSTATUS:
          break                                                              ;
          case FIXAPI::ORDERREPLACEREQUEST:
          break                                                              ;
          case FIXAPI::TRADINGSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::ORDERSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::TRADINGSESSIONSTATUS:
          break                                                              ;
          case FIXAPI::MASSQUOTE:
          break                                                              ;
          case FIXAPI::BUSINESSREJECT:
          break                                                              ;
          case FIXAPI::ALLOCATIONINSTRUCTION:
          break                                                              ;
          case FIXAPI::BIDREQUEST:
          break                                                              ;
          case FIXAPI::LISTCANCELREQUEST:
          break                                                              ;
          case FIXAPI::BIDRESPONSE:
          break                                                              ;
          case FIXAPI::LISTEXECUTE:
          break                                                              ;
          case FIXAPI::LISTSTRIKEPRICE:
          break                                                              ;
          case FIXAPI::LISTSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::XMLNONFIX:
          break                                                              ;
          case FIXAPI::LISTSTATUS:
          break                                                              ;
          case FIXAPI::REGISTRATIONINSTRUCTIONS:
          break                                                              ;
          case FIXAPI::REGISTRATIONRESPONSE:
          break                                                              ;
          case FIXAPI::ALLOCATIONACK:
          break                                                              ;
          case FIXAPI::ORDERMASSCANCELREQUEST:
          break                                                              ;
          case FIXAPI::DONTKNOWTRADE:
          break                                                              ;
          case FIXAPI::QUOTEREQUEST:
          break                                                              ;
          case FIXAPI::ORDERMASSCANCELREPORT:
          break                                                              ;
          case FIXAPI::QUOTE:
          break                                                              ;
          case FIXAPI::NEWORDERCROSS:
          break                                                              ;
          case FIXAPI::SETTLEMENTINSTRUNCTIONS:
          break                                                              ;
          case FIXAPI::CROSSORDERREPLACEREQUEST:
          break                                                              ;
          case FIXAPI::CROSSORDERCANCELREQUEST:
          break                                                              ;
          case FIXAPI::MARKETDATAREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYTYPEREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYTYPES:
          break                                                              ;
          case FIXAPI::MARKETDATAFULLREFRESH:
          break                                                              ;
          case FIXAPI::SECURITYLISTREQUEST:
          break                                                              ;
          case FIXAPI::MARKETDATAINCREMENTAL:
          break                                                              ;
          case FIXAPI::MARKETDATAREQUESTREJECT:
          break                                                              ;
          case FIXAPI::SECURITYLIST:
          break                                                              ;
          case FIXAPI::QUOTECANCEL:
          break                                                              ;
          case FIXAPI::NOTIFICATION:
          break                                                              ;
          case FIXAPI::ACCOUNTINFO:
          break                                                              ;
          case FIXAPI::INSTRUMENTPOSITIONINFO:
          break                                                              ;
          case FIXAPI::ACTIVATIONREQUEST:
          break                                                              ;
          case FIXAPI::ACTIVATIONRESPONSE:
          break                                                              ;
          case FIXAPI::ACCOUNTINFOREQUEST:
          break                                                              ;
          default                                                            :
          break                                                              ;
        }                                                                    ;
      }                                                                      ;
      break                                                                  ;
      case FIXAPI::FixFromAdmin                                            : {
        switch ( TypeId )                                                    {
          case FIXAPI::HEARTBEAT                                             :
          break                                                              ;
          case FIXAPI::TEST:
          break                                                              ;
          case FIXAPI::RESEND:
          break                                                              ;
          case FIXAPI::REJECT:
          break                                                              ;
          case FIXAPI::SEQUENCE:
          break                                                              ;
          case FIXAPI::LOGOUT:
          break                                                              ;
          case FIXAPI::IOI:
          break                                                              ;
          case FIXAPI::ADVERTISE:
          break                                                              ;
          case FIXAPI::EXECUTION:
          break                                                              ;
          case FIXAPI::CANCELREJECT:
          break                                                              ;
          case FIXAPI::QUOTESTATUS:
          break                                                              ;
          case FIXAPI::LOGON:
          break                                                              ;
          case FIXAPI::DERIVATIVESECURITYLIST:
          break                                                              ;
          case FIXAPI::NEWMULTILEG:
          break                                                              ;
          case FIXAPI::MULTILEGCANCELREPLACE:
          break                                                              ;
          case FIXAPI::TRADECAPTUREREQUEST:
          break                                                              ;
          case FIXAPI::TRADECAPTUREREPORT:
          break                                                              ;
          case FIXAPI::ORDERMASSREQUEST:
          break                                                              ;
          case FIXAPI::QUOTEREQUESTREJECT:
          break                                                              ;
          case FIXAPI::RFQREQUEST:
          break                                                              ;
          case FIXAPI::QUOTESTATUSREPORT:
          break                                                              ;
          case FIXAPI::QUOTERESPONSE:
          break                                                              ;
          case FIXAPI::CONFIRMATION:
          break                                                              ;
          case FIXAPI::POSITIONMAINTENANCEREQUEST:
          break                                                              ;
          case FIXAPI::POSITIONMAINTENANCEREPORT:
          break                                                              ;
          case FIXAPI::REQUESTPOSITION:
          break                                                              ;
          case FIXAPI::REQUESTPOSITIONACK:
          break                                                              ;
          case FIXAPI::POSITIONREPORT:
          break                                                              ;
          case FIXAPI::TRADEREPORTREQUESTACK:
          break                                                              ;
          case FIXAPI::TRADEREPORTREPORTACK:
          break                                                              ;
          case FIXAPI::ALLOCATIONREPORT:
          break                                                              ;
          case FIXAPI::ALLOCATIONREPORTACK:
          break                                                              ;
          case FIXAPI::CONFIRMATIONACK:
          break                                                              ;
          case FIXAPI::SETTLEMENTREQUEST:
          break                                                              ;
          case FIXAPI::ASSIGNMENTREPORT:
          break                                                              ;
          case FIXAPI::COLLATERALREQUEST:
          break                                                              ;
          case FIXAPI::COLLATERALASSIGNMENT:
          break                                                              ;
          case FIXAPI::COLLATERALRESPONSE:
          break                                                              ;
          case FIXAPI::NEWS:
          break                                                              ;
          case FIXAPI::MASSQUOTEACK:
          break                                                              ;
          case FIXAPI::COLLATERALREPORT:
          break                                                              ;
          case FIXAPI::COLLATERALINQUIRY:
          break                                                              ;
          case FIXAPI::NETWORKSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::NETWORKSTATUSRESPONSE:
          break                                                              ;
          case FIXAPI::USERREQUEST:
          break                                                              ;
          case FIXAPI::USERRESPONSE:
          break                                                              ;
          case FIXAPI::COLLATERALINQUIRYACK:
          break                                                              ;
          case FIXAPI::CONFIRMATIONREQUEST:
          break                                                              ;
          case FIXAPI::EMAIL:
          break                                                              ;
          case FIXAPI::SECURITYDEFINITIONREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYDEFINITION:
          break                                                              ;
          case FIXAPI::NEWORDERSINGLE:
          break                                                              ;
          case FIXAPI::SECURITYSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::NEWORDERLIST:
          break                                                              ;
          case FIXAPI::ORDERCANCELREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYSTATUS:
          break                                                              ;
          case FIXAPI::ORDERREPLACEREQUEST:
          break                                                              ;
          case FIXAPI::TRADINGSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::ORDERSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::TRADINGSESSIONSTATUS:
          break                                                              ;
          case FIXAPI::MASSQUOTE:
          break                                                              ;
          case FIXAPI::BUSINESSREJECT:
          break                                                              ;
          case FIXAPI::ALLOCATIONINSTRUCTION:
          break                                                              ;
          case FIXAPI::BIDREQUEST:
          break                                                              ;
          case FIXAPI::LISTCANCELREQUEST:
          break                                                              ;
          case FIXAPI::BIDRESPONSE:
          break                                                              ;
          case FIXAPI::LISTEXECUTE:
          break                                                              ;
          case FIXAPI::LISTSTRIKEPRICE:
          break                                                              ;
          case FIXAPI::LISTSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::XMLNONFIX:
          break                                                              ;
          case FIXAPI::LISTSTATUS:
          break                                                              ;
          case FIXAPI::REGISTRATIONINSTRUCTIONS:
          break                                                              ;
          case FIXAPI::REGISTRATIONRESPONSE:
          break                                                              ;
          case FIXAPI::ALLOCATIONACK:
          break                                                              ;
          case FIXAPI::ORDERMASSCANCELREQUEST:
          break                                                              ;
          case FIXAPI::DONTKNOWTRADE:
          break                                                              ;
          case FIXAPI::QUOTEREQUEST:
          break                                                              ;
          case FIXAPI::ORDERMASSCANCELREPORT:
          break                                                              ;
          case FIXAPI::QUOTE:
          break                                                              ;
          case FIXAPI::NEWORDERCROSS:
          break                                                              ;
          case FIXAPI::SETTLEMENTINSTRUNCTIONS:
          break                                                              ;
          case FIXAPI::CROSSORDERREPLACEREQUEST:
          break                                                              ;
          case FIXAPI::CROSSORDERCANCELREQUEST:
          break                                                              ;
          case FIXAPI::MARKETDATAREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYTYPEREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYTYPES:
          break                                                              ;
          case FIXAPI::MARKETDATAFULLREFRESH:
          break                                                              ;
          case FIXAPI::SECURITYLISTREQUEST:
          break                                                              ;
          case FIXAPI::MARKETDATAINCREMENTAL:
          break                                                              ;
          case FIXAPI::MARKETDATAREQUESTREJECT:
          break                                                              ;
          case FIXAPI::SECURITYLIST:
          break                                                              ;
          case FIXAPI::QUOTECANCEL:
          break                                                              ;
          case FIXAPI::NOTIFICATION:
          break                                                              ;
          case FIXAPI::ACCOUNTINFO:
          break                                                              ;
          case FIXAPI::INSTRUMENTPOSITIONINFO:
          break                                                              ;
          case FIXAPI::ACTIVATIONREQUEST:
          break                                                              ;
          case FIXAPI::ACTIVATIONRESPONSE:
          break                                                              ;
          case FIXAPI::ACCOUNTINFOREQUEST:
          break                                                              ;
          default                                                            :
          break                                                              ;
        }                                                                    ;
      }                                                                      ;
      break                                                                  ;
      case FIXAPI::FixToApp                                                : {
        switch ( TypeId )                                                    {
          case FIXAPI::HEARTBEAT:
          break                                                              ;
          case FIXAPI::TEST:
          break                                                              ;
          case FIXAPI::RESEND:
          break                                                              ;
          case FIXAPI::REJECT:
          break                                                              ;
          case FIXAPI::SEQUENCE:
          break                                                              ;
          case FIXAPI::LOGOUT:
          break                                                              ;
          case FIXAPI::IOI:
          break                                                              ;
          case FIXAPI::ADVERTISE:
          break                                                              ;
          case FIXAPI::EXECUTION:
          break                                                              ;
          case FIXAPI::CANCELREJECT:
          break                                                              ;
          case FIXAPI::QUOTESTATUS:
          break                                                              ;
          case FIXAPI::LOGON:
          break                                                              ;
          case FIXAPI::DERIVATIVESECURITYLIST:
          break                                                              ;
          case FIXAPI::NEWMULTILEG:
          break                                                              ;
          case FIXAPI::MULTILEGCANCELREPLACE:
          break                                                              ;
          case FIXAPI::TRADECAPTUREREQUEST:
          break                                                              ;
          case FIXAPI::TRADECAPTUREREPORT:
          break                                                              ;
          case FIXAPI::ORDERMASSREQUEST:
          break                                                              ;
          case FIXAPI::QUOTEREQUESTREJECT:
          break                                                              ;
          case FIXAPI::RFQREQUEST:
          break                                                              ;
          case FIXAPI::QUOTESTATUSREPORT:
          break                                                              ;
          case FIXAPI::QUOTERESPONSE:
          break                                                              ;
          case FIXAPI::CONFIRMATION:
          break                                                              ;
          case FIXAPI::POSITIONMAINTENANCEREQUEST:
          break                                                              ;
          case FIXAPI::POSITIONMAINTENANCEREPORT:
          break                                                              ;
          case FIXAPI::REQUESTPOSITION:
          break                                                              ;
          case FIXAPI::REQUESTPOSITIONACK:
          break                                                              ;
          case FIXAPI::POSITIONREPORT:
          break                                                              ;
          case FIXAPI::TRADEREPORTREQUESTACK:
          break                                                              ;
          case FIXAPI::TRADEREPORTREPORTACK:
          break                                                              ;
          case FIXAPI::ALLOCATIONREPORT:
          break                                                              ;
          case FIXAPI::ALLOCATIONREPORTACK:
          break                                                              ;
          case FIXAPI::CONFIRMATIONACK:
          break                                                              ;
          case FIXAPI::SETTLEMENTREQUEST:
          break                                                              ;
          case FIXAPI::ASSIGNMENTREPORT:
          break                                                              ;
          case FIXAPI::COLLATERALREQUEST:
          break                                                              ;
          case FIXAPI::COLLATERALASSIGNMENT:
          break                                                              ;
          case FIXAPI::COLLATERALRESPONSE:
          break                                                              ;
          case FIXAPI::NEWS:
          break                                                              ;
          case FIXAPI::MASSQUOTEACK:
          break                                                              ;
          case FIXAPI::COLLATERALREPORT:
          break                                                              ;
          case FIXAPI::COLLATERALINQUIRY:
          break                                                              ;
          case FIXAPI::NETWORKSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::NETWORKSTATUSRESPONSE:
          break                                                              ;
          case FIXAPI::USERREQUEST:
          break                                                              ;
          case FIXAPI::USERRESPONSE:
          break                                                              ;
          case FIXAPI::COLLATERALINQUIRYACK:
          break                                                              ;
          case FIXAPI::CONFIRMATIONREQUEST:
          break                                                              ;
          case FIXAPI::EMAIL:
          break                                                              ;
          case FIXAPI::SECURITYDEFINITIONREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYDEFINITION:
          break                                                              ;
          case FIXAPI::NEWORDERSINGLE:
          break                                                              ;
          case FIXAPI::SECURITYSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::NEWORDERLIST:
          break                                                              ;
          case FIXAPI::ORDERCANCELREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYSTATUS:
          break                                                              ;
          case FIXAPI::ORDERREPLACEREQUEST:
          break                                                              ;
          case FIXAPI::TRADINGSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::ORDERSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::TRADINGSESSIONSTATUS:
          break                                                              ;
          case FIXAPI::MASSQUOTE:
          break                                                              ;
          case FIXAPI::BUSINESSREJECT:
          break                                                              ;
          case FIXAPI::ALLOCATIONINSTRUCTION:
          break                                                              ;
          case FIXAPI::BIDREQUEST:
          break                                                              ;
          case FIXAPI::LISTCANCELREQUEST:
          break                                                              ;
          case FIXAPI::BIDRESPONSE:
          break                                                              ;
          case FIXAPI::LISTEXECUTE:
          break                                                              ;
          case FIXAPI::LISTSTRIKEPRICE:
          break                                                              ;
          case FIXAPI::LISTSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::XMLNONFIX:
          break                                                              ;
          case FIXAPI::LISTSTATUS:
          break                                                              ;
          case FIXAPI::REGISTRATIONINSTRUCTIONS:
          break                                                              ;
          case FIXAPI::REGISTRATIONRESPONSE:
          break                                                              ;
          case FIXAPI::ALLOCATIONACK:
          break                                                              ;
          case FIXAPI::ORDERMASSCANCELREQUEST:
          break                                                              ;
          case FIXAPI::DONTKNOWTRADE:
          break                                                              ;
          case FIXAPI::QUOTEREQUEST:
          break                                                              ;
          case FIXAPI::ORDERMASSCANCELREPORT:
          break                                                              ;
          case FIXAPI::QUOTE:
          break                                                              ;
          case FIXAPI::NEWORDERCROSS:
          break                                                              ;
          case FIXAPI::SETTLEMENTINSTRUNCTIONS:
          break                                                              ;
          case FIXAPI::CROSSORDERREPLACEREQUEST:
          break                                                              ;
          case FIXAPI::CROSSORDERCANCELREQUEST:
          break                                                              ;
          case FIXAPI::MARKETDATAREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYTYPEREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYTYPES:
          break                                                              ;
          case FIXAPI::MARKETDATAFULLREFRESH:
          break                                                              ;
          case FIXAPI::SECURITYLISTREQUEST:
          break                                                              ;
          case FIXAPI::MARKETDATAINCREMENTAL:
          break                                                              ;
          case FIXAPI::MARKETDATAREQUESTREJECT:
          break                                                              ;
          case FIXAPI::SECURITYLIST:
          break                                                              ;
          case FIXAPI::QUOTECANCEL:
          break                                                              ;
          case FIXAPI::NOTIFICATION:
          break                                                              ;
          case FIXAPI::ACCOUNTINFO:
          break                                                              ;
          case FIXAPI::INSTRUMENTPOSITIONINFO:
          break                                                              ;
          case FIXAPI::ACTIVATIONREQUEST:
          break                                                              ;
          case FIXAPI::ACTIVATIONRESPONSE:
          break                                                              ;
          case FIXAPI::ACCOUNTINFOREQUEST:
          break                                                              ;
          default                                                            :
          break                                                              ;
        }                                                                    ;
      }                                                                      ;
      break                                                                  ;
      case FIXAPI::FixFromApp                                              : {
        switch ( TypeId )                                                    {
          case FIXAPI::HEARTBEAT:
          break                                                              ;
          case FIXAPI::TEST:
          break                                                              ;
          case FIXAPI::RESEND:
          break                                                              ;
          case FIXAPI::REJECT:
          break                                                              ;
          case FIXAPI::SEQUENCE:
          break                                                              ;
          case FIXAPI::LOGOUT:
          break                                                              ;
          case FIXAPI::IOI:
          break                                                              ;
          case FIXAPI::ADVERTISE:
          break                                                              ;
          case FIXAPI::EXECUTION:
          break                                                              ;
          case FIXAPI::CANCELREJECT:
          break                                                              ;
          case FIXAPI::QUOTESTATUS:
          break                                                              ;
          case FIXAPI::LOGON:
          break                                                              ;
          case FIXAPI::DERIVATIVESECURITYLIST:
          break                                                              ;
          case FIXAPI::NEWMULTILEG:
          break                                                              ;
          case FIXAPI::MULTILEGCANCELREPLACE:
          break                                                              ;
          case FIXAPI::TRADECAPTUREREQUEST:
          break                                                              ;
          case FIXAPI::TRADECAPTUREREPORT:
          break                                                              ;
          case FIXAPI::ORDERMASSREQUEST:
          break                                                              ;
          case FIXAPI::QUOTEREQUESTREJECT:
          break                                                              ;
          case FIXAPI::RFQREQUEST:
          break                                                              ;
          case FIXAPI::QUOTESTATUSREPORT:
          break                                                              ;
          case FIXAPI::QUOTERESPONSE:
          break                                                              ;
          case FIXAPI::CONFIRMATION:
          break                                                              ;
          case FIXAPI::POSITIONMAINTENANCEREQUEST:
          break                                                              ;
          case FIXAPI::POSITIONMAINTENANCEREPORT:
          break                                                              ;
          case FIXAPI::REQUESTPOSITION:
          break                                                              ;
          case FIXAPI::REQUESTPOSITIONACK:
          break                                                              ;
          case FIXAPI::POSITIONREPORT:
          break                                                              ;
          case FIXAPI::TRADEREPORTREQUESTACK:
          break                                                              ;
          case FIXAPI::TRADEREPORTREPORTACK:
          break                                                              ;
          case FIXAPI::ALLOCATIONREPORT:
          break                                                              ;
          case FIXAPI::ALLOCATIONREPORTACK:
          break                                                              ;
          case FIXAPI::CONFIRMATIONACK:
          break                                                              ;
          case FIXAPI::SETTLEMENTREQUEST:
          break                                                              ;
          case FIXAPI::ASSIGNMENTREPORT:
          break                                                              ;
          case FIXAPI::COLLATERALREQUEST:
          break                                                              ;
          case FIXAPI::COLLATERALASSIGNMENT:
          break                                                              ;
          case FIXAPI::COLLATERALRESPONSE:
          break                                                              ;
          case FIXAPI::NEWS:
          break                                                              ;
          case FIXAPI::MASSQUOTEACK:
          break                                                              ;
          case FIXAPI::COLLATERALREPORT:
          break                                                              ;
          case FIXAPI::COLLATERALINQUIRY:
          break                                                              ;
          case FIXAPI::NETWORKSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::NETWORKSTATUSRESPONSE:
          break                                                              ;
          case FIXAPI::USERREQUEST:
          break                                                              ;
          case FIXAPI::USERRESPONSE:
          break                                                              ;
          case FIXAPI::COLLATERALINQUIRYACK:
          break                                                              ;
          case FIXAPI::CONFIRMATIONREQUEST:
          break                                                              ;
          case FIXAPI::EMAIL:
          break                                                              ;
          case FIXAPI::SECURITYDEFINITIONREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYDEFINITION:
          break                                                              ;
          case FIXAPI::NEWORDERSINGLE:
          break                                                              ;
          case FIXAPI::SECURITYSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::NEWORDERLIST:
          break                                                              ;
          case FIXAPI::ORDERCANCELREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYSTATUS:
          break                                                              ;
          case FIXAPI::ORDERREPLACEREQUEST:
          break                                                              ;
          case FIXAPI::TRADINGSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::ORDERSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::TRADINGSESSIONSTATUS:
          break                                                              ;
          case FIXAPI::MASSQUOTE:
          break                                                              ;
          case FIXAPI::BUSINESSREJECT:
          break                                                              ;
          case FIXAPI::ALLOCATIONINSTRUCTION:
          break                                                              ;
          case FIXAPI::BIDREQUEST:
          break                                                              ;
          case FIXAPI::LISTCANCELREQUEST:
          break                                                              ;
          case FIXAPI::BIDRESPONSE:
          break                                                              ;
          case FIXAPI::LISTEXECUTE:
          break                                                              ;
          case FIXAPI::LISTSTRIKEPRICE:
          break                                                              ;
          case FIXAPI::LISTSTATUSREQUEST:
          break                                                              ;
          case FIXAPI::XMLNONFIX:
          break                                                              ;
          case FIXAPI::LISTSTATUS:
          break                                                              ;
          case FIXAPI::REGISTRATIONINSTRUCTIONS:
          break                                                              ;
          case FIXAPI::REGISTRATIONRESPONSE:
          break                                                              ;
          case FIXAPI::ALLOCATIONACK:
          break                                                              ;
          case FIXAPI::ORDERMASSCANCELREQUEST:
          break                                                              ;
          case FIXAPI::DONTKNOWTRADE:
          break                                                              ;
          case FIXAPI::QUOTEREQUEST:
          break                                                              ;
          case FIXAPI::ORDERMASSCANCELREPORT:
          break                                                              ;
          case FIXAPI::QUOTE:
          break                                                              ;
          case FIXAPI::NEWORDERCROSS:
          break                                                              ;
          case FIXAPI::SETTLEMENTINSTRUNCTIONS:
          break                                                              ;
          case FIXAPI::CROSSORDERREPLACEREQUEST:
          break                                                              ;
          case FIXAPI::CROSSORDERCANCELREQUEST:
          break                                                              ;
          case FIXAPI::MARKETDATAREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYTYPEREQUEST:
          break                                                              ;
          case FIXAPI::SECURITYTYPES:
          break                                                              ;
          case FIXAPI::MARKETDATAFULLREFRESH:
          break                                                              ;
          case FIXAPI::SECURITYLISTREQUEST:
          break                                                              ;
          case FIXAPI::MARKETDATAINCREMENTAL:
          break                                                              ;
          case FIXAPI::MARKETDATAREQUESTREJECT:
          break                                                              ;
          case FIXAPI::SECURITYLIST:
          break                                                              ;
          case FIXAPI::QUOTECANCEL:
          break                                                              ;
          case FIXAPI::NOTIFICATION:
          break                                                              ;
          case FIXAPI::ACCOUNTINFO:
          break                                                              ;
          case FIXAPI::INSTRUMENTPOSITIONINFO:
          break                                                              ;
          case FIXAPI::ACTIVATIONREQUEST:
          break                                                              ;
          case FIXAPI::ACTIVATIONRESPONSE:
          break                                                              ;
          case FIXAPI::ACCOUNTINFOREQUEST:
          break                                                              ;
          default                                                            :
          break                                                              ;
        }                                                                    ;
      }                                                                      ;
      break                                                                  ;
    }                                                                        ;
  }                                                                          ;
}

void QtFIXAPI::run(void)
{
  working = true   ;
  WaitLogin    ( ) ;
  LoginStuffs  ( ) ;
  doLoop       ( ) ;
  LogoutStuffs ( ) ;
  working = false  ;
}

void QtFIXAPI::doCreate(void)
{
}

void QtFIXAPI::doLogon(void)
{
  isLogin    = 2                  ;
  if ( NULL == fixThread ) return ;
  fixThread -> LOGIN  ( Mode )    ;
}

void QtFIXAPI::doLogout(void)
{
  isLogin    = 0                  ;
  if ( NULL == fixThread ) return ;
  fixThread -> LOGOUT ( Mode )    ;
}

void QtFIXAPI::WaitLogin(void)
{
}

void QtFIXAPI::LoginStuffs(void)
{
}

void QtFIXAPI::doLoop(void)
{
}

void QtFIXAPI::LogoutStuffs(void)
{
}

QT_END_NAMESPACE
