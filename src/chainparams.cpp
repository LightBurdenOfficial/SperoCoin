// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>
#include <consensus/merkle.h>

#include <tinyformat.h>
#include <util.h>
#include <utilstrencodings.h>

#include <assert.h>

#include <chainparamsseeds.h>

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.nTime = nTime;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 0 << CScriptNum(42) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    // txNew.vout[0].scriptPubKey = genesisOutputScript;
    txNew.vout[0].scriptPubKey.clear();

    LogPrintf(">> txNew = %s\n", txNew.GetHash().ToString().substr(0, 10)); 

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 *
 * CBlock(hash=000004e29458ef4f2e0abab544737b07344e6ff13718f7c2d12926166db07b5e, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, 
 *  hashMerkleRoot=48a457c277b124a06b568c0036d2c834e918d952c5b2dbf4035d173f50c8d14c, nTime=1499843027, nBits=1e0fffff, nNonce=3832541, vtx=1, vchBlockSig=)
 *  Coinbase(hash=48a457c277, nTime=1499843027, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *  CTxIn(COutPoint(0000000000, 4294967295), coinbase 00012a32446565704f6e696f6e3a20746865206d6f73742073656375726520636f696e20696e20746865206379626572737061636521)
 *  CTxOut(empty)
 * vMerkleTree: 48a457c277 
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "A esperanca eh a ultima que morre.";
    const CScript genesisOutputScript = CScript() << ParseHex("a8852ebf7c49f01cd196e35394f3b74dd86283a07f57e0a262928e7493d4a3961d93d93c90ea3369719641d626d28b9cddc6d9307b9aabdbffc40b6d6da2e329d079b4187ff784b2893d9f53e9ab913a04ff02668114695b07d8ce877c4c8cac1b12b9beff3c51294ebe349eca41c24cd32a6d09dd1579d3947e5c4dcc30b2090b0454edb98c6336e7571db09e0fdafbd68d8f0470223836e90666a5b143b73b9cd71547c917bf24c0efc86af2eba046ed781d9acb05c80f007ef5a0a5dfca23236f37e698e8728def12554bc80f294f71c040a88eff144d130b24211016a97ce0f5fe520f477e555c9997683d762aff8bd1402ae6938dd5c994780b1bf6aa7239e9d8101630ecfeaa730d2bbc97d39beb057f016db2e28bf12fab4989c0170c2593383fd04660b5229adcd8486ba78f6cc1b558bcd92f344100dff239a8c00dbc4c2825277f241691dbe4a7d9bd503abb9") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

void CChainParams::UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    consensus.vDeployments[d].nStartTime = nStartTime;
    consensus.vDeployments[d].nTimeout = nTimeout;
}

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nSubsidyHalvingInterval = 131400;
        consensus.BIP16Height = 0; 
        consensus.BIP34Height = 1500000;
        consensus.BIP34Hash = uint256S("0x");
        consensus.BIP65Height = 1500000;
        consensus.BIP66Height = 1500000;
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 14400; 
        consensus.nPowTargetSpacing = 60;
        consensus.nPosTargetSpacing = 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.nStakeMinAge = 2 * 60 * 60;           // minimum age for coin age: 2h
        consensus.nStakeMaxAge = 12 * 60 * 60;          // stake age of full weight: 12h
        consensus.nModifierInterval = 10 * 30;              // time to elapse before new modifier is computed
        consensus.nCoinbaseMaturity = 5;                    // 05 Blocks maturity
        // disable NoRetargeting. NoRetargeting is always false
        // consensus.fPowNoRetargeting = false;
        // consensus.fPosNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 180; // 75% of 240
        consensus.nMinerConfirmationWindow = 960; // nPowTargetTimespan / nPowTargetSpacing * 4
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1499817600; // July 12, 2017
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1514764799; // December 31, 2017

        // Deployment of BIP68, BIP112, and BIP113.
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1548633600; // January 28, 2019
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 1548979199; // January 31st, 2019

        // Deployment of SegWit (BIP141, BIP143, and BIP147)
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 1609462800; // January 1, 2021
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = 1612054800; // January 31st, 2021

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x0000000000000000000000000000000000000000000000000000000100010001"); // Gênesis

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x87c20a7e4900d4f754cc56e7f41320df30eee8f64696406a0e6632b1761f37d7"); // 920000

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0x2d;
        pchMessageStart[1] = 0x3f;
        pchMessageStart[2] = 0xa2;
        pchMessageStart[3] = 0xf5;
        nDefaultPort = 55680;
        nPruneAfterHeight = 33331;

        genesis = CreateGenesisBlock(1506335848, 44360, 0x1e0fffff, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();

        //LogPrintf(">> block = %s\n", genesis.ToString()); 
        //LogPrintf(">> block.GetHash() == %s\n", genesis.GetHash().ToString().c_str());
        //LogPrintf(">> block.hashMerkleRoot == %s\n", genesis.hashMerkleRoot.ToString().c_str());
        //LogPrintf(">> block.nTime = %u \n", genesis.nTime);
        //LogPrintf(">> block.nNonce = %u \n", genesis.nNonce);

        assert(consensus.hashGenesisBlock == uint256S("0x000006f4925ed7b889f847f24621390d4943466f091c3254ca1bd8becc517f7b"));
        assert(genesis.hashMerkleRoot == uint256S("0x6f5dd836da72471e5ea8f3c836249e447059f9f7c7c26a2f91fecd0c509dd677"));

        // Note that of those with the service bits flag, most only support a subset of possible options
//        vSeeds.emplace_back("seed-a.SperoCoin.loshan.co.uk");
//        vSeeds.emplace_back("dnsseed.thrasher.io");
//        vSeeds.emplace_back("dnsseed.SperoCointools.com");
//        vSeeds.emplace_back("dnsseed.SperoCoinpool.org");
//        vSeeds.emplace_back("dnsseed.koin-project.com");

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,63);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,5);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,5);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,63 + 128);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4};

        bech32_hrp = "spr";

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        /* Início Adaptação para pagamentos Foundation */
        strFoundationAddr = "ScCJWtVVQxtEkKDqnL43aJpzULvpEE5fBD";
        strFoundationPoSAddr = "Sc2enwSCAjf9hnbQ5u9qA9TUDcBLcF1waA";
        /* Fim Adaptação para pagamentos Foundation */

        checkpointData = {
            {
                { 0,      uint256S("0x000006f4925ed7b889f847f24621390d4943466f091c3254ca1bd8becc517f7b")},
                { 1000,      uint256S("0x00000000074a040fe3a3192647a6d3f83addc2703494d5868f790603238a80d9")},
                { 2000,      uint256S("0x000000000136bf00b92f2e79a8f361a2243bfe3593caacee27ac0acfd9a9013b")},
                { 3000,      uint256S("0x00000000283981e9e700d6549b4ad850a9142d4da7fdf3b5152f94d59623309a")},
                { 5000,      uint256S("0xccfcfc45942ac1d385cd6aa98af323701a0046aea6104578faf1ed40ba533ee9")},
                { 7000,      uint256S("0x977f7b3268b676e5f9dced41992c71e11f0e5c3a3161b5caef19aa1e3c8abd33")},
                { 10000,      uint256S("0x4c5a2584e600e520f3f25b9a5a599926c2db45d3b71cb94973f8f6d8fcadc92d")},
                { 20000,      uint256S("0x0000000001196662f5fd94484fb558022128d94fa15cb41d6d358388065c3771")},
                { 30000,      uint256S("0x0000000067fefe4a3dbdba01f06e5cccbc89b9b731ec8fc4a9f871de1b98735d")},
                { 33331,      uint256S("0x000000000bddc36eaa652fb04fe731f817b10a9bc2bc224aa6daf015f6d47aed")},
                { 40000,      uint256S("0x5d77d38b79ad2df383a4900cc4c4e9c88f778e474f74db21caebee806c9c8d55")},
                { 50000,      uint256S("0x2e1e20e32e3d7225f4566a68054bbe1c186860dbea55b104a06abab2fd268dc0")},
                { 70000,      uint256S("0x41c0021b391ebf5ec5682f866df4fd32a997753f68e73deae3ad08220c595768")},
                { 100000,      uint256S("0xb9ac087b72409cfccff7c394170bc243e70d63d30a39e4e9b2429739383156bf")},
                { 110000,      uint256S("0xb259e70c4f4a5cf34a1a645c295f566c2a554903d29ae359c9fd81b1d68d9586")},
                { 120000,      uint256S("0xff8c33d12795d926a9213d80ba4bcb8fa153c87cbedb862830a55ab8956efa71")},
                { 130000,      uint256S("0x4f5727cd9a032ef1d05d1480e42a8b16e09d0d6588e389aa27bc5e461719cbc9")},
                { 135000,      uint256S("0xc7a08c183ecd1c9f38304979f2936224fe5922d0442221c22573770c66bb0a6a")},
                { 140000,      uint256S("0x298c377cc8a1f656abb7b07012e7ef92d64add2e3cd4242ba1693a6c33923aff")},
                { 145000,      uint256S("0x650aa730dc3c1e39fcce0aba4be54c2c903531a6b48c3d55c0c9b15bedd91509")},
                { 150000,      uint256S("0x19f806ae3dc3a1b2cdc54d2d05d8ca0bcef7e29ef618fe0c8ecfa826cd50f283")},
                { 155000,      uint256S("0x15edf3165319bf17b14b2c4641b854c78e12c0ed9a3b5a6f52f155f41e1f1e11")},
                { 160000,      uint256S("0xa2206bd55f4c7c63e864c067fc0a8b70f4f01d47815e711e03362140c20abd0c")},
                { 165000,      uint256S("0x226de5e21de3d782998ee55d499330b114f55f68b7cdc601654e1bef2fd1bc95")},
                { 165962,      uint256S("0xed866edc2d4e1b20891af3f927d1d703c773f49f42c4ec9b40d374969b3ca06e")},
                { 170000,      uint256S("0x1831e1b4a852924a1db2ff3ff9f93e2ac9b06cbf1024aab8a0ea7ca1feaf1af9")},
                { 175000,      uint256S("0xef7d2bc4dc99073c500eeab412f50478208bcda63d72b41888805764a45cf49a")},
                { 180000,      uint256S("0xd9f85a122c390cce46d1d2bced240630301e747fa8a4918507a0ce224693c684")},
                { 184000,      uint256S("0xa03611d59a3fb37f66ed7ddd38f0fbd045f54da6a717d9d98f71206d043d2350")},
                { 185000,      uint256S("0x689f24ada6cb2885b58be615a3f827900e2c48d15f1964340b5fae6d8d1dde29")},
                { 186000,      uint256S("0xb624a81f8ab0fa77c9ef639fa3ee37e7a13fab560167a00033976a8286632069")},
                { 187000,      uint256S("0x27efc9b195ab54910854e6991c10ca58794063fdaea2aba90241722cc5f71ce7")},
                { 188000,      uint256S("0x12545bbb7cbf660b89f3718bb01e936db6ee93e07761b2f96b8d62511c1259fd")},
                { 189000,      uint256S("0x5fb2ca80e80390c82c1643ddd561cd375dc8451e67472a222174a1f992225eae")},
                { 200000,      uint256S("0x73ed4f560bb3dbf0ed6169b8c971cd8069ed12f368c53a97b2173520347a9bdb")},
                { 210000,      uint256S("0xdd34d9828d4f550f62fa74b3df8ea1e5ef969fa8d07b6b21fa11c5ac18e30642")},
                { 230000,      uint256S("0xb6d0c200ce66fe3c0cabb881ed089748691cae301bda6e74f8bed8dd8d016d26")},
                { 250000,      uint256S("0x3146c51788dad996465a885ea6cdff85bf31509a8e12aba14cf461b816281e9c")},
                { 260000,      uint256S("0x5349683e732d5d2a1d392a734223105922728181fd7d8bee36c3bf58a53dcb75")},
                { 263250,      uint256S("0x0c901d5e0d96663ca5802fe8ba4f7476bf25a4eb1adf57bdcb90c4c5f4a39d8e")},
                { 263251,      uint256S("0xb508b26278a63518b277f77108e50131b2a5442884a783df73addadfa671f5d3")},
                { 280000,      uint256S("0x738bc1e2b8074f57f4fb104e2f1aedfd976731a5125eff410be6ed229db1fb48")},
                { 300000,      uint256S("0x000000003456f96a7c719deb49ddd4f4a080edb288c3b2e0feb339175293a51e")},
                { 360000,      uint256S("0x00000000804cf2ad577184eb0a3b8dd23edef687cc66482dbe0513e6da3bfdd2")},
                { 365000,      uint256S("0x00000000041b5e4026c9b72b4c63a24da88080c5970a1490d34e95aa39ab3626")},
                { 365500,      uint256S("0x0000058f2a47f11cd2e65460465b8de69a71c0531abf4097c845761bd9635986")},
                { 370000,      uint256S("0x00000000035ae77b39283df7678e04beae41aface0ca5530fc7d0cbedfc8f7db")},
                { 375000,      uint256S("0x85c3d98854258a0b6c899c2c98b1d014f1d737ebb70d350c9984952592b02b8a")},
                { 375500,      uint256S("0x0000000011bbd07ed1e92a8dcc875d514a4a450286ef1c0026aba23585ce600c")},
                { 380000,      uint256S("0x0000007a7ad20c949dcdd5a99e132567c609e8a38ca50a647921c06d2387426d")},
                { 400000,      uint256S("0x0000000063fa5d794e7f56bb49a35317b6a3b275cb7887dcd6c25bc4d5b9feb2")},
                { 450000,      uint256S("0x0000000007dcce1cd89a14247ffc6a6390c58910f343aa7ba2c3e0b2015e14a5")},
                { 500000,      uint256S("0xf545b82e2708d4b88a561e24a7389814f37937f9ffd873fe90960118e4e1922e")},
                { 550000,      uint256S("0x000000004d5a0d033c68e81a2e22776c9648ea5a8614145f15d00947a49f7080")},
                { 600000,      uint256S("0x00000000001ec1e4e1e67a4cab316fa610a79c3d51ecd671dc4ffa561bc2d05d")},
                { 650000,      uint256S("0x000001c48b97f83f6da9e0a14998f4e5766c00bafd6b5b3dc035c74effc4ff50")},
                { 700000,      uint256S("0x000000003a7a3a3b0d023b9570e43c245a8d618cff915f9226d16d2bdf2f99af")},
                { 750000,      uint256S("0x000000000a52cdac263acd1c9cf157f4253b8441e1de9f7c3080da675cce2d48")},
                { 800000,      uint256S("0x6d5fda655559255d493289d8c912ca2ea684a5ee4c0c502e65232839cb2829a7")},
                { 850000,      uint256S("0x00000000347da672c0ada6807320d272488262452e24ceabd03547b709656e67")},
                { 900000,      uint256S("0x9d9cd1a44e151b07b80be6381497f559a9786fbeb889c4cdf1c4a6ccfe887c44")},
                { 910000,      uint256S("0xc50aa29d2a643e693493186ce0cfbfebbd12fd91d87d3945906a9985854878aa")},
                { 920000,      uint256S("0x87c20a7e4900d4f754cc56e7f41320df30eee8f64696406a0e6632b1761f37d7")},
            }
        };

        chainTxData = ChainTxData{
            // Data as of block 87c20a7e4900d4f754cc56e7f41320df30eee8f64696406a0e6632b1761f37d7 (height 920000).
            1603115485, // * UNIX timestamp of last known number of transactions
            920000,  // * total number of transactions between genesis and that timestamp
                    //   (the tx=... number in the SetBestChain debug.log lines)
            0.017    // * estimated number of transactions per second after that timestamp
        };

        mapStakeModifierCheckpoints.insert(std::pair<int, unsigned int>(0, 0x0e00670bu));
    }
};



