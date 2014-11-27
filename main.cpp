#include "mbed.h"
#include "WiflyInterface.h"
#include "Websocket.h"


/* wifly interface:
*     - p9 and p10 are for the serial communication
*     - p19 is for the reset pin
*     - p26 is for the connection status
*     - "mbed" is the ssid of the network
*     - "password" is the password
*     - WPA is the security
*/
//WiflyInterface wifly(p9, p10, p25, p26, "mbed", "password", WPA);
//WiflyInterface wifly(p9, p10, p25, p26, "gaboo","");
//WiflyInterface wifly(p9, p10, p25, p26, "NJY08","c4e03dce94");
//WiflyInterface wifly(p9, p10, p25, p26,"","",);
char ssid[32]="NJY08";
char key[32]="c4e03dce94";
Security sec = WEP_64;
WiflyInterface wifly(p9, p10, p11, p26,ssid,key,sec);

int main() {
    // --testing--   
    //printf("entering cmdMode: \n"); 
    //wifly.cmdMode());
    //wifly.join();
    /*
    wifly.reset();
    wait_ms(5000);
    char response1[20];
    wifly.send("$$$", 3, "NO",response1,-1);
    wait_ms(10);
    printf("response: %s\n",response1);
    wait_ms(1000);
    char response2[100];
    wifly.send("show io\r", 10, "NO",response2,-1);
    wait_ms(10);
    printf("response: %s\n",response2);
    wait_ms(5000);
    char response3[20];
    wifly.send("exit\r", 6, "NO",response3,-1);
    printf("response: %s\n",response3);
    
    //wifly.reset();
    //char cmd[20];
    //sprintf(cmd, "scan\r");
    //char response[120];
    //wifly.sendCommand(cmd, "NO", NULL, 10000);
    //sprintf(cmd, "join NJY08\r");
    //char response[120];
    //printf("here's the cmd: %s\n", cmd);
    //wifly.sendCommand(cmd, "NO", response, -1);

    //printf("can i join: %s\n",response);
    //printf("can i join: %i\n",wifly.join());
    //-------end-testing-------------
    
    //printf("trying to reset\n");
    //wifly.reset();
    //wait(5.0);
    //printf("trying DHCP\n");
    //while(!wifly.init()); //Use DHCP
    */
    printf("telling wifly we'll use DHCP - e.g. init\n");
    wifly.init();
    wait_ms(1000);
    printf("joining ssid: %s\n", ssid);
    wifly.join();
    //wait_ms(5000);
    //while (!wifly.connect());
    printf("IP Address is %s\n\r", wifly.getIPAddress());


    //Websocket ws("ws://sockets.mbed.org:443/ws/jello/wo");
    //Websocket ws("ws://127.0.0.1:8888");
    Websocket ws("ws://54.68.226.181:8888/ws");
    //Websocket ws("ws://echo.websocket.org");
    while (!ws.connect()); 
    printf("are we connected: %b\n",ws.is_connected());

    while (1) {
            
            printf("sending message\n");
            printf("sent?:%b\n",ws.send("WebSocket Hello World over Wifly"));
            wait(1.0);
    }
    
}