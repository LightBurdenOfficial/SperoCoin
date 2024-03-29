// Copyright (c) 2017-2019 The SperoCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php

#include "themeoriginallight.h"

ThemeOriginalLight::ThemeOriginalLight()
{
	init();
}

void ThemeOriginalLight::init() 
{
    title_background = "#486EBA";

    mainMenuOverviewNormalBtnIco = ":/icons/overview";
    mainMenuSendcoinsNormalBtnIco = ":/icons/send";
    mainMenuReceiveCoinsNormalBtnIco = ":/icons/receiving_addresses";
    mainMenuTransactionsNormalBtnIco = ":/icons/history";
    mainMenuAddressBookNormalBtnIco = ":/icons/address-book";
    mainMenuMessagesNormalBtnIco = ":/icons/messaging";
    mainMenuExportNormalBtnIco = ":/icons/export";
	mainMenuUnlockWalletNormalBtnIco = ":/icons/lock_open";
	mainMenuLockWalletNormalBtnIco = ":/icons/lock_closed";
    mainMenuDeepVaultNormalBtnIco = ":/icons/sperovault";
    
    aboutImg = ":/images/about_light";
    speroCoinLogo = ":/icons/SperoCoinLogo";
    sendSperoSendIco = ":/icons/sperosendBlueLight";
    
    ThemeLight::init();
}
