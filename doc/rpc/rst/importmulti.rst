.. This file is licensed under the MIT License (MIT) available on
   http://opensource.org/licenses/MIT.

importmulti
===========

``importmulti "requests" ( "options" )``

Import addresses/scripts (with private or public keys, redeem script (P2SH)), rescanning all addresses in one-shot-only (rescan can be disabled via options). Requires a new wallet backup.

Argument #1 - requests
~~~~~~~~~~~~~~~~~~~~~~

**Type:** array, required

Data to be imported

::

  [     (array of json objects)
    {
      "scriptPubKey": "<script>" | { "address":"<address>" }, (string / json, required) Type of scriptPubKey (string for script, json for address)
      "timestamp": timestamp | "now"                        , (integer / string, required) Creation time of the key in seconds since epoch (Jan 1 1970 GMT),
                                                              or the string "now" to substitute the current synced blockchain time. The timestamp of the oldest
                                                              key will determine how far back blockchain rescans need to begin for missing wallet transactions.
                                                              "now" can be specified to bypass scanning, for keys which are known to never have been used, and
                                                              0 can be specified to scan the entire blockchain. Blocks up to 2 hours before the earliest key
                                                              creation time of all keys being imported by the importmulti call will be scanned.
      "redeemscript": "<script>"                            , (string, optional) Allowed only if the scriptPubKey is a P2SH address or a P2SH scriptPubKey
      "pubkeys": ["<pubKey>", ... ]                         , (array, optional) Array of strings giving pubkeys that must occur in the output or redeemscript
      "keys": ["<key>", ... ]                               , (array, optional) Array of strings giving private keys whose corresponding public keys must occur in the output or redeemscript
      "internal": <true>                                    , (boolean, optional, default: false) Stating whether matching outputs should be treated as not incoming payments
      "watchonly": <true>                                   , (boolean, optional, default: false) Stating whether matching outputs should be considered watched even when they're not spendable, only allowed if keys are empty
      "label": <label>                                      , (string, optional, default: '') Label to assign to the address (aka account name, for now), only allowed with internal=false
    }
  ,...
  ]

Argument #2 - options
~~~~~~~~~~~~~~~~~~~~~

**Type:** json, optional

::

  {
     "rescan": <false>,         (boolean, optional, default: true) Stating if should rescan the blockchain after all imports
  }

Examples
~~~~~~~~


.. highlight:: shell

::

  SperoCoin-cli importmulti '[{ "scriptPubKey": { "address": "<my address>" }, "timestamp":1455191478 }, { "scriptPubKey": { "address": "<my 2nd address>" }, "label": "example 2", "timestamp": 1455191480 }]'

::

  SperoCoin-cli importmulti '[{ "scriptPubKey": { "address": "<my address>" }, "timestamp":1455191478 }]' '{ "rescan": false}'

