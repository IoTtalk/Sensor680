# Sensor680

## Required BME680 library for Arduino IDE:
https://github.com/Seeed-Studio/Seeed_Arduino_BME68x

In Arduino IDE, please use "Add .ZIP Library" in "Include Library" of "Sketch" to add BME680 .ZIP library.

Also, the "Bridge" library is required which can be installed from "Manage Libraries..." (Library Manager).

## 安裝程序
在Arduino ATMega32u4端，要燒入以下INO檔

Sensor680/IDA_BME680/IDA_BME680.ino

https://github.com/IoTtalk/Sensor680/blob/master/IDA_BME680/IDA_BME680.ino


之後SSH登入ArduinoYun Linux介面後，輸入以下指令進行安裝程序。(要先讓Yun連上Internet才可執行下列指令)
```
wget http://yun.iottalk.tw/yunBME680DAinstall.tar.gz
tar zvxf yunBME680DAinstall.tar.gz
rm yunBME680DAinstall.tar.gz
chmod 700 yunBME680DAinstall.sh
./yunBME680DAinstall.sh
```

執行完上述指令後，會自動進入編輯config.py的狀態，

https://github.com/IoTtalk/Sensor680/blob/master/config.py

在config.py中，要填寫連線主機資訊(Lines 1 ~ 8)，填寫完成存檔後，斷電重啟板子後，看到白燈閃爍、紅燈亮起，即為成功運作。


## Device Model: 
本應用的IoTtalk Device Model 為
```
Sensor680
```

## Device Feature:
本應用的IoTtalk Input Device Feature (IDF) 為
```
idf_list = [
    ('Temperature', float),
    ('AtPressure', float),
    ('Humidity', float),
    ('Gas', float),
    ]

```





## 舊版說明，僅供參考
### SensorBox with Grove BME680

1. Arduino ATmega32u4 端，用Arduino IDE 燒入 IDA_BME680.ino，完成後，可用序列阜監控視窗驗證Arduino程式是否有正常運行。

2. Linux端環境安裝指令

    opkg update

    opkg install distribute

    opkg install python-openssl

    opkg install openssh-sftp-server

    wget http://yun.iottalk.tw/pip-10.0.1.tar.gz

    easy_install pip-10.0.1.tar.gz

    rm pip-10.0.1.tar.gz

    wget http://yun.iottalk.tw/requests-2.15.1-py2.py3-none-any.whl

    pip install requests-2.15.1-py2.py3-none-any.whl

    rm requests-2.15.1-py2.py3-none-any.whl


3. 上述運行環境準備好之後，再利用 SFTP (例如 WinSCP) 將 autoStart.py、csmapi.py、custom.py、DAI.py、DAN.py，上傳到Linux端root的目錄下。

4. 使用vi修改custom.py，將Line 3: ServerURL='http://DN:9999' 中的DN置換成IoTtalk server的DN。

5. 完成後執行 python autoStart.py 設定開機啟動執行 DAI.py

6. 下指令 python DAI.py ，測試運行，若成功啟動，並在IoTtalk server上看到數值後，之後板子直接上電就可以運行了。




