function class(name, parent)
    local _class = {}
    _class.name = name
    
    --设置父类
    if parent and type(parent) == 'table' then
        _class.super = parent
        setmetatable(_class, {__index = parent})
    end

    --构造函数
    _class.constructor = function() end

    --创建对象
    _class.create = function(...)
        local _object = {}
        
        --设置元表
        setmetatable(_object, {__index = _class})

        --构造函数
        _object:constructor(...)

        return _object
    end

    return _class
end