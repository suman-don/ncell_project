#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clr() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear"); // Linux/Mac
    #endif
}

void suman(){
	getchar();
}

int main() {
    char code[10];
    char numberCode[10];
    int balance = 0, choice, sapaati, exitEnter = 0;
    int oneday = 30, sevenday = 100, thirtyday = 1000;
    int onevoice = 40, sevenvoice = 150, thirtyvoice = 1200;
    char phoneNumber[] = "9709420496";
    // pack store
    int dataPack1 = 0, dataPack2 = 0, dataPack3 = 0;
    int voicePack1 = 0, voicePack2 = 0, voicePack3 = 0;
    char dataPack1Time[50] = "",dataPack2Time[50]= "",dataPack3Time[50]= "";
    char voicePack1Time[50] = "",voicePack2Time[50]= "",voicePack3Time[50] = "";
    
    //timing function 
  time_t t;
   
    

    // file handling method
    FILE *file = fopen("balance.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", 
               &balance);
        fclose(file);
    } else {
        balance = 100;
    }

    // Welcome message
    printf("\n                                                     Welcome to Ncell Pack!!!\n\n\n\n\n");
    printf("                                                     Press Enter to start...");
    suman();
    clr();  

    // Enter code prompt
    printf("\n\n\n\n                                                          CODE: 17123\n");
    printf("\n\n                                         1                   2                       3\n\n");
    printf("                                         4                   5                       6\n\n");
    printf("                                         7                   8                       9\n\n");
    printf("                                         *                   0                       #\n\n");
    printf("                                                           Call                         \n\n");

    printf("                                             Enter a code: ");
    scanf("%s", code);
    clr();  

    if (strcmp(code, "17123") == 0) {
        do {
            clr();
            printf("\n\n\n\n\n\n                                                     Select an option:\n");
            printf("                                                     1. Balance Inquiry\n");
            printf("                                                     2. Saapati\n");
            printf("                                                     3. Data Pack\n");
            printf("                                                     4. Voice Pack\n");
            printf("                                                     5. Check Number\n");
            printf("                                                     6. Pack Checking\n");
            printf("                                                     7. Exit\n");
            printf("                                             Enter your choice: ");
            scanf("%d", &choice);
            clr();

            switch (choice) {
                case 1:
                    printf("\n\n\n\n\n\n                                                     Your Available Balance: %d Rs\n", balance);
                    break;
                case 2:
                
                	printf("\n\n\n                                                   Maximum limit is: 200Rs!!!");
                    printf("\n\n\n\n\n\n                                                     Enter Saapati amount: ");
                    scanf("%d", &sapaati);
                    if(sapaati <= 200){
                    	balance += sapaati; 
                    clr();
                    printf("\n\n\n\n\n\n                                                     Total balance: %d Rs\n", balance);
					 }   
					else {
						clr();
						printf("\n\n\n\n\n                                              You cannot able to load more than 200rs !!!\n");
					}
                    
                    break;
                case 3:
                    printf("\n\n\n\n\n\n                                                     Select Data Pack:\n");
                    printf("                                                     1. 1 Day 1GB Data @30Rs\n");
                    printf("                                                     2. 7 Days 7GB Data @100Rs\n");
                    printf("                                                     3. 30 Days 40GB Data @1000Rs\n");
                    printf("                                                Enter your choice: ");
                    int pack;
                    scanf("%d", &pack);
                      
                       time(&t);
                    
                    if ((pack == 1 && balance >= oneday) ||
                        (pack == 2 && balance >= sevenday) ||
                        (pack == 3 && balance >= thirtyday)) {
                        if (pack == 1) { 
						balance -= oneday; 
						dataPack1 = 1;
						strcpy(dataPack1Time,ctime(&t));
						 }
                        else if (pack == 2) { 
						balance -= sevenday; 
						dataPack2 = 1;
						strcpy(dataPack2Time,ctime(&t));
						 }
                        else { 
						balance -= thirtyday;
						 dataPack3 = 1;
						 strcpy(dataPack3Time,ctime(&t));
						  }

                        clr();
                        printf("\n\n\n\n\n\n                                                 Data pack activated! Remaining Balance: %d Rs\n", balance);
                    } else if((pack ==1)<(pack ==0) || (pack ==3)<(pack ==4)){
                    	printf("\n\n\n\n\n\n                                                 Invaild select please select right option!!!");
					} 
					else {
                    	clr();
                        printf("\n\n\n\n\n\n                                                    Insufficient balance!\n");
                    }
                    break;
                case 4:
                    printf("\n\n\n\n\n\n                                                     Select Voice Pack:\n");
                    printf("                                                     1. 1 Day voice-pack @40Rs\n");
                    printf("                                                     2. 7 Days voice-pack @150Rs\n");
                    printf("                                                     3. 30 Days voice-pack @1200Rs\n");
                    printf("                                                  Enter your choice: ");
                
					scanf("%d", &pack);
                     
                      time(&t);

                    if ((pack == 1 && balance >= onevoice) ||
                        (pack == 2 && balance >= sevenvoice) ||
                        (pack == 3 && balance >= thirtyvoice)) {
                        if (pack == 1) { balance -= onevoice;
						 voicePack1 = 1;
						 strcpy(voicePack1Time,ctime(&t));
						  }
                        else if (pack == 2) { 
						balance -= sevenvoice; 
						voicePack2 = 1;
						strcpy(voicePack2Time,ctime(&t));
						 }
                        else { 
						balance -= thirtyvoice;
						 voicePack3 = 1;
						 strcpy(voicePack3Time,ctime(&t));
						  }

                        clr();
                        printf("\n\n\n\n\n\n                                                     Voice pack activated! Remaining Balance: %d Rs\n", balance);
                    } else if((pack ==1)<(pack ==0) || (pack == 3)<(pack == 4)){
                    	printf("\n\n\n\n\n\n                                                     Invaild select please select right option!!!");
					}
					
					 else {
                    	clr();
                        printf("\n\n\n\n\n\n                                                     Insufficient balance!\n");
                    }
                    break;
                case 5: clr();  

    // Enter code prompt
    printf("\n\n\n\n                                                          CODE: 903\n");
    printf("\n\n                                         1                   2                       3\n\n");
    printf("                                         4                   5                       6\n\n");
    printf("                                         7                   8                       9\n\n");
    printf("                                         *                   0                       #\n\n");
    printf("                                                           Call                         \n\n");

    printf("                                             Enter a code: ");
    scanf("%s", numberCode);
    clr();  
       if(strcmp(numberCode,"903")==0){
       	printf("\n\n\n\n\n\n                                                     Your number is: %s\n",phoneNumber);
        
	   } else{
	   	printf("\n\n\n\n\n\n                                                    Innvail code!!!\n\n\n\n\n");
	   }
                	    
                                break;
                case 6:
                    printf("\n\n\n                                                     Your Active Packs:\n");
                    if (dataPack1) printf("                              - 1GB Data (1 Day) Active at %s ",dataPack1Time);
                    if (dataPack2) printf("                              - 7GB Data (7 Days) Active at %s",dataPack2Time);
                    if (dataPack3) printf("                              - 40GB Data (30 Days) Active at %s",dataPack3Time);
                    if (voicePack1) printf("                             - 45min Voice (1 Day) Active at %s",voicePack1Time);
                    if (voicePack2) printf("                             - 200min Voice (7 Days) Active at %s",voicePack2Time);
                    if (voicePack3) printf("                             - 999min Voice (30 Days) Active at %s",voicePack3Time);
                    if (!dataPack1 && !dataPack2 && !dataPack3 && !voicePack1 && !voicePack2 && !voicePack3) {
                        printf("                                                     No Active Packs\n");
                    }
                    break;
                case 7:
                    printf("\n\n\n\n\n\n\n                                                              Exiting...\n");
                    exitEnter = 1;
                    break;
                default:
                    printf("\n\n\n\n\n\n\n                                                     Invalid choice! Please try again.\n");
            }

            // Save balance & pack data
            file = fopen("balance.txt", "w");
            if (file != NULL) {
                fprintf(file, "%d", 
                        balance);
                
                fclose(file);
            } else {
                printf("Error saving balance!\n");
            }

            printf("\n\n\n\n                                                     Press Enter to continue...");
            suman();
            suman();
            clr();

        } while (exitEnter == 0);
    } else {
        printf("Invalid code!\n");
    }

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                     Task complete!\n");
    return 0;
}

