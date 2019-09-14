
#include <IRremote.h>

int a=8;
int b=9;
int c=10;
int d=11;
int REC = 6;
 IRrecv irrecv(REC);
decode_results results;

void setup()
{
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}

void loop()
{
  if (irrecv.decode(&results))
    {
     Serial.println(results.value, HEX);
     irrecv.resume();    }
   // front
    if(results.value==0x1FE10EF)
    {
      digitalWrite(a,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,LOW);
    }
    // back
    if(results.value==0x1FE40BF)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,HIGH);
    }
    // left
     if(results.value==0x1FE20DF)
    {
      digitalWrite(b,LOW);
      digitalWrite(a,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
    }
    // right
     if(results.value==0x1FE609F)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(c,LOW);
    }
    // stop
    if(results.value==0x1FEA05F)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
    }
}
