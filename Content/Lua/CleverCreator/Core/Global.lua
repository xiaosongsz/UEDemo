function dump(table, indent)
    indent = indent or 0
    indent = indent + 1
    local head = ''
    for i=1,indent do
        head = head..'-'
    end
    for k,v in pairs(table) do
        print(head, k, v)
        if type(v) == 'table' then
            dump(v, indent)
        end
    end
end