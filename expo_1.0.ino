#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define button_pin 2  // пин кнопки
#define button_pin 3
#define button_pin 4
#define relay_pin 6    // пин реле

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int a = 15;
int x = 1;
int b = 70;
int c = 280;


boolean butt_flag = 0;      // флажок нажатия кнопки
boolean butt_flag2 = 0;
boolean butt_flag3 = 0;

boolean butt;// переменная, харнящая состояние кнопки
boolean butt2;
boolean butt3;

boolean flag = 0;           // флажок режима
boolean flag2 = 0;
boolean flag3 = 0;

unsigned long last_press; // таймер для фильтра дребезга
unsigned long last_press2;
unsigned long last_press3;

unsigned long last_time;
unsigned long last_time2;
unsigned long last_time3;
void setup(){

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(relay_pin, OUTPUT);          // пин реле как выход

  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print(" www.desig-c.ru ");
  lcd.setCursor(0,1);  
lcd.print("   Redy to go! ");
}
 
void loop(){

  
 butt = !digitalRead(2);  // считать текущее положение кнопки

  if (butt == 1 && butt_flag == 0 && millis() - last_press > 300) {  // если кнопка НАЖАТА, до этого была была ОТПУЩЕНА
     
 
    butt_flag = 1;                    // запоминаем, что нажимали кнопку
    flag = !flag;                    
    last_press = millis();           

    digitalWrite(relay_pin, flag);    // подаём сигнал на пин реле / светодиода
  }
  if (butt == 0 && butt_flag == 1) {  // если кнопка ОТПУЩЕНА, и до этого была НАЖАТА
    butt_flag = 0;                    // запоминаем, что отпустили кнопку
 }

 butt = !digitalRead(2);  
  if (butt == 0 && butt_flag == 1 ) {  // если кнопка НАЖАТА, до этого была была ОТПУЩЕНА
  
    butt_flag = 1;                    
    flag = !flag;   }   
    {
 butt = !digitalRead(2);  

  if (butt == 1 && butt_flag == 1 ) {  // если кнопка НАЖАТА, до этого была была ОТПУЩЕНА
    butt_flag = 0;                    
    flag = !flag;      
 
  for(int a = 15;a>=0; a-=x){
     int  timer1 = 0;
       lcd.clear();
       lcd.setCursor(2,0);
    lcd.print("Timer");
    lcd.setCursor(11,0);
         lcd.print("sec");
         Serial.write ( a );    
         lcd.setCursor(8,0);
         timer1 =  a ;
       lcd.print( timer1 ); 
            delay (1000);
     
  
    }
     lcd.setCursor(0,1);
    lcd.print("      DONE !");
  
    digitalWrite(relay_pin, flag);    // подаём сигнал на пин реле / светодиода
  } }




  //вторая кнопка

  butt2 = !digitalRead(3);  // считать текущее положение кнопки

  if (butt2 == 1 && butt_flag2 == 0 && millis() - last_press2 > 300) {  // если кнопка НАЖАТА, до этого была была ОТПУЩЕНА
     
 
    butt_flag2 = 1;                    
    flag2 = !flag2;                     
    last_press2 = millis();            

    digitalWrite(relay_pin, flag2);   
  }
  if (butt2 == 0 && butt_flag2 == 1) {  
    butt_flag2 = 0;                    
 }

 butt2 = !digitalRead(3);  
  if (butt2 == 0 && butt_flag2 == 1 ) {  
    butt_flag2 = 1;                    
    flag2 = !flag2;   }   
    {
 butt2 = !digitalRead(3); 

  if (butt2 == 1 && butt_flag2 == 1 ) {  
    butt_flag2 = 0;      
    flag2 = !flag2;      
 
  for(int b = 70 ;b>=0; b-=x){
     int  timer2 = 0;
       lcd.clear();
       lcd.setCursor(2,0);
    lcd.print("Timer");
    lcd.setCursor(11,0);
         lcd.print("sec");
         Serial.write ( b );    
         lcd.setCursor(8,0);
         timer2 =  b ;
       lcd.print( timer2 ); 
            delay (1000);
    }
     lcd.setCursor(0,1);
    lcd.print("      DONE !");  
    digitalWrite(relay_pin, flag2);    
  }
  }

  // третья кнопка 


  butt3 = !digitalRead(4);  

  if (butt3 == 1 && butt_flag3 == 0 && millis() - last_press3 > 300) {    
 
    butt_flag3 = 1;                    
    flag3 = !flag3;                    
    last_press3 = millis();            

    digitalWrite(relay_pin, flag3);    
  }
  if (butt3 == 0 && butt_flag3 == 1) { 
    butt_flag3 = 0;                    
 }

 butt3 = !digitalRead(4);  
  if (butt3 == 0 && butt_flag3 == 1 ) {
  
    butt_flag3 = 1;                    
    flag3 = !flag3;   }   
    {
 butt3 = !digitalRead(4);

  if (butt3 == 1 && butt_flag3 == 1 ) {
    butt_flag3 = 0;                    
    flag3 = !flag3;      
 
  for(int c = 280;c>=0; c-=x){
     int  timer3 = 0;
       lcd.clear();
       lcd.setCursor(2,0);
    lcd.print("Timer");
    lcd.setCursor(11,0);
         lcd.print("sec");
         Serial.write ( c );    
         lcd.setCursor(8,0);
         timer3 =  c ;
       lcd.print( timer3 ); 
            delay (1000);
     
  
    }
     lcd.setCursor(0,1);
    lcd.print("      DONE !");
  
    digitalWrite(relay_pin, flag3);    
  } 
  }
  }
   
