/*Tick Tack Boom umgestaltet von Mini Revollo, 
 * Januar 2018 im erfindergarden
 * Eine Art "Stadt, Land, Fluss" mit einer tickenden Bombe, 
 * die jederzeit hochgehen kann
 * Anzeige auf einem OLED und  Blinklicht, Sound über Buzzer oder Lautsprecher
 */
#include <Wire.h>  // Uno: scl->A5 SDA ->A4  Leonardeo:
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 32 
#define LOGO16_GLCD_WIDTH  128

const char t1[] PROGMEM = "Elektrogeraet";
const char t2[] PROGMEM = "Waffe";
const char t3[] PROGMEM = "Weltall";
const char t4[] PROGMEM = "Fahrzeug";
const char t5[] PROGMEM = "Behaelter";
const char t6[] PROGMEM = "Raeume";
const char t7[] PROGMEM = "Tatmotive";
const char t8[] PROGMEM = "Getraenke";
const char t9[] PROGMEM = "Tatort";
const char t10[] PROGMEM = "Fluchtfahrzeuge";
const char t11[] PROGMEM = "Sportgeraet";
const char t12[] PROGMEM = "Tanzstil";
const char t13[] PROGMEM = "Koerperteil";
const char t14[] PROGMEM = "Krankheit";
const char t15[] PROGMEM = "Kompliment";
const char t16[] PROGMEM = "X";
const char t17[] PROGMEM = "X";
const char t18[] PROGMEM = "X";
const char t19[] PROGMEM = "X";
const char t20[] PROGMEM = "X";
const char t21[] PROGMEM = "X";
const char t22[] PROGMEM = "X";
const char t23[] PROGMEM = "X";
const char t24[] PROGMEM = "X";
const char t25[] PROGMEM = "X";
const char t26[] PROGMEM = "X";
const char t27[] PROGMEM = "X";
const char t28[] PROGMEM = "X";
const char t29[] PROGMEM = "X";
const char t30[] PROGMEM = "X";
const char* const t[] PROGMEM = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12,
                                t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23,
                                t24, t25, t26, t27, t28, t29, t30};
const char b1[] PROGMEM = "PP";
const char b2[] PROGMEM = "GU";
const char b3[] PROGMEM = "LM";
const char b4[] PROGMEM = "SM";
const char b5[] PROGMEM = "WI";
const char b6[] PROGMEM = "BB";
const char b7[] PROGMEM = "CB";
const char b8[] PROGMEM = "OW";
const char b9[] PROGMEM = "TH";
const char b10[] PROGMEM = "FE";
const char b11[] PROGMEM = "AR";
const char b12[] PROGMEM = "HE";
const char b13[] PROGMEM = "MA";
const char b14[] PROGMEM = "KM";
const char b15[] PROGMEM = "DH";
const char b16[] PROGMEM = "PP";
const char b17[] PROGMEM = "GU";
const char b18[] PROGMEM = "LM";
const char b19[] PROGMEM = "SM";
const char b20[] PROGMEM = "WI";
const char b21[] PROGMEM = "BB";
const char b22[] PROGMEM = "CB";
const char b23[] PROGMEM = "OW";
const char b24[] PROGMEM = "TH";
const char b25[] PROGMEM = "FE";
const char b26[] PROGMEM = "AR";
const char b27[] PROGMEM = "HE";
const char b28[] PROGMEM = "MA";
const char b29[] PROGMEM = "KM";
const char b30[] PROGMEM = "X";
const char* const b[] PROGMEM = {b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, 
                                  b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, 
                                  b25, b26, b27, b28, b29, b30};
