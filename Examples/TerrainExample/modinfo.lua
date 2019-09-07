local modInfo = {
    name = "Terrain Example",
    version = "0.0.1",
    type = "world",
    cmods = {
        {
            path = "lib/MoreSmokeMod",
            loadOrder = 1, -- the functions in cmods with lower loadOrders are called first, and should be preffered.
        },
    }
}

return modInfo 