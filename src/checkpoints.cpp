// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "txdb.h"
#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        //( 0,      hashGenesisBlock )
        ( 0,      uint256("0x000006f4925ed7b889f847f24621390d4943466f091c3254ca1bd8becc517f7b") ) // Params().HashGenesisBlock())
        ( 1000,      uint256("0x00000000074a040fe3a3192647a6d3f83addc2703494d5868f790603238a80d9") )
        ( 2000,      uint256("0x000000000136bf00b92f2e79a8f361a2243bfe3593caacee27ac0acfd9a9013b") )
        ( 3000,      uint256("0x00000000283981e9e700d6549b4ad850a9142d4da7fdf3b5152f94d59623309a") )
        ( 5000,      uint256("0xccfcfc45942ac1d385cd6aa98af323701a0046aea6104578faf1ed40ba533ee9") )
        ( 7000,      uint256("0x977f7b3268b676e5f9dced41992c71e11f0e5c3a3161b5caef19aa1e3c8abd33") )
        ( 10000,      uint256("0x4c5a2584e600e520f3f25b9a5a599926c2db45d3b71cb94973f8f6d8fcadc92d") )
        ( 20000,      uint256("0x0000000001196662f5fd94484fb558022128d94fa15cb41d6d358388065c3771") )
        ( 30000,      uint256("0x0000000067fefe4a3dbdba01f06e5cccbc89b9b731ec8fc4a9f871de1b98735d") )
        ( 33331,      uint256("0x000000000bddc36eaa652fb04fe731f817b10a9bc2bc224aa6daf015f6d47aed") )
        ( 40000,      uint256("0x5d77d38b79ad2df383a4900cc4c4e9c88f778e474f74db21caebee806c9c8d55") )
        ( 50000,      uint256("0x2e1e20e32e3d7225f4566a68054bbe1c186860dbea55b104a06abab2fd268dc0") )
        ( 70000,      uint256("0x41c0021b391ebf5ec5682f866df4fd32a997753f68e73deae3ad08220c595768") )
        ( 100000,      uint256("0xb9ac087b72409cfccff7c394170bc243e70d63d30a39e4e9b2429739383156bf") )
        ( 110000,      uint256("0xb259e70c4f4a5cf34a1a645c295f566c2a554903d29ae359c9fd81b1d68d9586") )
        ( 120000,      uint256("0xff8c33d12795d926a9213d80ba4bcb8fa153c87cbedb862830a55ab8956efa71") )
        ( 130000,      uint256("0x4f5727cd9a032ef1d05d1480e42a8b16e09d0d6588e389aa27bc5e461719cbc9") )
        ( 135000,      uint256("0xc7a08c183ecd1c9f38304979f2936224fe5922d0442221c22573770c66bb0a6a") )
        ( 140000,      uint256("0x298c377cc8a1f656abb7b07012e7ef92d64add2e3cd4242ba1693a6c33923aff") )
        ( 145000,      uint256("0x650aa730dc3c1e39fcce0aba4be54c2c903531a6b48c3d55c0c9b15bedd91509") )
        ( 150000,      uint256("0x19f806ae3dc3a1b2cdc54d2d05d8ca0bcef7e29ef618fe0c8ecfa826cd50f283") )
        ( 155000,      uint256("0x15edf3165319bf17b14b2c4641b854c78e12c0ed9a3b5a6f52f155f41e1f1e11") )
        ( 160000,      uint256("0xa2206bd55f4c7c63e864c067fc0a8b70f4f01d47815e711e03362140c20abd0c") )
        ( 165000,      uint256("0x226de5e21de3d782998ee55d499330b114f55f68b7cdc601654e1bef2fd1bc95") )
        ( 165962,      uint256("0xed866edc2d4e1b20891af3f927d1d703c773f49f42c4ec9b40d374969b3ca06e") ) //Primeira Transação para uma wallet Android
        ( 170000,      uint256("0x1831e1b4a852924a1db2ff3ff9f93e2ac9b06cbf1024aab8a0ea7ca1feaf1af9") )
        ( 175000,      uint256("0xef7d2bc4dc99073c500eeab412f50478208bcda63d72b41888805764a45cf49a") )
        ( 180000,      uint256("0xd9f85a122c390cce46d1d2bced240630301e747fa8a4918507a0ce224693c684") )
        ( 184000,      uint256("0xa03611d59a3fb37f66ed7ddd38f0fbd045f54da6a717d9d98f71206d043d2350") )
        ( 185000,      uint256("0x689f24ada6cb2885b58be615a3f827900e2c48d15f1964340b5fae6d8d1dde29") )
        ( 186000,      uint256("0xb624a81f8ab0fa77c9ef639fa3ee37e7a13fab560167a00033976a8286632069") )
        ( 187000,      uint256("0x27efc9b195ab54910854e6991c10ca58794063fdaea2aba90241722cc5f71ce7") )
        ( 188000,      uint256("0x12545bbb7cbf660b89f3718bb01e936db6ee93e07761b2f96b8d62511c1259fd") )
        ( 189000,      uint256("0x5fb2ca80e80390c82c1643ddd561cd375dc8451e67472a222174a1f992225eae") )
        ( 200000,      uint256("0x73ed4f560bb3dbf0ed6169b8c971cd8069ed12f368c53a97b2173520347a9bdb") )
        ( 210000,      uint256("0xdd34d9828d4f550f62fa74b3df8ea1e5ef969fa8d07b6b21fa11c5ac18e30642") )
        ( 230000,      uint256("0xb6d0c200ce66fe3c0cabb881ed089748691cae301bda6e74f8bed8dd8d016d26") )
        ( 250000,      uint256("0x3146c51788dad996465a885ea6cdff85bf31509a8e12aba14cf461b816281e9c") )
        ( 260000,      uint256("0x5349683e732d5d2a1d392a734223105922728181fd7d8bee36c3bf58a53dcb75") )
        ( 263250,      uint256("0x0c901d5e0d96663ca5802fe8ba4f7476bf25a4eb1adf57bdcb90c4c5f4a39d8e") )
        ( 263251,      uint256("0xb508b26278a63518b277f77108e50131b2a5442884a783df73addadfa671f5d3") )
        ( 280000,      uint256("0x738bc1e2b8074f57f4fb104e2f1aedfd976731a5125eff410be6ed229db1fb48") )
        ( 300000,      uint256("0x000000003456f96a7c719deb49ddd4f4a080edb288c3b2e0feb339175293a51e") )
        ( 360000,      uint256("0x00000000804cf2ad577184eb0a3b8dd23edef687cc66482dbe0513e6da3bfdd2") )
        ( 365000,      uint256("0x00000000041b5e4026c9b72b4c63a24da88080c5970a1490d34e95aa39ab3626") )
        ( 365500,      uint256("0x0000058f2a47f11cd2e65460465b8de69a71c0531abf4097c845761bd9635986") )
        ( 370000,      uint256("0x00000000035ae77b39283df7678e04beae41aface0ca5530fc7d0cbedfc8f7db") )
        ( 375000,      uint256("0x85c3d98854258a0b6c899c2c98b1d014f1d737ebb70d350c9984952592b02b8a") )
        ( 375500,      uint256("0x0000000011bbd07ed1e92a8dcc875d514a4a450286ef1c0026aba23585ce600c") )
        ( 380000,      uint256("0x0000007a7ad20c949dcdd5a99e132567c609e8a38ca50a647921c06d2387426d") )
        ( 400000,      uint256("0x0000000063fa5d794e7f56bb49a35317b6a3b275cb7887dcd6c25bc4d5b9feb2") )
        ( 450000,      uint256("0x0000000007dcce1cd89a14247ffc6a6390c58910f343aa7ba2c3e0b2015e14a5") )
        ( 500000,      uint256("0xf545b82e2708d4b88a561e24a7389814f37937f9ffd873fe90960118e4e1922e") )
        ( 550000,      uint256("0x000000004d5a0d033c68e81a2e22776c9648ea5a8614145f15d00947a49f7080") )
        ( 600000,      uint256("0x00000000001ec1e4e1e67a4cab316fa610a79c3d51ecd671dc4ffa561bc2d05d") )
        ( 650000,      uint256("0x000001c48b97f83f6da9e0a14998f4e5766c00bafd6b5b3dc035c74effc4ff50") )
        ( 700000,      uint256("0x000000003a7a3a3b0d023b9570e43c245a8d618cff915f9226d16d2bdf2f99af") )
        ( 750000,      uint256("0x000000000a52cdac263acd1c9cf157f4253b8441e1de9f7c3080da675cce2d48") )
        ( 800000,      uint256("0x6d5fda655559255d493289d8c912ca2ea684a5ee4c0c502e65232839cb2829a7") )
        ( 850000,      uint256("0x00000000347da672c0ada6807320d272488262452e24ceabd03547b709656e67") )
        ( 900000,      uint256("0x9d9cd1a44e151b07b80be6381497f559a9786fbeb889c4cdf1c4a6ccfe887c44") )
        ( 910000,      uint256("0xc50aa29d2a643e693493186ce0cfbfebbd12fd91d87d3945906a9985854878aa") )
        ( 920000,      uint256("0x87c20a7e4900d4f754cc56e7f41320df30eee8f64696406a0e6632b1761f37d7") )
    ;

    // TestNet has no checkpoints
    static MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        ( 0, hashGenesisBlockTestNet )
    ;

    bool CheckHardened(int nHeight, const uint256& hash)
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }

    // SperoCoin: synchronized checkpoint (centrally broadcasted)
    uint256 hashSyncCheckpoint = 0;
    uint256 hashPendingCheckpoint = 0;
    CSyncCheckpoint checkpointMessage;
    CSyncCheckpoint checkpointMessagePending;
    uint256 hashInvalidCheckpoint = 0;
    CCriticalSection cs_hashSyncCheckpoint;

    // SperoCoin: get last synchronized checkpoint
    CBlockIndex* GetLastSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        if (!mapBlockIndex.count(hashSyncCheckpoint))
            error("GetSyncCheckpoint: block index missing for current sync-checkpoint %s", hashSyncCheckpoint.ToString().c_str());
        else
            return mapBlockIndex[hashSyncCheckpoint];
        return NULL;
    }

    // SperoCoin: only descendant of current sync-checkpoint is allowed
    bool ValidateSyncCheckpoint(uint256 hashCheckpoint)
    {
        if (!mapBlockIndex.count(hashSyncCheckpoint))
            return error("ValidateSyncCheckpoint: block index missing for current sync-checkpoint %s", hashSyncCheckpoint.ToString().c_str());
        if (!mapBlockIndex.count(hashCheckpoint))
            return error("ValidateSyncCheckpoint: block index missing for received sync-checkpoint %s", hashCheckpoint.ToString().c_str());

        CBlockIndex* pindexSyncCheckpoint = mapBlockIndex[hashSyncCheckpoint];
        CBlockIndex* pindexCheckpointRecv = mapBlockIndex[hashCheckpoint];

        if (pindexCheckpointRecv->nHeight <= pindexSyncCheckpoint->nHeight)
        {
            // Received an older checkpoint, trace back from current checkpoint
            // to the same height of the received checkpoint to verify
            // that current checkpoint should be a descendant block
            CBlockIndex* pindex = pindexSyncCheckpoint;
            while (pindex->nHeight > pindexCheckpointRecv->nHeight)
                if (!(pindex = pindex->pprev))
                    return error("ValidateSyncCheckpoint: pprev null - block index structure failure");
            if (pindex->GetBlockHash() != hashCheckpoint)
            {
                hashInvalidCheckpoint = hashCheckpoint;
                return error("ValidateSyncCheckpoint: new sync-checkpoint %s is conflicting with current sync-checkpoint %s", hashCheckpoint.ToString().c_str(), hashSyncCheckpoint.ToString().c_str());
            }
            return false; // ignore older checkpoint
        }

        // Received checkpoint should be a descendant block of the current
        // checkpoint. Trace back to the same height of current checkpoint
        // to verify.
        CBlockIndex* pindex = pindexCheckpointRecv;
        while (pindex->nHeight > pindexSyncCheckpoint->nHeight)
            if (!(pindex = pindex->pprev))
                return error("ValidateSyncCheckpoint: pprev2 null - block index structure failure");
        if (pindex->GetBlockHash() != hashSyncCheckpoint)
        {
            hashInvalidCheckpoint = hashCheckpoint;
            return error("ValidateSyncCheckpoint: new sync-checkpoint %s is not a descendant of current sync-checkpoint %s", hashCheckpoint.ToString().c_str(), hashSyncCheckpoint.ToString().c_str());
        }
        return true;
    }

    bool WriteSyncCheckpoint(const uint256& hashCheckpoint)
    {
        CTxDB txdb;
        txdb.TxnBegin();
        if (!txdb.WriteSyncCheckpoint(hashCheckpoint))
        {
            txdb.TxnAbort();
            return error("WriteSyncCheckpoint(): failed to write to db sync checkpoint %s", hashCheckpoint.ToString().c_str());
        }
        if (!txdb.TxnCommit())
            return error("WriteSyncCheckpoint(): failed to commit to db sync checkpoint %s", hashCheckpoint.ToString().c_str());

        Checkpoints::hashSyncCheckpoint = hashCheckpoint;
        return true;
    }

    bool AcceptPendingSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        if (hashPendingCheckpoint != 0 && mapBlockIndex.count(hashPendingCheckpoint))
        {
            if (!ValidateSyncCheckpoint(hashPendingCheckpoint))
            {
                hashPendingCheckpoint = 0;
                checkpointMessagePending.SetNull();
                return false;
            }

            CTxDB txdb;
            CBlockIndex* pindexCheckpoint = mapBlockIndex[hashPendingCheckpoint];
            if (!pindexCheckpoint->IsInMainChain())
            {
                CBlock block;
                if (!block.ReadFromDisk(pindexCheckpoint))
                    return error("AcceptPendingSyncCheckpoint: ReadFromDisk failed for sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
                if (!block.SetBestChain(txdb, pindexCheckpoint))
                {
                    hashInvalidCheckpoint = hashPendingCheckpoint;
                    return error("AcceptPendingSyncCheckpoint: SetBestChain failed for sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
                }
            }

            if (!WriteSyncCheckpoint(hashPendingCheckpoint))
                return error("AcceptPendingSyncCheckpoint(): failed to write sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
            hashPendingCheckpoint = 0;
            checkpointMessage = checkpointMessagePending;
            checkpointMessagePending.SetNull();
            printf("AcceptPendingSyncCheckpoint : sync-checkpoint at %s\n", hashSyncCheckpoint.ToString().c_str());
            // relay the checkpoint
            if (!checkpointMessage.IsNull())
            {
                BOOST_FOREACH(CNode* pnode, vNodes)
                    checkpointMessage.RelayTo(pnode);
            }
            return true;
        }
        return false;
    }

    // Automatically select a suitable sync-checkpoint
    uint256 AutoSelectSyncCheckpoint()
    {
        const CBlockIndex *pindex = pindexBest;
        // Search backward for a block within max span and maturity window
        while (pindex->pprev && (pindex->GetBlockTime() + CHECKPOINT_MAX_SPAN > pindexBest->GetBlockTime() || pindex->nHeight + 8 > pindexBest->nHeight))
            pindex = pindex->pprev;
        return pindex->GetBlockHash();
    }

    // Check against synchronized checkpoint
    bool CheckSync(const uint256& hashBlock, const CBlockIndex* pindexPrev)
    {
        if (fTestNet) return true; // Testnet has no checkpoints
        int nHeight = pindexPrev->nHeight + 1;

        LOCK(cs_hashSyncCheckpoint);
        // sync-checkpoint should always be accepted block
        assert(mapBlockIndex.count(hashSyncCheckpoint));
        const CBlockIndex* pindexSync = mapBlockIndex[hashSyncCheckpoint];

        if (nHeight > pindexSync->nHeight)
        {
            // trace back to same height as sync-checkpoint
            const CBlockIndex* pindex = pindexPrev;
            while (pindex->nHeight > pindexSync->nHeight)
                if (!(pindex = pindex->pprev))
                    return error("CheckSync: pprev null - block index structure failure");
            if (pindex->nHeight < pindexSync->nHeight || pindex->GetBlockHash() != hashSyncCheckpoint)
                return false; // only descendant of sync-checkpoint can pass check
        }
        if (nHeight == pindexSync->nHeight && hashBlock != hashSyncCheckpoint)
            return false; // same height with sync-checkpoint
        if (nHeight < pindexSync->nHeight && !mapBlockIndex.count(hashBlock))
            return false; // lower height than sync-checkpoint
        return true;
    }

    bool WantedByPendingSyncCheckpoint(uint256 hashBlock)
    {
        LOCK(cs_hashSyncCheckpoint);
        if (hashPendingCheckpoint == 0)
            return false;
        if (hashBlock == hashPendingCheckpoint)
            return true;
        if (mapOrphanBlocks.count(hashPendingCheckpoint)
            && hashBlock == WantedByOrphan(mapOrphanBlocks[hashPendingCheckpoint]))
            return true;
        return false;
    }

    // SperoCoin: reset synchronized checkpoint to last hardened checkpoint
    bool ResetSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        const uint256& hash = mapCheckpoints.rbegin()->second;
        if (mapBlockIndex.count(hash) && !mapBlockIndex[hash]->IsInMainChain())
        {
            // checkpoint block accepted but not yet in main chain
            printf("ResetSyncCheckpoint: SetBestChain to hardened checkpoint %s\n", hash.ToString().c_str());
            CTxDB txdb;
            CBlock block;
            if (!block.ReadFromDisk(mapBlockIndex[hash]))
                return error("ResetSyncCheckpoint: ReadFromDisk failed for hardened checkpoint %s", hash.ToString().c_str());
            if (!block.SetBestChain(txdb, mapBlockIndex[hash]))
            {
                return error("ResetSyncCheckpoint: SetBestChain failed for hardened checkpoint %s", hash.ToString().c_str());
            }
        }
        else if(!mapBlockIndex.count(hash))
        {
            // checkpoint block not yet accepted
            hashPendingCheckpoint = hash;
            checkpointMessagePending.SetNull();
            printf("ResetSyncCheckpoint: pending for sync-checkpoint %s\n", hashPendingCheckpoint.ToString().c_str());
        }

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            if (mapBlockIndex.count(hash) && mapBlockIndex[hash]->IsInMainChain())
            {
                if (!WriteSyncCheckpoint(hash))
                    return error("ResetSyncCheckpoint: failed to write sync checkpoint %s", hash.ToString().c_str());
                printf("ResetSyncCheckpoint: sync-checkpoint reset to %s\n", hashSyncCheckpoint.ToString().c_str());
                return true;
            }
        }

        return false;
    }

    void AskForPendingSyncCheckpoint(CNode* pfrom)
    {
        LOCK(cs_hashSyncCheckpoint);
        if (pfrom && hashPendingCheckpoint != 0 && (!mapBlockIndex.count(hashPendingCheckpoint)) && (!mapOrphanBlocks.count(hashPendingCheckpoint)))
            pfrom->AskFor(CInv(MSG_BLOCK, hashPendingCheckpoint));
    }

    bool SetCheckpointPrivKey(std::string strPrivKey)
    {
        // Test signing a sync-checkpoint with genesis block
        CSyncCheckpoint checkpoint;
        checkpoint.hashCheckpoint = !fTestNet ? hashGenesisBlock : hashGenesisBlockTestNet;
        CDataStream sMsg(SER_NETWORK, PROTOCOL_VERSION);
        sMsg << (CUnsignedSyncCheckpoint)checkpoint;
        checkpoint.vchMsg = std::vector<unsigned char>(sMsg.begin(), sMsg.end());

        std::vector<unsigned char> vchPrivKey = ParseHex(strPrivKey);
        CKey key;
        key.SetPrivKey(CPrivKey(vchPrivKey.begin(), vchPrivKey.end())); // if key is not correct openssl may crash
        if (!key.Sign(Hash(checkpoint.vchMsg.begin(), checkpoint.vchMsg.end()), checkpoint.vchSig))
            return false;

        // Test signing successful, proceed
        CSyncCheckpoint::strMasterPrivKey = strPrivKey;
        return true;
    }

    bool SendSyncCheckpoint(uint256 hashCheckpoint)
    {
        CSyncCheckpoint checkpoint;
        checkpoint.hashCheckpoint = hashCheckpoint;
        CDataStream sMsg(SER_NETWORK, PROTOCOL_VERSION);
        sMsg << (CUnsignedSyncCheckpoint)checkpoint;
        checkpoint.vchMsg = std::vector<unsigned char>(sMsg.begin(), sMsg.end());

        if (CSyncCheckpoint::strMasterPrivKey.empty())
            return error("SendSyncCheckpoint: Checkpoint master key unavailable.");
        std::vector<unsigned char> vchPrivKey = ParseHex(CSyncCheckpoint::strMasterPrivKey);
        CKey key;
        key.SetPrivKey(CPrivKey(vchPrivKey.begin(), vchPrivKey.end())); // if key is not correct openssl may crash
        if (!key.Sign(Hash(checkpoint.vchMsg.begin(), checkpoint.vchMsg.end()), checkpoint.vchSig))
            return error("SendSyncCheckpoint: Unable to sign checkpoint, check private key?");

        if(!checkpoint.ProcessSyncCheckpoint(NULL))
        {
            printf("WARNING: SendSyncCheckpoint: Failed to process checkpoint.\n");
            return false;
        }

        // Relay checkpoint
        {
            LOCK(cs_vNodes);
            BOOST_FOREACH(CNode* pnode, vNodes)
                checkpoint.RelayTo(pnode);
        }
        return true;
    }

    // Is the sync-checkpoint outside maturity window?
    bool IsMatureSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        // sync-checkpoint should always be accepted block
        assert(mapBlockIndex.count(hashSyncCheckpoint));
        const CBlockIndex* pindexSync = mapBlockIndex[hashSyncCheckpoint];
        return (nBestHeight >= pindexSync->nHeight + nCoinbaseMaturity ||
                pindexSync->GetBlockTime() + nStakeMinAge < GetAdjustedTime());
    }
}

