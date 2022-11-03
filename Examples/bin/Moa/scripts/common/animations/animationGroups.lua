local mod = {
    loadOrder = 1,
}

function mod:onload(animationGroups)
    table.insert(animationGroups.groupNames, "moa")
end

return mod