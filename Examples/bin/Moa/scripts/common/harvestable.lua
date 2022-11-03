
local mod = {
    loadOrder = 1,
}

function mod:onload(harvestable)
    local prevLoad = harvestable.load
    harvestable.load = function(harvestable_, gameObject)
        prevLoad(harvestable_, gameObject)

        harvestable:addHarvestable("moa", {
            gameObject.typeIndexMap.moaMeat,
            gameObject.typeIndexMap.moaMeat,
            gameObject.typeIndexMap.moaMeatLeg,
        }, 3, 3)
    end
end

return mod