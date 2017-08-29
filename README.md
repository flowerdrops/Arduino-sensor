# Arduino-sensor
Create a wireless sensor network using arduino

  I am using the arduino MKR1000 board
  You should create a wifi shield on your laptop. (I use the 360 free wifi)
  The default wifi ssid is "sjj" and the password is "aaa123456", you can change them as you like
  Once the board is connected to the wifi, it would create a new IP address. This IP address is changable so you may need to find what it is by adding the "IPAddress ip = WiFi.localIP();" command and print it in the Serial. More details can be found in WiFi101 example.
  When the code is uploaded, the IP address won't change anymore
  I set the DNS name as "http://www.sjjdata.local/". You can change it, of course.
  
Tips:
  DO NOT press the MKR1000 board into the black sponge(or something else). It might disable the board.  
