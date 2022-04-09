.. This file is licensed under the MIT License (MIT) available on
   http://opensource.org/licenses/MIT.

sendwithsperosend
================

``sendwithsperosend "address" amount``

Send an amount to a given address unisng sperosend service.

Argument #1 - address
~~~~~~~~~~~~~~~~~~~~~

**Type:** string, required

The SperoCoin address to send to.

Argument #2 - amount
~~~~~~~~~~~~~~~~~~~~

**Type:** numeric or string, required

The amount in SPERO to send. eg 0.1

Result
~~~~~~

.. list-table::
   :header-rows: 1

   * - Name
     - Type
     - Description
   * - txid
     - string
     - Info related with sperosend service.

Examples
~~~~~~~~


.. highlight:: shell

::

  SperoCoin-cli sendwithsperosend "Dc7BLTLqSyWSp6uEpQPbbcb7figA7xHjKQ" 0.123

