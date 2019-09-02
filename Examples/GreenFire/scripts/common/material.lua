local mjm = mjrequire "common/mjm"
local vec3 = mjm.vec3

local mod = {}

function mod:onload(incoming)
    local material = incoming

    material.types["ui_background"].color = vec3(0.05,0.5,0.05)
end

return mod