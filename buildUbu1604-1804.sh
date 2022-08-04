#!/bin/bash
YELLOW="$BOLD\e[93m"
NORMAL="$BOLD\e[0m"

function echoCores {
        echo -e $@$NORMAL
}

function pause(){
   read -p "$*"
}

menu(){
	while true; do
		clear
		echoCores $YELLOW"================================================"
		echoCores $YELLOW"Selecione o tipo de instalacao"
		echoCores $YELLOW"1) Com QT"
		echoCores $YELLOW"2) Sem QT"
		echoCores $YELLOW"========================"
		echoCores $YELLOW"Digite a opcao desejada:"
		read x
		echoCores $YELLOW"Opcao informada ($x)"
		echoCores $YELLOW"================================================"

		case "$x" in
			1)
				echoCores $YELLOW"================================================"
				echoCores -n $YELLOW"Baixando e instalando dependencias"
				echoCores -n $NORMAL""
				sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils python3 libseccomp-dev libcap-dev -y
				echoCores $YELLOW"Baixando e instalando libboost-all-dev"
				echoCores -n $NORMAL""
				sudo apt-get install libboost-all-dev -y
				echoCores $YELLOW"Baixando e instalando BerkeleyDB"
				echoCores -n $NORMAL""
				sudo apt-get install software-properties-common -y
				sudo add-apt-repository ppa:bitcoin/bitcoin
				sudo apt-get update
				sudo apt-get install libdb4.8-dev libdb4.8++-dev -y
				echoCores $YELLOW"Baixando e instalando libminiupnpc-dev"
				echoCores -n $NORMAL""
				sudo apt-get install libminiupnpc-dev -y
				echoCores $YELLOW"Baixando e instalando libzmq3-dev"
				echoCores -n $NORMAL""
				sudo apt-get install libzmq3-dev -y
				echoCores $YELLOW"Baixando e instalando QT5"
				echoCores -n $NORMAL""
				sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler -y
				echoCores $YELLOW"Baixando e instalando libqrencode-dev"
				echoCores -n $NORMAL""
				sudo apt-get install libqrencode-dev -y
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
				./configure --disable-tests --disable-bench
				echoCores $YELLOW"Compilando binarios"
				echoCores -n $NORMAL""
				make 2>&1 | tee ./build_log/buildUbu1804.log
				sleep 5
				pause 'Press [Enter] key to continue...'
				exit
		echoCores $YELLOW"================================================"
		;;
			2)
				echoCores $YELLOW"================================================"
				echoCores $YELLOW"Baixando e instalando dependencias"
				echoCores -n $NORMAL""
				sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils python3 libseccomp-dev libcap-dev -y
				echoCores $YELLOW"Baixando e instalando libboost-all-dev"
				echoCores -n $NORMAL""
				sudo apt-get install libboost-all-dev -y
				echoCores $YELLOW"Baixando e instalando BerkeleyDB"
				echoCores -n $NORMAL""
				sudo apt-get install software-properties-common -y
				sudo add-apt-repository ppa:bitcoin/bitcoin
				sudo apt-get update
				sudo apt-get install libdb4.8-dev libdb4.8++-dev -y
				echoCores $YELLOW"Baixando e instalando libminiupnpc-dev"
				echoCores -n $NORMAL""
				sudo apt-get install libminiupnpc-dev -y
				echoCores $YELLOW"Baixando e instalando libzmq3-dev"
				echoCores -n $NORMAL""
				sudo apt-get install libzmq3-dev -y
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
				./configure --disable-tests --disable-bench
				echoCores $YELLOW"Compilando binarios"
				echoCores -n $NORMAL""
				make 2>&1 | tee ./build_log/buildUbu1804.log
				sleep 5
				pause 'Press [Enter] key to continue...'
				exit
		;;
			*)
				echoCores $YELLOW"Opcao invalida!"
esac
done
}
menu