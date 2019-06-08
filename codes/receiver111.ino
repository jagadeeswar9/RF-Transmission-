#include <VirtualWire.h>
#include "Arduino.h"
const int m1n=3; 
const int m2p=4; 
const int m2n=5; 
const int m1p=2; 
byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message

void setup ( )
{
Serial.begin( 9600 ) ; 
Serial.println("Device is ready");
  // Initialize the IO and ISR
  vw_setup(2000); // Bits per sec
  vw_rx_start(); // Start the receiver

pinMode ( m1p , OUTPUT) ;
pinMode ( m1n , OUTPUT) ;
pinMode ( m2p , OUTPUT) ;
pinMode ( m2n , OUTPUT) ;
}
void loop ( ) 
{
if (vw_get_message(message, &messageLength)) // Non-blocking
  {
    Serial.print("Received: ");
    for (int i = 0; i < messageLength; i++)
    {
      Serial.write(message[i]);
    
  
  if(message[i]==2)
  {
digitalWrite( m1p , HIGH) ;
digitalWrite( m1n , LOW) ;
digitalWrite( m2p , HIGH) ;
digitalWrite( m2n , LOW) ;
}
else if(message[i]==8) 
{
//press 8
digitalWrite( m1p , LOW) ;
digitalWrite ( m1n , HIGH) ;
digitalWrite( m2p , LOW) ;
digitalWrite( m2n , HIGH) ;
}
else if(message[i]==4)
{ 
//press 4  
digitalWrite( m1p , HIGH) ;
digitalWrite ( m1n , LOW) ;
digitalWrite( m2p , LOW) ;
digitalWrite( m2n , LOW) ;
}
else if (message[i]==6) {
//press 6
digitalWrite( m1p , LOW) ;
digitalWrite ( m1n , LOW) ;
digitalWrite( m2p , HIGH) ;
digitalWrite( m2n , LOW) ;
}
else if(message[i]==5)
{
//press 5
digitalWrite( m1p , LOW) ;
digitalWrite( m1n , LOW) ;
digitalWrite( m2p , LOW) ;
digitalWrite( m2n , LOW) ;
}
  }
    Serial.println();
}
}

