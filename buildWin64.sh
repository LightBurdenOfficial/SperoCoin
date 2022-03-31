echo "Remocao da variável de importação %PATH% problemática do Windows"
PATH=$(echo "$PATH" | sed -e 's/:\/mnt.*//g')
echo "Entrando na pasta depends"
cd depends
echo "Compilando as dependencias"
make HOST=x86_64-w64-mingw32
echo "Retornando a pasta raiz"
cd ..
echo "Realizando limpeza de arquvos temporarios"
make clean
find ./src -type d -name ".deps" -exec rm -rf {} +
find ./src -iname ".dirstamp" -exec rm -rf {} +
echo "Gerar arquivos de configuracoes obrigatorias"
./autogen.sh
echo "Confugurando ambiente de compilacao"
CONFIG_SITE=$PWD/depends/x86_64-w64-mingw32/share/config.site ./configure --prefix=/ --disable-tests --disable-bench
echo "Compilando binarios"
make 2>&1 | tee ./build_log/buildWin64.log
