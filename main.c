#include "MKL25Z4.h"
int puls= 13;
int contador [7]={0, 1, 2, 3, 4, 5, 6};
int display[10][7]={
//   a  b  c  d  e  f  g
    {1, 1, 1, 1, 1, 1, 0},//0
    {0, 1, 1, 0, 0, 0, 0},//1
    {1, 1, 0, 1, 1, 0, 1},//2
    {1, 1, 1, 1, 0, 0, 1},//3
    {0, 1, 1, 0, 0, 1, 1},//4
    {1, 0, 1, 1, 0, 1, 1},//5
    {1, 0, 1, 1, 1, 1, 1},//6
    {1, 1, 1, 0, 0, 0, 0},//7
    {1, 1, 1, 1, 1, 1, 1},//8
    {1, 1, 1, 0, 0, 1, 1}//9
};
int i, j;
int main(void){
    SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;
    SIM->SCGC5|=SIM_SCGC5_PORTA_MASK;
    for(j=0; j<7; j++){
        PORTD->PCR[contador[j]]|=(1<<8);
        PTD->PDDR|=(1<<contador[j]);


    }
    PORTA->PCR[13]|=(1<<8)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
    PTA->PDDR&=~(1<<13);
    while(1){

            for (i = 0; i <10; i++){
            	if((PTA->PDIR&(1<<13))==0){
                for(j=0;j<7;j++){

                    if(display[i][j]==0){
                        PTD->PCOR|=(1<<contador[j]);
                    }else{
                        PTD->PSOR|=(1<<contador[j]);
                    }
                }
                for (int t = 7000000; t>0; t--);
            }
        }
    }
    return 0;
}
