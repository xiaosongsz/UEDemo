function class(name, super)
    local _class = {}
    _class._type = name

    --基类
    local _base = {
        --构造函数
        constructor = function() end,

        --创建对象
        __call = function(_class, ...)
            local _object = {}

            --设置元表
            setmetatable(_object, {__index = _class})

            --构造函数
            _object:constructor(...)

            return _object
        end,
    }

    --设置父类
    if super then
        _class._super = super
        _base.__index = super
    end

    setmetatable(_class, _base)

    return _class
end