.. This file is licensed under the MIT License (MIT) available on
   http://opensource.org/licenses/MIT.

getblock
========

``getblock "blockhash" ( verbosity )``

If verbosity is 0, returns a string that is serialized, hex-encoded data for block 'hash'.

If verbosity is 1, returns an Object with information about block 'hash'.

If verbosity is 2, returns an Object with information about block 'hash' and information about each transaction.

Argument #1 - blockhash
~~~~~~~~~~~~~~~~~~~~~~~

**Type:** string, required

The block hash

Argument #2 - verbosity
~~~~~~~~~~~~~~~~~~~~~~~

**Type:** numeric, optional, default=1

0 for hex encoded data, 1 for a json object, and 2 for json object with transaction data

Result (for verbosity = 0)
~~~~~~~~~~~~~~~~~~~~~~~~~~

.. list-table::
   :header-rows: 1

   * - Name
     - Type
     - Description
   * - data
     - string
     - A string that is serialized, hex-encoded data for block 'hash'.

Result (for verbosity = 1)
~~~~~~~~~~~~~~~~~~~~~~~~~~

::

  {
    "hash" : "hash",     (string) the block hash (same as provided)
    "confirmations" : n,   (numeric) The number of confirmations, or -1 if the block is not on the main chain
    "size" : n,            (numeric) The block size
    "strippedsize" : n,    (numeric) The block size excluding witness data
    "weight" : n           (numeric) The block weight as defined in BIP 141
    "height" : n,          (numeric) The block height or index
    "version" : n,         (numeric) The block version
    "versionHex" : "00000000", (string) The block version formatted in hexadecimal
    "merkleroot" : "xxxx", (string) The merkle root
    "tx" : [               (array of string) The transaction ids
       "transactionid"     (string) The transaction id
       ,...
    ],
    "time" : ttt,          (numeric) The block time in seconds since epoch (Jan 1 1970 GMT)
    "mediantime" : ttt,    (numeric) The median block time in seconds since epoch (Jan 1 1970 GMT)
    "nonce" : n,           (numeric) The nonce
    "bits" : "1d00ffff", (string) The bits
    "difficulty" : x.xxx,  (numeric) The difficulty
    "chainwork" : "xxxx",  (string) Expected number of hashes required to produce the chain up to this block (in hex)
    "previousblockhash" : "hash",  (string) The hash of the previous block
    "nextblockhash" : "hash"       (string) The hash of the next block
  }

Result (for verbosity = 2)
~~~~~~~~~~~~~~~~~~~~~~~~~~

::

  {
    ...,                     Same output as verbosity = 1.
    "tx" : [               (array of Objects) The transactions in the format of the getrawtransaction RPC. Different from verbosity = 1 "tx" result.
           ,...
    ],
    ,...                     Same output as verbosity = 1.
  }

Examples
~~~~~~~~


.. highlight:: shell

::

  SperoCoin-cli getblock "e2acdf2dd19a702e5d12a925f1e984b01e47a933562ca893656d4afb38b44ee3"

::

  curl --user myusername --data-binary '{"jsonrpc": "1.0", "id":"curltest", "method": "getblock", "params": ["e2acdf2dd19a702e5d12a925f1e984b01e47a933562ca893656d4afb38b44ee3"] }' -H 'content-type: text/plain;' http://127.0.0.1:55681/

