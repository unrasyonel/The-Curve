/* ISO-6976

A simple program to calculate various calorific values based on the ISO 6976 standard documentation. A small group project.

2005 release of the document can be obtained from the following link:

https://annas-archive.org/md5/366fd8036a647a100f704adf6599b768

*/

#include <cstdio> 
#include <cmath>
#include <iostream>

#define mgconstant 8.3144621 //molar gas constant (R)=8.3144621
#define mair 28.96546 //molar mass of dry air


/* Every part referenced as 'see' is included in iso-6976 */

double negativeCheck(double a) { //its the handling of negative numbers.

	while(0 > a) {
		printf("\nEnter a valid number: ");
		scanf("%lf",&a);
		if (a > 0) break; 
	}
	return a;
}

double compressionFactor() {  // 1.0 (see: 6.2)
	double xj, sj;	                  
		printf("Enter the mole fraction's (xj) value: ");
			scanf("%lf",&xj);

		xj = negativeCheck(xj);	
		
		printf("Enter the  summation factor's' (sj) value:");
			scanf("%lf",&sj);	
	
	double result;
	result = 1 - (xj*xj*sj*sj);
	printf("Compression factor value: %lf\n\n",result);
	
	return result;
}

double grossMolar(){  //2.1 Calculation of molar gross calorific value (see: 7.1)
	double hcg;
	double xj;
	double value;
	printf("\nCalculation of Gross Calorific Value on a Molar Basis\n\n");
	printf("\nEnter the ideal gross molar basis calorofic value of component(hcg): ");
		scanf("%lf",&hcg);
	printf("Enter the value of mole fraction (xj):");
		scanf("%lf",&xj);	
			
	value = xj * hcg;
	printf("Gross Calorific Value on Molar Basis is %lf\n\n",value);
	
	return value;
}




double netCalValue(double hg) { //2.2 Calculation of molar net calorific value (see: 7.2)
	
	double x, b, hcg, result, result2 = 0, resultfinal, enthalpy;
	short int temperature, i, j;
	hcg = hg;
	
		
	printf("\n\nCalculation of net calorific value\n\n");
	printf("Enter the number of compenents:");
		scanf("%d",&j);
		
	j = negativeCheck(j); //checks if the number provided is negative
	
	for(i=1; i<=j ;i++){
	
	printf("Enter the mole fraction:");
	scanf("%lf",&x);
	printf("Enter the number of hydrogen atoms:");
	scanf("%lf",&b);
	
	b = negativeCheck(b); //checks if the number provided is negative
	
	printf("\nType one of the temperature:\n0'C"
	"\n15'C\n20'C\n25'C\n");
	scanf("%d",&temperature);
	
	if(temperature == 0 || temperature == 20 || temperature == 15 || temperature == 25
	|| temperature == 1 || temperature == 2 || temperature == 3 || temperature == 4) {
		if(temperature == 0 || temperature == 1) enthalpy = 45.064;
		else if(temperature == 15 || temperature == 2) enthalpy = 44.431;
		else if(temperature == 20 || temperature == 3) enthalpy = 44.408;
		else if(temperature == 25 || temperature == 4) enthalpy = 44.013;
			
			result =(x)*(b/2)*(enthalpy);
			printf("Subtotal: %lf\n",result);
			result2 = result2 + result;
			}
		}
		
			resultfinal = (hcg - result2);
			printf("\nFinal result of net calorific value on molar basis:%lf",resultfinal);
			return resultfinal;
		}
		
		
double grossMass(){	//3.1 Calculation of gross mass calorific value (see: 8.1)
	double xj, m, MolarMass;
	printf("\nCalculation of molar mass\n\n");
		
	printf("Enter the mole fraction:");
		scanf("%lf",&xj);
			
	printf("Enter the molar mass of the compenent:");
		scanf("%lf",&m);
		m = negativeCheck(m); //checks if the number provided is negative
			
	MolarMass = m * xj;		
	return MolarMass;
}

netMass(){	//3.2 Calculation of mass net calorific value (see: 8.2)
	double xj, m, NetMass = 0;
	int i, j;
	printf("\nEnter the number of compenents:");
		scanf("%d",&j);
		j = negativeCheck(j); //checks if the number provided is negative
	
	double u[j];
	
	for(i=1; i<=j; i++){
		printf("\nCalculation of molar mass:\n");
		printf("\nEnter the mole fraction:");
			scanf("%lf",&xj);
			xj = negativeCheck(xj);
			
		printf("Enter the molar mass of the compenent:");
			scanf("%lf",&m);
			m = negativeCheck(m); //checks if the number provided is negative
		NetMass = NetMass + (m *xj);		
		}
		
		return NetMass;
}

