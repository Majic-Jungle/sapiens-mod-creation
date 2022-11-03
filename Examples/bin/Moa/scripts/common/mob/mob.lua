
local mobMoa = mjrequire "common/mob/mobMoa"

local mod = {
    loadOrder = 1,
}

function mod:onload(mob)
    table.insert(mob.mobLoaders, mobMoa)
end

return mod