#include <VirtualWire.h>
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;
const int led6 = 7;
const int led7 = 8;
const int led8 = 9;

byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message

void setup()
{
  Serial.begin(9600);
  Serial.println("Device is ready");
 vw_setup(2000); // Bits per sec
  vw_rx_start(); // Start the receiver
pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
   pinMode(led6, OUTPUT);
    pinMode(led7, OUTPUT);
     pinMode(led8, OUTPUT);
}
void loop()
{
if (vw_get_message(message, &messageLength)) // Non-blocking
  {
    Serial.print("Received: ");
    for (int i = 0; i < messageLength; i++)
    {
      Serial.write(message[i]);
    
  
  if(message[i]=='2')
  {
    digitalWrite(led1,HIGH);
    Serial.println("led1");
  }
  else if(message[i]=='3')
  {
    digitalWrite(led2,HIGH);
  }
  else if(message[i]=='4')
  {
     digitalWrite(led3,HIGH);
  }
  else if (message[i]=='5')
  {
         digitalWrite(led4,HIGH);
  }
  else if(message[i]=='6')
  {
    digitalWrite(led5,HIGH);
  }
  else if(message[i]=='7')
  {
    digitalWrite(led6,HIGH);

  }
   else if(message[i]=='8')
  {
    digitalWrite(led7,HIGH);

  }
   else if(message[i]=='9')
  {
    digitalWrite(led8,HIGH);

    Serial.println();
}
 else if(message[i]=='1')
  {
    digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);
digitalWrite(led5,LOW);
   digitalWrite(led6,LOW);
digitalWrite(led7,LOW);
digitalWrite(led8,LOW);

 
}
Serial.println();
    }
  }
}  
