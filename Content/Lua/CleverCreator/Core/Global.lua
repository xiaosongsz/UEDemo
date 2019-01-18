function dump(table)
    for k,v in pairs(table) do
        print(k, v)
        if type(v) == 'table' then
            dump(v)
        end
    end
end