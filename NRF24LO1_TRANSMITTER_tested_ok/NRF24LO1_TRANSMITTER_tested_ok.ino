#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const uint64_t pipes[1] = {0xF0F0F0F0E1LL};


void setup()
{
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(pipes[0]);
  radio.stopListening();
}

void loop()
{
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  
  delay(1000);
}
