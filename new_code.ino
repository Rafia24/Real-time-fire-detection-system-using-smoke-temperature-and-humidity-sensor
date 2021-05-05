#define gaspin 3
#define temppin A0
#define humiditypin A1

int redLED = 13;
int greenLED = 2;
int buzzer = 5;

int gas;
float humidityread,tempread,rh,humiditydata;
String gas_str,temp_str,hum_str;


int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;



void setup() {
  // put your setup code here, to run once:
  
 
  pinMode(gaspin, INPUT);
  pinMode(temppin, INPUT);
  pinMode(humiditypin, INPUT);
  pinMode (redLED, OUTPUT);
  pinMode (greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  


}

void loop() {
  // put your main code here, to run repeatedly:
  delay(200);
  gas = digitalRead(gaspin);


  tempread = analogRead(temppin);
  float val = (tempread/1024.0)*5000;
  float tempdata=val/10;
//
//  
  humidityread = analogRead(humiditypin);
  rh=((humidityread/1024.0)-0.1515)/0.00636;
  float true_rh=(rh)/(1.0546-0.00216*tempdata);


  if(gas==HIGH){
    gas_str="Smoke Detected. Fire Alert!";
    digitalWrite(redLED,HIGH);
    delay(50);
    digitalWrite(greenLED,LOW);
    delay(50);
    tone(buzzer,1000,500);
    delay(50);
    noTone(buzzer);
    
    
    
  }else{
    gas_str="No Smoke Detected";
    digitalWrite(greenLED,HIGH);
    delay(50);
    digitalWrite(redLED,LOW);
    delay(50);
    
  }

  if(tempdata>=57){
    temp_str = "Temperature is too high!";
    Serial.println(temp_str);
    }
    
  if(true_rh>=80){
    hum_str = "Humidity exceeded normal condition!";
    Serial.println(hum_str);
    }


  Serial.println();
  Serial.println();
  Serial.println("Temperature : "+String(tempdata));
  Serial.println("Humidity : "+String(true_rh));
  
 
 
  
  Serial.println(gas_str);





}
