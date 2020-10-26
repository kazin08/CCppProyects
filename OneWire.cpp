/* OneWire
Functions to use to get data from temperature sensors DS18B20
using OneWire communication. */

////////////////////////////////////////////////////////////////////////////////// 
//                  Reset and see if i get answer from the device              // 
////////////////////////////////////////////////////////////////////////////////// 
bool reset_DS18B20(DigitalInOut *pin_temp) {
    pin_temp->output();   // set pin to output
    pin_temp->write(0);   // se to 0 for 480 us
    wait_us(480);
    
    // see if i get answer
    pin_temp->input();
    wait_us(90);       // wait 90us for an answer
    
    return pin_temp->read();
}

////////////////////////////////////////////////////////////////////////////////// 
//                          Write to Read ROM (READROM)                        // 
////////////////////////////////////////////////////////////////////////////////// 
void write_DS18B20(DigitalInOut *pin_temp, int toWrite) {
    uint8_t i=0;
    
    pin_temp->output();
    pin_temp->write(1);
    wait_us(2);        
    for ( i=0; i<8; i++){            
        pin_temp->write(0);           
        if ( (toWrite >> i) & 0x01 ) {  // if value is 1 enter            
            wait_us(5);             // 5 us of delay
            pin_temp->write(1);
            wait_us(50);            // delay for finish the slot           
        } else {               
            wait_us(55);            // 55 us of delay
            pin_temp->write(1);               
        }          
        wait_us(2);                 // delay for send more data      
    }
}

////////////////////////////////////////////////////////////////////////////////// 
//                          recieve 1 byte - ROM CODE etc                      // 
////////////////////////////////////////////////////////////////////////////////// 
int read_DS18B20(DigitalInOut *pin_temp) {
    uint8_t i=0, data_readed=0;
    
    for (i=0; i < 8; i++) {
        pin_temp->output();
        pin_temp->write(1);         // write 1 and wait for 1 us
        wait_us(1);
        pin_temp->write(0);         // write 0 and wait for 2 us
        wait_us(2);
        pin_temp->input();          // set pin to input
        wait_us(10);                // delay for read             
        data_readed = data_readed + (pin_temp->read() << i);
        wait_us(45);                // wait for next data                    
    }
    return data_readed;
}

////////////////////////////////////////////////////////////////////////////////// 
//              temperature convertion to show it > 9 bits for DS18S20         // 
////////////////////////////////////////////////////////////////////////////////// 
uint8_t * conversionTemp(uint8_t dato, uint8_t sign, uint8_t count_per, uint8_t count_rem, uint8_t tipoConv) { 
    uint16_t convTemp = 0; 
    uint8_t i, comaTemp=0; 
    static uint8_t msbT_lsbT[2]={0,0};      // msbT = 0, lsbT = 1
    
    for (i=1; i<8; i++) {
        convTemp = convTemp + (((dato >> i) & 0x01) << i-1);
    }
        // logInfo("count_per %d , ccount_rem %d and data: %d", count_per, count_rem, dato);
    // convertion to 12 bits from datasheet
    if (tipoConv == 0) {    
        comaTemp = ((dato & 0x01) * 50) - 25 + (count_per - count_rem)*100/(count_per);    // coma from conv temp
    } 
    // convertion made without take care of the rest
    if (tipoConv == 1) {    
        comaTemp = (count_per - count_rem)*100/(count_per);    // coma from conv of temp without 0,5
    } 
    // normal convertion, with +-0.5 error
    if (tipoConv == 2) {
        comaTemp = convTemp*10 + ((dato & 0x01) * 5);
    }
    if(comaTemp > 180) {
        comaTemp = 0;  // negative value, set to zero
    }
    // check if a negative value to rest it
    if (comaTemp > 130) {
        comaTemp = !comaTemp;   // invert for negative value
        convTemp = convTemp*10 - (comaTemp/10);     // less significative values
    } else {
        convTemp = convTemp*10 + (comaTemp/10);     // less significative values
    }
        // logInfo("comaTemp %d and convTemp %d", comaTemp, convTemp);
    msbT_lsbT[0] = (convTemp & 0xFF00) >> 8;    // msbT
    msbT_lsbT[1] = (convTemp & 0x00FF);         // lsbT
    // inviert data if they are negative
    if (sign) {
        msbT_lsbT[0] = ~msbT_lsbT[0];       // msbT
        msbT_lsbT[1] = msbT_lsbT[1] - 1;    // lsbT
        msbT_lsbT[1] = ~msbT_lsbT[1];       // lsbT
    }
    return msbT_lsbT;
}