double idealGasGCV() {	//4.1 Calculation of ideal-gas gross calorific value (see: 9.1) 

	double volume, a, result = 0; //result is for grossMolar
	int answer;
	
	printf("\n\n1)Calculate the volume with formula( V=R*T/p)"
"\n2)Enter the volume manually");
	printf("\n\nSelect an option:");
		scanf("%d",&answer);
	
	if(answer == 1){
		int t,p;
		printf("\nEnter the absolute temparature:");
				scanf("%d",&t);
		
		printf("\nEnter the absolute pressure:");
				scanf("%d",&p);
		
		volume = (mgconstant*t)/p; 	//molar gas constant (R)=8.3144621 (defined)
	}
	
	else if(answer == 2){
	printf("Enter the volume of the gas:");
		scanf("%lf",&volume);
		volume = negativeCheck(volume); //checks if the number provided is negative
		}
	
	int j, i = 0;
			printf("\nEnter the number of compenents:");
				scanf("%d",&j);
				j = negativeCheck(j); //checks if the number provided is negative
		
		for(i=1; i<=j; i++){
			result = result + grossMolar();
				}
				
	a = (result/volume);
	
	printf("\n\nIdeal-gas gross calorific value is %lf",a);
	return a;
}

double idealGasNCV() {	//4.2 Calculation of ideal-gas net calorific value (see: 9.2)
	double a, net, volume, result = 0, finalresult;
	int answer, j, i = 0;
			printf("\nEnter the number of compenents:");
				scanf("%d",&j);
				j = negativeCheck(j); //checks if the number provided is negative
		
		for(i=1; i<=j; i++){
			result=result+grossMolar();
				}
		
		net=netCalValue(result);
		
		printf("\n\n1)Calculate the volume with formula( V=R*T/p)"
"\n\n2)Enter the volume manually");
	printf("\n\nSelect an option:");
		scanf("%d",&answer);

	if(answer == 1){
		int t,p;
		printf("\nEnter the absolute temparature:");
				scanf("%d",&t);
		
		printf("\nEnter the absolute pressure:");
				scanf("%d",&p);
		
		volume = (mgconstant*t)/p;	//molar gas constant (R)=8.3144621 (defined)
	}
	else if(answer == 2){
	printf("Whats the volume of the gas?:");
		scanf("%lf",&volume);
		volume = negativeCheck(volume); //checks if the number provided is negative
		}			

		a = net/volume; //final calculation
		printf("\n\nIdeal-gas net calorific value is: %lf",a);
		return a;
}

double realGasGCV(){	//4.3 Calculation of Real Gas Gross Calorific Value (see: 9.3)
	
	double volume, a, result;
	int answer;
	
	printf("\n\n1)Calculate the volume with formula( V=Z*R*T/p)"
"\n2)Enter the volume manually");
	printf("\n\nSelect an option:");
		scanf("%d",&answer);
	
	if(answer == 1){
		int t,p;
		printf("\nEnter the absolute temparature:");
				scanf("%d",&t);
		
		printf("\nEnter the absolute pressure:");
				scanf("%d",&p);
		
			int a,b;	//compression factor calculation
		printf("\nCompression factor calculation:\n\n");
		double result1;
		result1=0;
		printf("\nEnter the number of compenents:");
				scanf("%d",&b);
				b = negativeCheck(b); //checks if the number provided is negative
		
		for(a=1; a<=b; a++){
		result1 = result1 + compressionFactor();		
		}
		
		volume = result1 * mgconstant*t/p;	//molar gas constant (R)=8.3144621 (defined)
	}
		if(answer == 2){
			printf("Whats the volume of the gas?:");
				scanf("%lf",&volume);
				volume = negativeCheck(volume); //checks if the number provided is negative
		}
	
		
		printf("\nVolume:%lf",volume);
		int j,i=0;
			printf("\nEnter the number of compenents:");
				scanf("%d",&j);
				j = negativeCheck(j); //checks if the number provided is negative
		
		for(i=1; i<=j; i++){
			result = result + grossMolar();
				}
				
		a = (result / volume); //final calculation
	
	printf("\n\nIdeal-gas gross calorific value is %lf",a);
	return a;
}

