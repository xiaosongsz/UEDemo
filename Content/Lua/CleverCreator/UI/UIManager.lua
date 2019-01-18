local UIManager_C = class("UIManager", UClass)

function C_UIManager_CreateWidget(Widget)
    -- print("C_UIManager_CreateWidget", Widget)
    -- Widget:AddToViewport(0)
end

function C_UIManager_Init(C_UIManager)
    UIManager = UIManager_C(C_UIManager)
end