/**
 * Testnet (v3)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        consensus.nSubsidyHalvingInterval = 131400;
        consensus.BIP16Height = 0; // always enforce P2SH BIP16 on regtest
        consensus.BIP34Height = 100;
        consensus.BIP34Hash = uint256S("0x");
        consensus.BIP65Height = 100; // 8075c771ed8b495ffd943980a95f702ab34fce3c8c54e379548bda33cc8c0573
        consensus.BIP66Height = 100; // 8075c771ed8b495ffd943980a95f702ab34fce3c8c54e379548bda33cc8c0573
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 14400; 
        consensus.nPowTargetSpacing = 240;
        consensus.nPosTargetSpacing = 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        // consensus.fPowNoRetargeting = false;
        // consensus.fPosNoRetargeting = false;
        consensus.nStakeMinAge = 2 * 60 * 60;                   // minimum age for coin age: 2 hours
        consensus.nStakeMaxAge = 12 * 60 * 60;          // stake age of full weight: 12 hours
        consensus.nModifierInterval = 10 * 30;                  // time to elapse before new modifier is computed
        consensus.nCoinbaseMaturity = 5;                    // Blocks maturity
        consensus.nRuleChangeActivationThreshold = 45;      // 75% for testchains
        consensus.nMinerConfirmationWindow = 60;            // nPowTargetTimespan / nPowTargetSpacing
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008

        // Deployment of BIP68, BIP112, and BIP113.
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1483228800; // January 1, 2017
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 1517356801; // January 31st, 2018

        // Deployment of SegWit (BIP141, BIP143, and BIP147)
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 1602417600; // Sunday, 11-Oct-20 12:00:00 UTC
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = 1602504000; // Monday, 12-Sep-20 12:00:00 UTC

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x0000ad53ea93741a20bd68f895d886b6cadc2b4b30a4e487d03417cfd9e1e537");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x0000ad53ea93741a20bd68f895d886b6cadc2b4b30a4e487d03417cfd9e1e537"); //5

        pchMessageStart[0] = 0x71;
        pchMessageStart[1] = 0x36;
        pchMessageStart[2] = 0x22;
        pchMessageStart[3] = 0x05;
        nDefaultPort = 55690;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1506335848, 15547, 0x1f00ffff, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x00001fe23e7d6951a2a07ad684ff208fab9110fad607fabd81482a1692382f8f"));
        assert(genesis.hashMerkleRoot == uint256S("0x6f5dd836da72471e5ea8f3c836249e447059f9f7c7c26a2f91fecd0c509dd677"));

        //LogPrintf(">> block = %s\n", genesis.ToString()); 
        //LogPrintf(">> block.GetHash() == %s\n", genesis.GetHash().ToString().c_str());
        //LogPrintf(">> block.hashMerkleRoot == %s\n", genesis.hashMerkleRoot.ToString().c_str());
        //LogPrintf(">> block.nTime = %u \n", genesis.nTime);
        //LogPrintf(">> block.nNonce = %u \n", genesis.nNonce);

        vFixedSeeds.clear();
        vSeeds.clear();
        // nodes with support for servicebits filtering should be at the top
//        vSeeds.emplace_back("testnet-seed.SperoCointools.com");
//        vSeeds.emplace_back("seed-b.SperoCoin.loshan.co.uk");
//        vSeeds.emplace_back("dnsseed-testnet.thrasher.io");

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,125);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "tspr";

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        /* Início Adaptação para pagamentos Foundation */
        strFoundationAddr = "sbEje8AqUUqkUXXNGYJodR2SN3emT6PVzA";
        strFoundationPoSAddr = "saFFVBM6CGw7RTJLHdDJcizQ1V77XbkzTv";
        /* Fim Adaptação para pagamentos Foundation */

        checkpointData = (CCheckpointData) {
            {
                {  1, uint256S("0x0000dd2fd0ac02ea7f9594235cb04e12924d52a220592ba0b14e0348330ead3c")},
                {  2, uint256S("0x00005185d1aec84e07b99a472538ee28d4f1a06c1be7bf3252e60894e9233603")},
                {  3, uint256S("0x0000bd77c3d10fc67d9a32426b01e167caa6951f35fe299407e71a034eb5712e")},
                {  4, uint256S("0x0000f076b5717bcea271118b769470809b452bc472b10be4682b896e7c42dd44")},
                {  5, uint256S("0x0000ad53ea93741a20bd68f895d886b6cadc2b4b30a4e487d03417cfd9e1e537")},
                {  6, uint256S("0x00000f0df8b937efecf5fb4b9a8e723591c1c080b5ba7501271499aa84fbb18d")},
                {  7, uint256S("0x0000c3729cb6061411cf64d8afa53fbd14253d62d04b4c92920b25e02b9b73c8")},
                {  8, uint256S("0x000023d814940cadb8a8c34eb01e95c6144c00d1b2b13b924bd7fc8c7ef1dfe9")},
                {  9, uint256S("0x0000106b415faf09b543bc0996c48c008946bcbc7a268191743a7f189b0b3259")},
                {  10, uint256S("0x0000262264cac5c9c02f31b7ed6fe3c5fb95b610c7fc3ad5385459bd3a6f71e6")},
            }
        };

        chainTxData = ChainTxData{
            // Data as of block a0afbded94d4be233e191525dc2d467af5c7eab3143c852c3cd549831022aad6 (height 343833)
            1506335848,
            0,
            0.1
        };

        mapStakeModifierCheckpoints.insert(std::pair<int, unsigned int>( 0, 0x0e00670bu ));
        mapStakeModifierCheckpoints.insert(std::pair<int, unsigned int>( 6, 0xc502335bu ));
        mapStakeModifierCheckpoints.insert(std::pair<int, unsigned int>( 7, 0x0454233eu ));
        mapStakeModifierCheckpoints.insert(std::pair<int, unsigned int>( 8, 0x384c43c1u ));
        mapStakeModifierCheckpoints.insert(std::pair<int, unsigned int>( 9, 0x384c43c1u ));
        mapStakeModifierCheckpoints.insert(std::pair<int, unsigned int>( 10, 0x30267f1fu ));
    }
};

