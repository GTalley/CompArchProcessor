/* MIPS.C
  TEAM ACT
  
*/

// includes
#include <stdio.h>
#include "fetch.c"
#include "utility.c"
#include "time.h"

// function definition
//  

//globals
int debug_input = 0;
int debug_fetch = 1;
int debug_decode = 0;
int debug_execute = 0;


//temp: input def 
// MIPS.exe in_addr 
// argv[0]   argv[1]

void main(int argc, char *argv[]) {
    //main vars
    int temp = 0;
    int clk = 1;
    int adder2out = 0;
    int pcSrc = 0;
    int adder1in = 0, adder1out = 0;
    int FET_instruction = 0, DEC_instruction = 0;
    int i;
    clock_t start_t, end_t;
    
    //init
    //adder1 = 0;
    
    if (debug_input) printf("\nBegin main()...");
    if (debug_input) printf("\narg1 = %s", argv[1]);
    
    ///////////////////////////////////////////////
    // FETCH STAGE
    //  handles:
    //      programcounter
    //      
    ///////////////////////////////////////////////
    if (debug_fetch) printf("\n\nFETCH: ");

    //testing, run through all instructions
    for (i = 0; i < 18; i++) {
        fetch(clk, adder2out, pcSrc, &adder1in, &FET_instruction);
        start_t = clock();
        end_t = 0;
        while ((((double)(end_t - start_t))/CLOCKS_PER_SEC) < 1) {  //simulating a 1s clock for debug
                end_t = clock();
        }
        Reg_FetchToDecode(clk, &adder1in, &FET_instruction, &adder1out, &DEC_instruction);
        if (debug_fetch) printf("\nDEC_instruction: %d", DEC_instruction);  
    }
    //fetch(clk, adder2out, pcSrc, &adder1in, &FET_instruction);
    //Reg_FetchToDecode(clk, &adder1in, &FET_instruction, &adder1out, &DEC_instruction);
    
    if (debug_fetch) printf("\nEND FETCH:\n");
    ///////////////////////////////////////////////
    // DECODE STAGE
    //  handles:
    //      
    ///////////////////////////////////////////////
    if (debug_decode) printf("\nDECODE: ");
    if (debug_decode) printf("\nEND DECODE:\n");
    ///////////////////////////////////////////////
    // EXECUTE STAGE
    //  handles:
    //      
    ///////////////////////////////////////////////
    if (debug_execute) printf("\nEXECUTE: ");
    if (debug_execute) printf("\nEND EXECUTE:\n");
    
    // END MAIN
    printf("\n\nEnd main()...");
    printf("\n");
}






