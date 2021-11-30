// Copyright (c) 2019 The SperoCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php


#include "themedarkgreen.h"

ThemeDarkGreen::ThemeDarkGreen()
{
	init();
}

void ThemeDarkGreen::init()
{
    title_background = "#61ac56";

	aboutImg = ":/images/about_dark_green";
    speroCoinLogo = ":/icons/SperoCoinLogoGreen";
    sendSperoSendIco = ":/icons/sperosendGreenDark";
    
    ThemeDark::init();
}
