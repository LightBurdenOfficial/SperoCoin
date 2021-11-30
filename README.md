[![Codacy Badge](https://api.codacy.com/project/badge/Grade/1aa1a2fafa1a41e1bdcba6e453fcba1f)](https://app.codacy.com/app/DigitalCoin1/SperoCoin?utm_source=github.com&utm_medium=referral&utm_content=DigitalCoin1/SperoCoin&utm_campaign=Badge_Grade_Dashboard)
[![Build Status](https://travis-ci.org/DigitalCoin1/SperoCoin.svg?branch=master)](https://travis-ci.org/DigitalCoin1/SperoCoin)
<br>
[![N|Solid](https://i.imgur.com/0BOgWZy.png)](https://sperocoin.org/)

Version: 2.7.0.0
=====================================

SperoCoin is a cryptocurrency developed with the aim of creating a decentralized ecosystem whose main objective is the application of SOCIAL SUSTAINABILITY.

Social sustainability implies generating income without losing focus on reducing social inequalities, with the aim of improving society's quality of life.
However, this does not mean that the company will fail to profit or run after profit. Instead, the idea is to create a business model in which profit is no longer above everything else, but to make the company also start to worry about its impact on the society in which it operates.

In addition to this project seeking social sustainability, we also aim at the privacy of payments, using the TOR network to forward transactions.

The integration with TOR ensures that users are always on a secure environment. There is no client-side configuration needed. Our client will automatically join the TOR network and connect to available TOR nodes on the network (including our seed nodes). After a successful connection to the SperoCoin network, you may check your displayed IP using the SperoCoin client console, where you will see that your client is assigned a TOR hidden service address (.onion address).

#### Pluggable Transports

>SperoCoin has options for advanced users to configure PTs such as obfs4 & Meek. 
>
>Instructions:
>
>[Setup OBFS4]( https://github.com/DigitalCoin1/SperoCoin/blob/master/doc/setup-obfs4.md )
>
>[Setup Meek]( https://github.com/DigitalCoin1/SperoCoin/blob/master/doc/setup-meek.md )


## Specifications

| Specification | Value |
|:-----------|:-----------|
| Consensus Algorithm | `PoW & PoS` |
| Mining Algorithm | `X13` |
| Confirmations | `3 tx` |
| Block Confirm. | `5 minted confirms` |
| Port | `55680` |
| RPC Port | `55681` |


##### PoW:

> - 60 sec block interval.
> - Difficulty readjustment every block.


| Blocks Interval | Block Reward |
|:-----------|:-----------|
| 1 - 2 | `50000` |
| 3 - 33330 | `2` |
| 33331 - 1149999 | `0.05 + 0.015 Foundation` |
| 1150000 - 1339199 | `0.025` |
| 1339200 - 1339211 | `0.025 + 10000 Foundation` |
| 1339212 - 1625599 | `0.25` |
| 1625600 - 2151199 | `0.015` |
| 2151200 - INFINITE | `0.001` |


##### PoS:

> - 60 sec block interval.
> - Difficulty readjustment every block.
> - Minimum holding time before the PoS will be generated is 2 hours.
> - Maximum allowed accumulated coin is 12 hours.

| Blocks Interval | Block Reward |
|:-----------|:-----------|
| 1 - 263249 | `5% per year` |
| 263250 - 1149999 | `25% per year` |
| 1150000 - 1338999 | `0.25 per block + 0.25 Foundation` |
| 1150000 - 2151199 | `0.25 per block` |
| 2151200 - INFINITE | `0.25 per block` |


## Resources

:package: For software downloads, please see [Downloads](https://sperocoin.org/getStarted)

[Whitepaper](https://sperocoin.org/whitepaper/) 

[Roadmap](https://sperocoin.org/roadmap)

[Community](https://sperocoin.org/community)


## SperoCoin.conf file

Download [SperoCoin.conf](https://sperocoin.org/files/SperoCoin.conf.php?action=download) (right-click > save link as).

For more info on how setup your .conf file, please visit https://sperocoin.org/configurationFile


License :bookmark_tabs:
-------

SperoCoin is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.



Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be completely stable. 

