#when stood up on aws via python websocket_sms_server.py
#and 'hit' with a websocket msg
#this script will contact the twilio REST API
#which will send a SMS to the google voice number

import tornado.httpserver
import tornado.websocket
import tornado.ioloop
import tornado.web
from twilio.rest import TwilioRestClient

#twilio creds
account_sid = "AC703eaac6e7bf48fce8b73d523288db0c"
auth_token = "023edb059ce01e9b25a000c191ad64c1"
client = TwilioRestClient(account_sid, auth_token)

#need a validated "to" number for twilio trial
gv_num = "+15622732511"

#twilio number
twilio_num = "+12055189895"



class WSHandler(tornado.websocket.WebSocketHandler):
    def open(self):
        print 'new connection'
        self.write_message("Hello World")

    def on_message(self, message):
        print 'message received %s' % message
        twilio_msg = client.messages.create(to=gv_num, from_= twilio_num,
                                     body="garage open too long!")
        print 'twilio message: %s' %twilio_msg

    def on_close(self):
      print 'connection closed'

    def check_origin(self,origin):
        return True


application = tornado.web.Application([
    (r'/ws', WSHandler),
])


if __name__ == "__main__":
    http_server = tornado.httpserver.HTTPServer(application)
    http_server.listen(8888)
    tornado.ioloop.IOLoop.instance().start()