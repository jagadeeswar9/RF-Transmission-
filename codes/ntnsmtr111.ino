#include <VirtualWire.h>
#include <Keypad.h>
#include<stdio.h>
const byte ROWS=3;
const byte COLS=3;
char hexakeys[ROWS][COLS]={
  { ' ','2',' '},
  {'4','5','6'},
  {' ','8',' '}
 
};
byte rowpins[ROWS]={2,3,4};
byte colpins[COLS]={5,6,7};
Keypad customkeypad=Keypad(makeKeymap(hexakeys),rowpins,colpins,ROWS,COLS);

void setup()
{
  Serial.begin(9600);
    // Initialize the IO and ISR
  vw_setup(2000); // Bits per sec
}

void loop()
{
   char customKey=customkeypad.getKey();
  if(customKey)
  {
    Serial.println(customKey);
  }
 
  if(customKey=='2')
  {
   send("2");
   Serial.println("two");
  }
  else if(customKey=='4')
{
  send("4");
  Serial.println("four");
  
}
else if(customKey=='5')
{
  send("5");
  Serial.println("five");
  
}
else if(customKey=='6')
{
  send("6");
  Serial.println("six");
  
}   
else if(customKey=='8')
{
  send("8");
  Serial.println("eight");
 
}   
  
}

void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}

