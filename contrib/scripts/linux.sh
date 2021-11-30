mkdir -p ~/.SperoCoin
cd ~/.SperoCoin
mv -f SperoCoin.conf .SperoCoin.conf.bak
sudo apt-get install curl -y
echo "$(curl https://sperocoin.org/conf_file/SperoCoin.conf)" >> ~/.SperoCoin/SperoCoin.conf
echo "staking=1
checkblockchain=0" >> ~/.SperoCoin/SperoCoin.conf
echo Nodes updated! Restart the SperoCoin wallet.
