local mjm = mjrequire "common/mjm"
local vec2 = mjm.vec2
local vec3 = mjm.vec3

local edgeDecal = mjrequire "common/edgeDecal"

local mod = {
    loadOrder = 1,
}


function mod:onload(material)
    
    local function setMaterialB(baseTypeKey, color, roughness, metalOrNil)
        material.types[baseTypeKey].colorB = color
        material.types[baseTypeKey].roughnessB = roughness
        material.types[baseTypeKey].metalB = metalOrNil or 0.0
    end
    
    mj:insertIndexed(edgeDecal.groupTypes, {
        key = "moaFur",
        textureLocations = {
            edgeDecal.textureLocations.mammothA,
            edgeDecal.textureLocations.mammothB,
        },
        size = vec2(0.12, 0.0),
        discardFaces = true,
    })
    
    mj:insertIndexed(edgeDecal.groupTypes, {
        key = "moaFurShorter",
        textureLocations = {
            edgeDecal.textureLocations.mammothA,
            edgeDecal.textureLocations.mammothB,
        },
        size = vec2(0.05, 0.0),
        discardFaces = true,
    })

    local moaFurColor = vec3(0.18, 0.135, 0.12) * 1.3


    mj:insertIndexed(material.types, material.mat("moa", moaFurColor, 1.0))
    mj:insertIndexed(material.types, material.mat("moaDark", vec3(0.14, 0.135, 0.12) * 0.8, 1.0))
    mj:insertIndexed(material.types, material.mat("moaLight", vec3(0.20, 0.135, 0.12) * 1.7, 1.0))
    mj:insertIndexed(material.types, material.mat("moaEye", vec3(0.40, 0.32, 0.05), 0.03))


    mj:insertIndexed(material.types, material.mat("moaFur", moaFurColor, 1.0))
    setMaterialB("moaFur", moaFurColor * 1.2, 1.0)
    material.types.moaFur.edgeDecal = edgeDecal.groupTypes.moaFur

    mj:insertIndexed(material.types, material.mat("moaFurShorter", moaFurColor, 1.0))
    setMaterialB("moaFurShorter", moaFurColor * 1.2, 1.0)
    material.types.moaFurShorter.edgeDecal = edgeDecal.groupTypes.moaFurShorter
    
    mj:insertIndexed(material.types, material.mat("moaMeat", vec3(0.3, 0.12, 0.1) * 0.8, 0.4))
    mj:insertIndexed(material.types, material.mat("moaMeatCooked", vec3(0.07, 0.03, 0.01) * 0.8, 0.8))


end

return mod