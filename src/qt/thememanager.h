//
// Created by arcas on 5/18/2018.
//

#ifndef SPEROCOIN_THEME_THEMEMANAGER_H
#define SPEROCOIN_THEME_THEMEMANAGER_H
#include <iostream>
#include <string>
#include <map>
#include "theme.h"
#include <QString>

enum ThemeType
{
	THEME_ORIGINAL_DARK = 1,
	THEME_ORIGINAL_LIGHT = 2,
	THEME_FANCY_PURPLE = 3,
	THEME_LIGHT_PURPLE = 4,
	THEME_DARK_GREEN = 5,
	THEME_LIGHT_GREEN = 6	
};


class ThemeManager {
public:
    ThemeManager();
    void applyCurrentTheme();
    Theme* getCurrent();
    void switchTheme(QString newType);
    QString getThemeName(ThemeType type);
    ThemeType getThemeType(QString themeName);
    
private:
    Theme* current;
    std::map<ThemeType, Theme*> allThemes;
    ThemeType defaultTheme;
    std::map<ThemeType, QString> themeTypeToName;
};


#endif //SPEROCOIN_THEME_THEMEMANAGER_H
