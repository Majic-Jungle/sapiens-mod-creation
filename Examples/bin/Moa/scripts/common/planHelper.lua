
local gameObject = mjrequire "common/gameObject"

local mod = {
    loadOrder = 1,
}

function mod:onload(planHelper)
    planHelper.huntPlanInfosByObjectType[gameObject.types.moa.index] = planHelper.spearHuntingInfo
    
    planHelper.availablePlansFunctionsByObjectType[gameObject.types.deadMoa.index] = planHelper.availablePlansForNonResourceCarcass
end

return mod