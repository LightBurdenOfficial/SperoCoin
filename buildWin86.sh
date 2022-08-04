#!/bin/bash
YELLOW="$BOLD\e[93m"
NORMAL="$BOLD\e[0m"

function echoCores {
        echo -e $@$NORMAL
}

function pause(){
   read -p "$*"
}

echoCores $YELLOW"Remocao da variável de importação %PATH% problemática do Windows"
echoCores -n $NORMAL""
PATH=$(echo "$PATH" | sed -e 's/:\/mnt.*//g')

echoCores $YELLOW"Entrando na pasta depends"
echoCores -n $NORMAL""
cd depends

echoCores $YELLOW"Compilando as dependencias"
echoCores -n $NORMAL""
make HOST=i686-w64-mingw32

echoCores $YELLOW"Retornando a pasta raiz"
echoCores -n $NORMAL""
cd ..

echoCores $YELLOW"Realizando limpeza de arquvos temporarios"
echoCores -n $NORMAL""
make clean
find ./src -type d -name ".deps" -exec rm -rf {} +
find ./src -iname ".dirstamp" -exec rm -rf {} +

echoCores $YELLOW"Gerar arquivos de configuracoes obrigatorias"
echoCores -n $NORMAL""
./autogen.sh

echoCores $YELLOW"Confugurando ambiente de compilacao"
echoCores -n $NORMAL""
CONFIG_SITE=$PWD/depends/i686-w64-mingw32/share/config.site ./configure --prefix=/ --disable-tests --disable-bench

echoCores $YELLOW"Compilando binarios"
echoCores -n $NORMAL""
make 2>&1 | tee ./build_log/buildWin86.log
