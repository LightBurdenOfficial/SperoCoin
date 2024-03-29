.. This file is licensed under the MIT License (MIT) available on
   http://opensource.org/licenses/MIT.

getmempoolancestors
===================

``getmempoolancestors txid (verbose)``

If txid is in the mempool, returns all in-mempool ancestors.

Argument #1 - txid
~~~~~~~~~~~~~~~~~~

**Type:** string, required

The transaction id (must be in mempool)

Argument #2 - verbose
~~~~~~~~~~~~~~~~~~~~~

**Type:** boolean, optional, default=false

True for a json object, false for array of transaction ids

Result (for verbose=false)
~~~~~~~~~~~~~~~~~~~~~~~~~~

::

  [                       (json array of strings)
    "transactionid"           (string) The transaction id of an in-mempool ancestor transaction
    ,...
  ]

Result (for verbose=true)
~~~~~~~~~~~~~~~~~~~~~~~~~

::

  {                           (json object)
    "transactionid" : {       (json object)
      "size" : n,             (numeric) virtual transaction size as defined in BIP 141. This is different from actual serialized size for witness transactions as witness data is discounted.
      "fee" : n,              (numeric) transaction fee in SPERO
      "modifiedfee" : n,      (numeric) transaction fee with fee deltas used for mining priority
      "time" : n,             (numeric) local time transaction entered pool in seconds since 1 Jan 1970 GMT
      "height" : n,           (numeric) block height when transaction entered pool
      "descendantcount" : n,  (numeric) number of in-mempool descendant transactions (including this one)
      "descendantsize" : n,   (numeric) virtual transaction size of in-mempool descendants (including this one)
      "descendantfees" : n,   (numeric) modified fees (see above) of in-mempool descendants (including this one)
      "ancestorcount" : n,    (numeric) number of in-mempool ancestor transactions (including this one)
      "ancestorsize" : n,     (numeric) virtual transaction size of in-mempool ancestors (including this one)
      "ancestorfees" : n,     (numeric) modified fees (see above) of in-mempool ancestors (including this one)
      "wtxid" : hash,         (string) hash of serialized transaction, including witness data
      "depends" : [           (array) unconfirmed transactions used as inputs for this transaction
          "transactionid",    (string) parent transaction id
         ... ]
    }, ...
  }

Examples
~~~~~~~~


.. highlight:: shell

::

  SperoCoin-cli getmempoolancestors "mytxid"

::

  curl --user myusername --data-binary '{"jsonrpc": "1.0", "id":"curltest", "method": "getmempoolancestors", "params": ["mytxid"] }' -H 'content-type: text/plain;' http://127.0.0.1:55681/

