[![Codacy Badge](https://api.codacy.com/project/badge/Grade/1aa1a2fafa1a41e1bdcba6e453fcba1f)](https://app.codacy.com/app/DigitalCoin1/SperoCoin?utm_source=github.com&utm_medium=referral&utm_content=DigitalCoin1/SperoCoin&utm_campaign=Badge_Grade_Dashboard)
[![Build Status](https://travis-ci.org/DigitalCoin1/SperoCoin.svg?branch=master)](https://travis-ci.org/DigitalCoin1/SperoCoin)
<br>
[![N|Solid](https://i.imgur.com/0BOgWZy.png)](https://sperocoin.org/)
# Sperocoin - Sustainability in technology
# Version: 2.6.4.9
Sperocoin came with the mission to renew the world of the exhaustive consumption of electric energy.

With the PoS mining concept, we have an ecologically correct coin, since it is not necessary to use powerful mining machines to obtain rewards for solved blocks.

Also embrace this idea and help build a cleaner world, we count on your help!

All the balance that is collected by Spero is aimed directly at the growth of the structuring of the currency and the social programs that it covers.

# Contact:
> :speech_balloon: Telegram:
**https://t.me/joinchat/G7cebkL3dbRqfuy1gVNm3g**

> :speech_balloon: Slack:
**https://sperocoin.slack.com**

> :speech_balloon: Facebook:
**https://www.facebook.com/sperocoinofficial/**

> :speech_balloon: Twitter:
**https://twitter.com/Spero_Official**

> :speech_balloon: BTCTalk:
**https://bitcointalk.org/index.php?topic=2260985.0**

> :email: E-mail:
**sperocoin@gmail.com**

> :earth_americas: Website:
**https://sperocoin.org**

> :earth_americas: Block Explorer:
**https://explorer.sperocoin.org**

> :droplet: Faucet:
**https://faucet.sperocoin.org**

> :busts_in_silhouette: Support:
**https://suporte.sperocoin.org**

# Specifications:
  - **ALGORITHM:** x13
  - **BLOCK TIME:** 60 seconds
  - **AWARDS PoW:** 2 SPERO to block 263250
  - **PoS:** After 2h
  - **PoS:** 25% per year
  - **CONFIRMATIONS:** 5 for mining and 3 for transactions
  - **E2M MESSAGE** Send and receive encrypted messages directly into your wallet
  - **TOTAL COINS:** ~ 7 million
  - **LAST BLOCK PoW:** 33331
  - **PRE-MINED COINS:** ~ 100000 SPERO
  - **VELOCITY:** Triple verification system in every network transaction, thus preventing the "double spend"
  - **Adaptable Block Size(ABS):** The block holds all transactions sent within 60 seconds, regardless of the number of transactions


# Phases of Sperocoin (Blocks):

  - Proof of Work + Proof of Stake: 0 - 33331
  - Proof of Stake: 33331 - 263250
  - Proof of Work + Proof of Stake: acima de 263251

# Compile Source<br>
**Download and install the dependencies:**<br>
sudo apt-get install build-essential libboost-all-dev libcurl4-openssl-dev libdb5.3-dev libdb5.3++-dev libminiupnpc-dev qrencode libqrencode-dev git libtool automake autotools-dev autoconf pkg-config libssl-dev libgmp3-dev libevent-dev bsdmainutils
<br><br><br>
**Compile the daemon in the SperoCoin/src directory:**<br>
cd DigitalCoinBRL/src<br><br>
make -f makefile.unix USE_UPNP=1 USE_IPV6=1<br><br>
strip SperoCoind<br>
<br><br>
**Run daemon in the SperoCoin/src directory:**<br>
./SperoCoind<br><br>
<br>
**(OPTIONAL)Compile the QT in the SperoCoin directory - Ubuntu 16.04:**<br>
sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler libqrencode-dev qt-sdk<br><br>
qmake SperoCoin-qt.pro "USE_UPNP=1" "USE_QRCODE=1"<br><br>
make -f Makefile<br><br>
**(OPTIONAL)Compile the QT in the SperoCoin directory - Ubuntu 18.04:**<br>
sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler libqrencode-dev libqt4-dev<br><br>
qmake SperoCoin-qt.pro "USE_UPNP=1" "USE_QRCODE=1"<br><br>
make -f Makefile<br><br>

# sperocoin.conf
```sh
listen=1
txindex = 1
rpcuser=user
rpcpassword=Random_Password
rpcport=55681
port=55680
#(0=off, 1=on) daemon - run in the background as a daemon and accept commands
daemon=1
#(0=off, 1=on) server - accept command line and JSON-RPC commands
server=1
rpcallowip=127.0.0.1
testnet=0
addnode=seed1.sperocoin.org:55680
addnode=seed2.sperocoin.org:55680
addnode=seed3.sperocoin.org:55680
addnode=seed4.sperocoin.org:55680

```

# sperocoin.conf - Testnet
```sh
listen=1
txindex = 1
rpcuser=user
rpcpassword=Random_Password
rpcport=55691
port=55690
#(0=off, 1=on) daemon - run in the background as a daemon and accept commands
daemon=1
#(0=off, 1=on) server - accept command line and JSON-RPC commands
server=1
rpcallowip=127.0.0.1
testnet=1
addnode=seed1.sperocoin.org:55690
addnode=seed2.sperocoin.org:55690
addnode=seed3.sperocoin.org:55690
addnode=seed4.sperocoin.org:55690
```

# Exchanges:
 - 💎 https://exchange.sperocoin.org
 - 💎 https://nanu.exchange/exchange#btc_spero
 - 💎 https://catalogop2p.com.br/sperocoin-sustentabilidade-em-tecnologia

#  Mining:
- Solo Cpu:
```sh
{
"_comment1" : "Any long-format command line argument ",
"_comment2" : "may be used in this JSON configuration file",

"api-bind" : "127.0.0.1:4048",

"url" : "localhost:55681",
"user" : "user",
"pass" : "password",

"algo" : "x13",
"threads" : 0,
"cpu-priority" : 0,
"cpu-affinity" : -1,

"benchmark" : false,
"debug" : true,
"protocol": false,
"quiet" : false
}
```

```sh
cpuminer -q --algo=x13 -o 127.0.0.1:55681 -u user-p password
```

- Solo GPU:
```sh
ccminer30.exe -q --algo=x13 -o 127.0.0.1:55681 -u user-p password
```

# Rewards using the pre-mining balance:

> Wallet Android: 1000 SPERO<br>
> Wallet iOS: 1000 SPERO<br>
> Wallet MAC: 1000 SPERO<br>
> Translate Topic: 100 SPERO<br>
> Exchange: 10.000 SPERO(https://explorer.sperocoin.org/tx/954af0b2e80730721d2f5edc30708a636802a27e5dfaa22fbbd620d5399f3cf5)<br>
> Social Market Trading Point: 5000 SPERO<br>


# Timeline:
https://github.com/DigitalCoin1/SperoCoin/blob/master/changelog.md

