CHANGELOG SPEROCOIN

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

>$0028 2019/05/31<br>
→ Alterada Versão para 2.6.4.7;<br>
→ Alterada versão do protocolo mínimo para 700002;<br>
→ Adicionada página Charity(Doações POS);<br>
→ Adicionados endereços Donate Foudation;<br>
→ Correção das strings que determinam as fases de mineração;<br>
→ Preparação para o ambiente de mineração PoW após o bloco 263250;<br>
→ Mudança dos ícones e logos;<br>
→ Adição do parâmetro -zapwallettxes;<br>

>$0029 2020/10/22<br>
→ [UPDATE] Nova versão 2.6.5.0;<br>
→ [UPDATE] Adição de lista de endereços de participantes do sistema de doações(CHARITY);<br>
→ [OPMIZATION] Limpeza e Remoção de arquivos desnecessários da base do código;<br>
→ [FEATURE] Compatibilidade com Openssl versões 1.0.2 e acima;<br>
→ [FEATURE] Compatibilidade com Boost 1.66 e 1.70;<br>
→ [FEATURE] Implementação de auto-completar na janela de depuração;<br>
→ [FIX] getbalance() bug;<br>
→ [FIX] TransactionView: Cálculo do último mês;<br>
→ [UPDATE] Array de seed nodes;<br>
→ [UPDATE] Checkpoints;<br>
→ [UPDATE] Arquivos de Compilação SperoCoin-qt.pro e makefile.mingw usados em compilação Windows<br>

>$0030 2021/01/29<br>
→ [UPDATE] Nova versão 2.6.5.1;<br>
→ [UPDATE] Alterada versão do protocolo para mínimo 700003;<br>
→ [GUI] Novo Design QT;<br>
→ [GUI] Nova Splash Screen;<br>
→ [FIX] Dev fee;<br>
→ [FIX] Staking Dust;<br>
→ [FIX] Compilações MinGW/QT;<br>
→ [UPDATE] Novas premiações PoW e PoS;<br>
→ [UPDATE] Novos endereços Foundation PoS;<br>
→ [NEW] Halving Blocks<br>

>$0031 2021/03/18<br>
→ [NEW] Checkpoints;<br>
→ [FIX] Mineração PoS;<br>
→ [BUMP] Alterada versão do protocolo mínimo para 700004;<br>
→ [BUMP] Nova versão 2.6.5.2;<br>

>$0032 2021/10/14<br>
→ [NEW] Checkpoints;<br>
→ [REMOVE] Pagamentos para a Foundation PoS;<br>
→ [NEW] Fase especial de mineração para a Foundation PoW;<br>
→ [FORK] Preparação do código para o hardfork;<br>
→ [BUMP] Alterada versão do protocolo mínimo para 700006;<br>
→ [BUMP] Nova versão 2.6.5.4;<br>

>$0033 2021/11/30<br>
→ [HARDFORK] Nova versão 2.7.0.0;<br>
→ [BUMP] Alterada versão do protocolo mínimo para 700008;<br>
→ [NEW] Implementação Tor;<br>
→ [NEW] Design de carteira;<br>
→ [NEW] SPEROSEND;<br>
→ [FIX] Correções e melhorias;<br>

>$0034 2021/12/16<br>
→ [NEW] Ativação SEGWIT(17/12/2022 a 19/12/2022);<br>
→ [BUMP] Alterada versão do protocolo mínimo para 700009;<br>
→ [BUMP] Nova versão 2.7.0.2;<br>
→ [NEW] SPEROSEND;<br>
→ [FIX] Correções e melhorias;<br>

>$0035 2022/03/21<br>
→ [NEW] Suporte para rede ONION v3;<br>

>$0036 2022/03/22<br>
→ [BUMP] Alterada versão do protocolo mínimo para 700010;<br>
→ [BUMP] Nova versão 2.7.0.3;<br>
→ [NEW] Ativação CSV(04/03/2022 a 03/05/2022);<br>
→ [NEW] Desativação de retarget PoW em rede REGTEST;<br>
→ [FIX] REGTEST PoS;<br>
→ [FIX] Impedir que os blocos PoW sejam marcados como PoS no Regstest;<br>

>$0037 2022/03/22<br>
→ [NEW] Update tor;<br>

>$0038 2022/03/22<br>
→ [FIX] Update tor;<br>

>$0039 2022/03/22<br>
→ [FIX] Desabilitação temporária de livrarias bitcoin em compilação Windows;<br>

>$0040 2022/03/22<br>
→ [UPDATE] Descrições GITIAN;<br>

>$0041 2022/03/22<br>
→ [UPDATE] Update TOR Submodule;<br>

>$0042 2022/03/22<br>
→ [FIX] Versão do protocolo de endereço TorV3;<br>
→ [FIX] Erros de serialização;<br>

>$0043 2022/03/22<br>
→ [BUMP] Nova versão 2.7.0.4;<br>
→ [FIX] Corrige o arquivo aberto pendente ao remover o nome do host TorV2;<br>

>$0044 2022/03/22<br>
→ [FIX] Pequena correção de bug do SPEROSEND para garantir a presença de endereço legado(LEGACY);<br>

>$0045 2022/03/22<br>
→ [FIX] Pacote de implantação MAC;<br>

>$0046 2022/03/22<br>
→ [BUMP] Nova versão 2.7.0.5;<br>
→ [BUMP] Alterada versão do protocolo mínimo para 700011;<br>
→ [FIX] Transmissão de nós do SperoSend;<br>

>$0047 2022/03/22<br>
→ [UPDATE] Scripts de seed para suporte TorV3;<br>
→ [UPDATE] Nós TorV3;<br>

>$0048 2022/03/22<br>
→ [FIX] Atribuição de chaves SperoSend;<br>

>$0049 2022/03/22<br>
→ [SECURITY] SperoSend - Proibir reutilização de endereço;<br>

>$0050 2022/03/22<br>
→ [UPDATE] httpserver;<br>

>$0051 2022/03/22<br>
→ [UPDATE] Documentação Unix;<br>