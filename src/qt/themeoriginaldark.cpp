// Copyright (c) 2017-2019 The SperoCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php

#include "themeoriginaldark.h"


ThemeOriginalDark::ThemeOriginalDark() 
{
	init();
}

void ThemeOriginalDark::init() 
{
	title_background = "#486EBA";

	aboutImg = ":/images/about_dark";
	speroCoinLogo = ":/icons/SperoCoinLogo";
    sendSperoSendIco = ":/icons/sperosendBlueDark";
	
    ThemeDark::init();
}
