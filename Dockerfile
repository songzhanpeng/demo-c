# 使用基础镜像
FROM ubuntu:latest

# 更新软件包列表并安装必要的软件包
RUN apt-get update && apt-get install -y \
    nodejs \
    npm \
    gcc \
    && rm -rf /var/lib/apt/lists/*

# 设置工作目录
WORKDIR /usr/src/app

# 将本地文件复制到容器中
# COPY hello.c .
COPY . .

# 编译生成共享对象文件
RUN gcc -shared -fPIC -o hello.so hello.c

# 拷贝共享对象文件到工作目录外部
CMD ["cp", "hello.so", "/mnt"]
