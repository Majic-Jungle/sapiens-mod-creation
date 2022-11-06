
local gameObject = mjrequire "common/gameObject"
local mob = mjrequire "common/mob/mob"

local serverMoa = {}

local serverGOM = nil
local serverMob = nil


local function infrequentUpdate(objectID, dt, speedMultiplier)
    serverMob:infrequentUpdate(objectID, dt, speedMultiplier)
end


local function mobSapienProximity(objectID, sapienID, distance2, newIsClose)
    serverMob:mobSapienProximity(objectID, sapienID, distance2, newIsClose)
end

function serverMoa:init(serverGOM_, serverWorld_, serverMob_)
    serverGOM = serverGOM_
    serverMob = serverMob_

    serverGOM:addObjectLoadedFunctionForTypes({ gameObject.types.moa.index }, function(object)
        serverGOM:addObjectToSet(object, serverGOM.objectSets.interestingToLookAt)
        serverGOM:addObjectToSet(object, serverGOM.objectSets.moas)
        
        serverMob:mobLoaded(object)
    end)
    
    local reactDistance = mob.types.chicken.reactDistance
    
    serverGOM:setInfrequentCallbackForGameObjectsInSet(serverGOM.objectSets.moas, "update", 2.0, infrequentUpdate)-- this needs to be called frequently enough for the walk speed to only cover 4.5 meters, or mob will pause every update. Max of 4.5/speed
    serverGOM:addProximityCallbackForGameObjectsInSet(serverGOM.objectSets.moas, serverGOM.objectSets.sapiens, reactDistance, mobSapienProximity)
end

return serverMoa