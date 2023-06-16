#include <Arduino.h>

#define BOT1 ((PINB >> 0) & 0x01)
#define BOT2 ((PINB >> 1) & 0x01)
#define BOT3 ((PINB >> 2) & 0x01)
#define BOT4 ((PINB >> 3) & 0x01)

#define led1on PORTD |= (1 << PD2)
#define led2on PORTD |= (1 << PD3)
#define led3on PORTD |= (1 << PD4)
#define led4on PORTD |= (1 << PD5)
#define led5on PORTD |= (1 << PD6)
#define led6on PORTD |= (1 << PD7)

#define led1off PORTD &= ~(1 << PD2)
#define led2off PORTD &= ~(1 << PD3)
#define led3off PORTD &= ~(1 << PD4)
#define led4off PORTD &= ~(1 << PD5)
#define led5off PORTD &= ~(1 << PD6)
#define led6off PORTD &= ~(1 << PD7)

int cont = 0;

void secuencia(char cont); // declaro la Función que va a utilizar el Switch
void secuencia(char cont)  // defino la Función que va a utilizar el Switch
{
    switch (cont++) // Comienzo a alternar entre las posibilidades del dado
    {

    case 1:
        led1on;
        led2off;
        led3off;
        led4off;
        led5off;
        led6off;
        _delay_ms(100);
        break;

    case 2:
        led1on;
        led2on;
        led3off;
        led4off;
        led5off;
        led6off;
        _delay_ms(50);
        break;
    case 3:
        led1on;
        led2on;
        led3on;
        led4off;
        led5off;
        led6off;
        _delay_ms(100);
        break;
    case 4:
        led1on;
        led2on;
        led3on;
        led4on;
        led5off;
        led6off;
        _delay_ms(100);
        break;
    case 5:
        led1on;
        led2on;
        led3on;
        led4on;
        led5on;
        led6off;
        _delay_ms(100);
        break;
    case 6:
        led1on;
        led2on;
        led3on;
        led4on;
        led5on;
        led6on;
        _delay_ms(100);
        break;
    }
}

int main()

{
    DDRD |= (1 << PD2); // En esta linea configuro como salida
    DDRD |= (1 << PD3); // En esta linea configuro como salida
    DDRD |= (1 << PD4); // En esta linea configuro como salida
    DDRD |= (1 << PD5); // En esta linea configuro como salida
    DDRD |= (1 << PD6); // En esta linea configuro como salida
    DDRD |= (1 << PD7); // En esta linea configuro como salida

    DDRB &= ~(1 << PB0); // aca configuro como entrada
    DDRB &= ~(1 << PB1); // aca configuro como entrada
    DDRB &= ~(1 << PB2); // aca configuro como entrada
    DDRB &= ~(1 << PB3); // aca configuro como entrada

    DDRD |= 0x0f; // Configuro como salida
    DDRB &= 0x0f; // Configuro como entrada

    while (1)
    {
        while (BOT1 == 1) // Esperar hasta que se presione el botón BOT1
        {
        }

        while (BOT2 == 1) // si el boton 2 no esta apretado, ejecuto la secuencia mientras aumento el contador.
        {
            cont++;

            secuencia(cont);
        }

        secuencia(cont); // al ser apretado el boton 2, detengo la Función de los leds

        while ((BOT3 == 1 && BOT4 == 1)) // Pregunto si los botones 3 y 4 estan apretados, en caso de estarlo apago los leds.

        {
        }
        led1off;
        led2off;
        led3off;
        led4off;
        led5off;
        led6off;
    }
}
