#include <zephyr/kernel.h>
#include <zephyr/drivers/uart.h>

const struct device *uart = DEVICE_DT_GET(DT_NODELABEL(uart0));

    

/** 
 * @brief UART controller configuration structure
 * 
 * @param baudrate Baudrate setting in bps
 * @param parity Parity bit, use @ref uart_config_parity
 * @param stop_bits Stop bits, use @ref uart_config_stop_bits
 * @param data_bits Data bits, use @ref uart_config_data_bits
 * @param flow_ctrl Flow control setting, use @ref uart_config_flow_control
*/

//UART configurations
/*struct uart_config {
    uint32_t baudrate;
    uint8_t parity;
    uint8_t stop_bits;
    uint8_t data_bits;
    uint8_t flow_ctrl;
};*/
const struct uart_config uart_cfg = {
		.baudrate = 115200,
		.parity = UART_CFG_PARITY_NONE,
		.stop_bits = UART_CFG_STOP_BITS_1,
		.data_bits = UART_CFG_DATA_BITS_8,
		.flow_ctrl = UART_CFG_FLOW_CTRL_NONE
};

//Pass the UART API function to the variable uart_config



//Callback Function
static void uart_cb(const struct device *dev, struct uart_event *evt, void *user_data)
{
	switch (evt->type) {
	
	case UART_TX_DONE:
		// do something
		break;

	case UART_TX_ABORTED:
		// do something
		break;
		
	case UART_RX_RDY:
		// do something
		break;

	case UART_RX_BUF_REQUEST:
		// do something
		break;

	case UART_RX_BUF_RELEASED:
		// do something
		break;
		
	case UART_RX_DISABLED:
		uart_rx_enable(dev, rx_buf, sizeof(rx_buf), 100);//re-enable to continuously receive the data
		break;

	case UART_RX_STOPPED:
		// do something
		break;
		
	default:
		break;
	}
};

/** @brief Structure containing information about current event. */
//struct uart_event {
    /** @brief Type of event */
    //enum uart_event_type type;
    /** @brief Event data */
    //union uart_event_data {
        /** @brief @ref uart_event_type: :UART_TX_DONE and
         * @ref uart_event_type::UART_TX_ABORTED events data.
         */
        //struct uart_event_tx tx;
        /** @brief @ref uart_event_type:: UART_RX_RDY event data.  */
        //struct uart_event_rx rx; //will hold the incoming data over UART
        /** @brief @ref uart_event_type:: UART_RX_BUF_RELEASED event data.*/
        //struct uart_event_rx_buf rx_buf;
        /** @brief @ref uart_event_type::UART_RX_STOPPED event data. */
        //struct uart_event_rx_stop rx_stop;
    //} data;
//};

/** @brief UART RX event data.
 * 
 * The data represented by the event is stored in rx.buf(rx.offset) to 
 * rx.buf[rx.offset+rx.len]. That is, the length is relative to the offset.
 */
//struct uart_event_rx {
    /** @brief Pointer to current buffer. */
    //uint8_t *buf;
    /** @brief Currently received data offset in bytes. */
    //size_t offset;
    /** @brief Number of new bytes received. */
    //size_t len;
//};
//Register callback function

/** @brief Receiving the data.  */
static uint8_t rx_buf[10] = {0}; //A buffer to store incoming UART data 
    uart_rx_enable(uart, rx_buf, sizeof(rx_buf), 100); //pass the address to receive the buffer


/** @brief Transmitting buffer to hold the dats to be sent */
static uint8_t tx_buf[] =  {"nRF Connect SDK Fundamentals Course \n\r"}; //defined a transmition buffer



int main(void){
    int err = uart_configure(uart, &uart_cfg);
    if (!device_is_ready(uart)) {
        return;
    }
    if (err == -ENOSYS) {
    return -ENOSYS;
    }
    err = uart_tx(uart, tx_buf, sizeof(tx_buf), SYS_FOREVER_US); //function returned immediately and sending managed internally by UART driver
    if (err) {
        return err;
    }
    err = uart_callback_set(uart, uart_cb, NULL);
    if (err) {
        return err;
    }
    

    return 0;
}
