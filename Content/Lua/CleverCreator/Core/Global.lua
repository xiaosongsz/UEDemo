
------------------------------print------------------------------

function dump(table)
    for k,v in pairs(table) do
        print(k, v)
        if type(v) == 'table' then
            dump(v)
        end
    end
end

------------------------------string------------------------------

function string.split(input, delimiter)
    input = tostring(input)
    delimiter = tostring(delimiter)
    if (delimiter=='') then return false end
    local pos,arr = 0, {}
    -- for each divider found
    for st,sp in function() return string.find(input, delimiter, pos, true) end do
        table.insert(arr, string.sub(input, pos, st - 1))
        pos = sp + 1
    end
    table.insert(arr, string.sub(input, pos))
    return arr
end