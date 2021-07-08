# Window opener


This repository contains the code for the window opener. 

## Setup
![wiring](https://raw.githubusercontent.com/CleanAIR-Building/Report/main/diagrams/Wiring_Stepper-Motor.png?token=AH5OOFK6K3XFGOWGB4OEVF3A45JF6)

Create a file called `data/Config.json`. It should look like this:

```json
{
  "ssid": "the ssid",
  "password": "the psk",
  "mqttAddress": "the ip",
  "mqttPort": 1883,
  "mqttUser": "the user",
  "mqttPassword": "the users password",
  "mqttTopic": "the topic you want to connect to",
  "mqttClientName": "The client name",
  "deviceType": "the device type"
 }
``` 
To upload your config file run `Upload Filesystem Image` from VScode or 
```json
pio run -e debug -t uploadfs
```
or
```json
pio run -e release -t uploadfs
```
depending on the environment you used.

## Messaging
Messages have the form:
```json
{ "command": "OPEN" }
```
or
```json
{ "command": "CLOSE" }
```
