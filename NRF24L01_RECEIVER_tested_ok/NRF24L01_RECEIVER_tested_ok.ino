#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const uint64_t pipes[1] = {0xF0F0F0F0E1LL};

void setup()
{
  while (!Serial);
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, pipes[0]);
  radio.startListening();

}

void loop()
{
  if (radio.available())
  {
    unsigned long text = 0;
    radio.read(&text, sizeof(text));

    Serial.println(text);
  }
}
