#include <LiquidCrystal.h>               //library for LCD interface
#include <SPI.h>                         //library for SPI communication for SD card
#include <SD.h>                          // library for SD card interface

File myFile;                             //Declaring files for .txt files in SD cards
File myFile1;                            //


int val = 0; 
int val1 = 0; 
int val2 = 0; 
int val3 = 0; 
int inPin = 3;     
int inPin1 = 5;
int inPin2 = 6;
int k=0,yup=0,uk=0,out=0,count=0;
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  
  
void setup()
{
pinMode(inPin, INPUT);              //Declaring the reuired port pins as Input or output
pinMode(inPin1, INPUT);             //
pinMode(inPin2, INPUT);             //  
pinMode(2, OUTPUT);                 //
pinMode(7, OUTPUT);                 //
pinMode(8, OUTPUT);                 //  
pinMode(9, OUTPUT);                 //
pinMode(10, OUTPUT);                //

    long int b=1;
    Serial.begin(9600);               //starting the USART communication
    while (!Serial) {                 //waiting for communication to start  
    
    }
  lcd.begin(16,2);                   //initialising LCD display with 16 columns and 2 row

  if (!SD.begin(4)){                                //if the sd card is not detected
    lcd.clear();                                    //
    delay(100);                                     //    
    lcd.print("SD-Card failed");                    //
    delay(3000);                                    //  
    lcd.clear();                                    //  
    delay(100);                                     //
    lcd.print("Enter GR no.");                      //
    delay(1000);                                    //
    lcd.setCursor(0, 1);                            //
    Serial.println("Initialization Failed!");       //
  }
    
  
}

