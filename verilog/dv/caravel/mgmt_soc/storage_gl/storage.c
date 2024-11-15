/* SPDX-FileCopyrightText: 2020 Efabless Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// SPDX-License-Identifier: Apache-2.0
*/

#include "../../defs.h"

// --------------------------------------------------------

/*
	Storage area Test
	It uses GPIO to flag the success or failure of the test
*/

void main()
{
    int i;
    volatile uint32_t* ram_addr; 
    /* Upper 16 user area pins are configured to be GPIO output */

    reg_mprj_io_31 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_30 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_29 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_28 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_27 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_26 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_25 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_24 = GPIO_MODE_MGMT_STD_OUTPUT;

    reg_mprj_io_23 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_22 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_21 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_20 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_19 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_18 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_17 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_16 = GPIO_MODE_MGMT_STD_OUTPUT;

    // Apply configuration
    reg_mprj_xfer = 1;
    while (reg_mprj_xfer == 1);

    // start test
    reg_mprj_datal = 0xA0400000;

    // Test Management R/W block0
    for (i=0; i<10; i++){
        ram_addr = &reg_rw_block0 + i;
        *ram_addr = i*5000 + 10000;
    }
	
    for (i=0; i<10; i++){
        ram_addr = &reg_rw_block0 + i;
        if ((i*5000+10000) != *ram_addr) 
	    reg_mprj_datal = 0xAB400000;
    }
	
    reg_mprj_datal = 0xAB410000;
	
    // Test Management R/W block1
    reg_mprj_datal = 0xA0200000;
    for (i=0; i<10; i++){
        ram_addr = &reg_rw_block1 + i;
        *ram_addr = i*5000 + 10000;
    }
	
    for (i=0; i<10; i++){
        ram_addr = &reg_rw_block1 + i;
        if ((i*5000+10000) != *ram_addr) 
	    reg_mprj_datal = 0xAB200000;
    }
    
    reg_mprj_datal = 0xAB210000;
}

