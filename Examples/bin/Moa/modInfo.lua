local modInfo = {
    name = "Moa",
    description = "This is an official mod made by the developer, to show how to add a new mob type to the game. It's fully functional, and will be kept up to date.",
    preview = "preview.jpg",
    version = "0.9.0",
    type = "world",
    developer = "Majic Jungle",
    website = "https://majicjungle.com",
    loadOrder = 1, --default load order for all assets for this mod. Higher numbers are loaded after lower numbers. 
                   --For lua scripts, this can be optionally overriden in the mod table per lua script.
}

return modInfo