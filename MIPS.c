/* MIPS.C
  TEAM ACT
  
*/

// includes
#include <stdio.h>
#include "fetch.c"
#include "utility.c"

// function definition
//  

//globals
int debug_input = 0;
int debug_fetch = 1;
int debug_decode = 1;
int debug_execute = 1;


//temp: input def 
// MIPS.exe in_addr 
// argv[0]   argv[1]

void main(int argc, char *argv[]) {
    //main vars
    int temp = 0;
    int clk = 0;
    int adder2out = 0;
    int pcSrc = 0;
    int adder1 = 0;
    int instruction = 0;
    
    if (debug_input) printf("\nBegin main()...");
    if (debug_input) printf("\narg1 = %s", argv[1]);
    
    ///////////////////////////////////////////////
    // FETCH STAGE
    //  handles:
    //      programcounter
    //      
    ///////////////////////////////////////////////
    if (debug_fetch) printf("\n\nFETCH: ");
    
    
    fetch(clk, adder2out, pcSrc, adder1, instruction);
    
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






