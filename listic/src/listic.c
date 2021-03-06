#include <stdio.h>
#include <stdlib.h>
#include "listic.h"
#include <inttypes.h>

void KreirajPrazanListic(LISTIC* ls)
{
	uint8_t i;

	for(i = 0 ; i < 12 ; i++)
	{
		ls->slobodno[i].poeni=-1;
		ls->slobodno[i].zakljucano=0;

		ls->gore[i].poeni=-1;		
		if(i != 12)
		{
			ls->gore[i].zakljucano=1;
		}else
		{
			ls->gore[i].zakljucano=0;
		}
		
		ls->gore_dole[i].poeni=-1;
		if(i != 12 && i != 0)
		{
			ls->gore_dole[i].zakljucano=1;
		}else
		{
			ls->gore_dole[i].zakljucano=0;
		}
		
		ls->dole[i].poeni=-1;
		if(i == 0)
		{
			ls->gore_dole[i].zakljucano=0;
		}else
		{
			ls->gore_dole[i].zakljucano=1;
		}
	}
}

/********************************************** pomocne * funkcije *************************************************************************
*/


uint8_t skala(const KOCKICE *ob)
{
	uint8_t i;
	uint8_t ret_vrednost = 0;
	
	for(i = 0; i < broj_kockica-2 ; i++)
	{
		if(ob->rezultat_bacanja[i+1] - ob->rezultat_bacanja[i] <= 0)
		{
			return 0;		
		}else
		{
			ret_vrednost = 1;	
		}		
	}
	return ret_vrednost;
}

uint8_t full(const KOCKICE *ob)
{
	return 0;
}

uint8_t racunaj_za_broj(uint8_t k)
{
	return k;
}


uint16_t racunaBodove(const KOCKICE* ob, uint8_t red )
{
	uint8_t i;
	uint16_t ret_vrednost = 0;
	for(i = 0; i < broj_kockica; i++)
	{
		if(red-1 < 6)
		{
			if(ob->rezultat_bacanja[i] == racunaj_za_broj(red))
			{
				ret_vrednost += racunaj_za_broj(red);
			}		
		
		}else if(red-1 == 6 || red-1 == 7)		//min i max
		{
			ret_vrednost += ob->rezultat_bacanja[i];
		}else if(red-1 == 8)				//skala
		{
			if(skala(ob) == 1 )
			{
				if(ob->rezultat_bacanja[0] == 1)
				{
					ret_vrednost = 30;
				}else
				{
					ret_vrednost = 40;  
				}
			}else
			{	
				ret_vrednost = 0;			
			}		
		}else if(red-1 == 9)				//full
		{
			if(full(ob) == 1 )
			{
				
				ret_vrednost = 30;
				
			}else
			{	
				ret_vrednost = 0;			
			}		
		}			
		
	}
	return ret_vrednost;
}

uint16_t upisiPoeneUPolje(LISTIC *ls, uint8_t red , uint8_t kolona)
{
	return 0;
}


