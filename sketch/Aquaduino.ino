#include <Arduino.h>
#include "src/domoticzGateway.h"
#include <UIPEthernet.h>
#include "src/aquaConfig.h"
//#include "./src/Aquarium.h"


#define MAX_HTTP_BUF_SIZE 100
#define HTTP_PORT 80

#define DEV_MODE 1

const char http_Unauthorized[] PROGMEM =
   "HTTP/1.0 401 Unauthorized\r\n"
   "Content-Type: text/html\r\n\r\n"
   "<h1>401 Unauthorized</h1>";


const char http_OK[]  PROGMEM =
   "HTTP/1.0 200 OK\r\n"
   "Content-Type: text/html\r\n"
   "Pragma: no-cache\r\n\r\n";


char myChar;

EthernetServer server = EthernetServer(HTTP_PORT);
DomoticzGateway dzgw = DomoticzGateway(domoticzHost, domoticzPort);

const int dzIdxPh1 = 127;
const int dzIdxTemp1 = 124;
const int dzIdxTemp2 = 125;
const int dzIdxTurb1 = 126;

/*
const int dzIdxPh1 = 1338;
const int dzIdxTemp1 = 1335;
const int dzIdxTemp2 = 1336;
const int dzIdxTurb1 = 1337;
*/
int i = 10;
unsigned long lastTime;


