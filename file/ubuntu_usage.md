## ssh
```
sudo apt-get update
sudo apt-get install openssh-server
/etc/init.d/ssh start
sudo vim /etc/ssh/sshd_config
   port=60000                        # change port
sudo /etc/init.d/ssh resart
ssh -p 60000 $USER@127.0.0.1         # an example for using ssh
```

## user 
```
sudo adduser $USERNAME               # add one user, export USERNAME="logger"
sudo chown -R $USER /home/$USERNAME  # assum $USER has root permissions
sudo chmod 700 $HOME                 # change root home dir permissions, r=4,w=2,x=1, 7/0/0 for $USER/$GROUP/others 
sudo chmod 755 /home/$USERNAME       # add permissions to $USER so that to save log in /home/$USERNAME

sudo passwd $USER                    # change $USER password
```

## ftp
```
sudo apt-get update
sudo apt-get install vsftpd
sudo vim /etc/vsftpd.conf
   write_enable=YES                  # change write_enable
sudo /etc/init.d/vsftpd restart
```

## set static ip
```
ifconfig                              # find network cards name such as ens33, export NETNAME="ens33"
sudo  vim /etc/network/interfaces
   auto $NETNAME
   iface $NETNAME inet static
   address 192.168.0.89
   netmask 255.255.255.0
   gateway 192.168.0.1
sudo vim /etc/resolvconf/resolv.conf.d/head
   nameserver 192.168.0.1
   nameserver 8.8.8.8
sudo /etc/init.d/networking restart
```

## auto-run
```
sudo vim /etc/rc.local       # auto-run after computer boot
    bash xxx
sudo vim $HOME/.bashrc       # auto-run when open terminal for user-self
    bash xxx
sudo vim /etc/bash.bashrc    # auto-run when open terminal for all users
    bash xxx
```

