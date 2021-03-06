
## 安装docker（参考docker官网和nvidia-docker的github）

### 【0】. 卸载旧版本.
```
sudo apt-get remove docker \
    docker-engine \
    docker.io
```

### 【1】. 由于 apt 源使用 HTTPS 以确保软件下载过程中不被篡改。因此，我们首先需要添加使用 HTTPS 传输的软件包以及 CA 证书。
```
sudo apt-get update
sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common
```

### 【2】. 为了确认所下载软件包的合法性，需要添加软件源的 GPG 密钥。
```
curl -fsSL https://mirrors.ustc.edu.cn/docker-ce/linux/ubuntu/gpg | sudo apt-key add -
```

### 【3】. 向 source.list 中添加 Docker 软件源
```
sudo add-apt-repository \
    "deb [arch=amd64] https://mirrors.ustc.edu.cn/docker-ce/linux/ubuntu \
    $(lsb_release -cs) \
    stable"
```

### 【4】. 更新 apt 软件包缓存，并安装 docker-ce
```
sudo apt-get update
sudo apt-get install docker-ce
```

### 【5】. 启动 Docker CE
```
sudo systemctl enable docker
sudo systemctl start docker
```

### 【6】. 将当前用户加入 docker 组
```
sudo usermod -aG docker $USER
```

### 【7】. 测试 Docker 是否安装正确
```
sudo docker run hello-world
```

### 【8】. nvidia-docker安装
```
distribution=$(. /etc/os-release;echo $ID$VERSION_ID)
curl -s -L https://nvidia.github.io/nvidia-docker/gpgkey | sudo apt-key add -
curl -s -L https://nvidia.github.io/nvidia-docker/$distribution/nvidia-docker.list | sudo tee /etc/apt/sources.list.d/nvidia-docker.list
sudo apt-get update
sudo apt-get install -y nvidia-container-toolkit
sudo systemctl restart docker
```

### 【9】. 重启电脑让【6】加入用户组生效
```
sudo reboot
```



## docker命令

### 【1】. 交互式运行docker
```
docker run -it --rm --gpus 0 dric_server:v1.3.0 /bin/bash
[-i] 让容器的标准输入保持打开
[--rm] 停止后自动删除容器
[--gpus 0] docker可以使用gps0，新版本docker包括了nvidia-docker，直接指定可以使用的gpu即可
[dric_server:v1.3.0] 需要运行的镜像名称和tag
[/bin/bash] 运行后打开bash，这样才能交互式运作。
```

### 【2】. 查镜像
```
docker images
```

### 【3】. 删除镜像
```
docker rmi $IMAGE_ID
[$IMAGE_ID] 通过【2】可以查得到

docker image prune           # rm all images <none>
```

### 【4】. 查容器
```
docker container ps -a
```

### [5]. 本地文件复制进容器
```
docker cp $PATH_TO_COPY $CONTAINER_ID:$CONTAINER_PATH
[$PATH_TO_COPY] 宿主机器存放文件的路径（被复制文件）
[$CONTAINER_ID] 某运行中的容器id，通过【4】可以查得到
[$CONTAINER_PATH] 容器内的具体地址（要复制到哪里）
```

### [6]. 上线运行容器
```
docker run --privileged true -p 60101:60101 --restart always -v /home/lee/DRICServer-v1.3.0/log:/home/zjsmart/DRICServer/log --gpus 0 -d DRICServer:v1.3.0 /bin/sh -c 'cd /home/zjsmart/DRICServer && bash run.sh'
[--privileged true] 开放宿主系统的所有设备权限
[-p 60101:60101] 端口映射，宿主：容器
[--restart always] 服务死了自动重启
[-v] 文件夹映射，宿主：容器
[--gpus 0] 允许使用宿主gpu0
[DRICServer:v1.3.0] 具体运行哪个镜像，可以直接运行docker-hub云端的镜像（会自动下载到本地）
[-d] 后台运行容器，返回容器的id
[-c ''] 本容器执行-c后单引号内的指令 
```

### [7]. 导出镜像文件（导出来是为了复制到其他系统里面再加载，本机使用不需要导出）
```
docker save -o $MY_IMAGE_PACK_NAME.tar $IMAGE_NAME:$IMAGE_TAG
[$MY_IMAGE_PACK_NAME.tar] 输出的镜像包的路径（含文件名称）
[$IMAGE_NAME] 通过【4】查得到的镜像名称。docker-hub云端先通过【6】运行一次，本地就会有记录。
[$IMAGE_TAG] 这个镜像的具体版本，如果缺省的话，会把本地所有的同名镜像打包成一个包。
```

### [8]. 加载镜像文件
```
docker load -i $MY_IMAGE_PACK_NAME.tar
[$MY_IMAGE_PACK_NAME.tar] 镜像包的路径（含文件名称）
```

### [9]. 生成镜像（不是导出镜像文件）
```
docker build -t $IMAGE_NAME:$IMAGE_TAG .
[$IMAGE_NAME:$IMAGE_TAG] 自己定义的镜像名称，tag一般是v1.0.0这种版本号
[.] 从当前目录（./）寻找Dockerfile来生成镜像。
```

### [10]. 停止容器
```
docker container stop $IMAGE_ID
```

### [11]. 删除容器
```
docker container rm $IMAGE_ID

docker container prune       # rm all containers exited
```


## Dockerfile范例
```
FROM tensorflow/tensorflow:1.9.0-devel-gpu-py3
RUN apt-get update \
    && pip install --upgrade pip -i https://mirrors.aliyun.com/pypi/simple/ \
    && mkdir -p /home/zjsmart/Downloads \
COPY ./boost_1_69_0.zip /home/zjsmart/Downloads
RUN cd /home/zjsmart/Downloads \
    && unzip boost_1_69_0.zip \
    && cd boost_1_69_0 \
    && ./bootstrap.sh --with-libraries=python --with-toolset=gcc \
    && ./b2 cflags='-fPIC' cxxflags='-fPIC' --with-python include="/usr/include/python3.5m" \
    && ./b2 install \
    && cd /usr/local/lib \
    && ln -s libboost_python35.a libboost_python3.a \
    && ln -s libboost_python35.so libbost_python3.so

[FROM] 以哪个镜像为蓝本构建
[RUN] 相当于在bash中执行语句，启动gedit，vim，source等交互式的语句在制作镜像的时候是不管用的。
[COPY] 从本机的复制文件到镜像中
注意每执行一次[FROM][RUN][COPY]都会生成一个镜像缓存，并且最后的镜像会相对大很多，缓存会被下次制作重复使用（如果没有修改的话）
```




## 部署步骤
```
1. 将修改好的代码/程序放入到对应的源码文件夹；
2. 看是否需要修改Dockerfile，如何修改请进入相关应用的文件夹查看说明；
3. 生成镜像：（本地生成后导出tar发送到服务器，或者直接在服务器生成）
4. 线上运行容器；
```

## 云镜像网站（找到名称之后，直接docker run就自动下载了）
```
https://hub.docker.com/
https://hub.docker.com/r/nvidia/cuda/
https://hub.docker.com/r/tensorflow/tensorflow/
https://ngc.nvidia.com/catalog/containers/nvidia:tensorrt
https://gitlab.com/nvidia/cuda/tree/master/dist
```
