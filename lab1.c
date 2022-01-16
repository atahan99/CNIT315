/*
Lab 1
Description : Pool and hot tube volume calculation. And calculating
how much would it cost to fill it with water.

Atahan Kucuk


*/



#include <math.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI acos(-1,0)
#endif


int main() {

    int result;
    do
    {
      
    
    /*declared variables*/
    
    int wht, dht, rht;
    int wp, dp, lp, dps, ldp, lsp, lwp;
    float vpt, vp1, vp2, vp3, vp4, vht ;
    float ght, gp , gt, price;


    /*User input and verification*/
    printf("Please enter the width  of the hot tub(8-14 feet)\n");
    scanf("%d", &wht);
    while (wht < 8 || wht > 14)
    {
        printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 8 AND 14 FEET!!!!\n");
        printf("Please enter the width  of the hot tub(8-14 feet)\n");
        scanf("%d", &wht);
    }
    
    
    printf("Please enter the depth of the hot tub (3-5 feet)\n");
    scanf("%d", &dht);
    while (dht < 3 || dht > 5) 
    {
        printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 3 AND 5 FEET!!!!\n");
        printf("Please enter the depth of the hot tub (3-5 feet)\n");
        scanf("%d", &dht);
    }


    printf("Please enter the depth of the shallow end of the pool (0-5 feet)\n");
    scanf("%d",&dps);
    while (dps < 0 || dps > 5)
    {
        printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 0 AND 5 FEET!!!!\n");
        printf("Please enter the depth of the shallow end of the pool (0-5 feet)\n");
        scanf("%d",&dps);
    }
    

    printf("Please enter the depth of the deep end of the pool (6-15 feet)\n");
    scanf("%d", &dp);
    while (dp  < 6 || dp >15)
    {
        printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 6 AND 15 FEET!!!!\n");
        printf("Please enter the depth of the deep end of the pool (6-15 feet)\n");
        scanf("%d", &dp);
    }
    
    printf("Please enter the width of the pool (15-30 feet)\n");
    scanf("%d", &wp);
    while (wp < 15 || wp > 30)
    {
        printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 15 AND 30 FEET!!!!\n");
        printf("Please enter the width of the pool (15-30 feet)\n");
        scanf("%d", &wp);
    }
    
    printf("Please enter the length of the pool (35-70 feet)\n");
    scanf("%d", &lp);
    while (lp < 35 || lp > 70)
    {
         printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 35 AND 70 FEET!!!!\n");
         printf("Please enter the length of the pool 35-70 feet\n");
        scanf("%d", &lp);
    }
    int lp3, lp2 ;
    lp3 = lp * 1/3;
    lp2 = lp * 1/2;
    printf("Please enter the length of walk in for the pool (5 feet minimum to 1/3 of pool length)\n");
    scanf("%d", &lwp);
    while (lwp < 5 ||  lwp > lp3  )
    {
        printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 5 FEET AND 1/3 OF POOL LENGTH!!!!\n");
        printf("Please enter the length of walk in for the pool (5 feet minimum to 1/3 of pool length)\n");
        scanf("%d", &lwp);
    }
    
    printf("Please enter the length of the deep end of the pool (12 feet minimum to 1/2 of pool length) \n");
    scanf("%d", &ldp);
    while (ldp < 12 || ldp > lp2 )
    {
        printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 12 FEET AND 1/2 OF POOL LENGTH!!!!\n");
        printf("Please enter the length of the deep end of the pool (12 feet minimum to 1/2 of pool length) \n");
        scanf("%d", &ldp);
    }
    
    printf("Please enter the lenght of the shallow end of the pool (10 feet minimum to 1/2 of the pool lenght)\n");
    scanf("%d", &lsp);
    while (lsp < 10 || lsp > lp2 )
    {
        printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 10 FEET AND 1/2 OF POOL LENGTH!!!!\n");
        printf("Please enter the lenght of the shallow end of the pool (10 feet minimum to 1/2 of the pool lenght)\n");
        scanf("%d", &lsp);
    }
    


    /*Calculation of hot tub volume and gallon  of water it needs*/
    rht = wht/2;
    vht = (pow(rht, 2) * (dht-0.5) * (22/7)) ;
    ght = vht *7.481 ;

    /*Calculation of Pool volume and gallon of water it needs*/
    vp1 = wp * (dp-0.5) * ldp ;
    vp2 = wp * lsp * (dp-0.5) ;
    vp3 = wp * (lp - (ldp + lsp + lwp)/2) * ((dp-0.5 )+ (dps-0.5));
    vp4 = wp * ((dp-0.5) * lwp )/2;
    vpt = vp1 + vp2 + vp3 + vp4;
    gp = vpt * 7.481;
    /* gt is the total gallon amount*/ 
    gt = gp+ght;
    price = gt * 4 * 0.07;

    /*Final outputs*/
    printf("\n Pool Dimensions(feet)");
    printf("\nDepth of the shallow end :%d ", dps);
    printf("\nDepth of te deep end : %d", dp);
    printf("\nWidth of the pool : %d", wp);
    printf("\nLenght of the pool : %d", lp);
    printf("\nLenght of the walk-in : %d",lwp);
    printf("\nLenght of shallow end : %d", lsp);
    printf("\nLenght of deep end : %d ", ldp);
    printf("\nWidth of the hot tub: %d",wht);
    printf("\nDepth of the hot tub: %d", dht);
    printf("\nPool Volume");
    printf("\nTotal volume of pool: %f",vpt);
    printf("\nGallons of water to fill : %f" ,gp );
    printf("\nHot Tub Volume");
    printf("\nTotal volume of hot tub: %f", vht);
    printf("\nGallons of water to fill: %f", ght);
    printf("\nTotal gallons for both: %f", gt);
    printf("\nTotal cost for both : $%f", price);

    
    printf("\nDo you want to calculate another pool and hot tub setup (1 for yes / 2 for no ) ?\n");
    scanf("%d",&result);
    
    } while (result == 1 );

    
    return 0;
}