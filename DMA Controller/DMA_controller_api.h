#include "DMA_controller_driver.h"


int initialize(Stream stream, config_table * table);

int setFlagDMA(Stream stream, Flag flag); 

int enableDMA(Stream stream);

int disableDMA(Stream stream);

int resetDMA(Stream stream);