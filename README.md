wiflyws
=======
run server.py (python tornado imp of websockets) on aws or some reachable ip
can use client.py for testing but not needed for wifly itself

for example in main.cpp we create an instance of a ws
	Websocket ws("ws://54.68.226.181:8888/ws")
assuming we are running server.py at the ip/port in above constructor

also note that the "/ws" is consistent with servery.py :

	application = tornado.web.Application([
    	(r'/ws', WSHandler),
	])

modified wifly.h and wifly.cpp to add WEP_64 enum per wifly [documentation][id]
[id]: http://ww1.microchip.com/downloads/en/DeviceDoc/rn-wiflycr-ug-v1.2r.pdf

used to set security mode and key in wifly.cpp 'join' method

