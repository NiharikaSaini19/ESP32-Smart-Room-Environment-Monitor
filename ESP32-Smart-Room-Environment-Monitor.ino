#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);//made an object

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WebServer server(80); //webser at port 80 auto http default

void handleRoot() {

  float temperature = dht.readTemperature(); //read temp from sensor and store here
  float humidity = dht.readHumidity(); // read humidity from sensor and store here

  if (isnan(temperature) || isnan(humidity)) { //nan-not a number (either of the values if not a number server sends error message)
    server.send(200, "text/html",
                "<html><body><h1>Sensor Error!</h1></body></html>");
    return;
  }

  String status;
  String color;
  String recommendation;

  if (temperature < 30) {
    status = "Healthy";
    color = "green";
    recommendation = "✅ Environment is comfortable.";
  }
  else if (temperature <= 35) {
    status = "Warm";
    color = "orange";
    recommendation = "⚠ Room is getting warm.";
  }
  else {
    status = "Attention Required";
    color = "red";
    recommendation = "🚨 Increase ventilation.";
  }

  String html = "";

  html += "<!DOCTYPE html>";
  html += "<html>";
  html += "<head>";

  html += "<meta charset='UTF-8'>";
  html += "<meta http-equiv='refresh' content='5'>";
  html += "<title>ESP32 Smart Room Environment Monitor</title>";

  html += "<style>";

  html += "body{";
  html += "font-family:Arial,sans-serif;";
  html += "background:#eef4f8;";
  html += "margin:0;";
  html += "text-align:center;";
  html += "}";

  html += ".card{";
  html += "background:white;";
  html += "width:420px;";
  html += "margin:40px auto;";
  html += "padding:25px;";
  html += "border-radius:20px;";
  html += "box-shadow:0px 8px 25px rgba(0,0,0,0.18);";
  html += "}";

  html += "h1{color:#1976D2;margin-bottom:5px;}";

  html += ".subtitle{";
  html += "color:gray;";
  html += "font-size:17px;";
  html += "margin-bottom:20px;";
  html += "}";

  html += ".value{";
  html += "font-size:28px;";
  html += "font-weight:bold;";
  html += "color:#1976D2;";
  html += "}";

  html += "p{font-size:20px;}";

  html += "hr{margin:20px 0;}";

  html += ".footer{";
  html += "font-size:15px;";
  html += "color:gray;";
  html += "}";

  html += "</style>";

  html += "</head>";

  html += "<body>";

  html += "<div class='card'>";

  html += "<h1>🏠 Smart Room Environment Monitor</h1>";

  html += "<div class='subtitle'>";
  html += "Real-Time Indoor Environment Monitoring";
  html += "</div>";

  html += "<hr>";

  html += "<p>🌡 <b>Room Temperature</b></p>";
  html += "<div class='value'>";
  html += String(temperature);
  html += " &deg;C</div>";

  html += "<hr>";

  html += "<p>💧 <b>Room Humidity</b></p>";
  html += "<div class='value'>";
  html += String(humidity);
  html += " %</div>";

  html += "<hr>";

  html += "<p><b>🟢 Room Health</b></p>";

  html += "<div class='value' style='color:";
  html += color;
  html += ";'>";
  html += status;
  html += "</div>";

  html += "<hr>";

  html += "<p><b>💬 Recommendation</b></p>";

  html += "<p>";
  html += recommendation;
  html += "</p>";

  html += "<hr>";

  html += "<div class='footer'>";

  html += "📶 Wi-Fi Connected<br>";
  html += "Powered by ESP32<br>";
  html += "Updates every 5 seconds";

  html += "</div>";

  html += "</div>";

  html += "</body>";

  html += "</html>";

  server.send(200, "text/html", html);
}

void setup() {

  Serial.begin(115200);

  dht.begin();

  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected!");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.begin();

  Serial.println("Web Server Started");
}

void loop() {

  server.handleClient();

}
