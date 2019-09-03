local modinfo = {
    name = "C Mod Example",
    cmods = {
        {
            path = "lib/MoreSmokeMod",
            loadOrder = 1, -- the functions in cmods with lower loadOrders are called first, and should be preffered.
        },
    }
}

return modinfo