// SperoCoin: sync-checkpoint master key
const std::string CSyncCheckpoint::strMasterPubKey = "0x04fcb557b10ca5b18d9d8a60786d2e5420480ce5548f546150ae790dc7ecaaab0a37f9bb0baf459aca639ce3d72a92310e89b9b34f576cce86f452cff861502938";

std::string CSyncCheckpoint::strMasterPrivKey = "";

bool CSyncCheckpoint::RelayTo(CNode* pnode) const
{
    // don't relay to nodes which haven't sent their version message
    if (pnode->nVersion == 0)
        return false;
    // returns true if wasn't already sent
    if (pnode->hashCheckpointKnown != hashCheckpoint)
    {
        pnode->hashCheckpointKnown = hashCheckpoint;
        pnode->PushMessage("checkpoint", *this);
        return true;
    }
    return false;
}


// SperoCoin: verify signature of sync-checkpoint message
bool CSyncCheckpoint::CheckSignature()
{
    CKey key;
    if (!key.SetPubKey(ParseHex(CSyncCheckpoint::strMasterPubKey)))
        return error("CSyncCheckpoint::CheckSignature() : SetPubKey failed");
    if (!key.Verify(Hash(vchMsg.begin(), vchMsg.end()), vchSig))
        return error("CSyncCheckpoint::CheckSignature() : verify signature failed");

    // Now unserialize the data
    CDataStream sMsg(vchMsg, SER_NETWORK, PROTOCOL_VERSION);
    sMsg >> *(CUnsignedSyncCheckpoint*)this;
    return true;
}

