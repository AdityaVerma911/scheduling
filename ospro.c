#include <stdio.h>
 
// Defining pro details


int main()
{	
	struct pro 
	{	
    		int art, brt, cpt, wt, tat,hrt,com;
    		char name;
	} pcs[100],trp1;
	int m,o, t, sbt = 0,n,lc;
	char ch;
    	float awt = 0, awtt = 0,trp,hrn=-99;
	pcs[-1].cpt=0;
	printf("\nEnter the No. of processes :");
	scanf("%d",&n);
	for(m=0;m<n;m++)
	{
		printf("\tEnter the arrival time of %d pro :",m+1);
		scanf(" %d",&pcs[m].art);
	}
	for(m=0;m<n;m++)
	{
		printf("\tEnter the burst time of %d pro :",m+1);
		scanf(" %d",&pcs[m].brt);
	}

	// sorting according to Arrival Time
	for(m=0;m<n-1;m++)
	{
		for(o=m+1;o<n;o++)
		{
			if(pcs[m].art>pcs[o].art)
			{
				trp1=pcs[m];
				pcs[m]=pcs[o];
				pcs[o] = trp1;

			}
		}
		
	}

	for(m=0,ch ='A';m<n;m++,ch++){pcs[m].com = 0; sbt += pcs[m].brt; pcs[m].name=ch;}
	printf("\n  Process Arrival Burst\t Completion Turn-around-time Waiting  Highest Response Ratio" );
	for (t = pcs[0].art; t < sbt;)
	{	hrn=-99;
        	for (m = 0; m < n; m++) 
		{
            		if (pcs[m].art <= t && pcs[m].com != 1) 
			{
				trp = 1+((t - pcs[m].art) / pcs[m].brt);
	                	if (hrn < trp) 
				{ 
	                    		hrn = trp;
	                    		lc = m;
					pcs[lc].hrt=trp;
				}
            		}
        	}
		//printf("\n%d %d\n",lc,t);
		t += pcs[lc].brt;
		pcs[lc].cpt=t;	        
                pcs[lc].wt = t - pcs[lc].art - pcs[lc].brt;
                pcs[lc].tat = t - pcs[lc].art;
		awt+=pcs[lc].wt;
	        awtt += pcs[lc].tat;
		pcs[lc].com = 1;
		printf("\n   %c\t     %d\t    %d\t     %d\t\t  %d\t\t%d \t\t%d              ",pcs[lc].name,pcs[lc].art,pcs[lc].brt,pcs[lc].cpt,pcs[lc].tat,pcs[lc].wt,pcs[lc].hrt);
	}

printf("\n\t\tAverage Waiting Time : %f",awt/n);
printf("\n\t\tAverage Turn Around Time : %f",awtt/n);



return 0;
}
