/**
 * @brief       AMG8833.c
 * @details     Infrared Thermopile Sensor in Chip-Scale Package.
 *              Functions file.
 *
 *
 * @return      N/A
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019    The ORIGIN
 * @pre         N/A.
 * @warning     N/A
 * @pre         This code belongs to Nimbus Centre ( http://www.nimbus.cit.ie ). All rights reserved.
 */

#include "AMG8833.h"


AMG8833::AMG8833 ( PinName sda, PinName scl, uint32_t addr, uint32_t freq )
    : _i2c          ( sda, scl )
    , _AMG8833_Addr  ( addr )
{
    _i2c.frequency( freq );
}


AMG8833::~AMG8833()
{
}



/**
 * @brief       AMG8833_GetOperationMode (  AMG8833_data_t* )
 *
 * @details     It reads the operation mode ( power control register ).
 *
 * @param[in]    N/A.
 *
 * @param[out]   myOperationMode: Current operation mode.
 *
 *
 * @return       Status of AMG8833_GetOperationMode.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_GetOperationMode ( AMG8833_data_t* myOperationMode )
{
    char     cmd  =  0U;
    uint32_t aux;


    /* Read the register */
    cmd   =   AMG8833_PCTL;
    aux   =   _i2c.write ( _AMG8833_Addr, &cmd, 1U, true );
    aux   =   _i2c.read  ( _AMG8833_Addr, &cmd, 1U );


    /* Parse data   */
    myOperationMode->operationMode   =   (AMG8833_pctl_t)cmd;



    if ( aux == I2C_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_SetOperationMode ( AMG8833_data_t* )
 *
 * @details     It sets the operation mode ( power control register ).
 *
 * @param[in]    myOperationMode: Operation mode.
 *
 * @param[out]   N/A.
 *
 *
 * @return       Status of AMG8833_SetOperationMode.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_SetOperationMode ( AMG8833_data_t myOperationMode )
{
    char     cmd[]  =  { 0U, 0U };
    uint32_t aux;


    /* Update the register */
    cmd[0]   =   AMG8833_PCTL;
    cmd[1]   =   myOperationMode.operationMode;
    aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ), false );


    
    if ( aux == I2C_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_SoftwareReset ( AMG8833_rst_t )
 *
 * @details     It sets the reset mode.
 *
 * @param[in]    mySoftwareReset: Reset mode.
 *
 * @param[out]   N/A.
 *
 *
 * @return       Status of AMG8833_SoftwareReset.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_SoftwareReset ( AMG8833_rst_t mySoftwareReset )
{
    char     cmd[]  =  { 0U, 0U };
    uint32_t aux;


    /* Update the register */
    cmd[0]   =   AMG8833_RST;
    cmd[1]   =   mySoftwareReset;
    aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ), false );


    
    if ( aux == I2C_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_SetFrameMode ( AMG8833_fpsc_t )
 *
 * @details     It sets frame mode.
 *
 * @param[in]    myFrameMode:     Frame mode.
 *
 * @param[out]   N/A.
 *
 *
 * @return       Status of AMG8833_SetFrameMode.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_SetFrameMode ( AMG8833_fpsc_t myFrameMode )
{
    char     cmd[]  =  { 0U, 0U };
    uint32_t aux;


    /* Update the register */
    cmd[0]   =   AMG8833_FPSC;
    cmd[1]   =   myFrameMode;
    aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ), false );


    
    if ( aux == I2C_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_SetInterruptFunctionMode ( AMG8833_intmod_t , AMG8833_inten_t )
 *
 * @details     It sets interrupt function mode.
 *
 * @param[in]    myInterruptMode:   Interrupt mode.
 * @param[in]    myInterruptOutput: Interrupt output mode.
 *
 * @param[out]   N/A.
 *
 *
 * @return       Status of AMG8833_SetInterruptFunctionMode.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_SetInterruptFunctionMode ( AMG8833_intmod_t myInterruptMode, AMG8833_inten_t myInterruptOutput )
{
    char     cmd[]  =  { 0U, 0U };
    uint32_t aux;


    /* Update the register */
    cmd[0]   =   AMG8833_INTC;
    cmd[1]   =   ( myInterruptMode | myInterruptOutput );
    aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ), false );


    
    if ( aux == I2C_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_GetStatusRegisterValue ( uint8_t* )
 *
 * @details     It gets the status register value.
 *
 * @param[in]    N/A.
 *
 * @param[out]   myStatusRegisterValue: Current status register value.
 *
 *
 * @return       Status of AMG8833_GetStatusRegisterValue.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_GetStatusRegisterValue ( uint8_t* myStatusRegisterValue )
{
    char     cmd  =  0U;
    uint32_t aux;


    /* Update the register */
    cmd   =   AMG8833_STAT;
    aux   =   _i2c.write ( _AMG8833_Addr, &cmd, 1U, true );
    aux   =   _i2c.read  ( _AMG8833_Addr, &cmd, 1U );
    

    /* Parse data  */
    *myStatusRegisterValue  =   cmd;


    
    if ( aux == I2C_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_ClearFlags (  uint8_t )
 *
 * @details     It clears overflow and/or interrupt flags.
 *
 * @param[in]    myFlagsToBeCleared:  OVT_CLR_THERMISTOR_TEMPERATURE_OVERFLOW_CLEAR_FLAG and/or 
 *                                    OVS_CLR_TEMPERATURE_OVERFLOW_CLEAR_FLAG and/or 
 *                                    INTCLR_INTERRUPT_OUTBREAK_CLEAR_FLAG.
 *
 * @param[out]   N/A.
 *
 *
 * @return       Status of AMG8833_ClearFlags.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_ClearFlags ( uint8_t myFlagsToBeCleared )
{
    char     cmd[]  =  { 0U, 0U };
    uint32_t aux;


    /* Update the register */
    cmd[0]   =   AMG8833_SCLR;
    cmd[1]   =   myFlagsToBeCleared;
    aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ), false );


    
    if ( aux == I2C_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_SetAverageOutputMode ( AMG8833_mamod_t )
 *
 * @details     It sets twice moving average output mode.
 *
 * @param[in]    myAverageOutputMode: Average output mode.
 *
 * @param[out]   N/A.
 *
 *
 * @return       Status of AMG8833_SetAverageOutputMode.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_SetAverageOutputMode ( AMG8833_mamod_t myAverageOutputMode )
{
    char     cmd[]  =  { 0U, 0U };
    uint32_t aux;


    /* Update the register */
    cmd[0]   =   AMG8833_AVE;
    cmd[1]   =   myAverageOutputMode;
    aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ), false );


    
    if ( aux == I2C_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_SetInterruptLevel ( int16_t , int16_t )
 *
 * @details     It sets interrupt level upper/lower limit.
 *
 * @param[in]    myUpperLimit:    Interrupt Level upper limit.
 * @param[in]    myLowerLimit:    Interrupt Level loweer limit.
 *
 * @param[out]   N/A.
 *
 *
 * @return       Status of AMG8833_SetInterruptLevel.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_SetInterruptLevel ( int16_t myUpperLimit, int16_t myLowerLimit )
{
    char     cmd[]  =  { 0U, 0U };
    uint32_t aux;

    /* 12 bit resolution ( 11 bit + sign ) only   */
    if ( ( ( myUpperLimit < -4095 ) || ( myUpperLimit > 4095 ) ) || ( ( myLowerLimit < -4095 ) || ( myLowerLimit > 4095 ) ) )
    {
      return   AMG8833_FAILURE;
    }
    else
    {
      /* Update upper limit  */
      /* Update the register: INTHL */
      cmd[0]   =   AMG8833_INTHL;
      cmd[1]   =   (uint8_t)( myUpperLimit & 0x00FF );
      aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ), false );

      /* Update the register: INTHH */
      cmd[0]   =   AMG8833_INTHH;
      cmd[1]   =   (uint8_t)( ( myUpperLimit >> 8U ) & LIMIT_HYSTERESIS_INTHH_MASK );
      aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ), false );

      /* Update lower limit  */
      /* Update the register: INTLL */
      cmd[0]   =   AMG8833_INTLL;
      cmd[1]   =   (uint8_t)( myLowerLimit & 0x00FF );
      aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ), false );

      /* Update the register: INTLL */
      cmd[0]   =   AMG8833_INTLH;
      cmd[1]   =   (uint8_t)( ( myLowerLimit >> 8U ) & LIMIT_HYSTERESIS_INTLH_MASK );
      aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ), false );
    }



    
    if ( aux == I2C_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_SetHysteresisLevel ( int16_t )
 *
 * @details     It sets interrupt hysteresis level when interrupt is generated.
 *
 * @param[in]    myHysteresisLimit: Interrupt Hysteresis Level when Interrupt is generated.
 *
 * @param[out]   N/A.
 *
 *
 * @return       Status of AMG8833_SetHysteresisLevel.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_SetHysteresisLevel ( int16_t myHysteresisLimit )
{
    char     cmd[]  =  { 0U, 0U };
    uint32_t aux;

    /* 12 bit resolution ( 11 bit + sign ) only   */
    if ( ( myHysteresisLimit < -4095 ) || ( myHysteresisLimit > 4095)  )
    {
      return   AMG8833_FAILURE;
    }
    else
    {
      /* Hysteresis: Update the register: IHYSL */
      cmd[0]   =   AMG8833_IHYSL;
      cmd[1]   =   (uint8_t)( myHysteresisLimit & 0x00FF );
      aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ), false );

      /* Hysteresis: Update the register: IHYSH */
      cmd[0]   =   AMG8833_IHYSH;
      cmd[1]   =   (uint8_t)( ( myHysteresisLimit >> 8U ) & LIMIT_HYSTERESIS_IHYSH_MASK );
      aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ), false );
    }



    
    if ( aux == I2C_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_GetThermistorRawData ( AMG8833_data_t* )
 *
 * @details     It gets thermistor raw temperature data.
 *
 * @param[in]    N/A.
 *
 * @param[out]   myThermistorRawData: Thermistor raw temperature data.
 *
 *
 * @return       Status of AMG8833_GetThermistorRawData.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_GetThermistorRawData ( AMG8833_data_t* myThermistorRawData )
{
    char     cmd[2]  =  { 0U };
    uint32_t aux;

    /* Read the register */
    cmd[0]   =   AMG8833_TTHL;
    aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], 1U, true );
    aux      =   _i2c.read  ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );

    /* Parse the data  */
    myThermistorRawData->termistorOutputRawValue   =   cmd[1];
    myThermistorRawData->termistorOutputRawValue <<=   8U;
    myThermistorRawData->termistorOutputRawValue  |=   cmd[0];



    
    if ( aux == I2C_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_GetThermistorValue ( AMG8833_data_t* )
 *
 * @details     It gets thermistor temperature data.
 *
 * @param[in]    N/A.
 *
 * @param[out]   myThermistorValue: Thermistor temperature data.
 *
 *
 * @return       Status of AMG8833_GetThermistorValue.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_GetThermistorValue ( AMG8833_data_t* myThermistorValue )
{
    float                     mySign = 0.0;
    AMG8833::AMG8833_status_t aux;

    /* Get thermistor raw temperature data   */
    aux  =   AMG8833::AMG8833_GetThermistorRawData ( myThermistorValue );
    
    /* Check if the temperature is negative  */
    if ( ( myThermistorValue->termistorOutputRawValue & 0x800 ) == 0x800 )
    {
      myThermistorValue->termistorOutputRawValue  &=  0x800;
      mySign   =  -1.0;
    }
    else
    {
      mySign   =   1.0;
    }


    /* Parse the data  */
    myThermistorValue->termistorOutputValue  =   ( mySign ) * ( (float)( myThermistorValue->termistorOutputRawValue * THERMISTOR_RESOLUTION ) );



    
    if ( aux == AMG8833_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_GetPixelInterruptTable ( AMG8833_data_t* )
 *
 * @details     It gets pixel interrupt table.
 *
 * @param[in]    N/A.
 *
 * @param[out]   myPixelInterruptTable: Pixel interrupt table.
 *
 *
 * @return       Status of AMG8833_GetPixelInterruptTable.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_GetPixelInterruptTable ( AMG8833_data_t* myPixelInterruptTable )
{
    char     cmd  =  0U;
    uint32_t aux;

    /* Get pixel interrupt table */
    cmd   =   AMG8833_INT0;
    aux   =   _i2c.write ( _AMG8833_Addr, &cmd, 1U, true );
    aux   =   _i2c.read  ( _AMG8833_Addr, (char*)&myPixelInterruptTable->pixelInterruptTable[0], 64U );



    
    if ( aux == I2C_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_GetPixelRawTemperatures ( AMG8833_data_t* )
 *
 * @details     It gets pixel raw temperature data.
 *
 * @param[in]    N/A.
 *
 * @param[out]   myPixelRawTemperatureData: Pixel raw temperature data.
 *
 *
 * @return       Status of AMG8833_GetPixelRawTemperatures.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019  The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_GetPixelRawTemperatures ( AMG8833_data_t* myPixelRawTemperatureData )
{
    char     cmd[128]      =  { 0U };
    uint8_t  i             =  0U;
    uint32_t aux;

    /* Get pixel raw temperature value */
    cmd[0]   =   AMG8833_T01L;
    aux      =   _i2c.write ( _AMG8833_Addr, &cmd[0], 1U, true );
    aux      =   _i2c.read  ( _AMG8833_Addr, &cmd[0], sizeof( cmd )/sizeof( cmd[0] ) );
    
    

    for ( i = 0U; i < ( 64U ); i++ )
    {
      myPixelRawTemperatureData->pixelOutputRawValues[i]    = cmd[( i << 1U ) + 1U];
      myPixelRawTemperatureData->pixelOutputRawValues[i]  <<= 8U;
      myPixelRawTemperatureData->pixelOutputRawValues[i]   |= cmd[( i << 1U )];
    }



    
    if ( aux == I2C_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}



/**
 * @brief       AMG8833_GetPixelTemperatures ( AMG8833_data_t* )
 *
 * @details     It gets pixel temperature value in Celsius degrees.
 *
 * @param[in]    N/A.
 *
 * @param[out]   myPixelTemperatureData:  Pixel temperature data.
 *
 *
 * @return       Status of AMG8833_GetPixelTemperatures.
 *
 *
 * @author      Manuel Caballero
 * @date        11/January/2019
 * @version     11/January/2019   The ORIGIN
 * @pre         N/A.
 * @warning     N/A.
 */
AMG8833::AMG8833_status_t  AMG8833::AMG8833_GetPixelTemperatures ( AMG8833_data_t* myPixelTemperatureData )
{
    uint8_t                   i      = 0U;
    float                     mySign = 0.0;
    AMG8833::AMG8833_status_t aux;

    /* Get pixel raw temperature data   */
    aux  =   AMG8833::AMG8833_GetPixelRawTemperatures ( myPixelTemperatureData );
    

    /* Parse the data  */
    for ( i = 0U; i < 64U; i++ )
    {
      /* Check if the temperature is negative  */
      if ( ( myPixelTemperatureData->pixelOutputRawValues[i] & 0x800 ) == 0x800 )
      {
        myPixelTemperatureData->pixelOutputRawValues[i]  =  ~myPixelTemperatureData->pixelOutputRawValues[i];
        myPixelTemperatureData->pixelOutputRawValues[i] +=  1U;
        mySign   =  -1.0;
      }
      else
      {
        mySign   =   1.0;
      }


      /* Parse the data  */
      myPixelTemperatureData->pixelOutputValues[i]  =   ( mySign ) * ( (float)( myPixelTemperatureData->pixelOutputRawValues[i] * TEMPERATURE_RESOLUTION ) );

    }
    

    
    if ( aux == AMG8833_SUCCESS )
    {
        return   AMG8833_SUCCESS;
    }
    else
    {
        return   AMG8833_FAILURE;
    }
}