double realGasNCV(){	//4.4 Calculation of Real-Gas Net Calorific Value (see: 9.4)
	double result,net,a,resultfinal,volume;
	
		int answer;
	
	printf("\n\n1)Calculate the volume with formula( V=Z*R*T/p)"
"\n2)Enter the volume manually");
	printf("\n\nSelect an option:");
		scanf("%d",&answer);
	
	if(answer == 1){
		int t,p;
		printf("\nEnter the absolute temparature:");
			scanf("%d",&t);
		
		printf("\nEnter the absolute pressure:");
			scanf("%d",&p);
		
			int a,b;	//compression factor calculation
			
		printf("\nCompression factor calculation:\n\n");
		
		double result1 = 0;
		result1=0;
		printf("\nEnter the number of compenents:");
			scanf("%d",&b);
		
		for(a=1; a<=b; a++){
		result1 = result1 + compressionFactor();		
		}
		
		volume = (result1*mgconstant*t)/p;	//molar gas constant (R)=8.3144621 	
	}
		if(answer == 2){
			printf("Whats the volume of the gas?:");
				scanf("%lf",&volume);
				volume = negativeCheck(volume); //checks if the number provided is negative
		}
	
			int j,i=0;
			printf("\nEnter the number of compenents:");
				scanf("%d",&j);
				j = negativeCheck(j); //checks if the number provided is negative
		
		for(i=1; i<=j; i++){
			result = result + grossMolar();
				}
		
		net = netCalValue(result);
	
	a = (net/volume);	//final calculation
	
	printf("\n\nIdeal-gas net calorific value is %lf",a);
	
	return a;
}

void idealRDG(double *);

idealGD(double m){	//5.2 Ideal Gas Density (see: 10.2)
		int answer;
		double volume,final;
	printf("\n\n1)Calculate the volume with formula( V=R*T/p)"
"\n2)Enter the volume manually");
	printf("\n\nSelect an option:");
		scanf("%d",&answer);
	
	if(answer == 1){
		int t,p;
		printf("\nEnter the absolute temparature:");
				scanf("%d",&t);
		
		printf("\nEnter the absolute pressure:");
				scanf("%d",&p);
		
		volume = (mgconstant*t)/p; 	//molar gas constant (R)=8.3144621 (defined)
	}
	
	else if(answer == 2){
		printf("Whats the volume of the gas?:");
			scanf("%lf",&volume);
			volume = negativeCheck(volume); //checks if the number provided is negative
			}
		
			final = m/volume;
	return final;
}

realRD(){	// 5.5 Real Gas Relative Density (see: 10.5)
	double g,result1,zair,temperature,final;
	int a,b;
	
		idealRDG(&g);
   			printf("\ng = %lf", g);
   	
    		
		result1 = 0;
		printf("\nEnter the number of compenents for CF:");
				scanf("%d",&b);
				b = negativeCheck(b); //checks if the number provided is negative
		for(a=1; a<=b; a++){
		result1 = result1 + compressionFactor();		
		}
		
		if(result1 > 1) {
			result1 = result1 -b +1;
		}
		
		printf("\n\nFinal Result of CF:%lf",result1);
				
			
		printf("\nType one of the temperature for Z(air):\n0'C\n"
	"15'C\n15.55'C\n20'C\n");
			scanf("%lf",&temperature);
		if (temperature == 0) zair=0.999419;
		else if (temperature == 15) zair=0.999595;
    	else if (temperature == 15.55) zair=0.999601;
    	else if (temperature == 20) zair=0.999695;
    	
		printf("Z(air)(t2,p2)=%lf",zair);
		
		final = (g*zair)/result1;
		printf("\n\nReal Gas Relative Density: %lf",final);
		return final;
}

