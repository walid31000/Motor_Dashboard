/*
 * main.c
 *description:Motor Dashboard
 *  Created on: 26 Apr 2024
 *      Author: walid
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "DC_interface.h"
#include "Stepper_interface.h"
#include "KPD_interface.h"
#include "CLCD_interface.h"

/*function to get the Angle from user*/
uint16 Calc_u16Angle()
{
	uint16 Local_u16Angle=0;
	uint8 Local_u8Key=0xff;



	do
	{
		Local_u8Key=KPD_u8GetPressedKey();

		if((Local_u8Key>=0) && (Local_u8Key<=9))
		{
			CLCD_voidSendNumber(Local_u8Key);
			Local_u16Angle=Local_u16Angle*10+Local_u8Key;


		}
	}while(Local_u8Key!='S' );

	return Local_u16Angle;
}

void main(void)
{
	uint8 Local_u8Key=0xff;
	uint16 Local_u16Angle=0;

	DC_config_t DC_Motor={DIO_PORTD,DIO_PIN6,DIO_PIN7 };
	Stepper_config_t Stepper={DIO_PORTD,DIO_PIN0,DIO_PIN1,DIO_PIN2,DIO_PIN3};

	PORT_voidIint();
	CLCD_voidInit ();
	Hamoksha();//show first animation on LCD using this function

	/*show Motor menu on LCD*/
	CLCD_u8SendStringAtPos(0u,0u,"DC MOTOR ---->1");
	CLCD_u8SendStringAtPos(0u,1u,"STEPER MOTOR->2");

	while(1)
	{

		Local_u8Key=KPD_u8GetPressedKey();

		if(Local_u8Key!=0xff )
		{

			CLCD_voidSendNumber(Local_u8Key);
			if (Local_u8Key==1)//DC MOTOR
			{

				CLCD_voidSendCommand(1);
				CLCD_u8SendStringAtPos(0u,0u,"Rot CW ->1");
				CLCD_u8SendStringAtPos(0u,1u,"Rot CCW->2");



				while(1)
				{
					Local_u8Key=KPD_u8GetPressedKey();
					if(Local_u8Key!=0xff )
					{
						if(Local_u8Key==1)//DC Clock Wise  direction
						{
							Motor_voidRotateCW( &DC_Motor);
							CLCD_voidSendCommand(1);
							CLCD_u8SendStringAtPos(0u,0u,"Press 0 to stop");


						}




						else if(Local_u8Key==2) //DC counter Clock Wise  direction
						{
							Motor_voidRotateCCW( &DC_Motor);
							CLCD_voidSendCommand(1);
							CLCD_u8SendStringAtPos(0u,0u,"Press 0 to stop");

						}
						else if((Local_u8Key==0))
						{
							CLCD_voidSendCommand(1);
							CLCD_u8SendStringAtPos(0u,1u,"Thanks");

							Motor_voidStop(&DC_Motor);
							Hamoksha_Reverse();//animation in reverse

						}


					}
				}
			}

			else if (Local_u8Key==2)//STEPPER MOTOR
			{


				/*show rotation menu*/
				CLCD_voidSendCommand(1);
				CLCD_u8SendStringAtPos(0u,0u,"Rot CW ->1");
				CLCD_u8SendStringAtPos(0u,1u,"Rot CCW->2");


				while(1)
				{

					Local_u8Key=KPD_u8GetPressedKey();
					if(Local_u8Key!=0xff )
					{
						if(Local_u8Key==1)//Stepper Clock Wise rotation
						{
							/*Read ANGLE*/
							CLCD_voidSendCommand(1);
							CLCD_u8SendStringAtPos(0u,0u,"Enter Angle");
							Local_u16Angle=Calc_u16Angle();

							Stepper_u8Stepper_Rotate( &Stepper, Local_u16Angle,Clock_Wise_ROT );
							CLCD_voidSendCommand(1);
							CLCD_u8SendStringAtPos(0u,1u,"Thanks");

							Hamoksha_Reverse();

						}




						else if(Local_u8Key==2)//Stepper counter Clock Wise rotation
						{
							/*Read ANGLE*/
							CLCD_voidSendCommand(1);
							CLCD_u8SendStringAtPos(0u,0u,"Enter Angle");
							Local_u16Angle=Calc_u16Angle();
							Stepper_u8Stepper_Rotate( &Stepper, Local_u16Angle,Counter_Clock_Wise_ROT );
							CLCD_voidSendCommand(1);
							CLCD_u8SendStringAtPos(0u,1u,"Thanks");

							Hamoksha_Reverse();


						}

					}

				}
			}
		}
	}


}




























