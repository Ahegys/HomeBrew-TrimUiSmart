# Use uma imagem base
FROM debian:bullseye

# Atualize os repositórios e instale as ferramentas necessárias
RUN apt-get update && apt-get install -y \
    g++-arm-linux-gnueabihf \
    qemu-user \
    cmake \
    make \
    && rm -rf /var/lib/apt/lists/*

# Configure o diretório de trabalho
WORKDIR /app

# Copie o código-fonte para o contêiner
COPY SOURCE_CODE /app/SOURCE_CODE

# Defina o comando padrão que será executado quando o contêiner for iniciado
CMD ["bash"]