const char g1[] PROGMEM = "T O R N A I N T O";  //Notration
const char g2[] PROGMEM = "D E C E T K T E B";   //
const char g3[] PROGMEM = "B F I E R E I";  //Freibier
const char g4[] PROGMEM = "A B L A L D N H";  //Handball
const char g5[] PROGMEM = "P E E C H A P K K L";
const char g6[] PROGMEM = "W A H C T H S I C S";  //Waschtisch
const char g7[] PROGMEM = "E T R H E N T I U R";
const char g8[] PROGMEM = "I A L S B H N E";  //Seilbahn
const char g9[] PROGMEM = "F O S A T P N";
const char g10[] PROGMEM = "U U F R C B H A";  //Aufbruch
const char g11[] PROGMEM = "S E U R M N A P";  //Superman
const char g12[] PROGMEM = "S R A E E T G U I";  //Sauerteig
const char g13[] PROGMEM = "H E R L N T D A N I";//Hinterland
const char g14[] PROGMEM = "E W U K E I D";//Kuweide
const char g15[] PROGMEM = "K P N A E F R";//Krapfen
const char g16[] PROGMEM = "X";
const char g17[] PROGMEM = "X";
const char g18[] PROGMEM = "X";
const char g19[] PROGMEM = "X";
const char g20[] PROGMEM = "X";
const char g21[] PROGMEM = "X";
const char g22[] PROGMEM = "X";
const char g23[] PROGMEM = "X";
const char g24[] PROGMEM = "X";
const char g25[] PROGMEM = "X";
const char g26[] PROGMEM = "X";
const char g27[] PROGMEM = "X";
const char g28[] PROGMEM = "X";
const char g29[] PROGMEM = "X";
const char g30[] PROGMEM = "X";
const char* const g[] PROGMEM = {g1, g2, g3, g4, g5, g6, g7, g8, g9, g10, g11,
                                g12, g13, g14, g15, g16, g17, g18, g19, g20, 
                                g21,g22, g23, g24, g25,g26,g27,g28,g29,g30};

int laenge = 0;   //Länge der array thema
int laenge_bekannt = 0;   //Länge der array bekannt
int laenge_gemischt = 0;   //Länge der array gemischt
#define button_Pin  7  //Startbutton
#define LED 13           //Blinklicht rot
#define BUZZER 11         //Buzzer passiv
int button_state = 0;   //Status button
int menue = 0;          //menue 0, 1 = Anzeige Tehma, 2 = Bombe tickt  
long ratezeit = 60000;   //maximale Ratezeit, min 3000
long dauer = 0;          //Zeit zum Raten die per Zufall ausgewählt wird
long startzeit = 0;       //Startzeit
int buchstabe = 0;      //ASCII Code für a - z
int thema_nr = 0;       //Auswahl des Themas
int bekannt_nr = 0;        //Auswahl des bekannt
int gemischt_nr = 0;        //Auswahl des gemischt
int modus = 0;           //modus = Thema, Initialien oder Buchstabenmischung
char buffer[30];    //puffer um dem PROGMEM auszulesen

void setup() {
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(5000);
  
  pinMode(button_Pin, INPUT);
  digitalWrite(button_Pin, HIGH);   //internal Pullup
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  Serial.begin(9600);
  while(!Serial){
    ;
    }

  while(buffer[0] != 'X'){           //zählt die Themen durch
      strcpy_P(buffer, (char*)pgm_read_word(&(t[laenge]))); 
      laenge ++;
      Serial.println(buffer);
      Serial.println(laenge);
      }
  laenge = laenge - 2; 
  buffer[0] = 'Z';
  while(buffer[0] != 'X'){           //zählt die bekannt durch
      strcpy_P(buffer, (char*)pgm_read_word(&(b[laenge_bekannt]))); 
      laenge_bekannt ++;
      Serial.println(buffer);
      Serial.println(laenge_bekannt);
      } 
   laenge_bekannt = laenge_bekannt - 2; 
   buffer[0] = 'Z'; 
   while(buffer[0] != 'X'){           //zählt die gemischt durch
      strcpy_P(buffer, (char*)pgm_read_word(&(g[laenge_gemischt]))); 
      laenge_gemischt ++;
      Serial.println(buffer);
      Serial.println(laenge_gemischt);
      }     
   laenge_gemischt = laenge_gemischt - 2;
   
  display.clearDisplay();         //clear the screen 
  display.setCursor(10, 0);        // Set cursor to top-left
  display.setTextColor(WHITE);
  display.setTextSize(1);         // font size
  display.println(F("Tick, tack...Boom")); //Print the String
  display.setCursor(50, 8);        // Set cursor
  display.println(F("by")); //Print the String
  display.setCursor(20, 16);        // Set cursor 
  display.print(F("mini revollo")); 
  display.display();
  delay(5000);
  display.setCursor(0,24);        // Set cursor to top-left
  display.setTextSize(1);         // font
  //display.startscrollleft(0x08, 0x0F);
  display.print(F("drueck den Button")); 
  display.display();
  //delay(5000);
  //display.stopscroll();
}

