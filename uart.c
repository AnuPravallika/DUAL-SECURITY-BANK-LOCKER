//uart.c
#include <LPC21xx.h>
#include "defines.h"
#include "types.h"
#include "uart_defines.h"

void Init_UART0(void)
{
	//cfg p0.0 & p0.1 as txd0& rxd0 respectively
	PINSEL0|=0x00000005;
	//cfg uart for 8N1,& activate DLAB bit
	U0LCR=1<<DLAB_BIT|WORD_LEN_SEL;
	//cfg baudrate 
	U0DLL=LOADVAL;
	U0DLM=LOADVAL>>8;
	//deactivate DLAB bit;
	CLRBIT(U0LCR,DLAB_BIT);
	
}

void U0_TxChar(u8 sByte)
{
	//place byte to transmitted into THR sfr
	U0THR=sByte;
	//wait until transmitter empty status
	while(READBIT(U0LSR,TEMT_BIT)==0);	
}	

u8 U0_RxChar(void)
{
	//wait until data recvd status
	while(READBIT(U0LSR,DR_BIT)==0);
	//read & return recv data
	return U0RBR;
}

void U0_TxStr(s8 *s)
{
	while(*s)
		U0_TxChar(*s++);
}

void U0_TxU32(u32 n)
{
	s32 i=0;
	u8 a[10];
	if(n==0)
	{
		U0_TxChar('0');
	}
  else
  {
		while(n!=0)
		{
			a[i++]=(n%10)+48;
			n/=10;
		}
		for(--i;i>=0;i--)
		{
			U0_TxChar(a[i]);
		}
  }		
}

void U0_TxS32(s32 n)
{
	if(n<0)
	{
		U0_TxChar('-');
		n=-n;
	}
	U0_TxU32(n);
}

void U0_TxF32(f32 f,u32 nDP)
{
	u32 n,i;
	if(f<0.0)
	{
		U0_TxChar('-');
		f=-f;
	}
	n=f;
	U0_TxU32(n);
	U0_TxChar('.');
	for(i=0;i<nDP;i++)
	{
		f=(f-n)*10;
		n=f;
		U0_TxChar(n+48);
	}		
}

s8 * U0_RxStr(void)
{
	static s8 s[100];
	s32 i=0;
	while(1)
	{
		s[i]=U0_RxChar();
		U0_TxChar(s[i]);
		if((s[i]=='\n')||(s[i]=='\r'))
		{
			s[i]='\0';
			break;
		}
		i++;
	}
	return s;
}
