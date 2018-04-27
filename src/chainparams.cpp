// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x2a;
        pchMessageStart[1] = 0xdb;
        pchMessageStart[2] = 0x90;
        pchMessageStart[3] = 0xd7;
        vAlertPubKey = ParseHex("0440f8dfc18b7733499cdb751f790962c8b7d7f4380b70d75593b44b038bcd125f1a183481a4ebf1c88875be7e39983ef03fa302ebd6ff68984f20a8fa5e992a73");
        nDefaultPort = 41355;
        nRPCPort = 41356;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);

        const char* pszTimestamp = "24 April 2018 - Nchain Launches Nakasendo SDK for Bitcoin Cash Development";
        std::vector<CTxIn> vin;
        std::vector<CTxOut> vout;
        vin.resize(1);
        vout.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        vout[0].nValue = 0;
        vout[0].scriptPubKey = CScript() << ParseHex("0437fc95654bd4e5bd2e22107f0355f3d7f6d3d644cd1d6d794f2707ba4e1ec58fe86f4d1fdd3f45120b1d3088691c71a6b19549de476383001eea9470c8e0e09b") << OP_CHECKSIG;
        CTransaction txNew(1, 1524565638, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1524565638;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 3881855;

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x00000ef885e5e3439e940e6c0c142068f18d0ddb3e9b8b251b8e620cd8941789"));
        assert(genesis.hashMerkleRoot == uint256("0x0c51bedf289d06196d34b402679497e7114b1561bfc5f13b99afb179cbef5eb1"));

        vSeeds.push_back(CDNSSeedData("seed1", "seed1.dv8coin.com"));
        vSeeds.push_back(CDNSSeedData("seed2", "seed2.dv8coin.com"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 18); // 8
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 125); // s
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, 45); // K
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 5000;
        nMinStakingBeforeSuperblock = 2;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x9a;
        pchMessageStart[1] = 0x5f;
        pchMessageStart[2] = 0x7c;
        pchMessageStart[3] = 0xfb;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("04be31661637b5d6cae44b73dc35ad4286ffe66769001bc8dd8c4cb3bb32909d08fb1194c231e9fc9d0ed9310f3f5d73ffcddf493e219ef7043cb1432a81eddc6e");
        nDefaultPort = 31355;
        nRPCPort = 31356;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 463303;
        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x0000bdc49e43f203a2f1e5b695dd64ded3c29f4438ebf4224f9b7409424d5c4f"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 127); // t
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 125); // s
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 107); // k
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
        nMinStakingBeforeSuperblock = 2;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0x9f;
        pchMessageStart[1] = 0x11;
        pchMessageStart[2] = 0x64;
        pchMessageStart[3] = 0x15;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1411111111;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 196649;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18444;
        strDataDir = "regtest";

        assert(hashGenesisBlock == uint256("0x4d6bcd548288d0337b991bae754b10849304c0fe7144e83887f5ebabdb62e348"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
