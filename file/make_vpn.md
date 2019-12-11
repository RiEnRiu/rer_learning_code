## install pptp-linux
```
sudo apt-get install pptp-linux
```

## some macro
```
$VPN myvpn
$IP 192.168.1.1
$UN yyy
$PW 123456
```

## run pptpsetp
```
sudo pptpsetup --create $VPN --server $IP --username $UN --password $PW --encrypt --start
```

## change $VPN first then make "checkvpn" file as below
```
#!/bin/sh
#This shell is created by masterjkk (v@kkmir.cn)
while true
do
if [ -f "/tmp/vpn_status_check.lock" ]
then
        exit 0
fi
VPN_CONN=`ifconfig | grep ppp0`

if [ -z "$VPN_CONN" ]
then
        touch /tmp/vpn_status_check.lock
        echo WAN_VPN_RECONNECT at: >> /tmp/vpn_status_check_reconn.log
        date >> /tmp/vpn_status_check_reconn.log
        pon $VPN
        sleep 20
        route add -net 192.168.2.0/24 gw 192.168.2.1
        rm /tmp/vpn_status_check.lock
else
        date > /tmp/vpn_status_check.log
        sleep 5
fi
done

```

## auto run after computer boot
```
mv checkvnp /bin
sudo chmod +x /bin/checkvpn
vim /etc/rc.local
    sudo /bin/checkvpn &        #before "exit 0"
```