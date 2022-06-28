-- This example replaces a few of the main menu action names with poorly translated klingon values

-- To create your own localization, you can start by copying this directory, and modifying this file to change the display name.
-- The game searches for localization dirs in the install directory under: GameResources/localizations
-- It will then search in installed & enabled mods, so you can create a directory in any mod eg. myMod/localizations/french, and it will find your localizations there.
-- Lastly it will also search in the user's save directory eg AppData/Roaming/sapiens/localizations, and any localizations stored there will add to and override both the built in localizations, and any added by mods.
-- Localizations that are loaded later overwrite earlier ones, and localizations are considered the same if the directory name is the same. So if the game provides GameResources/localizations/french and then a mod provides myMod/localizations/french, then the mod can add its own new french localizations, or overwrite the game's existing ones.
-- The game will load all lua scripts placed in the localization directory, appending/replacing values. so you could for example have myConstructables.lua that just returns constructable translations in localizations.values
-- This info.lua file is not really required, the localization will function without it. It currently just sets the display name for the pull down menu in the settings UI.

local info = {
    displayName = "Klingon",
}

return info