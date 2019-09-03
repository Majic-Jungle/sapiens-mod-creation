local mjm = mjrequire "common/mjm"
local vec3 = mjm.vec3

local mod = {
    loadOrder = 1, -- lower numbers are loaded first, and should be preffered. If you require the mod be loaded after other mods, use a higher number.
}

function mod:onload(incoming)
    local material = incoming

    material.types["ui_background"].color = vec3(0.05,0.1,0.2)
end

return mod