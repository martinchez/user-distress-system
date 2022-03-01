#include <SoftwareSerial.h>
SoftwareSerial SIM800(3, 2);
char Received_SMS;              //Here we store the full received SMS (with phone sending number and date/time) as char

//short DHT_OK=-1,MLX_OK=-1;      //Used later it shows if there's the word "DHT"/"MLX" within the received SMS "-1" means they are not found
short STATUS_OK = -1, LEVEL_OK = -1; //Used later it shows if there's the word "DHT"/"MLX" within the received SMS "-1" means they are not found

String Data_SMS;
// ------- Tank details ------//
int total_height = 135; // Tank height in CM
int hold_height = 120;// Water hold height in CM

//----- Your Phone no. -------//
char cntry_code[] = "+254"; // Country code
char ph[] = "713297997"; // owner's (receiver's) phone no.

const int trigger = 8;
const int echo = 7;
int var_1 = 0;
char input_string[15];

long Time;
int distanceCM;
int resultCM;
float tnk_lvl ;
float tnk_lvl2 ;
float sensr_to_wtr ;
float batt_volt, batt_volt1;

int lowestLvl = 30;
int voltage;

int lengt = 200;
int width = 200;
int volume;

float pi = 3.142;
float radius = 63.5;
float volume_cy;

void setup() {
  SIM800.begin(9600);
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(A3, INPUT);
  Serial.println("Starting ...");
  delay(3000);
  ReceiveMode();


}

void loop() {
  String RSMS;
  while (SIM800.available() > 0) {

    Received_SMS = SIM800.read();
    Serial.print(Received_SMS);
    RSMS.concat(Received_SMS);
    STATUS_OK = RSMS.indexOf("STATUS");

  }
  if (STATUS_OK != -1) {

    delay(100);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    long Time = pulseIn(echo, HIGH);
    int distanceCM = Time * 0.034;
    int resultCM = distanceCM / 2;
    //battery voltage
    float voltage = analogRead(A3);
    float batt_volt1 = voltage / 103;
    float batt_volt = batt_volt1 / 2;
    float sensr_to_wtr;
    //tank water level
    float tnk_lvl = map(resultCM,  sensr_to_wtr, total_height, 100, 0);
    float tnk_lvl2 = total_height - resultCM ;
    float volume_cy = pi * radius * radius * tnk_lvl2;
    delay(1000);
    Serial.print("Tank water level is: ");
    Serial.println(tnk_lvl2);
    Serial.print("battery voltage: ");
    Serial.print(batt_volt);
    Serial.println(" v ");
    Serial.print("Tank Volume: ");
    Serial.print(volume);
    Serial.println("cm3");

    Data_SMS = "STATUS\nWater Level =" + String(tnk_lvl2, 1) + " \nBattery Voltage =" + String(batt_volt, 1) + "v";


    Send_Data();
    ReceiveMode();

    STATUS_OK = -1;
    LEVEL_OK = -1;
  }

  if (tnk_lvl2 >= hold_height ) {
    SIM800.println("AT+CNMI=2,2,0,0,0");
    delay(1000);
    SIM800.println("AT+CMGF=1");
    delay(500);
    SIM800.print("AT+CMGS=");
    SIM800.print("\"");
    SIM800.print(ph);
    SIM800.println("\"");
    delay(1000);
    SIM800.println("Tank Almost Full");
    SIM800.println("Tank ID : 1");
    SIM800.print("Battery level: ");
    SIM800.println(batt_volt);
    SIM800.print("water level: ");
    SIM800.println(tnk_lvl2);
    SIM800.print("Tank Percentage full: ");
    SIM800.print(tnk_lvl);
    SIM800.println("%");
    SIM800.print("Tank Volume: ");
    SIM800.println(volume);
    delay(100);
    SIM800.println((char)26);
  }
  if (tnk_lvl2 < lowestLvl ) {
    measure();
    SIM800.println("AT+CNMI=2,2,0,0,0");
    delay(1000);
    SIM800.println("AT+CMGF=1");
    delay(500);
    SIM800.print("AT+CMGS=");
    SIM800.print("\"");
    SIM800.print(ph);
    SIM800.println("\"");
    delay(1000);
    SIM800.println("Water level too low");
    SIM800.println("Tank ID : 1");
    SIM800.print("Battery level: ");
    SIM800.println(batt_volt);
    SIM800.print("water level: ");
    SIM800.println(tnk_lvl2);
    SIM800.print("Tank Percentage full: ");
    SIM800.print(tnk_lvl);
    SIM800.println("%");
    SIM800.print("Tank Volume: ");
    SIM800.println(volume);
    delay(100);
    SIM800.println((char)26);
  }
  delay(900000);
}
void Serialcom() {
  delay(500);
  while (Serial.available())
  {
    SIM800.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while (SIM800.available())
  {
    Serial.write(SIM800.read());//Forward what Software Serial received to Serial Port
  }
}
void ReceiveMode() {
  SIM800.println("AT"); //If everything is Okay it will show "OK" on the serial monitor
  Serialcom();
  SIM800.println("AT+CMGF=1"); // Configuring TEXT mode
  Serialcom();
  SIM800.println("AT+CNMI=2,2,0,0,0"); //Configure the SIM800L on how to manage the Received SMS... Check the SIM800L AT commands manual
  Serialcom();
}
void Send_Data() {
  Serial.println("Sending Data...");     //Displays on the serial monitor...Optional
  SIM800.print("AT+CMGF=1\r");          //Set the module to SMS mode
  delay(100);
  SIM800.print("AT+CMGS=\"+254713297997\"\r");  //Your phone number don't forget to include your country code example +212xxxxxxxxx"
  delay(500);
  SIM800.print(Data_SMS);  //This string is sent as SMS
  delay(500);
  SIM800.print((char)26);//Required to tell the module that it can send the SMS
  delay(500);
  SIM800.println();
  Serial.println("Data Sent.");
  delay(500);
}
void measure()
{

  delay(100);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  Time = pulseIn(echo, HIGH);
  distanceCM = Time * 0.034;
  resultCM = distanceCM / 2;

  //tank water level
  tnk_lvl = map(resultCM, sensr_to_wtr, total_height, 100, 0);
  tnk_lvl2 = total_height - resultCM ;

  //battery voltage
  voltage = analogRead(A3);
  batt_volt1 = voltage / 103;
  batt_volt = batt_volt1 / 2;

  //tank volume computation for  rectangular based tank
  volume = lengt * width * tnk_lvl2;
  volume_cy = pi * radius * radius * tnk_lvl2;


  if (tnk_lvl > 100) tnk_lvl = 100;
  if (tnk_lvl < 0) tnk_lvl = 0;

}