// SperoCoin: process synchronized checkpoint
bool CSyncCheckpoint::ProcessSyncCheckpoint(CNode* pfrom)
{
    if (!CheckSignature())
        return false;

    LOCK(Checkpoints::cs_hashSyncCheckpoint);
    if (!mapBlockIndex.count(hashCheckpoint))
    {
        // We haven't received the checkpoint chain, keep the checkpoint as pending
        Checkpoints::hashPendingCheckpoint = hashCheckpoint;
        Checkpoints::checkpointMessagePending = *this;
        printf("ProcessSyncCheckpoint: pending for sync-checkpoint %s\n", hashCheckpoint.ToString().c_str());
        // Ask this guy to fill in what we're missing
        if (pfrom)
        {
            pfrom->PushGetBlocks(pindexBest, hashCheckpoint);
            // ask directly as well in case rejected earlier by duplicate
            // proof-of-stake because getblocks may not get it this time
            pfrom->AskFor(CInv(MSG_BLOCK, mapOrphanBlocks.count(hashCheckpoint)? WantedByOrphan(mapOrphanBlocks[hashCheckpoint]) : hashCheckpoint));
        }
        return false;
    }

    if (!Checkpoints::ValidateSyncCheckpoint(hashCheckpoint))
        return false;

    CTxDB txdb;
    CBlockIndex* pindexCheckpoint = mapBlockIndex[hashCheckpoint];
    if (!pindexCheckpoint->IsInMainChain())
    {
        // checkpoint chain received but not yet main chain
        CBlock block;
        if (!block.ReadFromDisk(pindexCheckpoint))
            return error("ProcessSyncCheckpoint: ReadFromDisk failed for sync checkpoint %s", hashCheckpoint.ToString().c_str());
        if (!block.SetBestChain(txdb, pindexCheckpoint))
        {
            Checkpoints::hashInvalidCheckpoint = hashCheckpoint;
            return error("ProcessSyncCheckpoint: SetBestChain failed for sync checkpoint %s", hashCheckpoint.ToString().c_str());
        }
    }

    if (!Checkpoints::WriteSyncCheckpoint(hashCheckpoint))
        return error("ProcessSyncCheckpoint(): failed to write sync checkpoint %s", hashCheckpoint.ToString().c_str());
    Checkpoints::checkpointMessage = *this;
    Checkpoints::hashPendingCheckpoint = 0;
    Checkpoints::checkpointMessagePending.SetNull();
    printf("ProcessSyncCheckpoint: sync-checkpoint at %s\n", hashCheckpoint.ToString().c_str());
    return true;
}
