#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "Stepper_interface.h"







uint8 Stepper_u8Stepper_Rotate( Stepper_config_t* Stepper_Object,uint16 copy_u16Angl,Stepper_Rotation_t copy_dir )
{

	uint8 Local_u8ErrorState=OK;
	uint16 Lcoal_u16Counter;



	if(Stepper_Object!=NULL)
	{
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->BLEU_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->PINK_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->YELLOW_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->ORANGE_PIN,DIO_PIN_HIGH);

		/*Full step Angle (resolution)=5.625/32=0.1758° ->to rotate 360°->1*360/0.1758 =2048 steps */

		uint16 Local_u16Steps=(uint16)((uint32)copy_u16Angl*2048UL/360UL); // convert degree to number of full step
		//uint16 Local_u16Steps=copy_u16Angl;//to facilitate simulation assume 1step=1° degree

		/*If direction of rotation is CW_ROT (clock wise rotation) */
		if(copy_dir==Counter_Clock_Wise_ROT)
		{
			for(Lcoal_u16Counter=0;Lcoal_u16Counter<Local_u16Steps;Lcoal_u16Counter++)
			{
				if(Lcoal_u16Counter%4==0)
				{
					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->ORANGE_PIN,DIO_PIN_HIGH);

					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->BLEU_PIN,DIO_PIN_LOW);
					_delay_ms(3);
				}

				else if(Lcoal_u16Counter%4==1)
				{
					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->BLEU_PIN,DIO_PIN_HIGH);

					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->PINK_PIN,DIO_PIN_LOW);
					_delay_ms(3);
				}
				else if(Lcoal_u16Counter%4==2)
				{
					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->PINK_PIN,DIO_PIN_HIGH);

					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->YELLOW_PIN,DIO_PIN_LOW);
					_delay_ms(3);

				}
				else if(Lcoal_u16Counter%4==3)
				{
					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->YELLOW_PIN,DIO_PIN_HIGH);

					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->ORANGE_PIN,DIO_PIN_LOW);
					_delay_ms(3);

				}

			}
		}

		/*If direction of rotation is CCW_ROT (counter clock wise rotation)*/

		else if(copy_dir==Clock_Wise_ROT)
		{
			for(Lcoal_u16Counter=0;Lcoal_u16Counter<Local_u16Steps;Lcoal_u16Counter++)
			{
				if(Lcoal_u16Counter%4==0)
				{
					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->BLEU_PIN,DIO_PIN_HIGH);

					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->ORANGE_PIN,DIO_PIN_LOW);
					_delay_ms(3);
				}

				else if(Lcoal_u16Counter%4==1)
				{
					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->ORANGE_PIN,DIO_PIN_HIGH);

					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->YELLOW_PIN,DIO_PIN_LOW);
					_delay_ms(3);
				}
				else if(Lcoal_u16Counter%4==2)
				{
					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->YELLOW_PIN,DIO_PIN_HIGH);

					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->PINK_PIN,DIO_PIN_LOW);
					_delay_ms(3);

				}
				else if(Lcoal_u16Counter%4==3)
				{
					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->PINK_PIN,DIO_PIN_HIGH);

					DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->BLEU_PIN,DIO_PIN_LOW);
					_delay_ms(3);

				}



			}



		}
		else
		{
			Local_u8ErrorState=NOK;
		}
	}
	else
	{


		Local_u8ErrorState=NULL_PTR;

	}


	return Local_u8ErrorState;


}






