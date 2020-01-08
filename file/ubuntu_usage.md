# ubuntu16.04

## ssh
```
sudo apt-get update
sudo apt-get install openssh-server
/etc/init.d/ssh start
sudo vim /etc/ssh/sshd_config
   port=60000                        # change port
sudo /etc/init.d/ssh restart
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


## add new disk
```
sudo fdisk -l                             # see disk name, such as /dev/sdb
sudo fdisk /dev/sdb                       # to make partitions, remove all files!
    m                                     # for help
    n                                     # add a new partition
    1                                     # partion number(1-4)
    \n                                    # use default for partition beginning
    \n                                    # use default for partition ending
    p                                     # show partition
    w                                     # save partition
sudo mkfs -t ext4 /dev/sdb                # format partitions, remove all files!
sudo mount -t ext4 /dev/sdb /media/sdb    # mount disk partitions
sudo vim /etc/fstab                       # set auto mount while switch pc
    /dev/sdb /media/sdb ext4 default 0 0  
sudo vim /etc/rc.local                    # or try set "auto-run"
    mount -t ext4 /dev/sdb /media/sdb
```



## gcc/g++

### gcc -g -D_GNU_SOURCE file.c -o out_app
```
使用gcc编译c代码
"-g" 使用gdb，即Debug模式编译
"-D_GNU_SOURCE" 即#define _GNU_SOURCE，一个GNU的标准宏
"file.c" 待编译的文件名
"-o" 定义输出
"out_app" -o所定义的输出文件全名
```

### gdb ./out_app out_app_log
```
使用gdb显示出错的地方，需要先执行并生成错误文件
"out_app" 运行程序文件名称
"out_app_log" 运行出错时生成的文档名称
```

### gcc -c -D_GNU_SOURCE -Wall file.c
```
生成.o中间文件，最好用“-o ***.o”来定义输出文件名称，.o不是共享库
"-c" 源码被编译成中间文件.o
"-Wall" Warning最高等级
```


### g++-5 -std=c++0x eye_blink_detector.cpp test.cpp -o test -I/home/ubuntu/dlib-19.9/include -L/home/ubuntu/dlib-19.9/build/dlib -pthread -ldlib 
```
"g++-5" 版本为5的g++
"-std=c++0x" 使用c++标准0x，是c++11出来前的标准
"-I/path" 设置include路径，一次设置一个路径，标识是大写i
"-L/path" 设置动态库和静态库的路径，一次设置一个路径，标识是大写L
"-pthread" 即pthread的库，特殊标记，不用-l
"-ldlib" 添加依赖库，依赖库名称一般为lib***.a，lib***.so，标识是小写L
待编译的cpp应该放在输出和依赖库前面
cpp顺序：被依赖的排前面
依赖库顺序：被依赖的排前面
```

### g++ -shared -fPIC mymethod.cpp -o libmymethod.so
```
"-share" 生成动态库文件.so
"-fPIC" 表示代码是和地址无关的，不需要被不同模块重定位
```

### g++ -O3 main.cpp -o main -ldlib
```
"-O3" 运行效率优化等级3（最高），最低等级为0（不优化），可以优化静态库和动态库里面的运行效率
```


