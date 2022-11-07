local mjm = mjrequire "common/mjm"
local vec3 = mjm.vec3
local normalize = mjm.normalize
local vec3xMat3 = mjm.vec3xMat3
local dot = mjm.dot
local mat3LookAtInverse = mjm.mat3LookAtInverse
local mat3GetRow = mjm.mat3GetRow
local mat3Inverse = mjm.mat3Inverse

local gameObject = mjrequire "common/gameObject"

local mod = {
    loadOrder = 1,
}

function mod:onload(sapienObjectSnapping)
    sapienObjectSnapping.snapObjectFunctions[gameObject.types.deadMoa.index] = function(object, sapien, actionTypeIndex)
        local objectRotationToUse = object.rotation
        if dot(mat3GetRow(objectRotationToUse, 1), object.normalizedPos) < 0.5 then
            objectRotationToUse = sapien.rotation
        end
        local offsetPos = object.pos + vec3xMat3(vec3(mj:mToP(-1.0), 0.0, 0.0), mat3Inverse(objectRotationToUse))

        return {
            pos = offsetPos,
            rotation = mat3LookAtInverse(normalize(object.pos - offsetPos), object.normalizedPos),
            offsetToWalkableHeight = true,
        }
    end
end

return mod