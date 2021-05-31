#include<stdio.h>
#include<string.h>
#define MAX_IME 30
#define MAX_IGRACA 20


typedef struct Igrac{
	char ime[MAX_IME];
	float visina;
	float tezina;
	int minut;
	int gol;
	int ass;
	int autogol;
	int zuti;
	int crveni;
	int bod;
}fudbaler;
fudbaler mvp;

int br_igraca=0;

int upis(FILE *f,fudbaler *i);
void ispis(FILE *f,fudbaler *i,int n)
{
	int a;
	printf("\n\t+--------------------+-----+-----+-----+----+----+-----+-----+-----+"); //20 5 5 
	printf("\n\t|    Ime i prezime   |  V  |  T  |  G  | AS | AG |  Z  |  C  |  B  |");
	printf("\n\t+--------------------+-----+-----+-----+----+----+-----+-----+-----+");
}


main()
{
	fudbaler igraci[MAX_IGRACA];
	FILE *f=fopen("igraci.txt","r");
	if(f==NULL){
		printf("GRESKA.");
		return 26;
	}
	
	while(upis(f,&igraci[br_igraca]))
		{
			br_igraca++;			
		}
	int k=0;
	ispis(f,&igraci[br_igraca],br_igraca);
	while(k!=br_igraca)
	{
		printf("\n\t|   %-17s|%5.1f|%5.1f| %2d  | %2d | %2d | %3d | %3d | %3d |",igraci[k].ime,igraci[k].visina,igraci[k].tezina,igraci[k].gol,igraci[k].ass,igraci[k].autogol,igraci[k].zuti,igraci[k].crveni,igraci[k].bod);
		k++;
	}
	printf("\n\t+--------------------+-----+-----+-----+----+----+-----+-----+-----+");
	printf("\n\t|Igrac turnira je:                                                 |");
	printf("\n\t|%35s sa %d bodova.\t           |",mvp.ime,mvp.bod);
	printf("\n\t+------------------------------------------------------------------+");
	printf("\n\t| V - Visina		 T - Tezina    	M - Odigranih minuta       |");
	printf("\n\t| G - Broj datih golova	AS - Broj asistencija AG - Broj autogolova |");
	printf("\n\t| C - Zutih kartona      C  - Crvenih kartona UB - Ukupno bodova   |");
	printf("\n\t+------------------------------------------------------------------+");

}


int upis(FILE *f,fudbaler *i)
{
	fscanf(f,"%s%f%f%d%d%d%d%d%d",i->ime,&(i->visina),&(i->tezina),&(i->minut),&(i->gol),&(i->ass),&(i->autogol),&(i->zuti),&(i->crveni));
	int min,goal,asis,self,yel,red;
	if(i->minut<=200)
		min=1;
	else
		if(i->minut>200 && i->minut<=400)
			min=2;
		else min=3;
	goal=i->gol*5;
	asis=i->ass*3;
	self=i->autogol*(-2);		
	yel=i->zuti*(-1);
	red=i->crveni*(-3);
	i->bod=min+goal+asis+self;
	if(i->bod>mvp.bod) mvp=*i;
	return !feof(f);
}
