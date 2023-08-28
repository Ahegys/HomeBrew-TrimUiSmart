# Use uma imagem base
FROM debian:bullseye

# Atualize os repositórios e instale as ferramentas necessárias
RUN apt-get update && apt-get install -y \
    g++-arm-linux-gnueabihf \
    qemu-user \
    zsh \
    cmake \
    make \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Configure o diretório de trabalho
WORKDIR /app

# Copie o código-fonte para o contêiner
COPY SOURCE_CODE /app/SOURCE_CODE

# Baixe e compile o SDL2
RUN wget https://www.libsdl.org/release/SDL2-2.0.14.tar.gz && \
    tar -xzvf SDL2-2.0.14.tar.gz && \
    cd SDL2-2.0.14 && \
    ./configure --host=arm-linux-gnueabihf --prefix=/usr && \
    make && \
    make install

# Defina o comando padrão que será executado quando o contêiner for iniciado
CMD ["zsh"]

