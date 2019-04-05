Copyright (c) 2009-2019 Bitcoin Developers<br>
Copyright (c) 2017-2019 SperoCoin Developers<br>
Distributed under the MIT/X11 software license, see the accompanying file license.txt or http://www.opensource.org/licenses/mit-license.php.<br>
This product includes software developed by the OpenSSL Project for use in the OpenSSL Toolkit (http://www.openssl.org/).<br>
This product includes cryptographic software written by Eric Young (eay+AEA-cryptsoft.com) and UPnP software written by Thomas Bernard.<br>
<br>

# Tutorial Desenvolvido pela Equipe SperoCoin

## Comandos no Terminal:

Baixe o source:

```sh
git clone https://github.com/DigitalCoin1/SperoCoin/tree/Raspberry
```

Instale as dependências:
```sh
sudo apt-get install build-essential
sudo apt-get install libboost-all-dev
sudo apt-get install libcurl4-openssl-dev
sudo apt-get install libdb5.3-dev
sudo apt-get install libdb5.3++-dev
sudo apt-get install qt-sdk
sudo apt-get install libminiupnpc-dev
sudo apt-get install qrencode
sudo apt-get install libqrencode-dev
sudo apt-get install git
sudo apt-get install libtool
sudo apt-get install automake
sudo apt-get install autotools-dev
sudo apt-get install autoconf
sudo apt-get install pkg-config
sudo apt-get install libgmp3-dev
sudo apt-get install libevent-dev
sudo apt-get install bsdmainutils
```

Após instalar essas dependências mude a lista de fontes do Raspberry:
```sh
sudo nano /etc/apt/sources.list
```

Altere todas as linhas onde exista a palavra `stretch` pela palavra `jessie`:
Exemplo:
> ANTES = deb http://raspbian.raspberry.org/raspibian stretch main contrib non-free api<br>
> DEPOIS = deb http://raspbian.raspberry.org/raspibian jessie main contrib non-free api

Salve as alterações e saia do arquivo.

Envie os seguintes comandos:
```sh
sudo apt-get update
sudo apt-get install libssl-dev
sudo apt-mark hold libssl-dev
```

Edite novamente o arquivo de fontes do Raspberry:
```sh
sudo nano /etc/apt/sources.list
```

Altere todas as linhas onde exista a palavra `jessie` pela palavra `stretch`:
Exemplo:

> ANTES = deb http://raspbian.raspberry.org/raspibian jessie main contrib non-free api<br>
> DEPOIS = deb http://raspbian.raspberry.org/raspibian stretch main contrib non-free api

Salve as alterações e saia do arquivo.

As dependências abaixo são para a compilação da QT:
```sh
sudo apt-get install libqt5gui5
sudo apt-get install libqt5core5a
sudo apt-get install libqt5dbus5
sudo apt-get install qttools5-dev
sudo apt-get install qttools5-dev-tools
sudo apt-get install libprotobuf-dev
sudo apt-get install protobuf-compiler
sudo apt-get install libqrencode-dev
```

## PARA COMPILAR A DAEMON:
```sh
cd SperoCoin/src
make -f makefile.unix USE_UPNP=- USE_IPV6=1
strip SperoCoind
```

## PARA COMPILAR A QT:
```sh
cd SperoCoin
sudo qmake SperoCoin-qt.pro "USE_UPNP=-" "USE_QRCODE=1"
sudo make -f Makefile
```