local mjm = mjrequire "common/mjm"
local vec3 = mjm.vec3

local mod = {
    loadOrderPriority = 1,
}

function mod:onload(incoming)
    local material = incoming

    material.types["ui_background"].color = vec3(0.05,0.1,0.2)
end

return mod