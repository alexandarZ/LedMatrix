#include<SPI.h>

#define NUMBER_OF_DEVICES 4
#define CS_PIN 2

#define MAX7219_REG_NOOP         0x0
#define MAX7219_REG_DIGIT0       0x1
#define MAX7219_REG_DIGIT1       0x2
#define MAX7219_REG_DIGIT2       0x3
#define MAX7219_REG_DIGIT3       0x4
#define MAX7219_REG_DIGIT4       0x5
#define MAX7219_REG_DIGIT5       0x6
#define MAX7219_REG_DIGIT6       0x7
#define MAX7219_REG_DIGIT7       0x8
#define MAX7219_REG_DECODEMODE   0x9
#define MAX7219_REG_INTENSITY    0xA
#define MAX7219_REG_SCANLIMIT    0xB
#define MAX7219_REG_SHUTDOWN     0xC
#define MAX7219_REG_DISPLAYTEST  0xF

byte my_sprite[8];

char serial_str[512];
char serial_chr;
int  serial_ind;
int  sprite_ind;

void send_byte(const byte device, const byte reg, const byte data)
{
  int spiregister[NUMBER_OF_DEVICES];
  int spidata[NUMBER_OF_DEVICES];

  for (int i = 0; i < NUMBER_OF_DEVICES; i++)
  {
    spidata[i] = (byte)0;
    spiregister[i] = (byte)0;
  }

  spiregister[device] = reg;
  spidata[device] = data;

  digitalWrite(CS_PIN, LOW);

  for (int i = 0; i < NUMBER_OF_DEVICES; i++) {
    SPI.transfer (spiregister[i]);
    SPI.transfer (spidata[i]);
  }

  digitalWrite (CS_PIN, HIGH);
}

void init_matrix()
{
  pinMode(CS_PIN, OUTPUT);

  SPI.begin ();
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV128);

  for (byte device = 0; device < NUMBER_OF_DEVICES ; device++) {
    send_byte (device, MAX7219_REG_SCANLIMIT, 7);   // show all 8 digits
    send_byte (device, MAX7219_REG_DECODEMODE, 0);  // using an led matrix (not digits)
    send_byte (device, MAX7219_REG_DISPLAYTEST, 0); // no display test
    send_byte (device, MAX7219_REG_INTENSITY, 0);   // character intensity: range: 0 to 15
    send_byte (device, MAX7219_REG_SHUTDOWN, 1);    // not in shutdown mode (ie. start it up)
  }
}

void set_intensity(const byte intensity)
{
  for (byte i = 0; i < NUMBER_OF_DEVICES; i++)
  {
    send_byte(i, MAX7219_REG_INTENSITY, intensity);
  }

}

void clear_display()
{
  byte val = 0;

  //Device
  for (byte device = 0; device < NUMBER_OF_DEVICES; device++)
  {
    //Column
    for (byte column = 1; column < 9; column++)
    {
      //Value
      send_byte(device, column, val);
    }
  }

}

void set_sprite(byte device,byte sprite[8])
{
  byte col;
  
  for(byte i=0;i<8;i++)
  {
    col = (i%8)+1;
    send_byte(device, col, sprite[7-i]);
  }
  
}

void setup()
{
  Serial.begin(115200);

  init_matrix();
  clear_display();

  serial_ind=0;
  sprite_ind=0;
}

void loop()
{
  
   while (Serial.available()) 
   {
    delay(3);
    
    if (Serial.available() >0) {
      
      serial_chr = Serial.read();
      
      if(serial_chr==';')
      {
        Serial.print("RX:" );
        Serial.print(serial_str);

        byte value = 0;

        for(int i=0;i<8;i++)
        {
          if(serial_str[i]=='1')
          {
            value+=pow(2,i);
          }
        }

        Serial.print(" Sprite[");
        Serial.print(sprite_ind);
        Serial.print("] = ");
        Serial.println(value,HEX);
        
        my_sprite[sprite_ind]=value;
        sprite_ind++;
        
        serial_ind=0;
        memset(serial_str,0,512);  
      }
      else
      {
        serial_str[serial_ind] = serial_chr;
        serial_ind++;
      }
      
    } 
  }

  if(sprite_ind==8)
  {
    set_sprite(0,my_sprite);
    
    memset(my_sprite,0,8);
    sprite_ind=0;

    Serial.println();
  }

}








