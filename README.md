https://sperocoin.wixsite.com/sperocoin<br><br>
<b>sperocoin@gmail.com</b>
<br>
<h2><b>Version:</b></h2><br>
BETA 2.6.4.1<br>
<h2><b>Phases:</b></h2><br>
Pow and PoS: 0 - 33331<br>
PoS: 33331 - 263250<br>
PoW and PoS: 263251 up<br><br>
<h2><b>Downloads</b></h2><br>
<br>
<b>Qt Windows:</b><br>
http://www.mediafire.com/file/4hxe7mvm4oio7ol/SperoCoin-v.2.6.4.1.exe<br>
<br>
<b>Daemon Windows:</b><br>
http://www.mediafire.com/file/ix8toafas5hd1gs/sperocoind-v.2.6.4.1.exe<br>
<br>
<b>Sms:</b><br>
<br>
Sb4CCvH18ooqUXchUaM19Nk6Ys5NnWmDe8<br>
PubKey: 03cba0f207912dbdb5e6bf1a0afe09f17046f7ce09baa2250757e3a88cd644acc4<br>
<br>
<b>Mineração / Mining:</b><br>
<b>Solo CPU:</b><br>
<br>
{<br>
"_comment1" : "Any long-format command line argument ",<br>
"_comment2" : "may be used in this JSON configuration file",<br>
<br>
"api-bind" : "127.0.0.1:4048",<br>
<br>
"url" : "localhost:55681",<br>
"user" : "user",<br>
"pass" : "password",<br>
<br>
"algo" : "x13",<br>
"threads" : 0,<br>
"cpu-priority" : 0,<br>
"cpu-affinity" : -1,<br>
<br>
"benchmark" : false,<br>
"debug" : true,<br>
"protocol": false,<br>
"quiet" : false<br>
}<br>
<br>
<br>
cpuminer -q --algo=x13 -o 127.0.0.1:55681 -u user-p password<br>
<br>
<b>Solo GPU:</b><br>
<br>
ccminer30.exe -q --algo=x13 -o 127.0.0.1:55681 -u user-p password<br>
<br>
<br>
<br>
<b>Pool:</b><br>
<br>
🔥 Variable Difficulty : 0.001 ~ 0.01<br>
🔥 Stratum Host : stratum+tcp://pickaxe.online:10021<br>
🔥 Username : [YourWalletAddress]<br>
<br>
<br>
🔥 Variable Difficulty : 0.01 ~ 0.04<br>
🔥 Stratum Host : stratum+tcp://pickaxe.online:10022<br>
🔥 Username : [YourWalletAddress]<br>
<br>
<br>
🔥 Variable Difficulty : 0.4 ~ 4<br>
🔥 Stratum Host : stratum+tcp://pickaxe.online:10023<br>
🔥 Username : [YourWalletAddress]<br>
<br>
<br>
🔥 NiceHash<br>
🔥 Stratum Host : stratum+tcp://pickaxe.online:10024<br>
🔥 Username : [YourWalletAddress]<br>
<br>
<br>
🔥 Fees : 3%<br>
🔥 Payout cycle : 15 mins<br>
