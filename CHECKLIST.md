### DV8

Name: DV8 Coin
Ticker: DV8
Algo: Scrypt
Block Time: 120 secs
P2P Port: 41355 / 31355
RCP Port: 41356 / 31356
Max Supply: 50,000,000,000
Premine: (0.1%) 50m coins
Maturity: 10 blocks
Min Maturity: 12 hours
Max Maturity: 2 days

POW Reward scheme:

2-200 = 1
201-1000 = 5
1001-5000 =  10

POW ends at block 5k

POS Reward scheme: ”fixed” 500% except blocks:
08,88 – 10000%
11,77,99 – 7500%
00,22,33,44,55,66 – 5000%
18,28,38,48,58,68, – 2000%
05,12,15,25,32,35,42,45,52,62,65,72,75,82,85,92,95 - 1000%

Address start: 8



- [x] Change Text
- [x] Rename files


Usare Toolz/create_coin_keys per generare alert key main/test net
Queste pubkey vanno inserite dentro chainparams.cpp vAlertPubKey (classi CMainParams/CTestNetParams)

- [x] AlertKey
- [x] AlertKey Testnet

Prendiamo da https://en.bitcoin.it/wiki/List_of_address_prefixes il prefisso dell'indirizzo per PUBKEY_ADDRESS (chainparams.cpp)

- [x] PubKey

Usare Toolz/random_port per generare la porta P2P / RPC dentro il range 1025 - 65534.
Facciamo una sostituzione globale per le porte P2P/RPC della main/test net.
Possiamo prendere il valore attuale dentro chainparams.cpp (nDefaultPort e nRPCPort).

- [x] P2P Port
- [x] RPC Port

Per generare il blocco genesis dobbiamo modificare all'interno di chainparams.cpp i seguenti parametri:

pszTimestamp
scriptPubKey
nTime


- [x] Genesis
- [x] pchMessageStart main/test/reg net.

- [x] Change wallet test address (8WhgnJFY8KiQVE5atkh6gS5rGY1tViDWwj) 8WhgnJFY8KiQVE5atkh6gS5rGY1tViDWwj

- [x] Block time (main.h - GetTargetSpacing)
- [x] Max supply (main.h - MAX_MONEY)
- [x] Maturity (main.cpp - nCoinbaseMaturity)
- [x] Min Maturity
- [x] Max Maturity
- [x] POW Reward System
- [x] POS Reward System
- [x] Check max CAP

- [ ] Change images
- [ ] Change icons
- [ ] Custom UX