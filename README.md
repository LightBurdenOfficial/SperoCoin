[![Codacy Badge](https://api.codacy.com/project/badge/Grade/1aa1a2fafa1a41e1bdcba6e453fcba1f)](https://app.codacy.com/app/DigitalCoin1/SperoCoin?utm_source=github.com&utm_medium=referral&utm_content=DigitalCoin1/SperoCoin&utm_campaign=Badge_Grade_Dashboard)
<br>
[![N|Solid](https://i.imgur.com/0BOgWZy.png)](https://sperocoin.org/)
# Sperocoin - Sustainability in technology
# Version: 2.6.4.7
Sperocoin came with the mission to renew the world of the exhaustive consumption of electric energy.

With the PoS mining concept, we have an ecologically correct coin, since it is not necessary to use powerful mining machines to obtain rewards for solved blocks.

Also embrace this idea and help build a cleaner world, we count on your help!

All the balance that is collected by Spero is aimed directly at the growth of the structuring of the currency and the social programs that it covers.

# Contact:
> 💬Telegram:
**https://t.me/joinchat/G7cebkL3dbRqfuy1gVNm3g**

> 💬Slack:
**https://sperocoin.slack.com**

> 💬Facebook:
**https://www.facebook.com/sperocoinofficial/**

> 💬Twitter:
**https://twitter.com/Spero_Official**

> 💬BTCTalk:
**https://bitcointalk.org/index.php?topic=2260985.0**

> ✉️E-mail:
**sperocoin@gmail.com**

> 🌎Website:
**https://sperocoin.org**

> 🌎Block Explorer:
**http://sperocoin.ddns.net:3001**

> 🌎Block Explorer 2:
**http://52.67.138.144:3001**

> 📟Sms in Wallet:
**SiRvv6i8d5F7XbJSTqcGM35bdDMxATtMzz**
**PubKey: 03214f4cd930454878b87269b1ab12e54a4bd805634e65f113eaded61eba652219**


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
sudo apt-get install build-essential libboost-all-dev libcurl4-openssl-dev libdb5.3-dev libdb5.3++-dev qt-sdk libminiupnpc-dev qrencode libqrencode-dev git libtool automake autotools-dev autoconf pkg-config libssl-dev libgmp3-dev libevent-dev bsdmainutils
<br><br><br>
**Compile the daemon in the SperoCoin/src directory:**<br>
cd DigitalCoinBRL/src<br><br>
make -f makefile.unix USE_UPNP=1 USE_IPV6=1<br><br>
strip SperoCoind<br>
<br><br>
**Run daemon in the SperoCoin/src directory:**<br>
./SperoCoind<br><br>
<br>
**(OPTIONAL)Compile the QT in the SperoCoin directory:**<br>
sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler libqrencode-dev<br><br>
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
addnode=18.228.13.3:55680
addnode=35.198.22.94:55680
addnode=sperocoin.ddns.net:55680
addnode=167.114.103.43:55680
addnode=104.248.225.117:55680
addnode=45.195.201.179:55680

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
addnode=18.228.13.3:55690
addnode=18.228.13.3:55692
```

# Exchanges:
 - 💎 https://www.altilly.com/market/SPERO_BTC
 - 💎 https://www.altilly.com/market/SPERO_ETH
 - 💎 https://www.altilly.com/market/SPERO_DOGE
 - 💎 https://catalogop2p.com.br/sperocoin-sustentabilidade-em-tecnologia
 - 💎 https://nanu.exchange/exchange#btc_spero
 - 💎 https://bitsahani.com/exchange/SPERO-DOGE

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
> Exchange: 10.000 SPERO(http://sperocoin.ddns.net:3001/tx/954af0b2e80730721d2f5edc30708a636802a27e5dfaa22fbbd620d5399f3cf5)<br>
> Social Market Trading Point: 5000 SPERO<br>


# Timeline:
>$0001 2017/09/26<br>
Initial Upload to GitHub<br>

>$0006 2017/10/01<br>
In this update, the SperoCoin-qt.pro file has been changed for compilation in the Linux environment.<br>

>$0007 2017/10/06<br>
Update README.md and add files: src/leveldb/Makefile<br>

>$0008 2017/10/08<br>
Update infos about end phase of PoW and start phase PoS;<br>
Update font of qt wallet;<br>
Update version;<br>
Update Protocol Others general's updates<br>

>$0010 2017/10/10<br>
Update for new implementations:<br>
→ Added option of cleaning of orphans blocks;<br>
→ Added display option "STAKE" in the "type" column inside the "Transactions" tab;<br>
→ Added "setban" node "" add | remove "(bantime)" / "listbanned" and "clearbanned" in the RPC console;<br>

>$0012 2017/10/11<br>
Ban Forked Peers who are stuck in a Getblocks Loop.<br>

>$0013 2017/10/22<br>
→ Update of strings names;<br>
→ Updating information in README.md<br>
→ Update Stake Info in QT  Wallet<br>

>$0015 2017/11/18<br>
→ Release of testnet mining;<br>
→ File Fix:<br>
   • main.cpp<br>
   • alter.cpp<br>
   • checkpoints.cpp<br>
   • checkpoints.h<br>

>$0016 2017/11/30<br>
Add node in the source:<br>
addnode=http://dnssperocoin.ddnsking.com:55680<br>

>$0017 2018/03/28<br>
→ Add RPC Command "GETWALLETINFO"<br>
→ Update of transaction maturity icons<br>
→ splash screen main update<br>
→ Updating the logo inside the Wallet<br>
→ Added hashGenesisBlockTestNet = 0x00001fe23e7d6951a2a07ad684ff208fab9110fad607fabd81482a1692382f8f in main.h file<br>
→ Added testnet block.nNonce in main.cpp file (block.nNonce = 15547;)<br>
→ Added static MapCheckpoints mapCheckpointsTestnet = (0, uint256("0x000006f4925ed7b889f847f24621390d4943466f091c3254ca1bd8becc517f7b")) in the checkpoints.cpp file<br>
→ Change the initial letter of the testnet addresses in the base58.h file (PUBKEY_ADDRESS_TEST = 125, // Initial address letter (63 = s) -TESTNET))<br>
→ Change the example initial letter in the file qt / sendcoinsdialog.cpp<br>
(ui-> lineEditCoinControlChange-> setPlaceholderText (tr ("Enter the SperoCoin address (e.g. Sjz75uKHzUQJnSdzvpiigEGxseKkDhQToX)"));)<br>
→ Changed version to 2.6.4.3<br>

>$0019 2018/07/15<br>
→ Added RPC command "getnetworkinfo" - Change in files: bitcoinrpc.cpp; bitcoinrpc.h; rpcblockchain.cpp; rpcnet.cpp<br>
→ Added RPC command "getblockchaininfo" - Change in files:bitcoinrpc.cpp; bitcoinrpc.h; rpcblockchain.cpp; rpcnet.cpp<br>
→ Added Wallet Status Information (Locked or Unlocked) in the RPC command "getinfo"<br>
→ Added new points in the network map updating the mapping up to block 130000- Change in file: checkpoints.cpp<br>
→ Changing copyrights, updating the start date of SperoCoin works, being: "Copyright © 2017 The SperoCoin developers" - Change in ".ts" files in the "src \ qt \ locale" folder<br>
→ Update of QT splashscreen images<br>
→ Changing QT fonts for "Century Gothic"<br>
→ Clear Orphans with automatic transaction page refresh, no need to restart wallet<br>
→ Changed version to 2.6.4.4<br>

>$0020 2018/07/31<br>
→ Add/Remove Nodes<br>

>$0021 2018/10/27<br>
→ Added new points in the network map updating the mapping up to block 165962- Change in file: checkpoints.cpp<br>
→ Performance Enhancements - Increased Speed ​​in Synchronization - Changes in files: main.cpp; main.h;<br>
→ Added new icons<br>
→ Change style of block download progress bar from "QWindowsXPStyle" to "QWindowsVistaStyle" - Changes in file: bitcoingui.cpp<br>
→ Changing the size of the icons in "STATUSBAR_ICONSIZE" from 16 to 64 - Changes in file: guiconstants.h<br>
→ Adding SperoCoin.conf file opening from the Console Window menu<br>
→ Changed description of mining type PoW<br>
→ Changed description of mining type PoS<br>
→ New PoS Mining Icon<br>
→ Changed version to 2.6.4.5<br>

>$0022 2018/12/08<br>
→ Alterada Versão para 2.6.4.6;<br>
→ Alterada versão do protocolo para mínimo 700001;<br>
→ Adicionada Introdução;<br>
→ Adicionado pontos de checagem de blocos até o bloco 180000<br>

>$0023 2018/05/31<br>
→ Alterada Versão para 2.6.4.7;<br>
→ Alterada versão do protocolo mínimo para 700002;<br>
→ Adicionada página Charity(Doações POS);<br>
→ Adicionados endereços Donate Foudation;<br>
→ Correção das strings que determinam as fases de mineração;<br>
→ Preparação para o ambiente de mineração PoW após o bloco 263250;<br>
→ Mudança dos ícones e logos;<br>
→ Adição do parâmetro -zapwallettxes;<br>

