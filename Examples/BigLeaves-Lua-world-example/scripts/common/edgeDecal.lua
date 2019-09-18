
local mod = {
    loadOrder = 1, -- lower numbers are loaded first, and should be preffered. If you require the mod be loaded after other mods, use a higher number.
}

function mod:onload(edgeDecal)
    edgeDecal.groupTypes["leavesA"].size = edgeDecal.groupTypes["leavesA"].size * 4.0
    edgeDecal.groupTypes["leavesBigger"].size = edgeDecal.groupTypes["leavesBigger"].size * 4.0
end

return mod