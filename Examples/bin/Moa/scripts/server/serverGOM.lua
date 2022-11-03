
local mod = {
    loadOrder = 1,
}

function mod:onload(serverGOM)
    
    local prevCreateObjectSets = serverGOM.createObjectSets
    serverGOM.createObjectSets = function(serverGOM_)
        prevCreateObjectSets(serverGOM_)
        serverGOM.objectSets.moas = serverGOM:createObjectSet("moas")
    end
end

return mod