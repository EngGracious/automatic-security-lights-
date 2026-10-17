// C++ code
//PIN IDENTITY
 int static_variable =200;
  int lightValue;
const int inputVolts = A5; //INPUT
  const int outputVolts = 3; //OUTPUT
void setup()
{
  pinMode(inputVolts,INPUT);
  pinMode(outputVolts,OUTPUT);
  Serial.begin(9600);
 
}

void loop()
{
 
 lightValue = analogRead(inputVolts);
 if (lightValue <200){
   digitalWrite(outputVolts,LOW);
 }
 else{
   digitalWrite(outputVolts,HIGH);}
 
  


 Serial.print("lightValue");
Serial.print(lightValue);
 Serial.print(",");
Serial.print ("staticvariable");
 Serial.println( static_variable);
// Serial.print ("min:0.max:1023");
delay (1000);
}
// had undesired output and used this to troubleshhot by getting the values being received at a0
/*int inputVolts = A0;
void setup (){
  pinMode (inputVolts, INPUT);
  Serial.begin(9600);

}
void loop (){
  int lightValue;
  lightValue = analogRead(inputVolts);
  Serial.println(lightValue);
  delay (100);
}*/