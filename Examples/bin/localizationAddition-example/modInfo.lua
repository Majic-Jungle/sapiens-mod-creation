-- this example shows two things, the process is the same, but the goals are a little different
-- 1) It adds a very limited new "klingon" translation. This is how you would create a mod specifically to add a new language to the game.
--    see localizations/klingon/info.lua for more info
-- 2) It also replaces a vanilla english translation. This is how you can provide translations for any content you add in a content mod.
--    see localizations/english/localizations.lua for more info

local modInfo = {
    name = "Localization Example",
    description = "This example mod shows how to add a new localization, and also add to an existing one.",
    preview = "preview.png",
    version = "0.0.1",
    type = "app",
    developer = "Majic Jungle",
    website = "https://majicjungle.com",
    loadOrder = 1, --default load order for all assets for this mod. Higher numbers are loaded after lower numbers. 
                   --For lua scripts, this can be optionally overriden in the mod table per lua script.
}

return modInfo