realD(){	//5.6 Real Gas Density (see: 10.6)
	double result1 = 0,final;
	int a,b;
	
		printf("\nEnter the number of compenents for CF:");
				scanf("%d",&b);
				b = negativeCheck(b); //checks if the number provided is negative
		for(a=1; a<=b; a++){
		result1 = result1 + compressionFactor();		
		}
		
			if(result1>1) {
			result1 = result1 -b +1;
		}
		
			printf("\n\nFinal Result of CF:%lf",result1);
	
	double xj, m, molarresult = 0; //d0
	int q,w;
	
	printf("\nEnter the number of compenents:");
		scanf("%d",&w);
		w = negativeCheck(w); //checks if the number provided is negative
		
	double u[w];
		for(q=1; q<=w; q++){	//Calculation for M
		
			printf("\nCalculation of molar mass\n\n");
		
			printf("Enter the mole fraction:");
				scanf("%lf",&xj);
				xj = negativeCheck(xj); //checks if the number provided is negative
			
			printf("Enter the molar mass of the compenent:");
				scanf("%lf",&m);
				m = negativeCheck(m); //checks if the number provided is negative
		    
			u[q] = m*xj;
			molarresult = u[q] + molarresult;
			}
		double i;
		i = idealGD(molarresult);
		printf("\n\nIdeal Gas Density:%lf",i);
	
		final = i/result1;
		printf("\n\nReal Gas Density: %lf",final);
	
	return final;
}

void idealRDG(double *pg){//5.1 Calculation of ideal gas relative density (see:10.1)
	double xj, m, molarresult = 0;
	int q,w;
	
	printf("\nEnter the number of compenents:");
		scanf("%d",&w);
	double u[w];
	for(q=1; q<=w; q++){
		
			printf("\nCalculation of molar mass:\n");
		
			printf("Enter the mole fraction:");
				scanf("%lf",&xj);
			
			printf("Enter the molar mass of the compenent:");
				scanf("%lf",&m);
		    
			u[q] = m*xj;;
			molarresult = u[q] + molarresult;
			}
		
			printf("\nM-air (molar mass of dry air)'s  fixed reference composition value: 28.96546");
			
		*pg =molarresult/mair;
		printf("\n\nRelative Density of the Ideal Gas: %lf",*pg);

}

