/* ###################################################################
**     Filename    : main.c
**     Project     : ServoLineal
**     Processor   : MC9S08SH8CPJ
**     Version     : Driver 01.12
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2017-11-16, 19:29, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.12
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "AD1.h"
#include "Dedos.h"
#include "AD2.h"
#include "Muneca.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"


void piola(int signal);

/* User includes (#include below this line is not maintained by Processor Expert) */

	int y=0,   a=0, k=0, 
	div=0,     b=0, val=0,
	x=0,       c=0, viejovalor=0, state;
	
void main(void)
{
  /* Write your local variable definition here */
	
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  AD1_Enable();
  Dedos_Enable();
  AD2_Enable();
  Muneca_Enable();
  /* Write your code here */
  /* For example: for(;;) { } */

  Dedos_SetRatio8(10);
  Muneca_SetRatio8(12);
  state = 0;


  
  for(;;) 
  
  { 	  
	  	  		  
	  	  	  	  AD1_Measure(TRUE);
	  	  	  	  AD1_GetValue(&x);
	  	  	  	  div= x/4;
	  	  	  	  y= ((26*div)/256)+7;
	  	  	  	  
	  	  	  	  AD2_Measure(TRUE);
	  	  	  	  AD2_GetValue(&a);
	  	  	  	  b= a/4;
	  	  	  	  c= ((26*b)/256)+7;
	  	  	  	  
	  	  	  	  
	  	  	  	  if(y>13)
	  	  	  	  	  {	  	  	  	  
	  	  	  		  Dedos_SetRatio8(22);
	  	  	  	  	  }
	  	  	  	  
	  	  	  	  if(y<=13)
	  	  	 	  	   {	  	  	  	  
	  	  	  		   Dedos_SetRatio8(10);
	  	  	 	  	   }
	  	  	  	  
	  	  	  	  
	  	  	  	if( c > 15 && state==0){
	  	  	  		Muneca_SetRatio8(2);
	  	  	  		state = 1;
	  	  	  		Cpu_Delay100US(200000);
	  	  	  	}
	  	  	  	else if(c > 15 && state==1)
	  	  	  	{
	  	  	  		Muneca_SetRatio8(12);
	  	  	  		state = 0;
	  	  	  		Cpu_Delay100US(200000);
	  	  	  	}
	  	  	 	  	  
    
	  	  	  
  }
  
  void piola(int signal)
  	  	  	  {
	  	  	  Dedos_SetRatio8(10);
  	  	  	  }
  
  
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
 /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/
    }
/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