void loop()                          //starting the loop
{
watt:                                //  a goto function from line no. 694

char m[7]={'0','0','0','0','0','0','0'}, fail[70];   //initialising the arrays
int w=0,k=0;  

if (w==0)                            //to run the condition only once
{
lcd.print("Enter Password");
w++;                                 //-----''----------
}
lcd.setCursor(0, 1);


digitalWrite(inPin,HIGH);             //making all the three column pins high
digitalWrite(inPin1,HIGH);            //
digitalWrite(inPin2,HIGH);            //
delay(10);

int c=0,q=0,d=0,i=0,j=0,uk=0;

back:                                   // a goto function from line no. 702
     
digitalWrite(7,LOW);                    // making 1st row pin low
digitalWrite(2,HIGH);                   //remaining as it is
digitalWrite(9,HIGH);                   //
digitalWrite(10,HIGH);                  //
val = digitalRead(inPin);               //accepting the inputs from the 3 columns
val1 = digitalRead(inPin1);             //
val2 = digitalRead(inPin2);             //


//first row...

if (val==LOW )               //first column  (reset pin)
{
goto watt;                   //goto line 57
}
 
else if (val1==LOW )         //second column  (button '0')
{    
  m[c]='0';                  //putting the value in the array as '0'
  c++;                       //incrementing for next input
  k=c;                       //variable k for putting the '*' on lcd display                     
  lcd.clear();
  for (q=0;q<k;q++)
  {
    lcd.print("*");          //printing '*'
  }
  
  k=k+1;
  lcd.setCursor(0, k);       //setting the cursor of the lcd to next position to print '*'
  j++;                       //incrementing the count to become 7, as the password is of 7 digits
 
  delay(300);                //preventing repeatative acception of the input, when the button is pressed only once
}


else                    // second row
{


digitalWrite(7,HIGH);
digitalWrite(2,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);     
val = digitalRead(inPin);     
val1 = digitalRead(inPin1);    
val2 = digitalRead(inPin2);


if (val==LOW )                  //first column
{
m[c]='7';
c++;
lcd.clear();
k=c;
for (q=0;q<k;q++)
{
lcd.print("*");
}

k=k+1;
lcd.setCursor(0, k);

j++;
delay(300);
}

 
else if (val1==LOW )          //second column
{    
m[c]='8';
c++;
lcd.clear();
k=c;
for (q=0;q<k;q++)
{
lcd.print("*");
}

k=k+1;
lcd.setCursor(0, k);
j++;
delay(300);
}

 
else if (val2==LOW )              //third column
{

m[c]='9';
c++;
lcd.clear();
k=c;
for (q=0;q<k;q++)
{
lcd.print("*");
}

k=k+1;
lcd.setCursor(0, k);
j++;
delay(300);

} 


else                                //third row
{

digitalWrite(7,HIGH);
digitalWrite(2,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);     
val = digitalRead(inPin);
val1 = digitalRead(inPin1);    
val2 = digitalRead(inPin2);


if (val==LOW )                    //first column
{
m[c]='4';
c++;
lcd.clear();
k=c;
for (q=0;q<k;q++)
{
lcd.print("*");
}
k=k+1;
lcd.setCursor(0, k);
j++;
delay(300);
} 


else if (val1==LOW )                //second column
{
m[c]='5';
c++;
lcd.clear();
k=c;
for (q=0;q<k;q++)
{
lcd.print("*");
}

k=k+1;
lcd.setCursor(0, k);
j++;
delay(300);
} 


else if (val2==LOW )                  //third column
{
m[c]='6';
c++;
lcd.clear();
k=c;
for (q=0;q<k;q++)
{
lcd.print("*");
}

k=k+1;
lcd.setCursor(0, k);

j++;
delay(300);
} 


else                                  //forth column
{

digitalWrite(7,HIGH);
digitalWrite(2,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);     
val = digitalRead(inPin);  
val1 = digitalRead(inPin1);    
val2 = digitalRead(inPin2);

if (val==LOW )                        ////first column
{
m[c]='1';
c++;
lcd.clear();
k=c;
for (q=0;q<k;q++)
{
lcd.print("*");
}

k=k+1;
lcd.setCursor(0, k);

j++;
delay(300);
}

 
else if (val1==LOW )                    //second column
{
m[c]='2';
c++;
lcd.clear();
k=c;
for (q=0;q<k;q++)
{
lcd.print("*");
}
k=k+1;
lcd.setCursor(0, k);

j++;
delay(300);
} 


else if (val2==LOW )                      //third column
{
m[c]='3';
c++;
lcd.clear();
k=c;
for (q=0;q<k;q++)
{
lcd.print("*");
}

k=k+1;
lcd.setCursor(0, k);

j++;
delay(300);
} 


else 
{  
digitalWrite(8,LOW); 
}

}

}

}
////////////////////////////////////////////////////////////////

//procedure for restoring the passwords in the sd card when the sd card not detected 

myFile1 = SD.open("test1.txt",FILE_WRITE);            //opening the text file in the sd card

  if (myFile1)                                        
  {
     if(yup==1)                                      //checking the flag for condition of restoring the passwords 
    {
       int sep=0;
       for (i=0;i<(uk-1);i++)                        //restoring no. of passwords equal to passwords entered(uk) 
       { 
         myFile1.print(fail[i]);                     //writing the data of the gr numbers to the SD card, line by line
         sep++;
         if((sep%7)==0)
         {
            myFile1.print("\n");                     //
         }
       }
       myFile1.print("\n");                           //
       uk=0;
       yup=0;
    }
  }

   myFile1.close();                                   //closing the text file
///////////////////////////////////////////////////////////////

ghari:

if (j==7)                                             //after entering all seven characters, program enters in this condition 
{
  
  k=0;
  myFile = SD.open("test.txt",FILE_WRITE);            //opening the text file in the sd card to read the data from it (to compare the passwords present in it) 

  if (myFile)                                         //if it is opened successfully 
  {  
    myFile.close();
    }
    else
    {
    }
  myFile = SD.open("test.txt");                       //opening the text file
  if (myFile) 
  {
    
int f=0,r=0;    
int n=0,y=0,s=0,v=9,x=0,a=18;
char e[188],g[188],h[188],d;                          //arrays for storing and comparing the entered data and data inside the sd card   
    
while (myFile.available())                            //if the file is opened successfully
{
anna:                                                 //a goto function
x=0;

 if(f==a)
 {
 while (v<a)
 {
 g[v]=e[v]; 
 v++;
 }

v=v-9;
 for (n=0;n<7;n++)
 {
if (g[v]==m[n])
{  
  x++;
  v++;
}
 } 
v=v-7;

if (x==7)
{
  y=0;
  for (n=v;n<a;n++)
  {
    h[y]=g[n];
  y++;
  }
  
for (n=0;n<7;n++)  
{
Serial.print(h[n]);
} 
goto swatt;                                             //jump directly to goto function swatt: 
}

else
{
  
  y=0;
  for (n=v;n<a;n++)
  {
    h[y]=g[n];
  y++;
  }
  
}
 
 a=a+9;
  break;
 }
    
   d=myFile.read();
    e[s]=d;
    f++;
    s++;
    
}

if (a<=180)                                       //check until all 20 passwords with 9 characters are checked 
{
  goto anna;
}

lcd.clear();
delay(100);
lcd.setCursor(0,0);
lcd.print("Access Denied");
lcd.setCursor(0,1);
lcd.print("Wrong Password!!");
c=0;
count=2;
delay(3000);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Enter Password");
j=0;  
Serial.print("Password is wrong");
goto errr;

swatt:

lcd.clear();
delay(100);
   digitalWrite(8,HIGH);
   lcd.print("Access Granted");
   c=0;
//digitalWrite(8,HIGH);
   //delay(10000);
k=0;   
   delay(3000);
   digitalWrite(8,LOW);
   
 lcd.setCursor(0, 1); 
 lcd.print("Enter Password");
lcd.setCursor(0, 1);
j=0;
int i;  
for (i=0;i<7;i++)
  { 
    Serial.print(h[i]);   
  }
       
    myFile.close();

//8888888888888888888888888888888888888888888888888888888888888888888888

  myFile1 = SD.open("test1.txt", FILE_WRITE);                           //opening the text file

  if (myFile1)                                                          //if opened successfully
  {
   /* 
    if(yup==1)
    {
       int sep=0;
       for (i=0;i<(uk-1);i++)
       { 
         myFile1.print(fail[i]);
         sep++;
         if((sep%7)==0)
         {
            myFile1.print("\n");
         }
     }
       myFile1.print("\n");
       uk=0;
       yup=0;
    }
    */
  for (i=0;i<7;i++)                                                   //writting the correctly entered password to the text file in sd card
  { 
    myFile1.print(h[i]);   
  }
     myFile1.print("\n");
    myFile1.close();                                                //closing the file
   
  } 
  else {
        
 }
  myFile1 = SD.open("test1.txt");
  if (myFile1) {
    
      while (myFile1.available()) {
      Serial.write(myFile1.read());                                 //for watching the result on serial monitor
    }
    
    myFile1.close();
  } else {
    
    Serial.println("error opening test.txt");
  }

errr:

if(r==100)
{
Serial.print("Password is wrong");
}

  } 
  
  
  
  
  else                                                      //if sd card is not detected
  {
    //int count=0;  
    if (count==1)                                            //cheking the flag from line number 656
    {    
        char check[7]={'1','7','1','0','3','9','9'};          //the unique password stored in an array
        
    int item=0,data=0,qr=0;
    
    while(qr!=7)                                              //comparing the 7 elements in the array
    {
    if (check[item]==m[item])                                 //checking each and every element in the entered password with the unique password 
    {
     ++item;
     data=item;
    }
    qr++;
    }
    
     if (data==7)                                             // if the enetered password is matched successfully
     {
       
       lcd.clear(); 
       delay(100);
       lcd.print("correct");
       digitalWrite(8,HIGH);                                  //opening the latch for 3 seconds  
       delay(3000);
       digitalWrite(8,LOW);
       
     lcd.setCursor(0, 1); 
     lcd.print("password please");
     lcd.setCursor(0, 1);
    
    count=0;
    //out=1;
    //break;
    }
    
    else                                                      //if the password is not matched 
    {
       
       lcd.clear();
       delay(100);
       lcd.print("wrong one");
       delay(3000);
       lcd.setCursor(0, 1);
       lcd.print("password please");
       lcd.setCursor(0, 1);
    
    }
    
    
    
    
    
    }
    
    
    else if(count==0)                                             //when the program enters the else part from line number 548,
    {                                                              //initially the count =0, hence the program, enters this condition first
     
//using the 2D array for simplicity
      
      char o[15][7]={{'1','7','1','0','3','1','1'},                //the entered password is compared with these many passwords
                       {'1','7','1','0','3','1','2'},
                       {'1','7','1','0','3','1','3'},
                       {'1','7','1','0','3','2','4'},
                       {'1','7','1','0','3','3','6'},
                       {'1','7','1','0','3','8','9'},
                       {'1','7','1','0','3','4','5'},
                       {'1','7','1','0','3','2','8'},
                       {'1','7','1','0','3','5','6'},
                       {'1','7','1','0','3','7','7'},
                       {'1','7','1','0','3','4','4'},
                       {'1','7','1','0','3','7','1'},
                       {'1','7','1','0','3','3','5'},
                       {'1','7','1','0','3','6','9'},
                       {'1','7','1','0','3','1','4'}};
    
    int item=0,data=0,qr=0;
    
     for(i=0;i<15;i++)                                //for changing the first dimension of the 2D array
    {
    qr=0,item=0,data=0;  
    while(qr!=7)                                      //checking all the 7 numbers of the password
    {
    if (o[i][item]==m[item])                          //checking each and every element in the array
    {
     ++item;
     data=item;
    }
    qr++;
    }
    
     if (data==7)                                     // if the password is matched successfully with the above passwords,  
     {
    
        
      yup=1;                                          //setting flag for line number 335
      int rk=0;
      while(rk!=7)                                    //saving the correctly entered password in an array (which is used to store the epasswords back to sd card when detected)
      {
      fail[uk]=m[rk];
      rk++;
      uk++;
      }
    count=1;                                          //setting the flag for line number 535
    out=1;
    
    lcd.clear();
    delay(100);
    lcd.print("ok...");
    delay(3000);
    lcd.setCursor(0, 1);
       lcd.print("password please");
       lcd.setCursor(0, 1);
    //break;
    goto baher;                                                  //for breaking out of the loop when matched successfully
    }
    
    //     Serial.println("error opening test.txt");
    if(out==1)
    {
      out=0;
      break;
    }
    
    }
    
    
    if(data!=7)
    {
    lcd.clear();
    delay(100);
    lcd.print("plz enter GR");
    delay(1000);
    lcd.setCursor(0, 1);
      // lcd.print("password please");
       //lcd.setCursor(0, 1);
    }
    
      }

else if(count==2)                                     //from line no. 356
{
  goto ghari;
}
        
    baher:   
       goto watt;
}

}
if (j>7)
{
  goto watt;
}
  goto back;                                      //end of one eteration of a loop, returning to line number 77

}


