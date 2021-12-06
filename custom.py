import DAN

ServerURL='http://DN:9999' 
Comm_interval = 15 # unit:second

def profile_init():
    DAN.profile['dm_name']='Sensor680'
    DAN.profile['d_name']='SN-'+DAN.get_mac_addr()[-4:]

def odf():  # int only
    return []

def idf():
    return [
       ('AtPressure', int),
       ('Humidity', int),
       ('Temperature', float),
    ]
