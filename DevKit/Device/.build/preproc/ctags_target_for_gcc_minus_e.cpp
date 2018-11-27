# 1 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino"
# 1 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino"
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 
// To get started please visit https://microsoft.github.io/azure-iot-developer-kit/docs/projects/connect-iot-hub?utm_source=ArduinoExtension&utm_medium=ReleaseNote&utm_campaign=VSCode
# 5 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino" 2
# 6 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino" 2
# 7 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino" 2

# 9 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino" 2
# 10 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino" 2
# 11 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino" 2

static bool hasWifi = false;
int messageCount = 1;
static bool messageSending = true;
static uint64_t send_interval_ms;

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Utilities
static void InitWifi()
{
  Screen.print(2, "Connecting...");

  if (WiFi.begin() == WL_CONNECTED)
  {
    IPAddress ip = WiFi.localIP();
    Screen.print(1, ip.get_address());
    hasWifi = true;
    Screen.print(2, "Running... \r\n");
  }
  else
  {
    hasWifi = false;
    Screen.print(1, "No Wi-Fi\r\n ");
  }
}

static void SendConfirmationCallback(IOTHUB_CLIENT_CONFIRMATION_RESULT result)
{
  if (result == IOTHUB_CLIENT_CONFIRMATION_OK)
  {
    blinkSendConfirmation();
  }
}

static void MessageCallback(const char* payLoad, int size)
{
  blinkLED();
  Screen.print(1, payLoad, true);
}

static void DeviceTwinCallback(DEVICE_TWIN_UPDATE_STATE updateState, const unsigned char *payLoad, int size)
{
  char *temp = (char *)malloc(size + 1);
  if (temp == 
# 54 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino" 3 4
             __null
# 54 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino"
                 )
  {
    return;
  }
  memcpy(temp, payLoad, size);
  temp[size] = '\0';
  parseTwinMessage(updateState, temp);
  free(temp);
}

static int DeviceMethodCallback(const char *methodName, const unsigned char *payload, int size, unsigned char **response, int *response_size)
{
  do{{ LOGGER_LOG l = xlogging_get_log_function(); if (l != 
# 66 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino" 3 4
 __null
# 66 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino"
 ) l(AZ_LOG_INFO, (strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '/') ? strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '/') + 1 : (strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '\\') ? strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '\\') + 1 : "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino")), __func__, 66, 0x01, "Try to invoke method %s", methodName); }; }while((void)0,0);
  const char *responseMessage = "\"Successfully invoke device method\"";
  int result = 200;

  if (strcmp(methodName, "start") == 0)
  {
    do{{ LOGGER_LOG l = xlogging_get_log_function(); if (l != 
# 72 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino" 3 4
   __null
# 72 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino"
   ) l(AZ_LOG_INFO, (strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '/') ? strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '/') + 1 : (strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '\\') ? strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '\\') + 1 : "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino")), __func__, 72, 0x01, "Start sending temperature and humidity data"); }; }while((void)0,0);
    messageSending = true;
  }
  else if (strcmp(methodName, "stop") == 0)
  {
    do{{ LOGGER_LOG l = xlogging_get_log_function(); if (l != 
# 77 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino" 3 4
   __null
# 77 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino"
   ) l(AZ_LOG_INFO, (strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '/') ? strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '/') + 1 : (strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '\\') ? strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '\\') + 1 : "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino")), __func__, 77, 0x01, "Stop sending temperature and humidity data"); }; }while((void)0,0);
    messageSending = false;
  }
  else
  {
    do{{ LOGGER_LOG l = xlogging_get_log_function(); if (l != 
# 82 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino" 3 4
   __null
# 82 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino"
   ) l(AZ_LOG_INFO, (strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '/') ? strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '/') + 1 : (strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '\\') ? strrchr("c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino", '\\') + 1 : "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino")), __func__, 82, 0x01, "No method %s found", methodName); }; }while((void)0,0);
    responseMessage = "\"No method found\"";
    result = 404;
  }

  *response_size = strlen(responseMessage) + 1;
  *response = (unsigned char *)strdup(responseMessage);

  return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Arduino sketch
void setup()
{
  Screen.init();
  Screen.print(0, "IoT DevKit");
  Screen.print(2, "Initializing...");

  Screen.print(3, " > Serial");
  Serial.begin(115200);

  // Initialize the WiFi module
  Screen.print(3, " > WiFi");
  hasWifi = false;
  InitWifi();
  if (!hasWifi)
  {
    return;
  }

  LogTrace("HappyPathSetup", 
# 113 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino" 3 4
                            __null
# 113 "c:\\Users\\richn\\Documents\\IoTWorkbenchProjects\\examples\\devkit_getstarted\\Device\\GetStarted.ino"
                                );

  Screen.print(3, " > Sensors");
  SensorInit();

  Screen.print(3, " > IoT Hub");
  DevKitMQTTClient_SetOption("MiniSolution", "DevKit-GetStarted");
  DevKitMQTTClient_Init(true);

  DevKitMQTTClient_SetSendConfirmationCallback(SendConfirmationCallback);
  DevKitMQTTClient_SetMessageCallback(MessageCallback);
  DevKitMQTTClient_SetDeviceTwinCallback(DeviceTwinCallback);
  DevKitMQTTClient_SetDeviceMethodCallback(DeviceMethodCallback);

  send_interval_ms = SystemTickCounterRead();
}

void loop()
{
  if (hasWifi)
  {
    if (messageSending &&
        (int)(SystemTickCounterRead() - send_interval_ms) >= getInterval())
    {
      // Send teperature data
      char messagePayload[256];

      bool temperatureAlert = readMessage(messageCount++, messagePayload);
      EVENT_INSTANCE* message = DevKitMQTTClient_Event_Generate(messagePayload, MESSAGE);
      DevKitMQTTClient_Event_AddProp(message, "temperatureAlert", temperatureAlert ? "true" : "false");
      DevKitMQTTClient_SendEventInstance(message);

      send_interval_ms = SystemTickCounterRead();
    }
    else
    {
      DevKitMQTTClient_Check();
    }
  }
  delay(1000);
}
