#include <string.h>

#include "xtimer.h"

#include "net/loramac.h"
#include "semtech_loramac.h"

#include "lm75.h"
#include "lm75_params.h"

#include "board.h"
#include "periph/gpio.h"
#include "periph_conf.h"

#define BTN0_INT_FLANK  GPIO_FALLING
#define BTN1_INT_FLANK  GPIO_FALLING

#include "cayenne_lpp.h"

/* loramac descriptor */
extern semtech_loramac_t loramac;

/* temperature sensor device descriptor */
static lm75_t lm75;

/* Cayenne LPP descriptor */
static cayenne_lpp_t lpp;

static uint8_t alarme = 0;

/* Device and application informations required for OTAA activation */
//EUI 3E7417E757CF9054
static const uint8_t deveui[LORAMAC_DEVEUI_LEN] = { 0x3E, 0x74, 0x17, 0xE7, 0x57, 0xCF, 0x90, 0x54 };
static const uint8_t appeui[LORAMAC_APPEUI_LEN] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
static const uint8_t appkey[LORAMAC_APPKEY_LEN] = { 0xA0, 0xBE, 0x3A, 0xEA, 0xF0, 0x77, 0x3D, 0xA9, 0x37, 0x3B, 0x04, 0xEA, 0x05, 0x77, 0x1E, 0x84 };

static void cb(void *arg);
static void loop(void);
static void init_temp(void);
static void init_lora(void);

int main(void)
{
    int cnt = 0;
    
    /* Buzzer + LED OFF*/
    gpio_clear(GPIO_PIN(PORT_B,10));
    
    /* init button */
    gpio_init_int(BTN1_PIN, BTN1_MODE, BTN1_INT_FLANK, cb, (void *)cnt);
    
    init_temp();
    init_lora();

    loop();
    
    return 0;
}

/* Deactivate / Activate the alarm manually */
static void cb(void *arg)
{
    (void)arg;
    
    gpio_toggle(GPIO_PIN(PORT_B,10));
    
    if(alarme == 1) alarme = 0;
    else if (alarme == 0) alarme = 1;
    
    return;
}


static void loop(void)
{
    
    while(1)
    {
        /* wait 5 secs */
        xtimer_sleep(20);

        /* do some measurements */
        //temperature
        int temperature = 0;
        if (lm75_get_temperature(&lm75, &temperature)!= LM75_SUCCESS) {
            puts(" -- failed to read temperature!");
            init_temp();
        }
        
        printf("Temperature : %d\n",temperature);
        
        if(((float)temperature/1000) >= 26)
        {
            alarme = 1;
            gpio_set(GPIO_PIN(PORT_B,10));
        }
        
        /* Cayenne lpp payload(s) */
        cayenne_lpp_add_temperature(&lpp, 0, (float)temperature / 1000);
        cayenne_lpp_add_digital_input(&lpp, 1, alarme);
        
        if(alarme == 1) puts("L'alarme est activée !");
        alarme = 0;
        
        /* send the LoRaWAN message */
        printf("Sending LPP data\n");
        uint8_t ret = semtech_loramac_send(&loramac, lpp.buffer, lpp.cursor);
        
        if (ret != SEMTECH_LORAMAC_TX_DONE) {
            printf("Cannot send lpp message, ret code: %d\n", ret);
            init_lora();
        }
        

        /* Receive data : not working */
        /*
        while(1){
            switch (semtech_loramac_recv(&loramac)) {
                case SEMTECH_LORAMAC_RX_DATA:
                    puts("Data is received");
                    break;

                case SEMTECH_LORAMAC_RX_LINK_CHECK:
                    puts("Link check information is received");
                    break;

                case SEMTECH_LORAMAC_RX_CONFIRMED:
                    puts("ACK received from the network");
                    break;
                    
                default:
                    break;

            }
        }
        */

        /* Clear buffer */
        cayenne_lpp_reset(&lpp);
    
    }
      

    /* this should never be reached */
    return;
        
}


/* Initialisation temperature sensor */
static void init_temp(void){
    while (lm75_init(&lm75, &lm75_params[0]) != LM75_SUCCESS) {
        puts("Sensor initialization failed");
        xtimer_sleep(5);
    }
    puts("Sensor initialization succeeded");
}


/* Initialisation LoRa */
static void init_lora(void){
    /* datarate 5 */
    semtech_loramac_set_dr(&loramac, 5);

    /* set the LoRaWAN keys */
    semtech_loramac_set_deveui(&loramac, deveui);
    semtech_loramac_set_appeui(&loramac, appeui);
    semtech_loramac_set_appkey(&loramac, appkey);

    /* start the OTAA join procedure */
    puts("Starting join procedure");
    while (semtech_loramac_join(&loramac, LORAMAC_JOIN_OTAA) != SEMTECH_LORAMAC_JOIN_SUCCEEDED) {
        puts("Join procedure failed");
        xtimer_sleep(5);
    }
    puts("Join procedure succeeded");   
}