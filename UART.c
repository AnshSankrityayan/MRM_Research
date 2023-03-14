#include &quot;config.h&quot;
#define Baud_Calc 16000000UL/64
void UART_Init (long baud_rate){
float bps;
TRISCbits.TRISC6=1;
TRISCbits.TRISC7=1;
bps = ( (float) (Baud Calc) / (float) baud rate) - 1);
SPBRG= (int)bps;
TXSTAbits.CSRC = 0;
TXSTAbits.IX9 = 0;

TXSTAbits.IXEN = 1;
TXSTAbits. SYNC = 0;
TXSTAbits. BRGH = 1;
BAUDCONbits.BRG16 = 1;
RCSTAbits.SPEN=1;
RCSTAbits.CREN=I;
RCSTAbits.FERR=0;
RCSTAbits.ADDEN=1;
ROSTAbits.OFRR=0;
RCSTAbits.RX9=0;
Void UART_Write(char ch){
while(!TXIF);
TXREG=ch;
}
char UART_Read(){
if(OERR){
CREN=0;
CREN=1;
}
While(!RCIF);
Return RCREG;
}
Void UART_Write_text(char*st_print)
{
While(*st_print)
UART_Write(*st_print++);
}
void main (void)
{
TRISDbits.TRISDOmO;
PORTDbits.RDOm0;
UART_Init (9600);
UART_Write_text(“Welcome to MicroDigisofct”);
UART_Write_text(“Enter Value:”);
Int Enter_value;
While(1)
{
Enter_value=UART_Read();
If(Enter_value==’1’){
PORTDbits.RD0=1;
UART_Write_Text(“RED LED ON”);
UART_Write_Text(“Enter New Value=”0;
UART_Write(10);
}
If(Enter_value==’0’){
PORTDbits.RD0=0;
UART_Write_Text(“RED LED OFF”);

UART_Write_Text(“Enter New Value=”);
UART_Write(10);
}
}
}
