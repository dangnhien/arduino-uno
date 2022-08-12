int ledpin = 13 ;
int y = 0 ;

void setup ( ) {

attachInterrupt ( 0, increment, falling);
Serial.begin (9600 );

}

void loop ( ) {

digitalWrite(ledpin, LOW) ;
delay(3000) ;
Serial.println(y, DEC) ;

}

void increment ( ) {
y++ ;
digitalWrite ( ledpin, HIGH) ;

}
