
local mob = mjrequire "common/mob/mob"
local clientMoa = mjrequire "logicThread/mobs/clientMoa"

local mod = {
    loadOrder = 1,
}

function mod:onload(clientMob)
    clientMob.mobClassMap[mob.types.moa.index] = clientMoa
end

return mod