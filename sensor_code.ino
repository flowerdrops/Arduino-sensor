
#include <SPI.h>
#include <WiFi101.h>


char ssid[] = "sjj";      // your network SSID (name)
char pass[] = "aaa123456";   // your network password
int keyIndex = 0;                 // your network key Index number (needed only for WEP)
//192.168.253.2   http://www.sjjdata.local/
//172.27.35.2   http://www.sjjdata.local/
//IPAddress ip = WiFi.localIP();
int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup() {

  analogReadResolution(12);
  pinMode(6,OUTPUT);
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(1000);
    digitalWrite(6,HIGH);
    delay(1000);
    digitalWrite(6,LOW);
    delay(1000);
    digitalWrite(6,HIGH);
    delay(1000);
    digitalWrite(6,LOW);
    delay(1000);
    digitalWrite(6,HIGH);
  }
  server.begin();
}


void loop() {
  // listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 0.5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // output the value of each analog input pin
            float temp1 = analogRead(A0)*0.085-55.6;
 //           float temp2 = analogRead(A1)*0.085-55.6;
            client.print("analog input ");
            client.print(" is ");
//            client.print((temp1+temp2)*0.5);
            client.print(temp1);
//            client.print((analogRead(A0)+analogRead(A1))*0.5);
            client.println("<br />");
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);

    // close the connection:
    client.stop();
  }
}