void setup() {
  sensors.begin();

  #if defined(DEV_MODE)
    Serial.begin(9600);
    Serial.println(F("\n[webServer]"));
  #endif

  Serial.print("Locating devices...");
  Serial.print("Found ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" devices.");
  Serial.print("Parasite power is: ");
  if (sensors.isParasitePowerMode())
    Serial.println("ON");
  else
    Serial.println("OFF");

  if (!sensors.getAddress(ProbeT1, 0)) Serial.println("Unable to find address for Device 0");
  if (!sensors.getAddress(ProbeT2, 1)) Serial.println("Unable to find address for Device 1");

  sensors.setResolution(ProbeT1, TEMPERATURE_PRECISION);
  sensors.setResolution(ProbeT2, TEMPERATURE_PRECISION);

  // Initialisation des pins
  #if defined(DEV_MODE)
    Serial.println(F("  > Configuring Sensor Lvl"));
  #endif

  #if defined(DEV_MODE)
    Serial.println(F("  > Configuring Ethernet"));
  #endif

  // configuration de l'ethernet
  Ethernet.begin(mymac );

  #if defined(DEV_MODE)
    Serial.print(F("localIP: "));
    Serial.println(Ethernet.localIP());
  #endif

  lastTime = millis();

  // demarrage du serveur web
  #if defined(DEV_MODE)
    Serial.println(F("  > Starting webServer"));
  #endif

  server.begin();

  #if defined(DEV_MODE)
    Serial.println(F("-----Init Complete ------"));
  #endif
}

void refreshSensors(){
  sensors.requestTemperatures();

}

void printSensorsValuesToSerial(){
    // notif serie
    #if defined(DEV_MODE)
      Serial.println(F("------------------------"));
      Serial.println(F("Sondes : "));
      Serial.print(F("Ph 1 : "));
      Serial.println(Ph1.read(),2);
      Serial.print(F("Turbidity 1 : "));
      Serial.println(Turbidity1.read(),2);
      Serial.print(F("Temp 1 : "));
      Serial.print(Temp1.read());
      Serial.print(F(" C"));
      Serial.print(F("Temp 2 : "));
      Serial.print(Temp2.read());
      Serial.print(F(" C"));

    #endif
}

void notificationDomotique(){
// notif domoticz
//    dzgw.notifyDomoticz(dzIdxHumidSol1, humidVal1 );
  dzgw.notifyDomoticz(dzIdxPh1, Ph1.read() );
  dzgw.notifyDomoticz(dzIdxTemp1, Temp1.read() );
  dzgw.notifyDomoticz(dzIdxTemp2, Temp2.read());
  dzgw.notifyDomoticz(dzIdxTurb1, Turbidity1.read() );
}

void loop() {

    // maintient de la connection ethernet, relance du DHCP au besoin
    Ethernet.maintain();

    size_t size;
    if (EthernetClient client = server.available())
    {
        String  s = String (100);
        while((size = client.available()) > 0)
        {
          char c = client.read();
          if (s.length() < MAX_HTTP_BUF_SIZE) {
            s += c;
          }
        }

        processRequest(s, client);
        //client.println(http_OK);
        client.stop();
    }

    // controle de l'interval de rafraichissement
    unsigned long currentTime = millis();
    // Refressh toute les 60 seconde ou à chaque overflow de millis()
    if ( ( (currentTime - lastTime ) > 20000) || ( (currentTime - lastTime ) < 0 ) ) {
      // mise à jour des valeurs des capteurs
      refreshSensors();

      printSensorsValuesToSerial();

      notificationDomotique();
      lastTime = millis();
    }
}



// renvoyer Http OK sur le client
void copy_response(EthernetClient & client, const char * response){
  int len = strlen_P(response);
  for (int k = 0; k < len; k++)
  {
    myChar =  pgm_read_byte_near(response + k);
    client.print(myChar);
  }
}

// Envoi du statut de l'alerteBox
void SendStatut(EthernetClient & client){
  char buf[20];
  uptime(buf);
  copy_response(client, http_OK);
  client.println(F("<H1>AquaDuino</H1>"));
  client.println(F("<H2>Uptime : "));
  client.println(buf);
  client.println(F("</H2><H2>Sondes</h2> <h3> Temp 1 : "));
  client.println(Temp1.read(),2);
  client.println(F(" C</h3><h3> Temp 2 : "));
  client.println(Temp2.read(),2);
  client.println(F("C</h3><h3> Turbidity : "));
  client.println(Turbidity1.read(),2);
  client.println(F("</h3><h3> pH : "));
  client.println(Ph1.read(),2);
  client.println(F("</h3><h2> Niveau </H2> <h3> cuve : "));
  client.println();
  client.println(F(" % </h3>"));
}

// Envoi du statut de l'alerteBox
void SendStatutJson(EthernetClient & client){
  char buf[20];
  uptime(buf);
  copy_response(client, http_OK);
  client.println(F("[{ "));
  client.println(F(" \"Uptime\" : \""));
  client.println(buf);
  client.println(F("\", \"Temp1\": \""));
  client.println(Temp1.read(),2);
  client.println(F("\", \"Temp2\": \""));
  client.println(Temp2.read(),2);
  client.println(F("\", \"Tubidity1\": \""));
  client.println(Turbidity1.read(),2);
  client.println(F("\", \"pH1\": \""));
  client.println(Ph1.read(),2);
  client.println(F("\"}]"));
}


// traitement de la requete Http
void processRequest(String & request, EthernetClient & client){
  // cas de l'url exposée : /jardinduino en GET
  if (strstr(request.c_str(), "GET /aquaduino/statut")){
      SendStatut(client);
  }else
  if (strstr(request.c_str(), "GET /aquaduino/jsonstatut")){
      SendStatutJson(client);
  }else{
     copy_response(client, http_Unauthorized);
     client.println(F("<H1>UnAuthorized</H1>"));
  }
}

// Fonction de formatage de l'uptime
void uptime(char * dest)
{
  uptime(millis(), dest);
}

// Fonction de formatage de l'uptime
void uptime(unsigned long timestamp, char * dest) {
 int days=0;
 int hours=0;
 int mins=0;
 long secs=0;
 secs = timestamp/1000; //convect milliseconds to seconds
 mins=secs/60; //convert seconds to minutes
 hours=mins/60; //convert minutes to hours
 days=hours/24; //convert hours to days
 secs=secs-(mins*60); //subtract the coverted seconds to minutes in order to display 59 secs max
 mins=mins-(hours*60); //subtract the coverted minutes to hours in order to display 59 minutes max
 hours=hours-(days*24); //subtract the coverted hours to days in order to display 23 hours max
 //Display results

 sprintf(dest, "%02d days %02d:%02d:%02d", days, hours, mins, secs);

}




