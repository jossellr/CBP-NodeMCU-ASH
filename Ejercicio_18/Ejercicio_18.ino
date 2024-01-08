#include <ThreeWire.h> 
#include <RtcDS1302.h>

const int CLK = 12; // CLK -> SCLK.
const int DAT = 13; // DAT -> IO.
const int RST = 15; // RST -> CE.

ThreeWire my_wire(DAT, CLK, RST);
RtcDS1302<ThreeWire> rtc(my_wire);

void setup() 
{
    Serial.begin(9600);
    Serial.print("compiled: ");
    Serial.print(__DATE__);
    Serial.println(__TIME__);

    // Inicialización.
    rtc.Begin();

    RtcDateTime _compiled = RtcDateTime(__DATE__, __TIME__);
    printDateTime(_compiled);
    Serial.println();

    if (!rtc.IsDateTimeValid()) 
    {
        Serial.println("RTC lost confidence in the DateTime!");
        rtc.SetDateTime(_compiled);
    }

    if (rtc.GetIsWriteProtected())
    {
        Serial.println("RTC was write protected, enabling writing now");
        rtc.SetIsWriteProtected(false);
    }

    if (!rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        rtc.SetIsRunning(true);
    }

    RtcDateTime _now = rtc.GetDateTime();
    if (_now < _compiled) 
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        rtc.SetDateTime(_compiled);
    }
    else if (_now > _compiled) 
        Serial.println("RTC is newer than compile time. (this is expected)");
    else if (_now == _compiled) 
        Serial.println("RTC is the same as compile time! (not expected but all is fine)");
}

void loop () 
{
    // Obtenemos el timestamp actual.
    RtcDateTime _now = rtc.GetDateTime();

    // Imprimimos el timestamp actual.
    printDateTime(_now);
    Serial.println();

    if (!_now.IsValid())
        Serial.println("RTC lost confidence in the DateTime!");

    delay(1000);
}

#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& _dt)
{
    char _datestring[20];

    snprintf_P(_datestring, 
            countof(_datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            _dt.Day(),
            _dt.Month(),
            _dt.Year(),
            _dt.Hour(),
            _dt.Minute(),
            _dt.Second() );
    Serial.print(_datestring);
}