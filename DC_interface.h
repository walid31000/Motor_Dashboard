#ifndef DC_INTERFACE_H
#define DC_INTERFACE_H



typedef struct
{
	Dio_Port_t  PORT;
	Dio_Pin_t  PIN0;
	Dio_Pin_t  PIN1;



}DC_config_t;



void Motor_voidRotateCW( DC_config_t* copy_Motor_object);
void Motor_voidRotateCCW( DC_config_t* copy_Motor_object);
void Motor_voidStop( DC_config_t* copy_Motor_object);












#endif
