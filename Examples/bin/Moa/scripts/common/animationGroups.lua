local mod = {
    loadOrder = 1,
}

function mod:onload(animationGroups)
    table.insert(animationGroups.loadFileNames, "moa")
end

return mod