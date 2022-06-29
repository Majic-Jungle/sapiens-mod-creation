-- this is a very simple example that replaces the "Continue" text on the main menu with "Localized" when the language is set to english
-- When making mods that add content, you can supply your own localizations for your content for multiple languages in this way.
-- Create a localizations directory at the top level of your mod, and then create directories for each language you wish to support, containing lua files which provide the actual translations like this. Those translations will then be used wherever the game or your mod calls locale:get()

local localizations = {}


localizations.values = {
    ui_action_continue = "Localized",
}

        
return localizations