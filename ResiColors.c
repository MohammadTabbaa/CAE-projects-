int num1,num2,num3,num4 =0;
int pot1,pot2,pot3,pot4;


  void WriteColor(int pin ,int r,int g,int b);
  void WriteColor(int pin,int r,int g,int b){
      analogWrite(pin,255-r);
      analogWrite(pin+1,255-g);
      analogWrite(pin+2,255-b);      
      }

  void numToColor(int pin ,int color){
    int r,g,b;
    switch(color)
    {
  case 0://"black"
  r=0;g=0;b=0;
  break;
  case 1://"brown"
  r=120;g=30;b=0;
  break;
  case 2://"red"
  r=255;g=0;b=0;
  break;
  case 3://"orange"
  r=255;g=75;b=0;
  break;
  case 4://"yellow"
  r=255;g=150;b=0;
  break;
  case 5://green
  r=0;g=255;b=0;
  break;
  case 6://"blue"
  r=0;g=0;b=255;
  break;
  case 7://"violet"
  r=125;g=0;b=200;
  break;
  case 8://"gray"
  r=30;g=30;b=30;
  break;
  case 9://"white"
  r=255;g=255;b=255;
  break;
  }
    WriteColor(pin,r,g,b);
    }    
int led1=2;
int led2=5;
int led3=8;
int led4=11;
int pin1=30;
int pin2=34;
int pin3=38;
int pin4=42;
 void numTo7Seg(int n,int pin){
    int q,w,e,r;
      switch(n)
      {
        case 0:
        q=0;w=0;e=0;r=0;break;
        case 1:
        q=0;w=0;e=0;r=1;break;
        case 2:
        q=0;w=0;e=1;r=0;break;
        case 3:
        q=0;w=0;e=1;r=1;break;
        case 4:
        q=0;w=1;e=0;r=0;break;
        case 5:
        q=0;w=1;e=0;r=1;break;
        case 6:
        q=0;w=1;e=1;r=0;break;
        case 7:
        q=0;w=1;e=1;r=1;break;
        case 8:
        q=1;w=0;e=0;r=0;break;
        case 9:
        q=1;w=0;e=0;r=1;break;
        }
      digitalWrite(pin,q );
      digitalWrite(pin+1,w);
      digitalWrite(pin+2,e);
      digitalWrite(pin+3,r);
    }
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
  }

void loop() {
  
  pot1=analogRead(A1);
  pot2=analogRead(A2);
  pot3=analogRead(A3);
  pot4=analogRead(A4);

  num1=map(pot1,0,1023,18,-1);
  num2=map(pot2,0,1023,18,-1);
  num3=map(pot3,0,1023,19,-1);
  num4=map(pot4,0,1023,18,-1);

Serial.println((num4*100+num3*10+num2*1)*10^num1);
  // put your main code here, to run repeatedly:
  numToColor(led1,num1);
  numToColor(led2,num2);
  numToColor(led3,num3);
  numToColor(led4,num4);
  numTo7Seg(num1,pin1);
  numTo7Seg(num2,pin2);
  numTo7Seg(num3,pin3);
  numTo7Seg(num4,pin4);
     
  
}
