local modInfo = {
    name = "Resource Override Example",
    description = "This example mod replaces the rock model file with a custom one.",
    preview = "preview.jpg",
    version = "0.0.1",
    type = "world",
    developer = "Majic Jungle",
    website = "https://majicjungle.com",
    loadOrder = 1, --default load order for all assets for this mod. Higher numbers are loaded after lower numbers. 
                   --For lua scripts, this can be optionally overriden in the mod table per lua script.
}

return modInfo