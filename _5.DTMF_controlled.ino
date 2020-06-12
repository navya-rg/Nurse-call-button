int Q4=8;       
int Q3=9;       
int Q2=10;      
int Q1=11;      
char a='*';
char b='*';

void setup()                                              
{   Serial.begin(9600);
    pinMode(Q4,INPUT); 
    pinMode(Q3,INPUT);
    pinMode(Q2,INPUT);
    pinMode(Q1,INPUT);
}        
void loop()                                                                                   
{   
    int read[]={digitalRead(Q4),digitalRead(Q3),digitalRead(Q2),digitalRead(Q1)};                
   if(read[0]==0&&read[1]==0&&read[2]==0&&read[3]==1)        
    { b='1';
    }
    else if(read[0]==0&&read[1]==0&&read[2]==1&&read[3]==0)      
    { b='2';
    }
    else if(read[0]==0&&read[1]==0&&read[2]==1&&read[3]==1)    
    { b='3';
    }
    else if(read[0]==0&&read[1]==1&&read[2]==0&&read[3]==0)      
    { b='4';
    }
    else if(read[0]==0&&read[1]==1&&read[2]==0&&read[3]==1)      
    { b='5';
    }
    else if(read[0]==0&&read[1]==1&&read[2]==1&&read[3]==0)      
    { b='6';
    }
    else if(read[0]==0&&read[1]==1&&read[2]==1&&read[3]==1)      
    { b='7';
    }
    else if(read[0]==1&&read[1]==0&&read[2]==0&&read[3]==0)      
    { b='8';
    }
    else if(read[0]==1&&read[1]==0&&read[2]==0&&read[3]==1)      
    { b='9';
    }
    else if(read[0]==1&&read[1]==0&&read[2]==1 &&read[3]==0)       
    { b='0';
    }
    else if(read[0]==1&&read[1]==0&&read[2]==1&&read[3]==1)      
    { b='*';
      a='*';
    }
    if(a!=b && a=='*')
    {
        Serial.println(b);
        a=b;
    }       
}