int main(){
	
	  printf("1- Compression factor\n\n"
           "2- Calculation of Calorific Value on a Molar Basis\n"
           "\t2.1- Gross Calorific Value\n"
           "\t2.2- Net Calorific Value\n\n"
           "3- Calculation of Calorific Value on a Mass Basis\n"
           "\t3.1- Gross Calorific Value\n"
           "\t3.2- Net Calorific Value\n\n"
           "4- Calculation of Calorific Value on a Volume Basis\n"
           "\t4.1- Ideal Gas Gross Calorific Value\n"
           "\t4.2- Ideal Gas Net Calorific Value\n"
           "\t4.3- Real Gas Gross Calorific Value\n"
           "\t4.4- Real Gas Net Calorific Value\n\n"
           "5- Calculation of Associated Properties\n"
           "\t5.1- Ideal Gas Relative Density\n"
           "\t5.2- Ideal Gas Density\n"
           "\t5.3- Ideal Gas Gross Wobbe Index\n"
           "\t5.4- Ideal Gas Net Wobbe Index\n"
           "\t5.5- Real Gas Relative Density\n"
           "\t5.6- Real Gas Density\n"
           "\t5.7- Real Gas Gross Wobbe Index\n"
           "\t5.8- Real Gas Net Wobbe Index\n");
	

	int number;
	printf("\n\nSelect a calculation's number (1/2/3/4/5):");
		scanf("%d",&number);
	
	switch(number){
		case 1: //1
		int a,b;
		double result1;
		result1 = 0;
		
		printf("\nEnter the number of compenents:");
				scanf("%d",&b);
				
				b = negativeCheck(b);
		
		for(a=1; a<=b; a++){
		result1 = result1 + compressionFactor();		
		}
			printf("\n\nFinal Result of CF:%lf",result1);
			
		break;
		
		case 2: //2	
	{
		
		int number2;
	printf("\t1- Gross Calorific Value\n"
           "\t2- Net Calorific Value\n\n");
           
	printf("\n\nSelect the next calculation's number:");
		scanf("%d",&number2);
		
		if(number2 == 1){ //2.1
				int i = 0,j;
				double 	result2 = 0;
				
			printf("\nEnter the number of compenents:");
				scanf("%d",&j);
				j = negativeCheck(j); //checks if the number provided is negative
			
			
			
			for(i=1; i<=j; i++){
			
				result2 = result2 + grossMolar();
			}
			printf("\n\nFinal Result:%lf",result2);
	
			
		}
		            
		else if(number2 == 2){ //2.2 Calculation of molar net calorific value (see: 7.2)
				int k = 0,l;
				double 	result2_2 = 0;
				
			printf("\nEnter the number of compenents:");
				scanf("%d",&l);
			
		for(k=1; k<=l; k++){
			result2_2 = grossMolar() + result2_2;
			}
		netCalValue(result2_2);
	}
	break;
}
		case 3: // 3 Calculation of Calorific Value on a Mass Basis
		{
		int number3;
		printf("\t3.1- Gross Calorific Value\n"
           "\t3.2- Net Calorific Value\n\n");
           
	printf("\n\nSelect the next calculation's number:");
		scanf("%d",&number3);
	
		if(number3 == 1){ //3.1 Calculation of gross mass calorific value (see: 8.1)
			double resultmolar = 0, resultmass = 0;
			int c,v;	
			printf("\nEnter the number of compenents:");
				scanf("%d",&v);
				v = negativeCheck(v); //checks if the number provided is negative
			
			int h[v],j[v]; // calculating gross molar value and gross mass value
			for(c=1; c<=v; c++){
			
			printf("\nFor %d. compenent:",c);
				h[c] = grossMolar();
					resultmolar = h[c] + resultmolar;
		
				j[c] = grossMass();
					resultmass = j[c] + resultmass;
			}
			double finalresult3 = resultmolar/resultmass;
			printf("\n\nFinal Result= %lf", finalresult3);
		}
		
		else if(number3 == 2){ //3.2 Calculation of mass net calorific value (see: 8.2)
			
			double resultmolar2 = 0,resultmass2 = 0,m,n;
			int q,w;	
			printf("\nEnter the number of compenents:");
				scanf("%d",&w);
				w = negativeCheck(w); //checks if the number provided is negative
			
			double u[w],molarresult,netmassresult,finalresult3_2=0;
			
			for(q=1; q<=w; q++){
			u[q] = grossMolar();
			molarresult = u[q] + molarresult;
			}
			
			n = netCalValue(molarresult);
				printf("\n\nCalculation of Molar Mass:\n");
			m = netMass();
			
			finalresult3_2 =n/m;
			printf("Final result for the net calorific value on a mass basis: %lf",finalresult3_2);
		}
		
		break;}
		
		case 4:  //Calculation of Calorific Value on a Volume Basis
		int number4;
		
		printf("\t4.1- Ideal Gas Gross Calorific Value\n"
           "\t4.2- Ideal Gas Net Calorific Value\n"
           "\t4.3- Real Gas Gross Calorific Value\n"
           "\t4.4- Real Gas Net Calorific Value\n\n");
		
		printf("\n\nSelect the next calculation's number:");
			scanf("%d",&number4);
		
		if(number4 == 1){ //4.1 Calculation of ideal-gas gross calorific value (see: 9.1) 
			idealGasGCV();
		}
		else if(number4 == 2){//4.2 Calculation of ideal-gas net calorific value (see: 9.2)
			idealGasNCV();
		}
		else if(number4 == 3){//4.3 Calculation of Real Gas Gross Calorific Value (see: 9.3)
			realGasGCV();
		}
		else if(number4 == 4){//4.4 Calculation of Real-Gas Net Calorific Value (see: 9.4)
			realGasNCV();
		}
		break;
		
		case 5:  //Calculation of Associated Properties
		{
	int number5;
		printf("\t5.1- Ideal Gas Relative Density\n"
           "\t5.2- Ideal Gas Density\n"
           "\t5.3- Ideal Gas Gross Wobbe Index\n"
           "\t5.4- Ideal Gas Net Wobbe Index\n"
           "\t5.5- Real Gas Relative Density\n"
           "\t5.6- Real Gas Density\n"
           "\t5.7- Real Gas Gross Wobbe Index\n"
           "\t5.8- Real Gas Net Wobbe Index\n");
		
		printf("\n\nSelect the next calculation's number:");
			scanf("%d",&number5);
		
		if(number5 == 1){ //5.1 Calculation of ideal gas relative density (see:10.1)
			double x;
			idealRDG(&x);
		}
		
		else if(number5 == 2){ //5.2 Ideal Gas Relative Density (see: 10.1)
			double xj,m,molarresult = 0;
	int q,w;
	printf("\nEnter the number of compenents:");
		scanf("%d",&w);
		w = negativeCheck(w); //checks if the number provided is negative
	double u[w];
		for(q=1; q<=w; q++){ //Calculation for M
		
			printf("\nCalculation of molar mass:\n");
		
			printf("Enter the mole fraction:");
				scanf("%lf",&xj);
				xj = negativeCheck(xj); //checks if the number provided is negative
			
			printf("Enter the molar mass of the compenent:");
				scanf("%lf",&m);
				m = negativeCheck(m); //checks if the number provided is negative
		    
			u[q] = m*xj;;
			molarresult = u[q] + molarresult;
			}
		double i;
		i = idealGD(molarresult);
		printf("\n\nIdeal Gas Density:%lf",i);
		}	
		
		else if(number5 == 3){ //5.3 Ideal Gas Gross Wobbe Index (see:10.3)
			double hvg,result,g;
			
			 idealRDG(&g);
   				 printf("\ng = %lf", g);
   			 g = sqrt((double)g);
    			printf("\ng = %lf", g);
			hvg = idealGasGCV();
			
			result = hvg/g;
			printf("\n\nIdeal Gas Gross Wobbe Index: %lf",result);
		}
		
		else if(number5 == 4){ //5.4 Ideal Gas Net Wobbe Index (see:10.4)
			double ncv,g,result;
			
			idealRDG(&g);
   				printf("\ng = %lf", g);
   			g = sqrt((double)g);
    			printf("\ng = %lf", g);
			ncv = idealGasNCV();
			
			result=ncv/g;
			printf("\n\nIdeal Gas Net Wobbe Index: %lf",result);
		}
		
			else if(number5 == 5){ //5.5 Real Gas Relative Density (see: 10.5)
			realRD();
		}
	
		else if(number5 == 6){ //5.6
			realD();
		}
		
		else if(number5 == 7){ //5.7
			double G,hvg,result;
				double g,result1,zair,temperature,final;
	int a,b;
	
		idealRDG(&g);
   			printf("\ng = %lf", g);
   	
    		
		result1 = 0;
		printf("\nEnter the number of compenents for CF:");
				scanf("%d",&b);
				b = negativeCheck(b); //checks if the number provided is negative
		for(a=1; a<=b; a++){
		result1 = result1 + compressionFactor();		
		}
		
		if(result1 > 1) {
			result1 = result1 -b +1;
		}
		
		printf("\n\nFinal Result of CF:%lf",result1);
				
			
		printf("\nType one of the temperature for Z(air):\n0'C\n"
	"15'C\n15.55'C\n20'C\n");
			scanf("%lf",&temperature);
		if (temperature == 0 || temperature ==  1) zair = 0.999419;
		else if (temperature == 15 || temperature ==  2) zair = 0.999595;
    	else if (temperature == 15.55 || temperature ==  3) zair = 0.999601;
    	else if (temperature == 20 || temperature ==  4) zair = 0.999695;
    	
		printf("Z(air)(t2,p2)=%lf",zair);
		
		final = (g*zair)/result1;
		printf("\n\nReal Gas Relative Density (G): %lf",final);
			
			final = sqrt(final);
			
		printf("\n sqrt G:%lf",final);
			
			hvg = realGasGCV(); 
				
			result = hvg/final;
			
			printf("\n\nReal Gas Gross Wobbe Index: %lf",result);
			}
			
			
			else if(number5 == 8){ //5.87
				
		double G,hvn,result;
		double g,result1,zair,temperature,final;
		
	int a,b;
	
		idealRDG(&g);
   			printf("\ng = %lf", g);
   	
		result1 = 0;
		printf("\nEnter the number of compenents for CF:");
				scanf("%d",&b);
				b = negativeCheck(b); //checks if the number provided is negative
		for(a=1; a<=b; a++){
		result1 = result1 + compressionFactor();		
		}
		
		if(result1 > 1) {
			result1 = result1 -b +1;
		}
		
		printf("\n\nFinal Result of CF:%lf",result1);
				
			
		printf("\nType one of the temperature for Z(air):\n0'C\n"
	"15'C\n15.55'C\n20'C\n");
			scanf("%lf",&temperature);
		if (temperature == 0) zair=0.999419;
		else if (temperature == 15) zair=0.999595;
    	else if (temperature == 15.55) zair=0.999601;
    	else if (temperature == 20) zair=0.999695;
    	
		printf("Z(air)(t2,p2)=%lf",zair);
		
		final = (g*zair)/result1;
		printf("\n\nReal Gas Relative Density (G): %lf",final);
			
			final=sqrt(final);
		printf("\n sqrt G:%lf",final);
			
			hvn = realGasNCV(); 
				
			result = hvn/final;
		
			printf("\n\nReal Gas Net Wobbe Index: %lf",result);
			}
			
		break;}
			
		default:
			printf("Error: Unknown value");
			break;
			}	
	return 0;
}
