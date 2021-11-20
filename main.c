/* =======================================================================
 * Proyecto 19:
 * Programa que muestra el algoritmo que controla un dimmer digital 
 * haciendo uso del PWM del PSoC5LP. El control del dimmer se realiza con
 * dos pulsadores conectados a las entradas del PSoC, con esto se tiene un
 * valor de voltaje promedio que se ve reflejado con la intensidad del
 * brillo de un LED conectado a una salida del PSoC.
 * =======================================================================
*/

#include <project.h>

// Definición de variables

volatile uint8 cont;
uint8 estado;
uint16 tiempo;

int main()
{
    tiempo = 100;
    PWM_Start();
    cont=0; //Valor inicial del PWM
    for(;;)
    {
        estado = Pulsadores_Read();
        if (estado == 0b00){
            if (cont == 200){
                cont = 150;
                PWM_WriteCompare(cont);
                CyDelay(tiempo);
                cont = 100;
                PWM_WriteCompare(cont);
                CyDelay(tiempo);
                cont = 50;
                PWM_WriteCompare(cont);
                CyDelay(tiempo);
                cont = 0;
                PWM_WriteCompare(cont);
                CyDelay(tiempo);
            }
            cont = cont + 5;
            PWM_WriteCompare(cont);
            CyDelay(tiempo);
        }else{
            PWM_WriteCompare(0);    
        }
  /*
        if(estado == 0b00){
            PWM_WriteCompare(0);
        }
        
        if(estado == 0b01){
            PWM_WriteCompare(20);
        }
        
        if(estado == 0b10){
            PWM_WriteCompare(20);
        }
        
        if(estado == 0b11){
            PWM_WriteCompare(0);
        }
        */
    }
}