/**
 * Regression test
 */
class CRegTestParams : public CChainParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        consensus.nSubsidyHalvingInterval = 150;
        consensus.BIP16Height = 0; // always enforce P2SH BIP16 on regtest
        consensus.BIP34Height = 100000000; // BIP34 has not activated on regtest (far in the future so block v1 are not rejected in tests)
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 1351; // BIP65 activated on regtest (Used in rpc activation tests)
        consensus.BIP66Height = 1251; // BIP66 activated on regtest (Used in rpc activation tests)
        consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 14400; // two weeks
        consensus.nPowTargetSpacing = 240;
        consensus.nPosTargetSpacing = 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        // consensus.fPowNoRetargeting = true;
        // consensus.fPosNoRetargeting = true;
        consensus.nStakeMinAge = 2 * 60 * 60;           // minimum age for coin age: 1d
        consensus.nStakeMaxAge = 12 * 60 * 60;          // stake age of full weight: 30d
        consensus.nModifierInterval = 10 * 30;              // time to elapse before new modifier is computed
        consensus.nCoinbaseMaturity = 5;                    // 40 Blocks maturity
        consensus.nRuleChangeActivationThreshold = 45; // 75% for testchains
        consensus.nMinerConfirmationWindow = 60; // Faster than normal for regtest (144 instead of 2016)
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00");

        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nDefaultPort = 55670;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1604157889, 1249377, 0x1e0fffff, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();

        LogPrintf(">> block = %s\n", genesis.ToString()); 
        LogPrintf(">> block.GetHash() == %s\n", genesis.GetHash().ToString().c_str());
        LogPrintf(">> block.hashMerkleRoot == %s\n", genesis.hashMerkleRoot.ToString().c_str());
        LogPrintf(">> block.nTime = %u \n", genesis.nTime);
        LogPrintf(">> block.nNonce = %u \n", genesis.nNonce);


        //assert(consensus.hashGenesisBlock == uint256S("0x"));
        //assert(genesis.hashMerkleRoot == uint256S("0x"));

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //!< Regtest mode doesn't have any DNS seeds.

        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        /* Início Adaptação para pagamentos Foundation */
        strFoundationAddr = "sbEje8AqUUqkUXXNGYJodR2SN3emT6PVzA";
        strFoundationPoSAddr = "saFFVBM6CGw7RTJLHdDJcizQ1V77XbkzTv";
        /* Fim Adaptação para pagamentos Foundation */

        checkpointData = {
            {
                {0, uint256S("0x")},
            }
        };

        chainTxData = ChainTxData{
            0,
            0,
            0
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,140);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,58);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "rspr";

        mapStakeModifierCheckpoints.insert(std::pair<int, unsigned int>(0, 0x0e00670bu));

    }
};

static std::unique_ptr<CChainParams> globalChainParams;

const CChainParams &Params() {
    assert(globalChainParams);
    return *globalChainParams;
}

std::unique_ptr<CChainParams> CreateChainParams(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
        return std::unique_ptr<CChainParams>(new CMainParams());
    else if (chain == CBaseChainParams::TESTNET)
        return std::unique_ptr<CChainParams>(new CTestNetParams());
    else if (chain == CBaseChainParams::REGTEST)
        return std::unique_ptr<CChainParams>(new CRegTestParams());
    throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    globalChainParams = CreateChainParams(network);
}

void UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    globalChainParams->UpdateVersionBitsParameters(d, nStartTime, nTimeout);
}