//Added bluetooth voice commands
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "BluetoothSerial.h"

SoftwareSerial mySoftwareSerial(22, 23); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

/* Check if Bluetooth configurations are enabled in the SDK
If not, then you have to recompile the SDK */
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;

String voice; // to read the voice commands
int RandomNumber; // to play random audio file

void setup()
{
  // DF/SD card code begin here
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  // Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(30);  // Set volume (0 to 30)
  // DF/SD card code ends here

  SerialBT.begin("Kaavya chatbot"); // Bluetooth name, if no name is given, default is 'ESP32'
  SerialBT.begin();
  RandomNumber=random(1,3);  
  myDFPlayer.play(RandomNumber);  // Play the first mp3
}

void loop()
{
  voice=""; 

  if (Serial.available())
  {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available())
  {
    voice = SerialBT.readString();
    voice.toLowerCase();
    Serial.println(voice);
  }

  if (voice.indexOf("your name") > 0)
  {    
    RandomNumber = random(3, 6);                   
    Serial.println("Inside");  
    voice = "";
    Serial.println(RandomNumber);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("address") > 0) || (voice.indexOf("stay") > 0) ) 
  { 
    voice = "";
    RandomNumber = random(6, 8);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("phone number") > 0) 
  {
    RandomNumber = random(9, 11);
    voice = "";
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("who asked you") > 0) 
  {
    RandomNumber = random(12, 14);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("gender") > 0) || (voice.indexOf("male") > 0) || (voice.indexOf("female") > 0) ) 
  { 
    RandomNumber = random(15, 17);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("read") > 0) 
  {
    RandomNumber = random(18, 20);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("yes") > 0) || (voice.indexOf("of course") > 0) || (voice.indexOf("surely") > 0) ) 
  {
    RandomNumber = random(21, 23);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("beautiful") > 0) || (voice.indexOf("cute") > 0) ) 
  {
    Serial.println(RandomNumber);
    RandomNumber = random(24, 26);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("married") > 0) || (voice.indexOf("maritial status") > 0) ) 
  {  
    RandomNumber = random(27, 29);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("friend") > 0) 
  {  
    RandomNumber = random(30, 32);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("google now") > 0) 
  {
    myDFPlayer.play(33);
  }
  else if (voice.indexOf("siri") > 0) 
  {
    myDFPlayer.play(34);
  }
  else if ( (voice.indexOf("game") > 0) || (voice.indexOf("sport") > 0) ) 
  {  
    RandomNumber = random(35, 37);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("depressed") > 0) || (voice.indexOf("sad") > 0) || ((voice.indexOf("not") > 0) && (voice.indexOf("good") > 0)) > 0 ) 
  {
    RandomNumber = random(38, 42);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("sing") > 0) && (voice.indexOf("song") > 0) ) 
  {
    RandomNumber = random(46, 47);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("you") > 0) && (voice.indexOf("human") > 0) ) 
  {  
    RandomNumber = random(48, 60);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("shut up") > 0) 
  {  
    RandomNumber = random(51, 53);
    Serial.println("inside");
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("bore") > 0) 
  {
    RandomNumber = random(55, 56);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("fact") > 0) || (voice.indexOf("interesting") > 0) || (voice.indexOf("some") > 0) ) 
  {
    RandomNumber = random(59, 68);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("joke") > 0) 
  {
    RandomNumber = random(69, 73);
    myDFPlayer.play(RandomNumber);
  }
  else if (( voice.indexOf("age") > 0) || (voice.indexOf("old") > 0) ) 
  {
    RandomNumber = random(74, 76);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("story") > 0) 
  {
    RandomNumber = random(77, 80);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("how are you") > 0) || (voice.indexOf("how do you do") > 0) ) 
  {  
    RandomNumber = random(80, 82);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("thank") > 0) 
  {
    myDFPlayer.play(84);
  }
  else if ( (voice.indexOf("sibling") > 0) || (voice.indexOf("brother") > 0) || (voice.indexOf("sister") > 0) ) 
  {  
    RandomNumber = random(85, 87);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("introduc") > 0) 
  { 
    RandomNumber = random(88, 89);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("love") > 0) 
  {
    RandomNumber = random(90, 92);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("mean") > 0) && (voice.indexOf("Eve") > 0) ) 
  {  
    RandomNumber = random(93, 95);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("boring") > 0) || (voice.indexOf("stupid") > 0) || (voice.indexOf("annoying") > 0) ) 
  {  
    myDFPlayer.play(96);
  }
  else if ( (voice.indexOf("owner") > 0) || (voice.indexOf("inventor") > 0) || (voice.indexOf("creat") > 0) ) 
  {
    myDFPlayer.play(97);
  }
  else if (voice.indexOf("hate") > 0) 
  {  
    myDFPlayer.play(98);
  }
  else if ( ((voice.indexOf("my") > 0) || (voice.indexOf("we") > 0)) && (voice.indexOf("friend") > 0) ) 
  {  
    myDFPlayer.play(99);
  }
  else if (voice.indexOf("can you") > 0) 
  {  
    RandomNumber = random(101, 103);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("can i") > 0) 
  {  
    RandomNumber = random(104, 106);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("you are") > 0) || (voice.indexOf("you're") > 0) ) 
  {  
    RandomNumber = random(107, 111);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("i dont") > 0) 
  {  
    RandomNumber = random(111, 114);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("i feel") > 0) 
  {  
    RandomNumber = random(116, 118);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("why don't you") > 0) || (voice.indexOf("why do not you") > 0) || (voice.indexOf("why dont you") > 0) ) 
  {  
    RandomNumber = random(119, 121);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("why can't i") > 0) 
  {
    RandomNumber = random(122, 126);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("are you") > 0) 
  {
    RandomNumber = random(127, 129);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("i can't") > 0) 
  {
    RandomNumber = random(130, 132);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("i am") > 0) || (voice.indexOf("i'm") > 0) ) 
  {
    RandomNumber = (133, 136);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("you ") > 0) 
  {
    RandomNumber = random(137, 139);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("what") > 0) || (voice.indexOf("how") > 0) || (voice.indexOf("where") > 0) ) 
  {
    RandomNumber = random(140, 149);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("i want") > 0)
  {
    RandomNumber = random(150, 154);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("name") > 0) 
  {
    RandomNumber = random(155, 157);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("cause") > 0) 
  {
    RandomNumber = random(158, 161);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("sorry") > 0) 
  {
    RandomNumber = random(162, 164);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("dream") > 0) 
  {
    RandomNumber = random(165, 168);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("always") > 0) 
  {
    RandomNumber = random(169, 172);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("think") > 0) 
  {
    RandomNumber = random(173, 176);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("alike") > 0) 
  {
    RandomNumber = random(177, 182);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("friend") > 0) 
  {
    RandomNumber = random(183, 187);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("computer") > 0) 
  {
    RandomNumber = random(188, 193);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("car") > 0) 
  {
    RandomNumber = random(193, 199);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("yes") > 0) || (voice.indexOf("yeah") > 0) ) 
  {
    RandomNumber = random(200, 203);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("maybe") > 0) 
  {
    RandomNumber = random(202, 208);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("your") > 0) 
  {
    RandomNumber = random(209, 211);
    myDFPlayer.play(RandomNumber);
  }
  else if (voice.indexOf("no") > 0) 
  {
    RandomNumber = random(212, 215);
    myDFPlayer.play(RandomNumber);
  }
  else if ( (voice.indexOf("hello") > 0) || (voice.indexOf("hi ") > 0) ) 
  {
    RandomNumber = random(220, 226);
    myDFPlayer.play(RandomNumber);
  }
  else if(voice != "")
  {
    RandomNumber = random(258, 260);
    myDFPlayer.play(RandomNumber);
  }

  if (myDFPlayer.available()) 
  {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
}

void printDetail(uint8_t type, int value)
{
  delay(1000);
  switch (type) 
  {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) 
      {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}
