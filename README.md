# Sensor680

## 安裝程序
在Arduin ATMega32u4端，要燒入以下INO檔
https://github.com/IoTtalk/Sensor680/blob/master/IDA_BME680/IDA_BME680.ino


SSH登入ArduinoYun Linux介面後，輸入以下指令進行安裝程序。
```
wget http://yun.iottalk.tw/yunBME680DA.sh
chmod 700 yunBME680DA.sh
./yunBME680DA.sh
```

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




