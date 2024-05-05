#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DC_interface.h"











/*function to rotate motor in clock wise direction*/

void Motor_voidRotateCW( DC_config_t* copy_Motor_object)
{
	/*deactivate T2 and T3*/
	DIO_u8SetPinValue( copy_Motor_object->PORT,copy_Motor_object->PIN1,DIO_PIN_LOW);

	/*Activate T1 and T4*/
	DIO_u8SetPinValue( copy_Motor_object->PORT,copy_Motor_object->PIN0,DIO_PIN_HIGH);



}

/*function to rotate motor in counter clock wise direction*/

void Motor_voidRotateCCW( DC_config_t* copy_Motor_object)
{
	/*deactivate T1 and T4*/
	DIO_u8SetPinValue( copy_Motor_object->PORT,copy_Motor_object->PIN0,DIO_PIN_LOW);

	/*Activate T2 and T3*/
	DIO_u8SetPinValue( copy_Motor_object->PORT,copy_Motor_object->PIN1,DIO_PIN_HIGH);




}

/*function to stop motor */

void Motor_voidStop( DC_config_t* copy_Motor_object)
{
	/*deactivate T1 and T4*/
	DIO_u8SetPinValue( copy_Motor_object->PORT,copy_Motor_object->PIN0,DIO_PIN_LOW);

	/*deactivate T2 and T3*/
	DIO_u8SetPinValue( copy_Motor_object->PORT,copy_Motor_object->PIN1,DIO_PIN_LOW);




}
