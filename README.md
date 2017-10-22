[![N|Solid](https://i.imgur.com/lXSMMR2.png)](https://sperocoin.wixsite.com/sperocoin)
# Sperocoin
Sperocoin came with the mission to renew the world of the exhaustive consumption of electric energy.

With the PoS mining concept, we have an ecologically correct coin, since it is not necessary to use powerful mining machines to obtain rewards for solved blocks.

Also embrace this idea and help build a cleaner world, we count on your help!

All the balance that is collected by Spero is aimed directly at the growth of the structuring of the currency and the social programs that it covers.

# Contact:
> 💬Telegram:
**https://t.me/joinchat/G7cebkL3dbRqfuy1gVNm3g**

> ✉️E-mail:
**sperocoin@gmail.com**

> 🌎Website:
**https://sperocoin.wixsite.com/sperocoin**

> 📟Sms in Wallet:
**Sb4CCvH18ooqUXchUaM19Nk6Ys5NnWmDe8**
**PubKey: 03cba0f207912dbdb5e6bf1a0afe09f17046f7ce09baa2250757e3a88cd644acc4**


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
 - VOTE: https://www.tradesatoshi.com/Vote

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

# Pool:
- http://pickaxe.online/

```sh
 🔥Variable Difficulty : 0.001 ~ 0.01
 🔥Stratum Host : stratum+tcp://pickaxe.online:10021
 🔥Username : [YourWalletAddress]


 🔥Variable Difficulty : 0.01 ~ 0.04
 🔥Stratum Host : stratum+tcp://pickaxe.online:10022
 🔥Username : [YourWalletAddress]


 🔥Variable Difficulty : 0.4 ~ 4
 🔥Stratum Host : stratum+tcp://pickaxe.online:10023
 🔥Username : [YourWalletAddress]


 🔥NiceHash
 🔥Stratum Host : stratum+tcp://pickaxe.online:10024
 🔥Username : [YourWalletAddress]


 🔥Fees : 3%
 🔥Payout cycle : 15 mins
 🔥Minimum Payout : 0.01 SPERO
```

# Rewards using the pre-mining balance:

> Wallet Android: 1000 SPERO
> Wallet iOS: 1000 SPERO
> Wallet MAC: 1000 SPERO
> Translate Topic: 100 SPERO
> Exchange: 10.000 SPERO
> 3 Study Group (5 students): 5000 SPERO
 
 
# Timeline:
>$0001 2017/09/26
Initial Upload to GitHub

>$0006 2017/10/01
In this update, the SperoCoin-qt.pro file has been changed for compilation in the Linux environment.

>$0007 2017/10/06
Update README.md and add files: src/leveldb/Makefile

>$0008 2017/10/08
Update infos about end phase of PoW and start phase PoS;
Update font of qt wallet;
Update version;
Update Protocol Others general's updates

>$0010 2017/10/10
Update for new implementations:
→ Added option of cleaning of orphans blocks;
→ Added display option "STAKE" in the "type" column inside the "Transactions" tab;
→ Added "setban" node "" add | remove "(bantime)" / "listbanned" and "clearbanned" in the RPC console;

>$0012 2017/10/11
Ban Forked Peers who are stuck in a Getblocks Loop.


