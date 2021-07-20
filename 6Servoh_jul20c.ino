String readString;
int x=90, y=90, z=90, p=90, w=90, n=90; 
#include <Servo.h> 
Servo myservoa, myservob, myservoc, myservod, myservoe, myservof;

void setup() 
{
  Serial.begin(9600);


  myservoa.attach(8); 
  myservob.attach(9); 
  myservoc.attach(10);
  myservod.attach(11); 
  myservoe.attach(12);
  myservof.attach(13); 
  myservoa.write(x);
  myservob.write(y);
  myservoc.write(z);
  myservod.write(n);
  myservoe.write(w);
  myservof.write(p);
}

void loop() 
{
  if (Serial.available())  
  {
    char m = Serial.read();
    if (m == '/') 
    {
      if (readString.length() >1) 
      {
        Serial.println(readString);

        int temp = readString.toInt();
        
          Serial.print("writing Angle: ");
          Serial.println(temp);
          if(readString.indexOf('a') >=0)
          {
            if (temp>x)
            {
              for (int i=x; i<temp; i++)
              {
                myservoa.write(i);
                delay(10);
              }
              x=temp;
            }
            else 
            {
            for (int i=x; i>temp; i--)
              {
                myservoa.write(i);
                delay(30);
              }
            }
            x=temp;
         }
//////////////////////////////////////////////////////////////////////////////         
          if(readString.indexOf('b') >=0)
          {
            if (temp>y)
            {
              for (int i=y; i<temp; i++)
             { myservob.write(i);
              delay(10);
             }
              y=temp;
            }
            else 
            {
            for (int i=y; i>temp; i--)
             { 
              myservob.write(i);
              delay(10);
             }
              y=temp;
          }
         }
///////////////////////////////////////////////////////////////////////
          if(readString.indexOf('c') >=0) //myservoc.write(n);
          {
            if (temp>z)
            {
              for (int i=z; i<temp; i++)
              {myservoc.write(i);
              delay(10);}
              z=temp;
            }
            else 
            {
            for (int i=z; i>temp; i--)
             { 
              myservoc.write(i);
              delay(10);
              }
              z=temp;
            }
         }
         /////////////////////////////////////////////////////  
           if(readString.indexOf('e') >=0)
          {
            if (temp>w)
            {
              for (int i=w; i<temp; i++)
             { myservoe.write(i);
              delay(10);
             }
              w=temp;
            }
            else 
            {
            for (int i=w; i>temp; i--)
             { 
              myservoe.write(i);
              delay(10);
             }
              w=temp;
          }
         }

/////////////////////////////////////////////////////  
           if(readString.indexOf('f') >=0)
          {
            if (temp>n)
            {
              for (int i=n; i<temp; i++)
             { myservof.write(i);
              delay(10);
             }
              n=temp;
            }
            else 
            {
            for (int i=n; i>temp; i--)
             { 
              myservof.write(i);
              delay(10);
             }
              n=temp;
          }
         }
/////////////////////////////////////////////////////
         if(readString.indexOf('d') >=0)
          {
            if (temp>p)
            {
              for (int i=p; i<temp; i++)
              {
                myservod.write(i);
                delay(10);
              }
              p=temp;
            }
            else 
            {
            for (int i=p; i>temp; i--)
              {
                myservod.write(i);
                delay(30);
              }
            }
            p=temp;
         }

       readString="";
      }
    }  
    else 
    {     
      readString += m;
    }
  }
}
