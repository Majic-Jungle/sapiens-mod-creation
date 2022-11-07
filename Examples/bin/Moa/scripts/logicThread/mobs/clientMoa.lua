-- This file is a stub, which could allow for different behaviors per mob type. It is currently necessary to provide these functions here, as the vanilla code expects them.
-- Currently though, none of the mobs use this to override the base clientMob functionality.

local clientMoa = {}

clientMoa.serverUpdate = function(object, notifications, pos, rotation, scale, incomingServerStateDelta)
end

clientMoa.objectWasLoaded = function(object, pos, rotation, scale)
end

function clientMoa:update(object, dt, speedMultiplier)
end


function clientMoa:init(clientGOM_)
end

return clientMoa