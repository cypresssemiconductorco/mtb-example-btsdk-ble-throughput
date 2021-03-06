/******************************************************************************
* File Name:   tput_client_ble.h
*
* Description: Header file for tput_client_ble.c
*
* Related Document: See README.md
*
*******************************************************************************
* (c) 2020, Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* ("Software"), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries ("Cypress") and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software ("EULA").
*
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress's integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer of such
* system or application assumes all risk of such use and in doing so agrees to
* indemnify Cypress against all liability.
*******************************************************************************/

#ifndef TPUT_CLIENT_BLE_H_
#define TPUT_CLIENT_BLE_H_

/*******************************************************************************
 *                                           EXTERNS and FUNCTIONS
 ******************************************************************************/
wiced_bt_dev_status_t             tput_management_callback( wiced_bt_management_evt_t, wiced_bt_management_evt_data_t* );
static wiced_bt_gatt_status_t     tput_gattc_callback( wiced_bt_gatt_evt_t event, wiced_bt_gatt_event_data_t *p_event_data );
static wiced_bt_gatt_status_t     enable_disable_gatt_notification( uint8_t notify );
static void                       tput_app_sec_timeout( uint32_t );
static void                       tput_app_msec_timeout( uint32_t );
static void                       tput_btn_interrupt_handler( void*, uint8_t );
static void                       tput_scan_result_cback( wiced_bt_ble_scan_results_t *p_scan_result, uint8_t *p_adv_data );
static void                       tput_init( void );
static void                       tput_gattc_connection_down( void );
static void                       tput_gattc_connection_up( wiced_bt_gatt_connection_status_t *p_status );
static void                       tput_gattc_conn_status_cb( wiced_bt_gatt_connection_status_t *p_status );
static uint16_t                   get_write_cmd_pkt_size( uint16_t att_mtu_size );

/******************************************************************************
 *                    Structures and Enumerations
 ******************************************************************************/
typedef struct
{
    BD_ADDR     remote_addr;  /* remote peer device address */
    uint16_t    conn_id;  /* connection ID referenced by the stack */
    uint16_t    peer_mtu; /* peer MTU */
} tput_conn_state_t;

typedef enum
{
    GATT_Notif_StoC,        /* Server to Client Notifications */
    GATT_Write_CtoS,         /* Client to Server GATT writes   */
    GATT_NotifandWrite     /* Both Notifications and GATT writes */
}tput_mode_t;

/******************************************************************************
 *                                Constants
 ******************************************************************************/

#define TIMER_PRINT_TPUT                 (1) /* Print throughput output every one second */
#define TIMER_GENERATE_DATA              (1) /* Send gatt writes every millisecond */
#define GATT_CCCD_HANDLE                 (3) /* CCCD handle in GATT DB */
#define GATT_WRITE_HANDLE                (5) /* Handle to write field in GATT DB */
#define GATT_CONNECT_LED                 LED1
#define CONGESTION_LED                   LED2
#define CCCD_LENGTH                      (2)
#define GATT_WRITE_BYTES_MAX_LEN         (495)
#define CONN_INTERVAL_MAJOR(a)           (a / 100)
#define CONN_INTERVAL_MINOR(a)           (a % 100)
#define CONN_INTERVAL_MULTIPLIER         (125)
#define DISCOVER_TPUT_SERVICE_UUID       {0xCCu, 0x7Bu, 0xCBu, 0x32u, 0x07u, 0x08u, 0x17u, 0xAFu,\
                                          0xD3u, 0x43u, 0x1Eu, 0x5Du, 0x20u, 0x0Du, 0xECu, 0x1Au}

#endif /* TPUT_CLIENT_BLE_H_ */
