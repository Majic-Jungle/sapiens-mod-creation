local mjm = mjrequire "common/mjm"
local vec3 = mjm.vec3

local mod = {
    loadOrder = 1,
}

function mod:onload(material)
    mj:insertIndexed(material.types, material.mat("moa", vec3(0.18, 0.135, 0.12) * 1.3, 1.0))
    mj:insertIndexed(material.types, material.mat("moaDark", vec3(0.14, 0.135, 0.12) * 0.8, 1.0))
    mj:insertIndexed(material.types, material.mat("moaLight", vec3(0.20, 0.135, 0.12) * 1.7, 1.0))
    
    mj:insertIndexed(material.types, material.mat("moaMeat", vec3(0.3, 0.12, 0.1) * 0.8, 0.4))
    mj:insertIndexed(material.types, material.mat("moaMeatCooked", vec3(0.07, 0.03, 0.01) * 0.8, 0.8))

end

return mod