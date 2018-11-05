/*******************************************************************************
  ADC Driver Initialization File

  File Name:
    drv_adc_static.c

  Summary:
    This file contains source code necessary to initialize the ADC driver.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "DRV_ADC_Initialize" function, configuration bits, and allocates
    any necessary global system resources, such as the systemObjects structure
    that contains the object handles to all the MPLAB Harmony module objects in
    the system.
 *******************************************************************************/

/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************
#include "framework/driver/adc/drv_adc_static.h"
 
// *****************************************************************************
// *****************************************************************************
// Section: ADC Static Driver Functions
// *****************************************************************************
// *****************************************************************************
void DRV_ADC_Initialize(void)
{    PLIB_ADC_MuxAInputScanEnable(ADC_ID_1);
    /* Select Clock Source */
    PLIB_ADC_ConversionClockSourceSelect(ADC_ID_1, ADC_CLOCK_SOURCE_SYSTEM_CLOCK);
    /* Select Clock Prescaler */
    PLIB_ADC_ConversionClockSet(ADC_ID_1, SYS_CLK_FREQ, 320000000);
    /* Select Power Mode */
    PLIB_ADC_StopInIdleDisable(ADC_ID_1);
    /* Select Voltage Reference */
    PLIB_ADC_VoltageReferenceSelect(ADC_ID_1, ADC_REFERENCE_VDD_TO_AVSS);
    /* Sampling Selections */
    /* Enable Auto Sample Mode */
    PLIB_ADC_SampleAutoStartEnable(ADC_ID_1);
    /* Sample Acquisition Time (Auto Sample Mode) */ 
    PLIB_ADC_SampleAcquisitionTimeSet(ADC_ID_1, 31);
    /* Select Sampling Mode */
    PLIB_ADC_SamplingModeSelect(ADC_ID_1, ADC_SAMPLING_MODE_MUXA);
    /* Number of Samples Per Interrupt */
    PLIB_ADC_SamplesPerInterruptSelect(ADC_ID_1, ADC_10SAMPLES_PER_INTERRUPT);
    /* Conversion Selections */
    /* Select Trigger Source */
    PLIB_ADC_ConversionTriggerSourceSelect(ADC_ID_1, ADC_CONVERSION_TRIGGER_INTERNAL_COUNT);
    /* Select Result Format */
    PLIB_ADC_ResultFormatSelect(ADC_ID_1, ADC_RESULT_FORMAT_INTEGER_16BIT);
    /* Buffer Mode */
    PLIB_ADC_ResultBufferModeSelect(ADC_ID_1, ADC_BUFFER_MODE_ONE_16WORD_BUFFER);
    /* Channel Selections */
    /* MUX A Negative Input Select */
    PLIB_ADC_MuxChannel0InputNegativeSelect(ADC_ID_1, ADC_MUX_A, ADC_INPUT_NEGATIVE_VREF_MINUS);
    /* Select Scan Input 0 */
    PLIB_ADC_InputScanMaskAdd(ADC_ID_1, ADC_INPUT_SCAN_AN0);
    /* Select Scan Input 1 */
    PLIB_ADC_InputScanMaskAdd(ADC_ID_1, ADC_INPUT_SCAN_AN1);
    /* Select Scan Input 2 */
    PLIB_ADC_InputScanMaskAdd(ADC_ID_1, ADC_INPUT_SCAN_AN2);
    /* Select Scan Input 3 */
    PLIB_ADC_InputScanMaskAdd(ADC_ID_1, ADC_INPUT_SCAN_AN3);
    /* Select Scan Input 4 */
    PLIB_ADC_InputScanMaskAdd(ADC_ID_1, ADC_INPUT_SCAN_AN4);
        /* Select Scan Input 5 */
    PLIB_ADC_InputScanMaskAdd(ADC_ID_1, ADC_INPUT_SCAN_AN5);
    /* Select Scan Input 6 */
    PLIB_ADC_InputScanMaskAdd(ADC_ID_1, ADC_INPUT_SCAN_AN6);
    /* Select Scan Input 7 */
    PLIB_ADC_InputScanMaskAdd(ADC_ID_1, ADC_INPUT_SCAN_AN7);
    /* Select Scan Input 8 */
    PLIB_ADC_InputScanMaskAdd(ADC_ID_1, ADC_INPUT_SCAN_AN8);
    /* Select Scan Input 9 */
    PLIB_ADC_InputScanMaskAdd(ADC_ID_1, ADC_INPUT_SCAN_AN9);
    /* Initialize ADC Interrupt */
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_ADC_1);
    PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_ADC_1);
    PLIB_INT_VectorPrioritySet(INT_ID_0, INT_VECTOR_AD1, INT_PRIORITY_LEVEL3);
    PLIB_INT_VectorSubPrioritySet(INT_ID_0, INT_VECTOR_AD1, INT_SUBPRIORITY_LEVEL0); 
}

inline void DRV_ADC_DeInitialize(void)
{
    /* Disable ADC */
    PLIB_ADC_Disable(DRV_ADC_ID_1);
}

inline void DRV_ADC_Open(void)
{
    /* Enable ADC */
    PLIB_ADC_Enable(DRV_ADC_ID_1);
}

inline void DRV_ADC_Close(void)
{
    /* Disable ADC */
    PLIB_ADC_Disable(DRV_ADC_ID_1);
}

inline void DRV_ADC_Start(void)
{
    /* Start ADC */
    PLIB_ADC_SamplingStart(DRV_ADC_ID_1);
}

inline void DRV_ADC_Stop(void)
{
    /* Stop ADC */
    PLIB_ADC_SamplingStop(DRV_ADC_ID_1);	
}

inline void DRV_ADC_NegativeInputSelect(DRV_ADC_MUX mux, DRV_ADC_INPUTS_NEGATIVE input)
{
    /* Select Negative Input */
    PLIB_ADC_MuxChannel0InputNegativeSelect(DRV_ADC_ID_1, mux, input);
}

inline void DRV_ADC_PositiveInputSelect(DRV_ADC_MUX mux, DRV_ADC_INPUTS_POSITIVE input)
{
    /* Select Positive Input */
    PLIB_ADC_MuxChannel0InputPositiveSelect(DRV_ADC_ID_1, mux, input);
}

inline void DRV_ADC_ChannelScanInputsAdd(DRV_ADC_INPUTS_SCAN scanInput)
{
    /* Add Scan Input */
    PLIB_ADC_InputScanMaskAdd(DRV_ADC_ID_1, scanInput);
}

inline void DRV_ADC_ChannelScanInputsRemove(DRV_ADC_INPUTS_SCAN scanInput)
{
    /* Remove Scan Input */
    PLIB_ADC_InputScanMaskRemove(DRV_ADC_ID_1, scanInput);
}

ADC_SAMPLE DRV_ADC_SamplesRead(uint8_t bufIndex)
{
    /* Read Result */
    return PLIB_ADC_ResultGetByIndex(DRV_ADC_ID_1, bufIndex);
}

bool DRV_ADC_SamplesAvailable(void)
{
    /* Return ADC conversion complete status */
    return (PLIB_ADC_ConversionHasCompleted(DRV_ADC_ID_1));
}
