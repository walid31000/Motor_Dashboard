#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H



typedef struct
{

	Dio_Port_t     PORT_STEPPER;
	Dio_Pin_t      BLEU_PIN;
	Dio_Pin_t      PINK_PIN;
	Dio_Pin_t      YELLOW_PIN;
	Dio_Pin_t      ORANGE_PIN;


}Stepper_config_t;


typedef enum
{

	Clock_Wise_ROT,Counter_Clock_Wise_ROT //enum to choose between direction of rotation CW_ROT (clock wise rotation) ,CCW_ROT (counter clock wise rotation)

}Stepper_Rotation_t;

uint8 Stepper_u8Stepper_Rotate( Stepper_config_t* Stepper_Object,uint16 copy_u16Angl,Stepper_Rotation_t copy_dir );













#endif