////////////////////////////////////////////////////////////////////////////////// 
//              temperature convertion to show it > 9 bits on DS18B20          // 
////////////////////////////////////////////////////////////////////////////////// 
uint8_t * conversionTemp_18B20(uint8_t dato, uint8_t sign) { 
    uint16_t convTemp = 0; 
    uint8_t i, comaTemp=0; 
    static uint8_t msbT_lsbT[2]={0,0};      // msbT = 0, lsbT = 1
    
    // convert the firs data then save it in convTemp and comaTemp
    for (i=0; i<11; i++) {
        if ( i>7 ) {
            convTemp = convTemp + (((sign >> i-8) & 0x01) << i-4);   
        } if ( i>3 )  {
            convTemp = convTemp + (((dato >> i) & 0x01) << i-4);
        } else {
            comaTemp = comaTemp + 100/(((dato >> i) & 0x01) << 4-i);
        }
    }
    
    // divide the number to get the value after comma, then add it to convTemp (the max value is 0x30)
    comaTemp = comaTemp / 10;
    // mult by 10 then add the comma value
    convTemp = (convTemp * 10) + comaTemp;
    
    // logInfo("comaTemp %d and convTemp %d", comaTemp, convTemp);    

    msbT_lsbT[0] = (convTemp & 0xFF00) >> 8;    // msbT
    msbT_lsbT[1] = (convTemp & 0x00FF);         // lsbT
    // invert if its a negative value
    if (sign & 0x80) {
        msbT_lsbT[0] = ~msbT_lsbT[0];           // msbT
        msbT_lsbT[1] = msbT_lsbT[1] - 1;        // lsbT
        msbT_lsbT[1] = ~msbT_lsbT[1];           // lsbT
    }
    return msbT_lsbT;
}


////////////////////////////////////////////////////////////////////////////////// 
//                       Temperature sensor Data Read                          // 
//////////////////////////////////////////////////////////////////////////////////        

uint8_t * read_sensor_temp(DigitalInOut *pin_temp, uint8_t qty_sens_f){
    
    uint8_t j, aux, est_sens_f, dato_bit;
    uint8_t READROM = 0x33; 
    uint8_t TEMPCONVERT = 0x44;
    uint8_t TRANSMIT = 0xBE;
    uint8_t SKIPROMCOM = 0xCC;
    static uint8_t data_read_f[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        
    // Functions to read data from temperature sensors      
    aux = reset_DS18B20(pin_temp);     // reset and look for answer 
    
    // if i get an answer, continue
    if (aux==0) {
        wait_us(390);   // wait 390us to continue sending data
        write_DS18B20(pin_temp, READROM);   // first, write to Read ROM
        
        // receive 8 bytes of ROM CODE
        est_sens_f = 0;                     // init the var
        for (j=0; j<8; j++) {
            wait_us(1);                     // wait to read data
            data_read_f[j] = read_DS18B20(pin_temp);   // read data
            est_sens_f = est_sens_f + data_read_f[j];  // check for sensor wired
        }
        
        // check if a sensor is wired to continue
        if (est_sens_f != 0) {
        
            qty_sens_f++;          // add 1 to sensor quantity
            
            // write for temperature convertion
            write_DS18B20(pin_temp, TEMPCONVERT);    
            
            // chek if the convertion finished
            dato_bit = 0;
            while (dato_bit == 0) {
                wait_us(1);                 // wait for read data      
                pin_temp->output();
                pin_temp->write(1);         // write 1 for 1 us
                wait_us(1);
                pin_temp->write(0);         // write 0 for 1 us
                wait_us(2);
                pin_temp->input();          // set pin to input
                wait_us(10);                // wait for read   
                dato_bit = pin_temp->read();    // read pin            
                wait_us(45);                // wait for next data                   
            }
    
            // reset for receive data
            aux = reset_DS18B20(pin_temp);
            
            // continue if i get answer
            if (aux==0) {
                wait_us(390);
                write_DS18B20(pin_temp, SKIPROMCOM);
            
                // write to enable the transmition of the temp
                write_DS18B20(pin_temp, TRANSMIT); 
                
                // receive 9 bytes 
                for (j=0; j<9; j++) {
                    wait_us(1);                    // wait to read data
                    data_read_f[j] = read_DS18B20(pin_temp);   // read data                  
                }
                              
            }
                             
        }        
    }
    
    data_read_f[9] = qty_sens_f;   // add quantity of sensors
    data_read_f[10] = est_sens_f;   // add the state of the sensor to know if any
    
    return data_read_f;
}