void loop() {
    
  while(menue == 0){    
    modus = random(0,3);   //wählt den spielmodus aus
    buttonabfrage();
   }

  switch (modus) {
  case 0: //thema
    thema_nr = random(0,laenge);
    dauer = random(2000,ratezeit);
    buchstabe = random(65, 82);
    display.clearDisplay();
    display.setCursor(20, 4);
    strcpy_P(buffer, (char*)pgm_read_word(&(t[thema_nr]))); 
    display.println(buffer);
    display.setCursor(0, 22);
    display.println(F("mit:")); 
    display.setCursor(50,18);        // Set cursor
    display.setTextSize(2);
    display.write(buchstabe);
    display.setTextSize(1); 
    display.display();
    
    startzeit = millis();
    menue = 2;
    break;
  case 1: //bekannt
    bekannt_nr = random(0,laenge_bekannt);
    display.clearDisplay();           //clear the screen 
    display.setCursor(0, 0);
    display.println(F("Bekannter mit den")); //Print the String
    display.print(F("Initialen:")); //Print the String
    display.setCursor(73, 16);
    display.setTextSize(2);
    strcpy_P(buffer, (char*)pgm_read_word(&(b[bekannt_nr]))); 
    display.println(buffer);
    display.setTextSize(1); 
    display.display();
    
    dauer = random(2000,ratezeit);
    startzeit = millis();
    menue = 2;
    break;
  default:  //gemischt
    gemischt_nr = random(0,laenge_gemischt);
    display.clearDisplay();           //clear the screen 
    display.setCursor(0, 0);
    display.println(F("   gemischtes Wort")); //Print the String
    display.setCursor(0,20 );
    strcpy_P(buffer, (char*)pgm_read_word(&(g[gemischt_nr]))); 
    display.println(buffer);
    display.display();
    
    dauer = random(2000,ratezeit);
    startzeit = millis();
    menue = 2;
}
  
  while(menue == 2){
    countdown();  
  }
}

//------------------------ buttonabfrage ---------------------------------

void buttonabfrage(){
   if(digitalRead(button_Pin)== LOW && button_state == 0){
        button_state = 1; 
   }
   if(digitalRead(button_Pin) == HIGH && button_state == 1){
        button_state = 0;
        menue = menue + 1;
        if(menue > 2){
            menue = 0;
        }
   }
   delay(100);   //debounce
}
//----------------------- buttonabfrage ende --------------------------------
//----------------------- countdown -----------------------------------------
void countdown(){
    digitalWrite(LED, HIGH);
    tone(BUZZER,300,100); 
    digitalWrite(LED, LOW);
    delay(500);
    digitalWrite(LED, HIGH);
    tone(BUZZER,150,100); 
    digitalWrite(LED, LOW);
    delay(500);
    if(millis()>= startzeit + dauer){
      for(int i=0; i<=20; i++){
        tone(BUZZER,150);
        delay(10);
        tone(BUZZER,170);
        delay(10);
        tone(BUZZER,50);
        delay(10);
        tone(BUZZER,600);
        delay(10);
        tone(BUZZER,100);
        delay(10);
        tone(BUZZER,60); 
        delay(10);       
        }
      noTone(BUZZER);
      
      menue = 0;
    }
}
//------------------------- countdown ende ----------------------------------

