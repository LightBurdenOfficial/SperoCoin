[![N|Solid](https://i.imgur.com/lXSMMR2.png)](https://sperocoin.wixsite.com/sperocoin)
# Sperocoin - Sustainability in technology
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
**https://sperocoin.ddns.net**

> 🌎Block Explorer:
**http://sperocoin.ddns.net:3001**
**http://exsperocoin.ddns.net:3001**

> 📟Sms in Wallet:
**SiRvv6i8d5F7XbJSTqcGM35bdDMxATtMzz**
**PubKey: 03214f4cd930454878b87269b1ab12e54a4bd805634e65f113eaded61eba652219**


# Specifications:
  - ALGORITHM: X13
  - BLOCK TIME: 60 seconds
  - AWARDS PoW: 2 SPERO to block 263250
  - PoS: After 2h
  - PoS : 25% per year
  - CONFIRMATIONS: 5 for mining and 3 for transactions
  - ENCRYPTED MESSAGE
  - TOTAL COINS: ~ 7 million
  - LAST BLOCK PoW: 33331
  - PRE-MINED COINS: ~ 100000 SPERO


# Phases of Sperocoin (Blocks):

  - Proof of Work + Proof of Stake: 0 - 33331
  - Proof of Stake: 33331 - 263250
  - Proof of Work + Proof of Stake: acima de 263251

# sperocoin.conf
```sh
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
addnode=hopeassistencia.ddns.net
```
# Exchanges:
 - 💎 https://coinsmarkets.com/trade-BTC-SPERO.htm 
 - 💎 https://catalogop2p.com.br/sperocoin-sustentabilidade-em-tecnologia 
 - 💎 https://p2brasil.com/produto/sperocoin/ 
 - 💎 https://sperocoin.ddns.net/exchange 

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

> Wallet Android: 1000 SPERO
> Wallet iOS: 1000 SPERO
> Wallet MAC: 1000 SPERO
> Translate Topic: 100 SPERO
> Exchange: 10.000 SPERO
> 3 Study Group (5 students): 5000 SPERO
 
 
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
